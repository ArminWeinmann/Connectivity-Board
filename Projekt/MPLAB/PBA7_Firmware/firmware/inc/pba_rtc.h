/**
 * @defgroup 		RTC
 * @brief 			Stellt Funktionen für die Verwendung des Real-Time-Clocks
 *                  DS3231 auf dem PBA7 zur Verfügung.
 * @{
 *******************************************************************************
 * @file            pba_rtc.h
 * @brief           Stellt Funktionen für die Verwendung des Real-Time-Clocks
 *                  DS3231 auf dem PBA7 zur Verfügung.
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

#ifndef PBA_RTC_H
#define	PBA_RTC_H

/***Includes*******************************************************************/

#include "../mcc_generated_files/mcc.h"

/***Funktionsprototypen********************************************************/

void RTC_Init(void);
uint8_t RTC_GetSeconds(void);
void RTC_SetSeconds(uint8_t seconds);
uint8_t RTC_GetMinutes(void);
void RTC_SetMinutes(uint8_t minutes);
uint8_t RTC_GetHours(void);
void RTC_SetHours(uint8_t houres);
void RTC_ConvertTemp(void);
uint8_t RTC_IsTempConvDone(void);
int8_t RTC_GetTemp(void);

#endif	/* PBA_RTC_H */

