/**
 * @defgroup        HARDWARETEST
 * @brief           Hardwaretestsoftware für das PIC Board Advanced 7
 * @{
 *******************************************************************************
 * @file            main.c
 * @brief           Hardwaretestsoftware für das PIC Board Advanced 7
 * @author          ICT Berufsbildungscenter AG
 *******************************************************************************
 *
 * @copyright
 * @{
 *
 * Diese Software kann unter den Bedingungen der MIT-Lizenz verwendet werden.
 *
 * Copyright &copy; 2020 ICT Berufsbildungscenter AG
 *
 * #####MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @}
 */

/***Includes*******************************************************************/

#include "inc/pba_config.h"

/***Prototypen und Typendeklarationen******************************************/

void Summer(void);
void ReceiveHandler(void);

/**
 * @brief Aufzählung für die Zustände, der Zustandsmaschine.
 */
typedef enum 
{
    S_TASTER,       ///< In diesem Zustand werden die Taster und die LEDs getestet.
    S_SUMMER,       ///< In diesem Zustand wird der Summer getestet.
    S_RTC,          ///< In diesem Zustand wird der RTC (I2C) getestet.
    S_TEMP_RTC,     ///< In diesem Zustand wird der Temperatursensor des RTCs getestet
    S_POTI,         ///< In diesem Zustand werden die Potentiometer getestet.
    S_UART          ///< In diesem Zustand wird die UART Schnittstelle getestet.
}state_t; 

/**
 * @brief Aufzählung für die Softtimer.
 */
enum{
    LOOP_TIMER,     ///< Timer für die Zykluszeit
    BLINK_TIMER,    ///< Timer fürs Blinken
    SUMMER_TIMER   ///< Timer für den Summer
};

/***HAUPTPROGRAM**************************************************************/

/**
 * @brief Hauptprogramm. Hardwaretest für das PBA7.
 */
void main(void)
{
    PBA_Init();
    state_t myState = S_TASTER;     // Zustand der Hauptzustandmaschine
    STATEMACHINE_Init(&myState);
    SYSTICK_TimerLoadAndRun(LOOP_TIMER,10);     //Zykluszeit 10ms
    while (1)
    {
        while(!SYSTICK_Timeout(LOOP_TIMER));    //Warten bis Zykluszeit abgelaufen ist.
        SYSTICK_TimerLoadAndRun(LOOP_TIMER,10); //Zyklustimer neu laden und starten
        switch(myState){
/***********S_TASTER***********************************************************/
            case S_TASTER:
                if(STATEMACHINE_StateEntry()){
                    printf("Taster und LEDs Test\n\nweiter mit T0...");
                    LED0 = 1;
                    LED8 = LED9 = 1;
                    SYSTICK_TimerLoadAndRun(BLINK_TIMER, 500);  //Timer fürs blinken von L0 starten
                }
                
                /*Den LEDs 1-7 die Taster 1-7 zuweisen. L0 bleibt unverändert.*/
                LEDS_D |= TASTER & 0xFE;
                LEDS_D &= TASTER | 0x01;
                
                /*LED0 blinkt mit 1Hz.*/
                if(SYSTICK_Timeout(BLINK_TIMER)){
                    LED0 = !LED0;
                    SYSTICK_TimerLoadAndRun(BLINK_TIMER, 500);
                }
                
                /*Bei einer positiven Flanke an T0, wird der Zustand gewechselt.*/
                if(BTN_GetPosEdge(0)){
                    myState = S_SUMMER;
                }
                
                /*Display löschen und alles zurücksetzen.*/
                if(STATEMACHINE_StateExit()){
                    OLED_Clear();
                    SYSTICK_TimerStop(BLINK_TIMER);
                    LEDS_D = 0;
                    LED8 = LED9 = 0;
                }
                break;
               
/***********S_SUMMER***********************************************************/
            case S_SUMMER:
                if(STATEMACHINE_StateEntry()){
                    printf("Summer Test\n\n\nweiter mit T0...");
                    /*Softtime um den Summer mit 500Hz zu betreiben. Die Funktion
                     summer wird jede Millisekunde aufgerufen.*/
                    SYSTICK_TimerLoadAndRun(SUMMER_TIMER, 1);
                    SYSTICK_AddTimeoutHandler(SUMMER_TIMER, Summer);
                    SYSTICK_TimerLoadAndRun(BLINK_TIMER, 500);
                    LED1 = 1;
                }
                /*LED1 blinkt mit 1Hz*/
                if(SYSTICK_Timeout(BLINK_TIMER)){
                    LED1 = !LED1;
                    SYSTICK_TimerLoadAndRun(BLINK_TIMER,500);
                }
                
                /*Bei pos. Flanke an T0, wird der nächste Test gestartet.*/
                if(BTN_GetPosEdge(0)){
                    myState = S_RTC;
                }
                
                /*Display löschen und Timer stoppen.*/
                if(STATEMACHINE_StateExit()){
                    OLED_Clear();
                    SYSTICK_TimerStop(BLINK_TIMER);
                    SYSTICK_TimerStop(SUMMER_TIMER);
                    LEDS_D = 0;
                }
                break;
                
/***********S_RTC**************************************************************/
            case S_RTC:
                /*Blinktimer starten und RTC zurücksetzen.*/
                if(STATEMACHINE_StateEntry()){
                    LED2 = 1;
                    SYSTICK_TimerLoadAndRun(BLINK_TIMER, 500);
                    printf("RTC Test\nVerstrichene Zeit:\n\nweiter mit T0...");
                    RTC_SetHours(0);
                    RTC_SetMinutes(0);
                    RTC_SetSeconds(0);
                }
                
                /*Verstrichene Zeit aktualisieren.*/
                OLED_GotoXY(0,2);
                printf("%02i:%02i:%02i", RTC_GetHours(), RTC_GetMinutes(), RTC_GetSeconds());
                
                /*LED2 blinkt mit 1Hz.*/
                if(SYSTICK_Timeout(BLINK_TIMER)){
                    SYSTICK_TimerLoadAndRun(BLINK_TIMER, 500);
                    LED2 = !LED2;
                }
                
                /*Bei pos. Flanke an T0, wird der nächste Test gestartet.*/
                if(BTN_GetPosEdge(0)){
                    myState = S_TEMP_RTC;
                }
                
                /*Display löschen und Timer stoppen.*/
                if(STATEMACHINE_StateExit()){
                    OLED_Clear();
                    SYSTICK_TimerStop(BLINK_TIMER);
                    LED2 = 0;
                }
                break;
                
/***********S_TEMP_RTC*********************************************************/
            case S_TEMP_RTC:
                if(STATEMACHINE_StateEntry()){
                    printf("RTC Temperatur Test\nTemperatur:\n\nweiter mit T0...");
                    SYSTICK_TimerLoadAndRun(BLINK_TIMER, 500);
                    LED3 = 1;
                    /*Anderer Zeichensatz wählen, der "°" beinhaltet.*/
                    OLED_SelectROM(ROMC);
                }
                
                /*LED3 blinkt mit 1Hz. Die Temperaturwandlung wird alle 500ms gestartet.*/
                if(SYSTICK_Timeout(BLINK_TIMER)){
                    SYSTICK_TimerLoadAndRun(BLINK_TIMER, 500);
                    RTC_ConvertTemp();
                    LED3 = !LED3;
                }
                
                /*Wenn die Temmperaturwandlung abgeschlossen ist, wird sie ausgegeben.*/
                if(RTC_IsTempConvDone()){
                    OLED_GotoXY(11,1);
                    printf("%3i%cC", RTC_GetTemp(), 0xDF);  //Grad Zeichen hat die Adresse 0xDF
                }
                
                /*Bei pos. Flanke an T0, wird der nächste Test gestartet.*/
                if(BTN_GetPosEdge(0)){
                    myState = S_POTI;
                }
                
                /*Zeichensatz auf Standard zurückstellen. Display löschen.*/
                if(STATEMACHINE_StateExit()){
                    OLED_SelectROM(ROMB);
                    OLED_Clear();
                    SYSTICK_TimerStop(BLINK_TIMER);
                    LED3 = 0;
                }
                break;
                
/***********S_POTI*************************************************************/
            case S_POTI:
                if(STATEMACHINE_StateEntry()){
                    printf("Potentiometer Test\n\n\nweiter mit T0...");
                    SYSTICK_TimerLoadAndRun(BLINK_TIMER, 500);
                    LED4 = 1;
                }
                
                /*LED4 blinkt mit 1Hz.*/
                if(SYSTICK_Timeout(BLINK_TIMER)){
                    SYSTICK_TimerLoadAndRun(BLINK_TIMER, 500);
                    LED4 = !LED4;
                }
                
                /*Ausgabe der Spannung an den Potis mit einer Nachkommastelle in V.*/
                OLED_GotoXY(0,1);
                printf("Pot0: %01i.%01iV", ADC_GetConversion(POT0)/310, (ADC_GetConversion(POT0)/31)%10);
                printf("\nPot1: %01i.%01iV", ADC_GetConversion(POT1)/310, (ADC_GetConversion(POT1)/31)%10);
                
                /*Bei pos. Flanke an T0, wird der nächste Test gestartet.*/
                if(BTN_GetPosEdge(0)){
                    myState = S_UART;
                }
                
                /*Display löschen und Timer stoppen.*/
                if(STATEMACHINE_StateExit()){
                    OLED_Clear();
                    SYSTICK_TimerStop(BLINK_TIMER);
                    LED4 = 0;
                }
                break;
                
/***********S_UART*************************************************************/
            case S_UART:
                if(STATEMACHINE_StateEntry()){
                    printf("UART Baud: 115200\n\n\nweiter mit T0...");
                    OLED_GotoXY(0,1);
                    OLED_CursorOn(true);        //Display Cursor einschalten
                    PBA_ConfigPrintf(false, true);     //Printf Ausgabe über UART und nicht auf Display
                    printf("********************************************\n\r");
                    printf("*       PIC Board Advanced 7               *\n\r");
                    printf("*       ICT Berufsbildungscenter AG        *\n\r");
                    printf("*       Hardware-Testsoftware              *\n\r");
                    printf("********************************************\n\r");
                    printf("\nBitte Text eingeben:\n\r");
                    PBA_ConfigPrintf(true, false);     //Printf Ausgabe wieder aufs Display
                    /*Empfangs Interrupt Handler definieren und Interrupt einschalten.*/
                    EUSART1_SetRxInterruptHandler(ReceiveHandler);
                    PIE3bits.RC1IE = 1;
                    SYSTICK_TimerLoadAndRun(BLINK_TIMER, 500);
                    LED5 = 1;
                }
                
                /*LED5 blinkt mit 1Hz.*/
                if(SYSTICK_Timeout(BLINK_TIMER)){
                    SYSTICK_TimerLoadAndRun(BLINK_TIMER, 500);
                    LED5 = !LED5;
                }
                
                /*Bei pos. Flanke an T0 wieder zum ersten Test.*/
                if(BTN_GetPosEdge(0)){
                    myState = S_TASTER;
                }
                
                if(STATEMACHINE_StateExit()){
                    PBA_ConfigPrintf(false, true);     //Printf Ausgabe über UART und nicht auf Display
                    printf("\n\r********************************************\n\r");
                    printf("*       UART Test wurde beendet            *\n\r");
                    printf("********************************************\n\r");
                    PBA_ConfigPrintf(true, false);     //Printf Ausgabe wieder aufs Display
                    OLED_Clear();
                    OLED_CursorOn(false);        //Display Cursor ausschalten
                    SYSTICK_TimerStop(BLINK_TIMER);
                    LED5 = 0;
                    PIE3bits.RC1IE = 0;         //Empfangsinterrupt einschalten
                }
                break;
        }
        
        STATEMACHINE_Update();      //Zustände aktualisieren.
        
    }
}

/**
 * @brief Toggelt den Summer und startet den SUMMER_TIMER neu.
 * @details Bsp: \code SYSTICK_AddTimeoutHandler(SUMMER_TIMER, summer); \endcode
 */
void Summer(void){
    SUMMER_Toggle();
    SYSTICK_TimerLoadAndRun(SUMMER_TIMER, 1);
}

/**
 * @brief Interrupt Handler für UART Empfang. Gibt ein Echo ans Terminal und 
 * schreibt das Zeichen ans OLED.
 * @details Bsp: \code EUSART1_SetRxInterruptHandler(ReceiveHandler); \endcode
 */
void ReceiveHandler(void){
    char c = RC1REG;
    OLED_Putc(c);
    EUSART1_Write(c);
}