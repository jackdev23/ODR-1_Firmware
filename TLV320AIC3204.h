/*******************************************************************************
* This work is licensed under the Creative Commons Attribution-ShareAlike
* 4.0 International License. To view a copy of this license, visit
* http://creativecommons.org/licenses/by-sa/4.0/ or send a letter to
* Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*******************************************************************************/

#ifndef __LV320AIC3204_H
#define __LV320AIC3204_H

#define	int8 signed char                // AKA int8_t
#define	uint8 unsigned char             // AKA uint8_t
#define	uint16 unsigned int             // AKA uint16_t

uint8 Codec_Read_SPI(uint8 address);
void Codec_Write_SPI(uint8 address, uint8 data);
void Init_Audio_Codec(void);                 // Initialize Audio Codec

void Codec_HP_Gain (int8 HP_Gain);           // Sets gain of L & R Headphone Amps
void Codec_LO_Gain (int8 LO_Gain);           // Sets gain of L & R Line Out Amps
void Codec_MICPGA_Gain (uint8 MICPGA_Gain);  // Sets gain of L & R Mic PGAs
void Codec_DAC_Gain (int8 DAC_Gain);         // Sets digital gain of L & R DAC out
void Codec_ADC_Gain (int8 ADC_Gain);         // Sets digital gain of L & R ADC out
void Codec_Mic_Bias (uint8 Mic_Bias);        // Turn Codec Mic Bias on(1) off(0)

void Codec_Config_RX (void);        // Config Codec for normal Receive
void Codec_Config_TX_Mic (void);    // Config Codec for Transmit using Mic input
void Codec_Config_PT1_RX (void);    // Config Analog Pass Through Receive
void Codec_Config_PT1_TX (void);    // Config Analog Pass Through Transmit
void Codec_Config_PT2_RX (void);    // Config ADC-DAC Pass Through Receive
void Codec_Config_PT3_RX (void);    // Config ADC-DSP-DAC Pass Through Receive

void Codec_Beep_Freq (uint8 Beep_Freq);  // Set Codec Beep Frequency
void Codec_Beep_Vol (uint8 Beep_Vol);    // Set Codec Beep Volume
void Codec_Beep (uint16 Beep_Length);    // Set Codec Beep Duration and enable beep

#endif