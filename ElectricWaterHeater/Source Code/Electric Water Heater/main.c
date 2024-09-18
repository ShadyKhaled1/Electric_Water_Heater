

#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"
#include "DIO_Interface.h"
#include <util/delay.h>
#include "EXTI_Interface.h"
#include "GIE_interface.h"
#include "DIO_Interface.h"
#include "DIO_Register.h"
#include "SS_Interface.h"
#include "GLOBAL.h"
#include "TIMER2_config.h"
#include "TIMER2_interface.h"
#include "TIMERS_config.h"
#include "TIMERS_interface.h"
#include "ADC_interface.h"
#include "LM35_interface.h"
#include "EEPROM.h"



void Heating_And_Cooling(void){
	
	if(AVG_TEMP<(SET_TEMP-5)){
		//Heater ON
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		//Cooler OFF
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
		// Raise Heater LED Flag to blink every 1 sec
		Heater_Led_Flag=1;
		
		if(Heater_OnOff_switch==1){
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
		}
		else if(Heater_OnOff_switch==0){
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		}
		
		
		
	}
	else if(AVG_TEMP>(SET_TEMP+5)){
		//Lower the Heater LED Flag to close the 1 second heater led blink
		Heater_Led_Flag=0;
		Heater_Blink_Counter=0;
		//Heater OFF
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
		//Cooler ON
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
		
		//Heating LED ON
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
	}
	else{
		Heater_Led_Flag=0;
		Heater_Blink_Counter=0;
		//OFF heating LED
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		//OFF Heating And Cooling Elements
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
	}
}

void Last_Ten_Readings_AVG(void){
	Reading_Counter++;
	Readings_Sum+=CURRENT_TEMP;
	if(Reading_Counter==10){
		AVG_TEMP=Readings_Sum/10;
		Reading_Counter=0;
		Readings_Sum=0;
		// do the heating and cooling after calculating the average of last 10 readings
		Heating_And_Cooling();
		
	}
}



void app_exit_five_sec_ctc_timer_two (void)
{
	
	SS_EXIT_COUNTER++;

	if(SS_EXIT_COUNTER == 5000)  // 5 sec
	{
		SET_TEMP_UP=0;
		SET_TEMP_DOWN=0;
		SS_EXIT_COUNTER = 0;
		
	}
}

void app_temp_sense_hundred_ms_ctc_timer_zero (void)
{
	
	TEMP_SENSE_COUNTER++;
	
	
	if(Heater_Led_Flag==1){
		
		Heater_Blink_Counter++;
	}
	
	
	if(TEMP_SENSE_COUNTER == 1000)  // 100 ms
	{
		LM35_TEMP_SENSOR_ON(&CURRENT_TEMP);
		TEMP_SENSE_COUNTER=0;
		Last_Ten_Readings_AVG();
		

	}
	if(Heater_Blink_Counter== 10000){
		Heater_Blink_Counter=0;
		if(Heater_OnOff_switch==0){
			Heater_OnOff_switch=1;
		}
		else if (Heater_OnOff_switch==1){
			Heater_OnOff_switch=0;
		}
		
	}
	
}

void APP_INT0(){
	
	 SS_EXIT_COUNTER = 0;
	 TIMER2_u8CallBackFunction(TIMER2_CTC_MODE,app_exit_five_sec_ctc_timer_two);
	if (SET_TEMP_UP==0 && ON_OFF==1){

		SET_TEMP_UP=1;
		
	}
	else if(SET_TEMP_UP==1 && SET_TEMP<75){
		SET_TEMP+=5;
		eepromWrite(0,SET_TEMP);
		
	}
}
void APP_INT1(){
	
	
	 SS_EXIT_COUNTER = 0;
	 TIMER2_u8CallBackFunction(TIMER2_CTC_MODE,app_exit_five_sec_ctc_timer_two);

	if (SET_TEMP_DOWN==0 && ON_OFF==1){
		SET_TEMP_DOWN=1;
	}
	else if(SET_TEMP_DOWN==1 && SET_TEMP>35){
		SET_TEMP-=5;
		eepromWrite(0,SET_TEMP);
	}
}


void APP_INT2(){
	if(ON_OFF==0){
		ON_OFF=1;
		
	}
	else if (ON_OFF==1){
		ON_OFF=0;
		CHANGE_IN_POWER_STATE_FLAG=1;
		DIO_u8SetPinValue(DIO_PORTB, DIO_PIN1, DIO_PIN_LOW);   // Turn off both displays
		DIO_u8SetPinValue(DIO_PORTB, DIO_PIN0, DIO_PIN_LOW);   // Turn off both displays
	}
	
}


void TEMP_OUT_SS(){
	if ( (SET_TEMP_UP==0) && (SET_TEMP_DOWN==0) ){
		SS_OUT(CURRENT_TEMP);
	}
	else if( (SET_TEMP_UP==1) || (SET_TEMP_DOWN==1) ){

		SS_ONE_SEC_BLINK();
		SS_OUT(SET_TEMP);
		
	}
}




int main(void)
{
	eepromWrite(0,SET_TEMP);
	
	SS_Init();
	
	
	//Heating And Cooling Pins
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN1,DIO_PIN_OUTPUT);
	
	//Heating LED Pin
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	

	
	// intrupt 1 AND 0 pin as input
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT);
	
	// intrupt 2 pin as input
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_INPUT);
	
	//internal pullup on for interupts
	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN2,DIO_PIN_HIGH);
	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	
	// intrupt enable
	EXTI_voidPeripheralINT_enable(EXTI_INT0_ID,EXTI_SENSE_CTRL_FALLING_EDGE);
	EXTI_voidPeripheralINT_enable(EXTI_INT1_ID,EXTI_SENSE_CTRL_FALLING_EDGE);
	EXTI_voidPeripheralINT_enable(EXTI_INT2_ID,EXTI_SENSE_CTRL_FALLING_EDGE);
	EXTI_u8CallBackFuntion(EXTI_INT0_ID,APP_INT0);
	EXTI_u8CallBackFuntion(EXTI_INT1_ID,APP_INT1);
	EXTI_u8CallBackFuntion(EXTI_INT2_ID,APP_INT2);
	
	/*ADC CHANNEL 0 INPUT  LM35*/
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);
	
	ADC_voidInit();	
	
	GIE_Enable();
	TIMER0_voidInit();
	TIMER2_voidInit();
	
    while (1) 
    {
		
		
		if(CHANGE_IN_POWER_STATE_FLAG==1){
			SET_TEMP=eepromRead(0);
		}
		
		
		switch(ON_OFF){
			
			case 0:
				Reading_Counter=0;
				Readings_Sum=0;
				AVG_TEMP=0;
				Heater_Led_Flag=0;
				Heater_Blink_Counter=0;
				Heater_OnOff_switch=0;
				TEMP_SENSE_COUNTER=0;
				//off leds
				DIO_u8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
				//off heating and cooling elements
				DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
				DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
			break;
			
			case 1:
			
				TIMER0_u8CallBackFunction(TIMER0_CTC_MODE,app_temp_sense_hundred_ms_ctc_timer_zero);
				TEMP_OUT_SS();
				
			break;
			
			default   :     break;
			
		}

		

	        }
		
	}
