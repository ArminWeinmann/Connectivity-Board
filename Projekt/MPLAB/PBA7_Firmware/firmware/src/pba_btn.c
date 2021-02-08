/**
 * @defgroup BTN
 * @{
 *******************************************************************************
 * @file            pba_btn.c
 * @brief           Stellt Funktionen im Umgang mit Tastern zur Verfügung.
 * @details         Für die Flankenerkennung muss ausserhalb dieser Funktionen
 * entprellt werden. Dazu reicht eine einfache Verzögerung (z.B. 10ms). 
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

#include "../inc/pba_btn.h"

/***Funktionsprototypen statischer Funktionen**********************************/

static inline bool BitTest(uint8_t reg, uint8_t bitNumber);

/***Funktionen*****************************************************************/

/**
 * @brief Prüft ob eine positive Flanke an einem Taster stattgefunen hat. Darf 
 * nicht ständig aufgerufen werden. Für die Entprellung wird etwas Zeit benötigt.
 * @details Bsp: \code if(BTN_GetPosEdge(3)){ .. } \endcode 
 * @param button Welcher Taster am Port abgefragt wird. (0-7)
 * @return Gibt true zurück, wenn eine positive Flanke registriert wurde. 
 */
bool BTN_GetPosEdge(uint8_t button){
    static uint8_t flags = 0xFF;    //< Zwischenspeicher für Flankenerkennung
    bool posEdge = false;           //< Zwischenspeicher für return
    /*Wenn der entsprechende Taster gedrückt ist und das flag noch auf 0 ist.*/
    if(BitTest(TASTER_PORT,button)&&!BitTest(flags,button)){  
        posEdge = true;
    }
    /*Das Flag des entsprechenden Tasters wird aktualisiert. Eine oder und eine
     und Verknüpfung, damit alle anderen Bits nicht verändert werden.*/
    flags |= TASTER_PORT & (1<<button);
    flags &= TASTER_PORT | (~(1<<button));
    return posEdge;
}

/**
 * @brief Prüft ob eine negative Flanke an einem Taster stattgefunen hat. Darf 
 * nicht ständig aufgerufen werden. Für die Entprellung wird etwas Zeit benötigt.
 * @details Bsp: \code if(BTN_GetNegEdge(3)){ .. } \endcode 
 * @param button Welcher Taster am Port abgefragt wird. (0-7)
 * @return Gibt true zurück, wenn eine negative Flanke registriert wurde. 
 */
bool BTN_GetNegEdge(uint8_t button){
    static uint8_t flags = 0x00;    //< Zwischenspeicher für Flankenerkennung
    bool negEdge = false;           //< Zwischenspeicher für return
    /*Wenn der entsprechende Taster schon low ist und das Flag noch high.*/
    if(!BitTest(TASTER_PORT,button)&&BitTest(flags,button)){
        negEdge = true;
    }
    /*Das Flag des entsprechenden Tasters wird aktualisiert. Eine oder und eine
     und Verknüpfung, damit alle anderen Bits nicht verändert werden.*/
    flags |= TASTER_PORT & (1<<button);
    flags &= TASTER_PORT | (~(1<<button));
    return negEdge;
}

/**
 * @brief Überprüft den Zustand eines Tasters.
 * @details Bsp: \code if(BTN_GetValue(3){ .. }) \endcode
 * @param button Der zu prüfende Taster am Port.
 * @return Gibt true zurück, wenn der Taster hight ist. false, wenn Taster low.
 */
bool BTN_GetValue(uint8_t button){
    if(BitTest(TASTER_PORT,button))
        return true;
    else 
        return false;
}

/**
 * @brief Testet ein bestimmtes Bit in einem Byte und retourniert den Zustand.
 * @details Bsp: \code if(BitTest(regA,3){ .. } \endcode
 * @param reg Datenbyte
 * @param bitNumber Bitnummer
 */
static inline bool BitTest(uint8_t reg, uint8_t bitNumber){
    if(reg & (1 << bitNumber))
        return true;
    else
        return false;
}