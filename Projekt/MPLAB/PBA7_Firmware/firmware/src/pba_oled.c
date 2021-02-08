/**
 * @defgroup OLED
 * @{
 *******************************************************************************
 * @file            pba_oled.c
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

/***Includes*******************************************************************/

#include "../inc/pba_oled.h"

/***Defines********************************************************************/

/**
 * @brief Höchste Spaltenadresse des Displays.
 * @details Die Anzahl Spalten auf dem Display entspricht MAX_COLUMN_ADD + 1
 */
#define MAX_COLUMN_ADD  0x13            

/**
 * @brief Höchste Zeilenadresse des Displays.
 * @details Die Anzahl Zeilen auf dem Display entspricht MAX_ROW_ADD + 1
 */
#define MAX_ROW_ADD     0x03    

/**
 * @brief Startframe fürs Display -> Die nächsten Bytes sind Befehle.
 * @details R/W = 0 -> Write, DC = 0 Command
 */
#define COMMAND         0b11111000      

/**
 * @brief Startframe fürs Display -> Die nächsten Bytes sind Daten (ASCII-Zeichen).
 * @details R/W = 0 -> Write, DC = 1 Data
 */
#define DATA            0b11111010      

/**
 * @brief Zeichensatz A
 * @details Siehe Datenblatt des EA OLEDM204 für den genauen Zeichensatz.
 */
#define OLED_ROMA       0x00            

/**
 * @brief Zeichensatz B
 * @details Siehe Datenblatt des EA OLEDM204 für den genauen Zeichensatz.
 */
#define OLED_ROMB       0x04            

/**
 * @brief Zeichensatz C
 * @details Siehe Datenblatt des EA OLEDM204 für den genauen Zeichensatz.
 */
#define OLED_ROMC       0x08            /**< Zeichensatz C*/

/***Funktionsprototypen für statische Funktionen*******************************/

static void Send(uint8_t data);

/***Variablen******************************************************************/

static uint8_t addX;   /**< x-Adresse des Display Cursors (Spalten)*/
static uint8_t addY;   /**< y-Adresse des Display Cursors (Zeilen)*/

/***Funktionen*****************************************************************/

/**
 * @brief Initialisiert das EA OLEDM204
 * @details Bsp: \code OLED_Init(); \endcode
 */
void OLED_Init(void){
    OLED_RES_SetHigh();
    __delay_ms(1);      //Warten auf stabile Betriebsspannung
    OLED_CS_SetLow();
    SPI1_Exchange8bit(COMMAND);  //Befehl senden
    Send(0x3A);     //Function Set: N=1 DH=0 RE=1 IS=0
    Send(0x09);     //4-line mode
    Send(0x72);     //ROM Select (Zeichensatz wählen)

    SPI1_Exchange8bit(DATA);  //Send Data
    Send(OLED_ROMB);     //ROM B 

    SPI1_Exchange8bit(COMMAND);  //Send Command
    Send(0x38);     //Function Set: N=1 DH=0 RE=0 IS=0
    Send(0x01);     //clear Display
    Send(0x0C);     //Display on / Cursor off
    
    OLED_CS_SetHigh();
}

/**
 * @brief Schreibt ein Zeichen auf das Display.
 * @details Bsp: \code OLED_Putc('A'); \endcode
 * @param ch    Zeichen, das geschrieben werden soll.
 */
void OLED_Putc(char ch){
    static uint8_t arrowCnt = 0;
    /*Wenn der arrowCnt grösser 0 ist, wurde eine Pfeiltaste gedrückt. Dabei werden
     drei Zeichen gesendet. Das dritte Zeichen unterscheidet sich je nach Richtung.*/
    if(arrowCnt){
        if(++arrowCnt == 3){
            arrowCnt = 0;
            switch(ch){
                case 0x41:          //UP
                    if(addY>0)
                        addY--;
                    break;
                case 0x42:          //DOWN
                    if(addY<3)
                        addY++;
                    break;
                case 0x43:          //RIGHT
                    if(addX<0x13)
                        addX++;
                    break;
                case 0x44:          //LEFT
                    if(addX>0)
                        addX--;
                    break;
            }
            OLED_GotoXY(addX,addY);
        }
    }
    /*Wenn vorhin keine Pfeiltaste gesendet wurde.*/
    else{
        switch(ch){
            /*Wenn eine Pfeiltaste gedrückt wird, werden 3 Zeichen gesendet. Das 
             erste hat den Wert 0x1b. Das dritte Zeichen ist spezifisch je nach 
             Pfeilrichtung. Durch den counter wird gezählt, wann das dritte Zeichen
             eintrifft.*/
            case 0x1b:
                arrowCnt = 1;
                break;
            /*Bei Delete wird das aktuelle Zeichen gelöscht.*/
            case 0x7F:  //Delete
                OLED_CS_SetLow();
                SPI1_Exchange8bit(0b11111010);
                Send(' ');
                OLED_CS_SetHigh(); 
                OLED_GotoXY(addX,addY);
                break;
            /*Bei einem Backspace wird eins zurück gegangen, das Zeichen mit einem
              Leerzeichen überschrieben und der Cursor wieder zurück gestellt.*/
            case '\b': //Backspace
                if(--addX>MAX_COLUMN_ADD){
                    addX = MAX_COLUMN_ADD;
                    if(--addY>MAX_ROW_ADD){
                        addY = 0;
                        addX = 0;
                    }
                }
                OLED_GotoXY(addX,addY);
                OLED_CS_SetLow();
                SPI1_Exchange8bit(0b11111010);
                Send(' ');
                OLED_CS_SetHigh(); 
                OLED_GotoXY(addX,addY);
                break;
            /*Bei einem Line-Feed oder einem Carriage-Return, wird die Spaltenadresse
             * zurückgesetzt. Und die Zeile eins erhöht.*/
            case '\n':  //Line Feed
            case '\r':  //Carriage Return
                if(++addY>MAX_ROW_ADD)
                    addY = 0;
                addX = 0;
                OLED_GotoXY(addX,addY);
                break;
            /*Tabulator*/
            case '\t':
                addX = (addX/4+1)*4;
                if(addX>MAX_COLUMN_ADD){
                    addX = 0;
                    addY++;
                    if(addY>MAX_ROW_ADD)
                        addY=0;
                }
                OLED_GotoXY(addX,addY);
                break;
            /*Form feed*/
            case '\f':
                OLED_Clear();
                break;
            /*Ein normales Zeichen wird ans Display gesendet. Anschliessend wird
             die Adresse erhöht.*/
            default:
                OLED_CS_SetLow();
                SPI1_Exchange8bit(DATA);
                Send(ch);
                OLED_CS_SetHigh(); 
                addX++;
                if(addX>MAX_COLUMN_ADD){
                    addX = 0;
                    addY++;
                    if(addY>MAX_ROW_ADD)
                        addY=0;
                }
        }
    }
    
}

/**
 * @brief Verschiebt den Cursor des Displays an die angegebenen Koordinaten.
 * @details Bsp: \code OLED_GotoXY(0, 3); \endcode
 * @param x X-Position (Spalte)
 * @param y Y-Position (Zeile)
 */
void OLED_GotoXY(uint8_t x, uint8_t y){
    /*Wenn die Koordinaten innerhalb des Displays liegen wird die Adresse geändert.*/
    if((x<=MAX_COLUMN_ADD)&&(y<=MAX_ROW_ADD)){
        addX = x;
        addY = y;
        OLED_CS_SetLow();
        SPI1_Exchange8bit(COMMAND);  //Write command
        Send((addX+addY*0x20)|0x80);
        OLED_CS_SetHigh();
    }
}

/**
 * @brief Löscht das LCD und setzt den Cursor an die Ursprungsposition.
 * @details Bsp: \code OLED_Clear(); \endcode
 */
void OLED_Clear(void){
    OLED_CS_SetLow();
    SPI1_Exchange8bit(COMMAND);  //Befehl senden
    Send(0x01);         //löschen
    OLED_CS_SetHigh();
    addX = addY = 0;    //Adresse zurücksetzten
}

/**
 * @brief Wechselt den Zeichensatz des Displays.
 * @details Bsp: \code OLED_SelectROM(ROMB); \endcode
 * @param oledROM Welcher Zeichensatz angewählt werden soll. (ROMA, ROMB oder ROMC)
 */
void OLED_SelectROM(oled_rom_t oledROM){
    OLED_CS_SetLow();
    SPI1_Exchange8bit(COMMAND);  //Befehl senden
    Send(0x3A);     //Function Set: N=1 BE=0 RE=1 IS=0
    Send(0x72);     //Befehl um den Zeichensatz zu wechseln.

    SPI1_Exchange8bit(DATA);  //Daten senden
    Send(oledROM == ROMA ? OLED_ROMA : oledROM == ROMB ? OLED_ROMB : OLED_ROMC); //entsprechenden Zeichensatzu wählen
    SPI1_Exchange8bit(COMMAND);  //Befehl senden
    Send(0x38);     //Function Set: N=1 DH=0 RE=0 IS=0
    
    OLED_CS_SetHigh();
}

/**
 * @brief Schaltet den Cursor des Displays ein oder aus.
 * @param cursor Wenn true wird der Cursor eingeschalten, sonst ausgeschalten.
 */
void OLED_CursorOn(bool cursor){
    OLED_CS_SetLow();
    SPI1_Exchange8bit(COMMAND);  //Befehl senden
    Send(0x38);     //Function Set: N=1 DH=0 RE=0 IS=0
    Send(cursor ? 0x0D : 0x0C);     //Display einschalten und cursor ein/ausschalten (0x0C -> Cursor off / 0x0D -> Cursor on) 
    OLED_CS_SetHigh();
}

/**
 * @brief Array um alle Bits von einem Byte zu tauschen (MSB to LSB)
 */
static const uint8_t BitReverseTable256[] = 
{
  0x00, 0x80, 0x40, 0xC0, 0x20, 0xA0, 0x60, 0xE0, 0x10, 0x90, 0x50, 0xD0, 0x30, 0xB0, 0x70, 0xF0, 
  0x08, 0x88, 0x48, 0xC8, 0x28, 0xA8, 0x68, 0xE8, 0x18, 0x98, 0x58, 0xD8, 0x38, 0xB8, 0x78, 0xF8, 
  0x04, 0x84, 0x44, 0xC4, 0x24, 0xA4, 0x64, 0xE4, 0x14, 0x94, 0x54, 0xD4, 0x34, 0xB4, 0x74, 0xF4, 
  0x0C, 0x8C, 0x4C, 0xCC, 0x2C, 0xAC, 0x6C, 0xEC, 0x1C, 0x9C, 0x5C, 0xDC, 0x3C, 0xBC, 0x7C, 0xFC, 
  0x02, 0x82, 0x42, 0xC2, 0x22, 0xA2, 0x62, 0xE2, 0x12, 0x92, 0x52, 0xD2, 0x32, 0xB2, 0x72, 0xF2, 
  0x0A, 0x8A, 0x4A, 0xCA, 0x2A, 0xAA, 0x6A, 0xEA, 0x1A, 0x9A, 0x5A, 0xDA, 0x3A, 0xBA, 0x7A, 0xFA,
  0x06, 0x86, 0x46, 0xC6, 0x26, 0xA6, 0x66, 0xE6, 0x16, 0x96, 0x56, 0xD6, 0x36, 0xB6, 0x76, 0xF6, 
  0x0E, 0x8E, 0x4E, 0xCE, 0x2E, 0xAE, 0x6E, 0xEE, 0x1E, 0x9E, 0x5E, 0xDE, 0x3E, 0xBE, 0x7E, 0xFE,
  0x01, 0x81, 0x41, 0xC1, 0x21, 0xA1, 0x61, 0xE1, 0x11, 0x91, 0x51, 0xD1, 0x31, 0xB1, 0x71, 0xF1,
  0x09, 0x89, 0x49, 0xC9, 0x29, 0xA9, 0x69, 0xE9, 0x19, 0x99, 0x59, 0xD9, 0x39, 0xB9, 0x79, 0xF9, 
  0x05, 0x85, 0x45, 0xC5, 0x25, 0xA5, 0x65, 0xE5, 0x15, 0x95, 0x55, 0xD5, 0x35, 0xB5, 0x75, 0xF5,
  0x0D, 0x8D, 0x4D, 0xCD, 0x2D, 0xAD, 0x6D, 0xED, 0x1D, 0x9D, 0x5D, 0xDD, 0x3D, 0xBD, 0x7D, 0xFD,
  0x03, 0x83, 0x43, 0xC3, 0x23, 0xA3, 0x63, 0xE3, 0x13, 0x93, 0x53, 0xD3, 0x33, 0xB3, 0x73, 0xF3, 
  0x0B, 0x8B, 0x4B, 0xCB, 0x2B, 0xAB, 0x6B, 0xEB, 0x1B, 0x9B, 0x5B, 0xDB, 0x3B, 0xBB, 0x7B, 0xFB,
  0x07, 0x87, 0x47, 0xC7, 0x27, 0xA7, 0x67, 0xE7, 0x17, 0x97, 0x57, 0xD7, 0x37, 0xB7, 0x77, 0xF7, 
  0x0F, 0x8F, 0x4F, 0xCF, 0x2F, 0xAF, 0x6F, 0xEF, 0x1F, 0x9F, 0x5F, 0xDF, 0x3F, 0xBF, 0x7F, 0xFF
};

/**
 * @brief Sendet Daten oder ein Befehl ans Display.
 * @details Bsp: \code Send(0x01); \endcode
 * @param data
 */
static void Send(uint8_t data){
    data = BitReverseTable256[data];    //LSB to MSB
    SPI1_Exchange8bit(data&0xF0);       //Oberes Nibble senden
    SPI1_Exchange8bit((data<<4)&0xF0);  //unteres Nibble senden
}



