/**
 * @dir inc
 * @brief 			Header Files des PBA BSP
 *******************************************************************************
 * @defgroup 		CONFIG
 * @brief           Stellt eine Funktion zur Initialisierung des PBA7, sowie 
 *                  weitere hilfreiche Funktionen und Makros zur Verfügung.
 * @{
 *******************************************************************************
 * @file            pba_config.h
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

#ifndef PBA_CONFIG_H
#define	PBA_CONFIG_H

/***Includes*******************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "../mcc_generated_files/mcc.h"
#include "pba_oled.h"
#include "pba_rtc.h"
#include "pba_btn.h"
#include "pba_systick.h"
#include "pba_statemachine.h"

/***Defines********************************************************************/

#define LED0    IO_RD0_LAT
#define LED1    IO_RD1_LAT
#define LED2    IO_RD2_LAT
#define LED3    IO_RD3_LAT
#define LED4    IO_RD4_LAT
#define LED5    IO_RD5_LAT
#define LED6    IO_RD6_LAT
#define LED7    IO_RD7_LAT
#define LED8    IO_RE0_LAT
#define LED9    IO_RE1_LAT
#define LEDS_D  LATD
#define LEDS_E  LATE

#define TASTER0 IO_RC0_PORT
#define TASTER1 IO_RC1_PORT
#define TASTER2 IO_RC2_PORT
#define TASTER3 IO_RC3_PORT
#define TASTER4 IO_RC4_PORT
#define TASTER5 IO_RC5_PORT
#define TASTER6 IO_RC6_PORT
#define TASTER7 IO_RC7_PORT
#define TASTER  PORTC

/***Funktionsprototypen********************************************************/

void PBA_Init(void);
inline void PBA_SetLEDs(uint16_t leds);
void PBA_ConfigPrintf(bool enableOLED, bool enableUART);
void putch(char ch);

/***Warnings ausschalten*******************************************************/

#pragma warning disable 520     //Function is never called
#pragma warning disable 2053    //Inline function is never called

#endif	/* PBA_CONFIG_H */

