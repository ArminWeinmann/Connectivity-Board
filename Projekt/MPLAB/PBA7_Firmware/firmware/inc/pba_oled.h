/**
 * @defgroup 		OLED
 * @brief 			Stellt Funktionen für die Verwendung des EA OLEDM204 auf dem
 *                  PBA7 zur Verfügung.
 * @{
 *******************************************************************************
 * @file            pba_oled.h
 * @brief           Stellt Funktionen für die Verwendung des EA OLEDM204 auf dem
 *                  PBA7 zur Verfügung.
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

#ifndef PBA_OLED_H
#define	PBA_OLED_H

/***Includes*******************************************************************/

#include "../mcc_generated_files/mcc.h"

/***Typendeklarationen********************************************************/

/**
 * @brief Typendeklaration für die Zeichensätze des OLEDs.
 * @details Die Zeichensätze findet man im Datenblat des EA OLEDM204
 */
typedef enum{
    ROMA, ROMB, ROMC
}oled_rom_t;

/***Funktionsprototypen*******************************************************/

void OLED_Init(void);
void OLED_Putc(char ch);
void OLED_GotoXY(uint8_t x, uint8_t y);
void OLED_Clear(void);
void OLED_SelectROM(oled_rom_t oledROM);
void OLED_CursorOn(bool cursor);

#endif	/* PBA_OLED_H */

