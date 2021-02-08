/**
 * @defgroup STATEMACHINE
 * @{
 *******************************************************************************
 * @file            pba_statemachine.c
 * @brief           Funktionen für den Umgang mit State-Machines (FSM).
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

#include "../inc/pba_statemachine.h"

/***Variablen******************************************************************/

static uint8_t currentState;                ///< aktueller Zustand
static uint8_t previousState = 255;         //< vorheriger Zustand
static uint8_t *p_state;                    //< Pointer auf Zustand aus Hauptprogramm

/***Funktionen*****************************************************************/

/**
 * @brief Initialisiert die Statemachine-Library
 * @details Bsp: \code 
 * typedef enum{
 *     STATE1, STATE2, STATE3
 * }state_t;
 * 
 * enum{
 *     LOOP_TIMER, BLINK_TIMER
 * };
 * 
 * void main(void)
 * {
 *     PBA_Init();
 *     
 *     state_t myState = STATE1;
 *     STATEMACHINE_Init(&myState);
    
 *     SYSTICK_TimerLoadAndRun(LOOP_TIMER,10);
 *     while (1)
 *     {
 *         while(!SYSTICK_Timeout(LOOP_TIMER));
 *         SYSTICK_TimerLoadAndRun(LOOP_TIMER,10);
  
 *         switch(myState){
 *             case STATE1:
 *                 if(STATEMACHINE_StateEntry()){ .. }
 *                 
 *                 //do
 *                 //..
 * 
 *                 if(STATEMACHINE_StateExit()){ .. }
 *                 break;
 * 
 *             case STATE2:
 *                 //..
 *                 break;
 *         }
 *         STATEMACHINE_Update();
 *     }
 * }
 *  \endcode
 * @param p_statePointer Pointer auf ein enum mit den Zuständen.
 */
void STATEMACHINE_Init(uint8_t *p_statePointer){
    p_state = p_statePointer;
    currentState = *p_state;
}

/**
 * @brief Aktualisiert die Zustandmaschine. Aufruf immer unter dem Switch für die Statemachine.
 * Bei Aufruf oberhalb vom switch, wird beim Anfangszustand StateEntry nicht ausgelöst.
 * @details Bsp: \code STATEMACHINE_Update(); \endcode
 */
void STATEMACHINE_Update(void){
    previousState = currentState;
    currentState = *p_state;
}

/**
 * @brief Prüft ob eine Transition in den Zustand stattgefunden hat.
 * @details Bsp: \code if(STATEMACHINE_StateEntry()){ .. } \endcode
 * @return Gibt true zurück, wenn eine Transition in den Zustand stattgefunden hat.
 */
bool STATEMACHINE_StateEntry(void){
    if(currentState!=previousState)
        return true;
    else
        return false;
}

/**
 * @brief Prüft ob der Zustand gerade verlassen wird.
 * @details Bsp: \code if(STATEMACHINE_StateExit()){ .. } \endcode
 * @return Gibt true zurück, wenn der Zustand verlassen wird.
 */
bool STATEMACHINE_StateExit(void){
    if(*p_state!=currentState)
        return true;
    else
        return false;
}
