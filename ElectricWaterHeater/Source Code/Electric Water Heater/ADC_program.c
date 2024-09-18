
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"


#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"



void ADC_voidInit(void)
{
	
	/*Reference Selection Bits: AVCC with external capacitor at AREF pin*/
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	
	#if ADC_RESOLUTION == ADC_8_BIT_RESOLUTION
	/* left adjust: 8 bit resolution Bit 5 – ADLAR: ADC Left Adjust Result */
	SET_BIT(ADMUX,5);
	
	#elif ADC_RESOLUTION == ADC_10_BIT_RESOLUTION
	/* right adjust: 8 bit resolution */
	CLR_BIT(ADMUX,5);
	#else
	#error "ADC_RESOLUTION @ config file "
	#endif
	
	
	/*select prescaler /4
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
	*/
	ADCSRA &=0b11111000;
	ADCSRA |=ADC_PRESCALER;

	/*Bit 7 – ADEN: ADC Enable*/
	SET_BIT(ADCSRA,7);
	
	
	
}
u8 ADC_u8StartConversion(u8 copy_u8_Channel_ID, u16 * copy_pu16_Result)
{
	u8 local_u8_Err_state=OK;
	
	/*set channel */
	ADMUX  &=0b11100000;
	ADMUX  |= copy_u8_Channel_ID;
	
	/*START conversion*/
	SET_BIT(ADCSRA,6);
	
	/*busy waiting until flag = 1*/
	while (GET_BIT(ADCSRA,4) == 0);

	/*clear flag*/
	SET_BIT(ADCSRA,4);
	
	/*get reading*/
	if (copy_pu16_Result != NULL)
	{
		
		#if ADC_RESOLUTION == ADC_8_BIT_RESOLUTION
		//get 8bit data
		*copy_pu16_Result = ADCH;
		
		#elif ADC_RESOLUTION == ADC_10_BIT_RESOLUTION
		//get 10bit data
		*copy_pu16_Result = ADC_10_BIT_DATA;
		
		#else
		#error "ADC_RESOLUTION @ config file "
		#endif
		
		
	}
	else
	{
		local_u8_Err_state=NOK;
	}
	
	
	return local_u8_Err_state;
}