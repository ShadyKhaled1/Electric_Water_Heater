
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"

#include "LM35_interface.h"
#include "ADC_interface.h"

void LM35_TEMP_SENSOR_ON(volatile u8 * CURRENT_TEMP){
	u16 ADC_u16_Digital_Read = 0;
	u32 ADC_u32_Analog_mv = 0;
	u16 LM35_u16_Result = 0;
	
	
	ADC_u8StartConversion(ADC_CHANNEL_ID_0,&ADC_u16_Digital_Read);
	ADC_u32_Analog_mv= ( ADC_u16_Digital_Read * 5000UL)/1024;    //10bits
	LM35_u16_Result=ADC_u32_Analog_mv/10;
	
	*CURRENT_TEMP=(u8)LM35_u16_Result;
}

