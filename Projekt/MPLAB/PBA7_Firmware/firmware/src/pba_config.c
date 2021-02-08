/**
 * @dir             src
 * @brief           Source files des PBA BSP
 * @defgroup        CONFIG
 * @{
 *******************************************************************************
 * @file            pba_config.c
 * @brief           Stellt eine Funktion zur Initialisierung des PBA7, sowie 
 *                  weitere hilfreiche Funktionen und Makros zur Verfügung.
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

#include "../inc/pba_config.h"

/***Variablen******************************************************************/

/**
 * @brief Gibt an, ob Zeichen, die mit printf ausgegeben werden, ans OLED gesendet werden.
 */
static uint8_t printfEnableOLED = 1; 

/**
 * @brief Gibt an, ob Zeichen, die mit printf ausgegeben werden, per UART gesendet werden.
 */
static uint8_t printfEnableUART = 0;

/***Funktionen*****************************************************************/

/**
 * @brief Initialisiert das PBA.
 * @details Bsp: \code PBA_Init(); \endcode
 */
void PBA_Init(void){
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    OLED_Init();
    OLED_Init();
    RTC_Init();
    TMR0_SetInterruptHandler(&SYSTICK_Handler);
}

/**
 * @brief Beschreibt beide LED-Ports gleichzeitig.
 * @details Bsp: \code PBA_SetLEDs(0x02AA); \endcode
 * @param leds Wert der an die LEDs ausgegeben werden soll (rechtsbündig).
 */
inline void PBA_SetLEDs(uint16_t leds){
    LEDS_D = leds&0x00FF;
    LEDS_E |= (leds>>8)&0x03;
    LEDS_E &= (leds>>8)|0xFC;
}

/**
 * @brief Konfiguriert den Output bei Verwendung von printf
 * @details Bsp: \code PBA_ConfigPrintf(1, 0); \endcode
 * @param enableOLED Wenn true, werden Zeichen ans OLED geschrieben.
 * @param enableUART Wenn true, werden Zeichen über UART ausgegeben.
 */
void PBA_ConfigPrintf(bool enableOLED, bool enableUART){
    printfEnableOLED = enableOLED;
    printfEnableUART = enableUART;
}

/**
 * @brief Schreibt ein Zeigen. Wird von der printf Funktion verwendet.
 * @details Bsp: \code putch('A'); \endcode
 * @param ch ASCII Zeichen, das geschrieben werden soll.
 */
void putch(char ch){
    if(printfEnableOLED)
        OLED_Putc(ch);
    if(printfEnableUART)
        EUSART1_Write(ch);
}