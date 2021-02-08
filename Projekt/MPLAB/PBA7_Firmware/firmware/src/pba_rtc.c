/**
 * @defgroup RTC
 * @{
 *******************************************************************************
 * @file            pba_rtc.c
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

/***Includes*******************************************************************/

#include "../inc/pba_rtc.h"

/***Defines********************************************************************/

/**
 * @brief I2C Adresse des DS3231.
 */
#define RTC_ADDRESS     0b01101000      //< I2C Adresse des RTC

/***Prototypen statischer Funktionen*******************************************/

static inline uint8_t BcdToBinary(uint8_t numberBCD);
static inline uint8_t BinaryToBcd(uint8_t binaryValue);

/***Funktionen*****************************************************************/

/**
 * @brief Initialisiert den RTC DS3231.
 * @details Bsp: \code RTC_Init(); \endcode
 */
void RTC_Init(void){
    I2C2_MESSAGE_STATUS i2cWflag = I2C2_MESSAGE_PENDING;
    
    uint8_t data[2] = {0x0E,0x00};
    I2C2_MasterWrite(data,2,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
}

/**
 * @brief Liest die Sekunden vom RTC aus.
 * @details Bsp: \code uint8_t sec = RTC_GetSeconds(); \endcode
 * @return Sekunden als Binärwert.
 */
uint8_t RTC_GetSeconds(void){
    I2C2_MESSAGE_STATUS i2cWflag = I2C2_MESSAGE_PENDING;
    
    uint8_t data = 0x00;
    I2C2_MasterWrite(&data,1,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
    I2C2_MasterRead(&data,1,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
    return BcdToBinary(data);
}

/**
 * @brief Setzt die Sekunden vom RTC
 * @details Bsp: \code RTC_SetSeconds(0); \endcode
 * @param seconds Sekunden als Binärwert.
 */
void RTC_SetSeconds(uint8_t seconds){
    I2C2_MESSAGE_STATUS i2cWflag = I2C2_MESSAGE_PENDING;
    
    uint8_t data[2] = {0x00,BinaryToBcd(seconds)};
    I2C2_MasterWrite(data,2,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
}

/**
 * @brief Liest die Minuten vom RTC aus.
 * @details Bsp: \code uint8_t sec = RTC_GetMinutes(); \endcode
 * @return Minuten als Binärwert.
 */
uint8_t RTC_GetMinutes(void){
    I2C2_MESSAGE_STATUS i2cWflag = I2C2_MESSAGE_PENDING;
    
	uint8_t data = 0x01;
    I2C2_MasterWrite(&data,1,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
    I2C2_MasterRead(&data,1,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
    return BcdToBinary(data);
}

/**
 * @brief Setzt die Minuten vom RTC
 * @details Bsp: \code RTC_SetMinutes(0); \endcode
 * @param minutes Minuten als Binärwert.
 */
void RTC_SetMinutes(uint8_t minutes){
    I2C2_MESSAGE_STATUS i2cWflag = I2C2_MESSAGE_PENDING;
    
    uint8_t data[2] = {0x01,BinaryToBcd(minutes)};
    I2C2_MasterWrite(data,2,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
}

/**
 * @brief Liest die Stunden vom RTC aus.
 * @details Bsp: \code uint8_t sec = RTC_GetHours(); \endcode
 * @return Stunden als Binärwert.
 */
uint8_t RTC_GetHours(void){
    I2C2_MESSAGE_STATUS i2cWflag = I2C2_MESSAGE_PENDING;
    
	uint8_t data = 0x02;
    I2C2_MasterWrite(&data,1,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
    I2C2_MasterRead(&data,1,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
    return BcdToBinary(data&0b00111111);
}

/**
 * @brief Setzt die Stunden vom RTC
 * @details Bsp: \code RTC_SetHours(0); \endcode
 * @param houres Stunden als Binärwert.
 */
void RTC_SetHours(uint8_t houres){
    I2C2_MESSAGE_STATUS i2cWflag = I2C2_MESSAGE_PENDING;
    
    uint8_t data[2] = {0x02,BinaryToBcd(houres)&0b00111111};
    I2C2_MasterWrite(data,2,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
}

/**
 * @brief Startet die Temperaturwandlung im RTC
 * @details Bsp: \code RTC_ConvertTemp(); \endcode
 */
void RTC_ConvertTemp(void){
    I2C2_MESSAGE_STATUS i2cWflag = I2C2_MESSAGE_PENDING;
    uint8_t data[2] = {0x0E,0x20};
    I2C2_MasterWrite(data,2,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
}

/**
 * @brief Überprüft ob die Temperaturwandlung beendet wurde.
 * @return Gibt eine 1 zurück, wenn die Wanlung abgeschlossen ist.
 */
uint8_t RTC_IsTempConvDone(void){
    I2C2_MESSAGE_STATUS i2cWflag = I2C2_MESSAGE_PENDING;
    uint8_t data[2] = {0x0E,0x00};
    I2C2_MasterWrite(&data[0],1,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
    I2C2_MasterRead(&data[1],1,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
    if((data[1]&0x20)==0)
        return 1;
    else
        return 0;
}

/**
 * @brief Liest die Temperatur ohne Nachkommastellen aus dem RTC aus.
 * @details Bsp: \code int8_t temp = RTC_GetTemp(); \endcode
 * @return Temperatur als signed 8 Bit Zahl.
 */
int8_t RTC_GetTemp(void){
    I2C2_MESSAGE_STATUS i2cWflag = I2C2_MESSAGE_PENDING;
    uint8_t data = 0x11;
    I2C2_MasterWrite(&data,1,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
    I2C2_MasterRead(&data,1,RTC_ADDRESS,&i2cWflag);
    while(i2cWflag!=I2C2_MESSAGE_COMPLETE);
    return data;
}

/**
 * @brief Wandelt eine BCD Zahl in eine Binärzahl.
 * @details Bsp: \code uint8_t binary = BcdToBinary(bcd); \endcode
 * @param numberBCD BCD Zahl als 8Bit unsigned.
 * @return Binärzahl als 8Bit unsigned.
 */
static inline uint8_t BcdToBinary(uint8_t numberBCD){
    uint8_t zehner = (numberBCD >> 4) & 0b00001111;
    uint8_t einer = numberBCD & 0b00001111;
    return (einer + (zehner*10));
}

/**
 * @brief Wandelt eine Binärzahl in eine BCD Zahl.
 * @details Bsp: \code uint8_t bcd = BinaryToBcd(binary); \endcode
 * @param binaryValue Binärzahl als 8Bit unsigned
 * @return BCD Zahl als 8Bit unsiged.
 */
static inline uint8_t BinaryToBcd(uint8_t binaryValue){
    uint8_t einer = binaryValue%10;
    uint8_t zehner = binaryValue/10;
    return (einer+(zehner<<4));
}