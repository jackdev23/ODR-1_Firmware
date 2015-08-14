/******************************************************************************
 * Header file for DSPIC33E_hardware.c
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *****************************************************************************/

// Board specific definitions
#ifndef __DSPIC33E_HARDWARE_H
#define __DSPIC33E_HARDWARE_H

// Compile for SNAPPIC evaluation board
//#ifndef SNAP_PIC
//#define SNAP_PIC
//#endif


// all sort of CPU clock dependent constants
// define FCY, system cycle rate, in the 33F chip Fosc / 2
// #define FCY 29491200UL	// 29,4912 MHz
// #define FCY 38707200UL	// 38,7072 MHz

#define CYCLE_TIME 12e-3
#define TIMER_PERIOD (CYCLE_TIME/(16.66667e-9 * 64))


// define general I/O signals
// Use LAT for write only operations and PORT for read operations
#define	LCD_CS     LATEbits.LATE7     // LCD Slave Select on RE7(RP87)
#define	LCD_REST   LATEbits.LATE6     // LCD Reset on RE6(RPI86)
#define BPF_S0     LATDbits.LATD14    // Band Pass Filter Select 0
#define BPF_S1     LATBbits.LATB15    // Band Pass Filter Select 1
#define BPF_CS0    LATBbits.LATB14    // Band Pass Filter Chip Select 0
#define BPF_CS1    LATDbits.LATD15    // Band Pass Filter Chip Select 1
#define ATT_S0     LATBbits.LATB13    // RF Attenuator Select 0
#define ATT_S1     LATBbits.LATB12    // RF Attenuator Select 1
#define TX_RX      LATDbits.LATD0     // TX/RX Control line
#define EN_12V     LATDbits.LATD9     // 12V Power Enable
#define AUX_OUT    LATAbits.LATA3     // Rear Auxiliary Output
#define PTT_OUT    LATAbits.LATA2     // Rear PTT Output
#define CODEC_RST  LATEbits.LATE4     // Audio Codec Reset Line RE4


// Configure LCD Data / Command Pin
#ifdef SNAP_PIC  // Configure for development board
    #define	LCD_DC     LATEbits.LATE4    //LCD Data/Command on RE4(RP84) temporary
#else  // Configure for ODR-1 Hardware
    #define	LCD_DC     LATGbits.LATG15    //LCD Data/Command on RG15(RP127)
#endif

//#define	Debug_0    LATDbits.LATD0     //Debug_0 on RD0(RP64)
//#define	Button_1  PORTGbits.RG15      //Push Button on RG15
//#define	Button_2  PORTBbits.RB2       //Push Button on RB2

// SPI1CON1 Configuration (Audio Codec)
// 15-13    Not Used    = 000
// 12       DISSCK      = 0
// 11       DISSDO      = 0
// 10       MODE16      = 1   Use 16 bit mode for Audio codec
//  9       SMP         = 0
//  8       CKE         = 1         Not used in framed mode
//  7       SSEN        = 0
//  6       CKP         = 1
//  5       MSTEN       = 1         Master Mode Enable
//  4-2     SPRE        = 1 01      000=8 thru 111=1
//  1-0     PPRE        = 10        00=64, 01=16, 10=4, 11=1
#define	SPI1CON1_INIT	0x0576  //clk at 60Mhz/12 = 5Mhz

// SPI1CON2 Configuration (Audio Codec)
// 15       FRMEN       = 0         Frame Mode Enable
// 14       SPIFSD      = 0
// 13       FRMPOL      = 0
// 12-2     NOT USED    = 0 0000 0000 00
//  1       FRMDLY      = 0
//  0       SPIBEN      = 0
#define	SPI1CON2_INIT	0x0000


// SPI2CON1 Configuration (LCD Display)
// 15-13    Not Used    = 000
// 12       DISSCK      = 0
// 11       DISSDO      = 0
// 10       MODE16      = 0
//  9       SMP         = 0
//  8       CKE         = 1         Not used in framed mode
//  7       SSEN        = 0
//  6       CKP         = 1
//  5       MSTEN       = 1         Master Mode Enable
//  4-2     SPRE        = 1 01      000=8 thru 111=1
//  1-0     PPRE        = 10        00=64, 01=16, 10=4, 11=1
//#define	SPI2CON1_INIT	0x0061
//#define	SPI2CON1_INIT	0x0161  //works with spi at 475 khz
#define	SPI2CON1_INIT	0x0176  //clk at 60Mhz/12 = 5Mhz

// SPI2CON2 Configuration (LCD Display)
// 15       FRMEN       = 0         Frame Mode Enable
// 14       SPIFSD      = 0
// 13       FRMPOL      = 0
// 12-2     NOT USED    = 0 0000 0000 00
//  1       FRMDLY      = 0
//  0       SPIBEN      = 0
//#define	SPI2CON2_INIT	0x8001
#define	SPI2CON2_INIT	0x0000

// SPI3CON1 Configuration (Ethernet)
// 15-13    Not Used    = 000
// 12       DISSCK      = 0
// 11       DISSDO      = 0
// 10       MODE16      = 0
//  9       SMP         = 0
//  8       CKE         = 1         Not used in framed mode
//  7       SSEN        = 0
//  6       CKP         = 1
//  5       MSTEN       = 1         Master Mode Enable
//  4-2     SPRE        = 1 01      000=8 thru 111=1
//  1-0     PPRE        = 10        00=64, 01=16, 10=4, 11=1
#define	SPI3CON1_INIT	0x0176  //clk at 60Mhz/12 = 5Mhz

// SPI3CON2 Configuration (Ethernet)
// 15       FRMEN       = 0         Frame Mode Enable
// 14       SPIFSD      = 0
// 13       FRMPOL      = 0
// 12-2     NOT USED    = 0 0000 0000 00
//  1       FRMDLY      = 0
//  0       SPIBEN      = 0
#define	SPI3CON2_INIT	0x0000

// SPI4CON1 Configuration (EEPROM)
// 15-13    Not Used    = 000
// 12       DISSCK      = 0
// 11       DISSDO      = 0
// 10       MODE16      = 0
//  9       SMP         = 0
//  8       CKE         = 1         Not used in framed mode
//  7       SSEN        = 0
//  6       CKP         = 1
//  5       MSTEN       = 1         Master Mode Enable
//  4-2     SPRE        = 1 01      000=8 thru 111=1
//  1-0     PPRE        = 10        00=64, 01=16, 10=4, 11=1
#define	SPI4CON1_INIT	0x0176  //clk at 60Mhz/12 = 5Mhz

// SPI4CON2 Configuration (EEPROM)
// 15       FRMEN       = 0         Frame Mode Enable
// 14       SPIFSD      = 0
// 13       FRMPOL      = 0
// 12-2     NOT USED    = 0 0000 0000 00
//  1       FRMDLY      = 0
//  0       SPIBEN      = 0
#define	SPI4CON2_INIT	0x0000


// Declare functions available
void Init_SPI1(void);
void Init_SPI2(void);
void Init_SPI3(void);
void Init_SPI4(void);
void Init_P33EP512MU810_osc(void);
void Init_P33EP512MU810_pins(void);
void Init_QEI_1(void);
void Init_QEI_2(void);
void Init_PWM();
void Init_RTCC();

void Init_I2C2(void);                                   // Init I2C system
void I2C2_Byte_Write(unsigned char, unsigned char);     // write byte, (address, data)
//unsigned char I2C2_Byte_Read(unsigned char);		// read (address)
void I2C2_Byte_Read(unsigned char);		// read (address)
void Init_Timer1(void);
#endif
