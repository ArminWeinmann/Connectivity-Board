/**
 * @defgroup 		SYSTICK
 * @brief			Library für die Verwendung von Soft-Timer.
 * @{
 *******************************************************************************
 * @file            pba_systick.h
 * @brief           Library für die Verwendung von Soft-Timer.
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

#ifndef PBA_SYSTICK_H
#define	PBA_SYSTICK_H

/***Includes*******************************************************************/

#include <stdint.h>
#include <stdbool.h>

/***Defines********************************************************************/

/**
 * @brief Maximale Anzahl an Softtimern, die verwendet werden können.
 * @details Für diese Timer wird Speicherplatz recerviert. Um Ressourcen zu sparen
 * sollten nicht unnötig viele Timer recerviert werden. 
 */
#define SYSTICK_MAX_SOFT_TIMERS     6   

/***Funktionsprototypen********************************************************/

void SYSTICK_TimerLoadAndRun(uint8_t descriptor, uint32_t loadValue);
void SYSTICK_TimerRun(uint8_t descriptor);
void SYSTICK_TimerLoad(uint8_t descriptor, uint32_t loadValue);
void SYSTICK_TimerStop(uint8_t descriptor);
bool SYSTICK_Timeout(uint8_t descriptor);
void SYSTICK_AddTimeoutHandler(uint8_t descriptor, void (*p_Function)(void));
void SYSTICK_Handler(void);

#endif	/* PBA_SYSTICK_H */

