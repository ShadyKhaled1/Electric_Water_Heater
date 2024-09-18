#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

#define ADC_CHANNEL_ID_0  0
#define ADC_CHANNEL_ID_1  1
#define ADC_CHANNEL_ID_2  2
#define ADC_CHANNEL_ID_3  3
#define ADC_CHANNEL_ID_4  4
#define ADC_CHANNEL_ID_5  5
#define ADC_CHANNEL_ID_6  6
#define ADC_CHANNEL_ID_7  7

 void ADC_voidInit(void);
 u8 ADC_u8StartConversion(u8 copy_u8_Channel_ID, u16 * copy_pu16_Result); 
 


#endif