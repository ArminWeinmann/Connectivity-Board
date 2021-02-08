/**
 * @defgroup SYSTICK
 * @{
 *******************************************************************************
 * @file            pba_systick.c
 * @brief           Library für die Verwendung von Soft-Timern.
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

#include "../inc/pba_systick.h"

/***Typendeklarationen*********************************************************/

/**
 * @brief Zustand des Timers
 * @details Der Timer kann entweder laufen oder nicht laufen.
 */
typedef enum 
{
    NOT_RUNNING,    ///< Der Timer läuft nicht.
    RUNNING         ///< Der Timer läuft.
}timer_state_t;    

/**
 * @brief Datentyp für einen Soft-Timer
 * @details Ein Softtimer hat einen Zähler, der angibt, wie viele Millisekunden der Timer noch läuft.
 * Er hat einen Zustand (Timer läuft oder Timer ist gestoppt) und er hat eine callback function, die
 * aufgerufen wird, sobald der Timer ausgelaufen ist. 
 */
typedef struct 
{
    uint32_t tickCnt;       ///< Zähler für den Timer. Bei 0 ist der Timer ausgelaufen.
    timer_state_t state;    ///< Zustand des Timers. Timer läuft oder Timer läuft nicht.
    void (*p_callbackFunction)(void);   ///< Funktionspointer für die callback function.
}soft_timer_t;      

/***Varablen*******************************************************************/

/**
 * @brief Array mit den Softtimern.
 * @details Die einzelnen Timer werden durch einen "Descriptor" identifiziert (uint8_t Zahl).
 */
volatile static soft_timer_t softTimer[SYSTICK_MAX_SOFT_TIMERS];    

/***Funktionen*****************************************************************/

/**
 * @brief Setzt den Zustand eines Timers auf laufend. Damit er zählt, muss er aber auch
 * geladen sein. 
 * @details Bsp: \code SYSTICK_TimerRun(0); \endcode
 * @param descriptor Welcher Timer gestartet werden soll. Kann auch mit einem Define oder enum gemacht werden.
 */
void SYSTICK_TimerRun(uint8_t descriptor) 
{
    /*Wenn es den Timer gibt, wird er gestartet.*/
    if(descriptor < SYSTICK_MAX_SOFT_TIMERS)
    {
        softTimer[descriptor].state = RUNNING;
    }
}

/**
 * @brief Lädt einen Timer mit einem Wert und startet diesen.
 * @details Bsp: \code SYSTICK_TimerLoadAndRun(0, 1000); \endcode
 * @param descriptor Welcher Timer geladen und gestartet werden soll. Kann auch mit einem Define oder enum gemacht werden.
 * @param loadValue Zeit, die geladen wird in ms.
 */
void SYSTICK_TimerLoadAndRun(uint8_t descriptor, uint32_t loadValue) 
{
    /*Der Timer wird geladen und anschliessend gestartet.*/
    SYSTICK_TimerLoad(descriptor, loadValue);
    SYSTICK_TimerRun(descriptor);
}

/**
 * @brief Lädt einen Timer mit einem Wert. Wenn der Timer nicht gestartet ist, passiert aber nichts.
 * @param descriptor Welcher Timer geladen werden soll. Kann auch mit einem Define oder enum gemacht werden.
 * @param loadValue Zeit, die geladen wird in ms.
 */
void SYSTICK_TimerLoad(uint8_t descriptor, uint32_t loadValue) 
{
    /*Wenn es den Timer gibt, wird denn Wert geladen.*/
    if(descriptor < SYSTICK_MAX_SOFT_TIMERS)
    {
        softTimer[descriptor].tickCnt = loadValue;
    }
}

/**
 * @brief Stoppt einen Timer. 
 * @param descriptor Welcher Timer gestoppt werden soll. Kann auch mit einem Define oder enum gemacht werden.
 */
void SYSTICK_TimerStop(uint8_t descriptor) 
{
    /*Wenn es den Timer gibt, wird er gestoppt.*/
    if(descriptor < SYSTICK_MAX_SOFT_TIMERS) 
    {
        softTimer[descriptor].state = NOT_RUNNING;
    }
}

/**
 * @brief Prüft ob der Timer abgelaufen ist.
 * @param descriptor Welcher Timer geprüft werden soll. Kann auch mit einem Define oder enum gemacht werden.
 * @return Gibt true zurück, wenn der Timer ausgelaufen ist. 
 */
bool SYSTICK_Timeout(uint8_t descriptor) 
{
    bool isTimeout = false;     ///< Zwischenspeicher für return
    /*Wenn es den Timer gibt, er läuft und ausgelaufen ist, wird true zurückgegeben.*/
    if(descriptor < SYSTICK_MAX_SOFT_TIMERS) 
    {
        if(softTimer[descriptor].state == RUNNING && softTimer[descriptor].tickCnt == 0)
        {
            SYSTICK_TimerStop(descriptor);
            isTimeout = true;
        }
    }
    return isTimeout;
}

/**
 * @brief Interrupt Handler für einen Softtimer festlegen.
 * @details Bsp: \code SYSTICK_AddTimeoutHandler(SUMMER_TIMER, Summer); \endcode
 * @param descriptor
 * @param p_Function
 */
void SYSTICK_AddTimeoutHandler(uint8_t descriptor, void (*p_Function)(void)){
    softTimer[descriptor].p_callbackFunction = p_Function;
}

/**
 * @brief Der Handler updatet alle Softtimers. Muss jede Millisekunde in einem Interrupt aufgerufen werden.
 * @details Bsp: \code TMR0_SetInterruptHandler(&SYSTICK_Handler); \endcode
 */
void SYSTICK_Handler(void) 
{
    /*Für jeden der Softtimers, der läuft und noch nicht abgelaufen ist, wird der
     Zähler dekrementiert.*/
    for (uint8_t i  = 0; i < SYSTICK_MAX_SOFT_TIMERS; i++) 
    {
        if (softTimer[i].state == RUNNING && softTimer[i].tickCnt > 0) 
        {
            softTimer[i].tickCnt--;
            if(softTimer[i].tickCnt == 0 && softTimer[i].p_callbackFunction != 0){
                softTimer[i].p_callbackFunction();
            }
        }
    }
}

