/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F15385
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set POT0 aliases
#define POT0_TRIS                 TRISAbits.TRISA0
#define POT0_LAT                  LATAbits.LATA0
#define POT0_PORT                 PORTAbits.RA0
#define POT0_WPU                  WPUAbits.WPUA0
#define POT0_OD                   ODCONAbits.ODCA0
#define POT0_ANS                  ANSELAbits.ANSA0
#define POT0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define POT0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define POT0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define POT0_GetValue()           PORTAbits.RA0
#define POT0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define POT0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define POT0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define POT0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define POT0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define POT0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define POT0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define POT0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set POT1 aliases
#define POT1_TRIS                 TRISAbits.TRISA1
#define POT1_LAT                  LATAbits.LATA1
#define POT1_PORT                 PORTAbits.RA1
#define POT1_WPU                  WPUAbits.WPUA1
#define POT1_OD                   ODCONAbits.ODCA1
#define POT1_ANS                  ANSELAbits.ANSA1
#define POT1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define POT1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define POT1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define POT1_GetValue()           PORTAbits.RA1
#define POT1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define POT1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define POT1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define POT1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define POT1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define POT1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define POT1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define POT1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set FPGA_CS aliases
#define FPGA_CS_TRIS                 TRISAbits.TRISA2
#define FPGA_CS_LAT                  LATAbits.LATA2
#define FPGA_CS_PORT                 PORTAbits.RA2
#define FPGA_CS_WPU                  WPUAbits.WPUA2
#define FPGA_CS_OD                   ODCONAbits.ODCA2
#define FPGA_CS_ANS                  ANSELAbits.ANSA2
#define FPGA_CS_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define FPGA_CS_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define FPGA_CS_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define FPGA_CS_GetValue()           PORTAbits.RA2
#define FPGA_CS_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define FPGA_CS_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define FPGA_CS_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define FPGA_CS_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define FPGA_CS_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define FPGA_CS_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define FPGA_CS_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define FPGA_CS_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set ARD_CS aliases
#define ARD_CS_TRIS                 TRISAbits.TRISA4
#define ARD_CS_LAT                  LATAbits.LATA4
#define ARD_CS_PORT                 PORTAbits.RA4
#define ARD_CS_WPU                  WPUAbits.WPUA4
#define ARD_CS_OD                   ODCONAbits.ODCA4
#define ARD_CS_ANS                  ANSELAbits.ANSA4
#define ARD_CS_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define ARD_CS_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define ARD_CS_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define ARD_CS_GetValue()           PORTAbits.RA4
#define ARD_CS_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define ARD_CS_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define ARD_CS_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define ARD_CS_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define ARD_CS_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define ARD_CS_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define ARD_CS_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define ARD_CS_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set OLED_CS aliases
#define OLED_CS_TRIS                 TRISAbits.TRISA5
#define OLED_CS_LAT                  LATAbits.LATA5
#define OLED_CS_PORT                 PORTAbits.RA5
#define OLED_CS_WPU                  WPUAbits.WPUA5
#define OLED_CS_OD                   ODCONAbits.ODCA5
#define OLED_CS_ANS                  ANSELAbits.ANSA5
#define OLED_CS_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define OLED_CS_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define OLED_CS_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define OLED_CS_GetValue()           PORTAbits.RA5
#define OLED_CS_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define OLED_CS_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define OLED_CS_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define OLED_CS_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define OLED_CS_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define OLED_CS_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define OLED_CS_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define OLED_CS_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set ARD_IO8 aliases
#define ARD_IO8_TRIS                 TRISAbits.TRISA6
#define ARD_IO8_LAT                  LATAbits.LATA6
#define ARD_IO8_PORT                 PORTAbits.RA6
#define ARD_IO8_WPU                  WPUAbits.WPUA6
#define ARD_IO8_OD                   ODCONAbits.ODCA6
#define ARD_IO8_ANS                  ANSELAbits.ANSA6
#define ARD_IO8_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define ARD_IO8_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define ARD_IO8_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define ARD_IO8_GetValue()           PORTAbits.RA6
#define ARD_IO8_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define ARD_IO8_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define ARD_IO8_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define ARD_IO8_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define ARD_IO8_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define ARD_IO8_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define ARD_IO8_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define ARD_IO8_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set ARD_IO9 aliases
#define ARD_IO9_TRIS                 TRISAbits.TRISA7
#define ARD_IO9_LAT                  LATAbits.LATA7
#define ARD_IO9_PORT                 PORTAbits.RA7
#define ARD_IO9_WPU                  WPUAbits.WPUA7
#define ARD_IO9_OD                   ODCONAbits.ODCA7
#define ARD_IO9_ANS                  ANSELAbits.ANSA7
#define ARD_IO9_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define ARD_IO9_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define ARD_IO9_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define ARD_IO9_GetValue()           PORTAbits.RA7
#define ARD_IO9_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define ARD_IO9_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define ARD_IO9_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define ARD_IO9_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define ARD_IO9_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define ARD_IO9_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define ARD_IO9_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define ARD_IO9_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set SDO1 aliases
#define SDO1_TRIS                 TRISBbits.TRISB0
#define SDO1_LAT                  LATBbits.LATB0
#define SDO1_PORT                 PORTBbits.RB0
#define SDO1_WPU                  WPUBbits.WPUB0
#define SDO1_OD                   ODCONBbits.ODCB0
#define SDO1_ANS                  ANSELBbits.ANSB0
#define SDO1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define SDO1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define SDO1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define SDO1_GetValue()           PORTBbits.RB0
#define SDO1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define SDO1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define SDO1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define SDO1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define SDO1_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define SDO1_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define SDO1_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define SDO1_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set MISO aliases
#define MISO_TRIS                 TRISBbits.TRISB1
#define MISO_LAT                  LATBbits.LATB1
#define MISO_PORT                 PORTBbits.RB1
#define MISO_WPU                  WPUBbits.WPUB1
#define MISO_OD                   ODCONBbits.ODCB1
#define MISO_ANS                  ANSELBbits.ANSB1
#define MISO_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define MISO_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define MISO_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define MISO_GetValue()           PORTBbits.RB1
#define MISO_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define MISO_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define MISO_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define MISO_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define MISO_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define MISO_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define MISO_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define MISO_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set SCK aliases
#define SCK_TRIS                 TRISBbits.TRISB2
#define SCK_LAT                  LATBbits.LATB2
#define SCK_PORT                 PORTBbits.RB2
#define SCK_WPU                  WPUBbits.WPUB2
#define SCK_OD                   ODCONBbits.ODCB2
#define SCK_ANS                  ANSELBbits.ANSB2
#define SCK_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define SCK_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define SCK_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define SCK_GetValue()           PORTBbits.RB2
#define SCK_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define SCK_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define SCK_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define SCK_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define SCK_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define SCK_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define SCK_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set SDA2 aliases
#define SDA2_TRIS                 TRISBbits.TRISB3
#define SDA2_LAT                  LATBbits.LATB3
#define SDA2_PORT                 PORTBbits.RB3
#define SDA2_WPU                  WPUBbits.WPUB3
#define SDA2_OD                   ODCONBbits.ODCB3
#define SDA2_ANS                  ANSELBbits.ANSB3
#define SDA2_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SDA2_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SDA2_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SDA2_GetValue()           PORTBbits.RB3
#define SDA2_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SDA2_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SDA2_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SDA2_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SDA2_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define SDA2_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define SDA2_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define SDA2_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set SCL2 aliases
#define SCL2_TRIS                 TRISBbits.TRISB4
#define SCL2_LAT                  LATBbits.LATB4
#define SCL2_PORT                 PORTBbits.RB4
#define SCL2_WPU                  WPUBbits.WPUB4
#define SCL2_OD                   ODCONBbits.ODCB4
#define SCL2_ANS                  ANSELBbits.ANSB4
#define SCL2_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SCL2_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SCL2_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SCL2_GetValue()           PORTBbits.RB4
#define SCL2_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SCL2_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SCL2_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SCL2_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SCL2_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SCL2_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SCL2_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SCL2_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set OLED_RES aliases
#define OLED_RES_TRIS                 TRISBbits.TRISB5
#define OLED_RES_LAT                  LATBbits.LATB5
#define OLED_RES_PORT                 PORTBbits.RB5
#define OLED_RES_WPU                  WPUBbits.WPUB5
#define OLED_RES_OD                   ODCONBbits.ODCB5
#define OLED_RES_ANS                  ANSELBbits.ANSB5
#define OLED_RES_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define OLED_RES_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define OLED_RES_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define OLED_RES_GetValue()           PORTBbits.RB5
#define OLED_RES_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define OLED_RES_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define OLED_RES_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define OLED_RES_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define OLED_RES_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define OLED_RES_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define OLED_RES_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define OLED_RES_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_RB6 aliases
#define IO_RB6_TRIS                 TRISBbits.TRISB6
#define IO_RB6_LAT                  LATBbits.LATB6
#define IO_RB6_PORT                 PORTBbits.RB6
#define IO_RB6_WPU                  WPUBbits.WPUB6
#define IO_RB6_OD                   ODCONBbits.ODCB6
#define IO_RB6_ANS                  ANSELBbits.ANSB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RB6_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define IO_RB6_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define IO_RB6_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define IO_RB6_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_OD                   ODCONBbits.ODCB7
#define IO_RB7_ANS                  ANSELBbits.ANSB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define IO_RB7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define IO_RB7_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set IO_RC0 aliases
#define IO_RC0_TRIS                 TRISCbits.TRISC0
#define IO_RC0_LAT                  LATCbits.LATC0
#define IO_RC0_PORT                 PORTCbits.RC0
#define IO_RC0_WPU                  WPUCbits.WPUC0
#define IO_RC0_OD                   ODCONCbits.ODCC0
#define IO_RC0_ANS                  ANSELCbits.ANSC0
#define IO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_GetValue()           PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_RC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_RC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define IO_RC0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define IO_RC0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set IO_RC1 aliases
#define IO_RC1_TRIS                 TRISCbits.TRISC1
#define IO_RC1_LAT                  LATCbits.LATC1
#define IO_RC1_PORT                 PORTCbits.RC1
#define IO_RC1_WPU                  WPUCbits.WPUC1
#define IO_RC1_OD                   ODCONCbits.ODCC1
#define IO_RC1_ANS                  ANSELCbits.ANSC1
#define IO_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_RC1_GetValue()           PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IO_RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define IO_RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define IO_RC1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define IO_RC1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define IO_RC1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define IO_RC1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set IO_RC2 aliases
#define IO_RC2_TRIS                 TRISCbits.TRISC2
#define IO_RC2_LAT                  LATCbits.LATC2
#define IO_RC2_PORT                 PORTCbits.RC2
#define IO_RC2_WPU                  WPUCbits.WPUC2
#define IO_RC2_OD                   ODCONCbits.ODCC2
#define IO_RC2_ANS                  ANSELCbits.ANSC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_RC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define IO_RC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define IO_RC2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define IO_RC2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set IO_RC3 aliases
#define IO_RC3_TRIS                 TRISCbits.TRISC3
#define IO_RC3_LAT                  LATCbits.LATC3
#define IO_RC3_PORT                 PORTCbits.RC3
#define IO_RC3_WPU                  WPUCbits.WPUC3
#define IO_RC3_OD                   ODCONCbits.ODCC3
#define IO_RC3_ANS                  ANSELCbits.ANSC3
#define IO_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_RC3_GetValue()           PORTCbits.RC3
#define IO_RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define IO_RC3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define IO_RC3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define IO_RC3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define IO_RC3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define IO_RC3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define IO_RC3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set IO_RC4 aliases
#define IO_RC4_TRIS                 TRISCbits.TRISC4
#define IO_RC4_LAT                  LATCbits.LATC4
#define IO_RC4_PORT                 PORTCbits.RC4
#define IO_RC4_WPU                  WPUCbits.WPUC4
#define IO_RC4_OD                   ODCONCbits.ODCC4
#define IO_RC4_ANS                  ANSELCbits.ANSC4
#define IO_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_RC4_GetValue()           PORTCbits.RC4
#define IO_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_RC4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_RC4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_RC4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define IO_RC4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define IO_RC4_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define IO_RC4_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set IO_RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.WPUC5
#define IO_RC5_OD                   ODCONCbits.ODCC5
#define IO_RC5_ANS                  ANSELCbits.ANSC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_RC5_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set IO_RC6 aliases
#define IO_RC6_TRIS                 TRISCbits.TRISC6
#define IO_RC6_LAT                  LATCbits.LATC6
#define IO_RC6_PORT                 PORTCbits.RC6
#define IO_RC6_WPU                  WPUCbits.WPUC6
#define IO_RC6_OD                   ODCONCbits.ODCC6
#define IO_RC6_ANS                  ANSELCbits.ANSC6
#define IO_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_RC6_GetValue()           PORTCbits.RC6
#define IO_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO_RC6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define IO_RC6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define IO_RC6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define IO_RC6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define IO_RC6_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define IO_RC6_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set IO_RC7 aliases
#define IO_RC7_TRIS                 TRISCbits.TRISC7
#define IO_RC7_LAT                  LATCbits.LATC7
#define IO_RC7_PORT                 PORTCbits.RC7
#define IO_RC7_WPU                  WPUCbits.WPUC7
#define IO_RC7_OD                   ODCONCbits.ODCC7
#define IO_RC7_ANS                  ANSELCbits.ANSC7
#define IO_RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define IO_RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define IO_RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define IO_RC7_GetValue()           PORTCbits.RC7
#define IO_RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define IO_RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define IO_RC7_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define IO_RC7_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define IO_RC7_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define IO_RC7_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define IO_RC7_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define IO_RC7_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set IO_RD0 aliases
#define IO_RD0_TRIS                 TRISDbits.TRISD0
#define IO_RD0_LAT                  LATDbits.LATD0
#define IO_RD0_PORT                 PORTDbits.RD0
#define IO_RD0_WPU                  WPUDbits.WPUD0
#define IO_RD0_OD                   ODCONDbits.ODCD0
#define IO_RD0_ANS                  ANSELDbits.ANSD0
#define IO_RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IO_RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IO_RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IO_RD0_GetValue()           PORTDbits.RD0
#define IO_RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define IO_RD0_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define IO_RD0_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define IO_RD0_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define IO_RD0_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define IO_RD0_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define IO_RD0_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set IO_RD1 aliases
#define IO_RD1_TRIS                 TRISDbits.TRISD1
#define IO_RD1_LAT                  LATDbits.LATD1
#define IO_RD1_PORT                 PORTDbits.RD1
#define IO_RD1_WPU                  WPUDbits.WPUD1
#define IO_RD1_OD                   ODCONDbits.ODCD1
#define IO_RD1_ANS                  ANSELDbits.ANSD1
#define IO_RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IO_RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IO_RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IO_RD1_GetValue()           PORTDbits.RD1
#define IO_RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define IO_RD1_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define IO_RD1_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define IO_RD1_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define IO_RD1_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define IO_RD1_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define IO_RD1_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set IO_RD2 aliases
#define IO_RD2_TRIS                 TRISDbits.TRISD2
#define IO_RD2_LAT                  LATDbits.LATD2
#define IO_RD2_PORT                 PORTDbits.RD2
#define IO_RD2_WPU                  WPUDbits.WPUD2
#define IO_RD2_OD                   ODCONDbits.ODCD2
#define IO_RD2_ANS                  ANSELDbits.ANSD2
#define IO_RD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define IO_RD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define IO_RD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define IO_RD2_GetValue()           PORTDbits.RD2
#define IO_RD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define IO_RD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define IO_RD2_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define IO_RD2_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define IO_RD2_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define IO_RD2_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define IO_RD2_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define IO_RD2_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set IO_RD3 aliases
#define IO_RD3_TRIS                 TRISDbits.TRISD3
#define IO_RD3_LAT                  LATDbits.LATD3
#define IO_RD3_PORT                 PORTDbits.RD3
#define IO_RD3_WPU                  WPUDbits.WPUD3
#define IO_RD3_OD                   ODCONDbits.ODCD3
#define IO_RD3_ANS                  ANSELDbits.ANSD3
#define IO_RD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define IO_RD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define IO_RD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define IO_RD3_GetValue()           PORTDbits.RD3
#define IO_RD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define IO_RD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define IO_RD3_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define IO_RD3_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define IO_RD3_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define IO_RD3_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define IO_RD3_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define IO_RD3_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set IO_RD4 aliases
#define IO_RD4_TRIS                 TRISDbits.TRISD4
#define IO_RD4_LAT                  LATDbits.LATD4
#define IO_RD4_PORT                 PORTDbits.RD4
#define IO_RD4_WPU                  WPUDbits.WPUD4
#define IO_RD4_OD                   ODCONDbits.ODCD4
#define IO_RD4_ANS                  ANSELDbits.ANSD4
#define IO_RD4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define IO_RD4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define IO_RD4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define IO_RD4_GetValue()           PORTDbits.RD4
#define IO_RD4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define IO_RD4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define IO_RD4_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define IO_RD4_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define IO_RD4_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define IO_RD4_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define IO_RD4_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define IO_RD4_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set IO_RD5 aliases
#define IO_RD5_TRIS                 TRISDbits.TRISD5
#define IO_RD5_LAT                  LATDbits.LATD5
#define IO_RD5_PORT                 PORTDbits.RD5
#define IO_RD5_WPU                  WPUDbits.WPUD5
#define IO_RD5_OD                   ODCONDbits.ODCD5
#define IO_RD5_ANS                  ANSELDbits.ANSD5
#define IO_RD5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define IO_RD5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define IO_RD5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define IO_RD5_GetValue()           PORTDbits.RD5
#define IO_RD5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define IO_RD5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define IO_RD5_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define IO_RD5_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define IO_RD5_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define IO_RD5_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define IO_RD5_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define IO_RD5_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set IO_RD6 aliases
#define IO_RD6_TRIS                 TRISDbits.TRISD6
#define IO_RD6_LAT                  LATDbits.LATD6
#define IO_RD6_PORT                 PORTDbits.RD6
#define IO_RD6_WPU                  WPUDbits.WPUD6
#define IO_RD6_OD                   ODCONDbits.ODCD6
#define IO_RD6_ANS                  ANSELDbits.ANSD6
#define IO_RD6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define IO_RD6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define IO_RD6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define IO_RD6_GetValue()           PORTDbits.RD6
#define IO_RD6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define IO_RD6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define IO_RD6_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define IO_RD6_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define IO_RD6_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define IO_RD6_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define IO_RD6_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define IO_RD6_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set IO_RD7 aliases
#define IO_RD7_TRIS                 TRISDbits.TRISD7
#define IO_RD7_LAT                  LATDbits.LATD7
#define IO_RD7_PORT                 PORTDbits.RD7
#define IO_RD7_WPU                  WPUDbits.WPUD7
#define IO_RD7_OD                   ODCONDbits.ODCD7
#define IO_RD7_ANS                  ANSELDbits.ANSD7
#define IO_RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define IO_RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define IO_RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define IO_RD7_GetValue()           PORTDbits.RD7
#define IO_RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define IO_RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define IO_RD7_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define IO_RD7_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define IO_RD7_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define IO_RD7_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define IO_RD7_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define IO_RD7_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

// get/set IO_RE0 aliases
#define IO_RE0_TRIS                 TRISEbits.TRISE0
#define IO_RE0_LAT                  LATEbits.LATE0
#define IO_RE0_PORT                 PORTEbits.RE0
#define IO_RE0_WPU                  WPUEbits.WPUE0
#define IO_RE0_OD                   ODCONEbits.ODCE0
#define IO_RE0_ANS                  ANSELEbits.ANSE0
#define IO_RE0_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define IO_RE0_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define IO_RE0_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define IO_RE0_GetValue()           PORTEbits.RE0
#define IO_RE0_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define IO_RE0_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define IO_RE0_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define IO_RE0_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define IO_RE0_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define IO_RE0_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define IO_RE0_SetAnalogMode()      do { ANSELEbits.ANSE0 = 1; } while(0)
#define IO_RE0_SetDigitalMode()     do { ANSELEbits.ANSE0 = 0; } while(0)

// get/set IO_RE1 aliases
#define IO_RE1_TRIS                 TRISEbits.TRISE1
#define IO_RE1_LAT                  LATEbits.LATE1
#define IO_RE1_PORT                 PORTEbits.RE1
#define IO_RE1_WPU                  WPUEbits.WPUE1
#define IO_RE1_OD                   ODCONEbits.ODCE1
#define IO_RE1_ANS                  ANSELEbits.ANSE1
#define IO_RE1_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define IO_RE1_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define IO_RE1_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define IO_RE1_GetValue()           PORTEbits.RE1
#define IO_RE1_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define IO_RE1_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define IO_RE1_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define IO_RE1_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define IO_RE1_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define IO_RE1_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define IO_RE1_SetAnalogMode()      do { ANSELEbits.ANSE1 = 1; } while(0)
#define IO_RE1_SetDigitalMode()     do { ANSELEbits.ANSE1 = 0; } while(0)

// get/set SUMMER aliases
#define SUMMER_TRIS                 TRISEbits.TRISE2
#define SUMMER_LAT                  LATEbits.LATE2
#define SUMMER_PORT                 PORTEbits.RE2
#define SUMMER_WPU                  WPUEbits.WPUE2
#define SUMMER_OD                   ODCONEbits.ODCE2
#define SUMMER_ANS                  ANSELEbits.ANSE2
#define SUMMER_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define SUMMER_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define SUMMER_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define SUMMER_GetValue()           PORTEbits.RE2
#define SUMMER_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define SUMMER_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define SUMMER_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define SUMMER_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define SUMMER_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define SUMMER_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define SUMMER_SetAnalogMode()      do { ANSELEbits.ANSE2 = 1; } while(0)
#define SUMMER_SetDigitalMode()     do { ANSELEbits.ANSE2 = 0; } while(0)

// get/set ARD_AD0 aliases
#define ARD_AD0_TRIS                 TRISFbits.TRISF0
#define ARD_AD0_LAT                  LATFbits.LATF0
#define ARD_AD0_PORT                 PORTFbits.RF0
#define ARD_AD0_WPU                  WPUFbits.WPUF0
#define ARD_AD0_OD                   ODCONFbits.ODCF0
#define ARD_AD0_ANS                  ANSELFbits.ANSF0
#define ARD_AD0_SetHigh()            do { LATFbits.LATF0 = 1; } while(0)
#define ARD_AD0_SetLow()             do { LATFbits.LATF0 = 0; } while(0)
#define ARD_AD0_Toggle()             do { LATFbits.LATF0 = ~LATFbits.LATF0; } while(0)
#define ARD_AD0_GetValue()           PORTFbits.RF0
#define ARD_AD0_SetDigitalInput()    do { TRISFbits.TRISF0 = 1; } while(0)
#define ARD_AD0_SetDigitalOutput()   do { TRISFbits.TRISF0 = 0; } while(0)
#define ARD_AD0_SetPullup()          do { WPUFbits.WPUF0 = 1; } while(0)
#define ARD_AD0_ResetPullup()        do { WPUFbits.WPUF0 = 0; } while(0)
#define ARD_AD0_SetPushPull()        do { ODCONFbits.ODCF0 = 0; } while(0)
#define ARD_AD0_SetOpenDrain()       do { ODCONFbits.ODCF0 = 1; } while(0)
#define ARD_AD0_SetAnalogMode()      do { ANSELFbits.ANSF0 = 1; } while(0)
#define ARD_AD0_SetDigitalMode()     do { ANSELFbits.ANSF0 = 0; } while(0)

// get/set ARD_AD1 aliases
#define ARD_AD1_TRIS                 TRISFbits.TRISF1
#define ARD_AD1_LAT                  LATFbits.LATF1
#define ARD_AD1_PORT                 PORTFbits.RF1
#define ARD_AD1_WPU                  WPUFbits.WPUF1
#define ARD_AD1_OD                   ODCONFbits.ODCF1
#define ARD_AD1_ANS                  ANSELFbits.ANSF1
#define ARD_AD1_SetHigh()            do { LATFbits.LATF1 = 1; } while(0)
#define ARD_AD1_SetLow()             do { LATFbits.LATF1 = 0; } while(0)
#define ARD_AD1_Toggle()             do { LATFbits.LATF1 = ~LATFbits.LATF1; } while(0)
#define ARD_AD1_GetValue()           PORTFbits.RF1
#define ARD_AD1_SetDigitalInput()    do { TRISFbits.TRISF1 = 1; } while(0)
#define ARD_AD1_SetDigitalOutput()   do { TRISFbits.TRISF1 = 0; } while(0)
#define ARD_AD1_SetPullup()          do { WPUFbits.WPUF1 = 1; } while(0)
#define ARD_AD1_ResetPullup()        do { WPUFbits.WPUF1 = 0; } while(0)
#define ARD_AD1_SetPushPull()        do { ODCONFbits.ODCF1 = 0; } while(0)
#define ARD_AD1_SetOpenDrain()       do { ODCONFbits.ODCF1 = 1; } while(0)
#define ARD_AD1_SetAnalogMode()      do { ANSELFbits.ANSF1 = 1; } while(0)
#define ARD_AD1_SetDigitalMode()     do { ANSELFbits.ANSF1 = 0; } while(0)

// get/set ARD_AD2 aliases
#define ARD_AD2_TRIS                 TRISFbits.TRISF2
#define ARD_AD2_LAT                  LATFbits.LATF2
#define ARD_AD2_PORT                 PORTFbits.RF2
#define ARD_AD2_WPU                  WPUFbits.WPUF2
#define ARD_AD2_OD                   ODCONFbits.ODCF2
#define ARD_AD2_ANS                  ANSELFbits.ANSF2
#define ARD_AD2_SetHigh()            do { LATFbits.LATF2 = 1; } while(0)
#define ARD_AD2_SetLow()             do { LATFbits.LATF2 = 0; } while(0)
#define ARD_AD2_Toggle()             do { LATFbits.LATF2 = ~LATFbits.LATF2; } while(0)
#define ARD_AD2_GetValue()           PORTFbits.RF2
#define ARD_AD2_SetDigitalInput()    do { TRISFbits.TRISF2 = 1; } while(0)
#define ARD_AD2_SetDigitalOutput()   do { TRISFbits.TRISF2 = 0; } while(0)
#define ARD_AD2_SetPullup()          do { WPUFbits.WPUF2 = 1; } while(0)
#define ARD_AD2_ResetPullup()        do { WPUFbits.WPUF2 = 0; } while(0)
#define ARD_AD2_SetPushPull()        do { ODCONFbits.ODCF2 = 0; } while(0)
#define ARD_AD2_SetOpenDrain()       do { ODCONFbits.ODCF2 = 1; } while(0)
#define ARD_AD2_SetAnalogMode()      do { ANSELFbits.ANSF2 = 1; } while(0)
#define ARD_AD2_SetDigitalMode()     do { ANSELFbits.ANSF2 = 0; } while(0)

// get/set ARD_AD3 aliases
#define ARD_AD3_TRIS                 TRISFbits.TRISF3
#define ARD_AD3_LAT                  LATFbits.LATF3
#define ARD_AD3_PORT                 PORTFbits.RF3
#define ARD_AD3_WPU                  WPUFbits.WPUF3
#define ARD_AD3_OD                   ODCONFbits.ODCF3
#define ARD_AD3_ANS                  ANSELFbits.ANSF3
#define ARD_AD3_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define ARD_AD3_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define ARD_AD3_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define ARD_AD3_GetValue()           PORTFbits.RF3
#define ARD_AD3_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define ARD_AD3_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define ARD_AD3_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define ARD_AD3_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define ARD_AD3_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define ARD_AD3_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define ARD_AD3_SetAnalogMode()      do { ANSELFbits.ANSF3 = 1; } while(0)
#define ARD_AD3_SetDigitalMode()     do { ANSELFbits.ANSF3 = 0; } while(0)

// get/set ARD_AD4 aliases
#define ARD_AD4_TRIS                 TRISFbits.TRISF4
#define ARD_AD4_LAT                  LATFbits.LATF4
#define ARD_AD4_PORT                 PORTFbits.RF4
#define ARD_AD4_WPU                  WPUFbits.WPUF4
#define ARD_AD4_OD                   ODCONFbits.ODCF4
#define ARD_AD4_ANS                  ANSELFbits.ANSF4
#define ARD_AD4_SetHigh()            do { LATFbits.LATF4 = 1; } while(0)
#define ARD_AD4_SetLow()             do { LATFbits.LATF4 = 0; } while(0)
#define ARD_AD4_Toggle()             do { LATFbits.LATF4 = ~LATFbits.LATF4; } while(0)
#define ARD_AD4_GetValue()           PORTFbits.RF4
#define ARD_AD4_SetDigitalInput()    do { TRISFbits.TRISF4 = 1; } while(0)
#define ARD_AD4_SetDigitalOutput()   do { TRISFbits.TRISF4 = 0; } while(0)
#define ARD_AD4_SetPullup()          do { WPUFbits.WPUF4 = 1; } while(0)
#define ARD_AD4_ResetPullup()        do { WPUFbits.WPUF4 = 0; } while(0)
#define ARD_AD4_SetPushPull()        do { ODCONFbits.ODCF4 = 0; } while(0)
#define ARD_AD4_SetOpenDrain()       do { ODCONFbits.ODCF4 = 1; } while(0)
#define ARD_AD4_SetAnalogMode()      do { ANSELFbits.ANSF4 = 1; } while(0)
#define ARD_AD4_SetDigitalMode()     do { ANSELFbits.ANSF4 = 0; } while(0)

// get/set ARD_AD5 aliases
#define ARD_AD5_TRIS                 TRISFbits.TRISF5
#define ARD_AD5_LAT                  LATFbits.LATF5
#define ARD_AD5_PORT                 PORTFbits.RF5
#define ARD_AD5_WPU                  WPUFbits.WPUF5
#define ARD_AD5_OD                   ODCONFbits.ODCF5
#define ARD_AD5_ANS                  ANSELFbits.ANSF5
#define ARD_AD5_SetHigh()            do { LATFbits.LATF5 = 1; } while(0)
#define ARD_AD5_SetLow()             do { LATFbits.LATF5 = 0; } while(0)
#define ARD_AD5_Toggle()             do { LATFbits.LATF5 = ~LATFbits.LATF5; } while(0)
#define ARD_AD5_GetValue()           PORTFbits.RF5
#define ARD_AD5_SetDigitalInput()    do { TRISFbits.TRISF5 = 1; } while(0)
#define ARD_AD5_SetDigitalOutput()   do { TRISFbits.TRISF5 = 0; } while(0)
#define ARD_AD5_SetPullup()          do { WPUFbits.WPUF5 = 1; } while(0)
#define ARD_AD5_ResetPullup()        do { WPUFbits.WPUF5 = 0; } while(0)
#define ARD_AD5_SetPushPull()        do { ODCONFbits.ODCF5 = 0; } while(0)
#define ARD_AD5_SetOpenDrain()       do { ODCONFbits.ODCF5 = 1; } while(0)
#define ARD_AD5_SetAnalogMode()      do { ANSELFbits.ANSF5 = 1; } while(0)
#define ARD_AD5_SetDigitalMode()     do { ANSELFbits.ANSF5 = 0; } while(0)

// get/set RF6 procedures
#define RF6_SetHigh()            do { LATFbits.LATF6 = 1; } while(0)
#define RF6_SetLow()             do { LATFbits.LATF6 = 0; } while(0)
#define RF6_Toggle()             do { LATFbits.LATF6 = ~LATFbits.LATF6; } while(0)
#define RF6_GetValue()              PORTFbits.RF6
#define RF6_SetDigitalInput()    do { TRISFbits.TRISF6 = 1; } while(0)
#define RF6_SetDigitalOutput()   do { TRISFbits.TRISF6 = 0; } while(0)
#define RF6_SetPullup()             do { WPUFbits.WPUF6 = 1; } while(0)
#define RF6_ResetPullup()           do { WPUFbits.WPUF6 = 0; } while(0)
#define RF6_SetAnalogMode()         do { ANSELFbits.ANSF6 = 1; } while(0)
#define RF6_SetDigitalMode()        do { ANSELFbits.ANSF6 = 0; } while(0)

// get/set RF7 procedures
#define RF7_SetHigh()            do { LATFbits.LATF7 = 1; } while(0)
#define RF7_SetLow()             do { LATFbits.LATF7 = 0; } while(0)
#define RF7_Toggle()             do { LATFbits.LATF7 = ~LATFbits.LATF7; } while(0)
#define RF7_GetValue()              PORTFbits.RF7
#define RF7_SetDigitalInput()    do { TRISFbits.TRISF7 = 1; } while(0)
#define RF7_SetDigitalOutput()   do { TRISFbits.TRISF7 = 0; } while(0)
#define RF7_SetPullup()             do { WPUFbits.WPUF7 = 1; } while(0)
#define RF7_ResetPullup()           do { WPUFbits.WPUF7 = 0; } while(0)
#define RF7_SetAnalogMode()         do { ANSELFbits.ANSF7 = 1; } while(0)
#define RF7_SetDigitalMode()        do { ANSELFbits.ANSF7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/