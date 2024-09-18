#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "DIO_Register.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

u8 DIO_u8SetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinDirection){
	
	u8 Local_ERROR_STATE = OK;	
	
	if(Copy_u8PinNumber>=DIO_PIN0 && Copy_u8PinNumber<= DIO_PIN7){
		if(Copy_u8PinDirection == DIO_PIN_OUTPUT){
			
			switch(Copy_u8PortName)
			
			{
				case DIO_PORTA : SET_BIT(DDRA,Copy_u8PinNumber); break;
				case DIO_PORTB : SET_BIT(DDRB,Copy_u8PinNumber); break;
				case DIO_PORTC : SET_BIT(DDRC,Copy_u8PinNumber); break;
				case DIO_PORTD : SET_BIT(DDRD,Copy_u8PinNumber); break;
				default   :  Local_ERROR_STATE=NOK;             break;
			}
			
		}
		else if (Copy_u8PinDirection == DIO_PIN_INPUT){
			
			switch(Copy_u8PortName)
			
			{
				case DIO_PORTA : CLR_BIT(DDRA,Copy_u8PinNumber); break;
				case DIO_PORTB : CLR_BIT(DDRB,Copy_u8PinNumber); break;
				case DIO_PORTC : CLR_BIT(DDRC,Copy_u8PinNumber); break;
				case DIO_PORTD : CLR_BIT(DDRD,Copy_u8PinNumber); break;
				default   :  Local_ERROR_STATE=NOK;             break;
			}
			
		}
		else {
			Local_ERROR_STATE= NOK;
		}
	}
	else{
		Local_ERROR_STATE=NOK;
	}
	
	return Local_ERROR_STATE;
	
}
u8 DIO_u8SetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue){
	
	u8 Local_ERROR_STATE = OK;
	
	if(Copy_u8PinNumber>=DIO_PIN0 && Copy_u8PinNumber<= DIO_PIN7){
		if(Copy_u8PinValue == DIO_PIN_HIGH){
			
			switch(Copy_u8PortName)
			
			{
				case DIO_PORTA : SET_BIT(PORTA,Copy_u8PinNumber); break;
				case DIO_PORTB : SET_BIT(PORTB,Copy_u8PinNumber); break;
				case DIO_PORTC : SET_BIT(PORTC,Copy_u8PinNumber); break;
				case DIO_PORTD : SET_BIT(PORTD,Copy_u8PinNumber); break;
				default   :  Local_ERROR_STATE=NOK;             break;
			}
			
		}
		else if (Copy_u8PinValue == DIO_PIN_LOW){
			
			switch(Copy_u8PortName)
			
			{
				case DIO_PORTA : CLR_BIT(PORTA,Copy_u8PinNumber); break;
				case DIO_PORTB : CLR_BIT(PORTB,Copy_u8PinNumber); break;
				case DIO_PORTC : CLR_BIT(PORTC,Copy_u8PinNumber); break;
				case DIO_PORTD : CLR_BIT(PORTD,Copy_u8PinNumber); break;
				default   :  Local_ERROR_STATE=NOK;             break;
			}
			
		}
		else {
			Local_ERROR_STATE= NOK;
		}
	}
	else{
		Local_ERROR_STATE=NOK;
	}
	
	return Local_ERROR_STATE;
	
}
u8 DIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 * Copy_Pu8_ReturnedValue){
	u8 Local_ERROR_STATE = OK;
	
	if(Copy_u8PinNumber>=DIO_PIN0 && Copy_u8PinNumber<= DIO_PIN7){
					
			switch(Copy_u8PortName)
			{
				case DIO_PORTA : * Copy_Pu8_ReturnedValue = GET_BIT(PINA,Copy_u8PinNumber); break;
				case DIO_PORTB : * Copy_Pu8_ReturnedValue = GET_BIT(PINB,Copy_u8PinNumber); break;
				case DIO_PORTC : * Copy_Pu8_ReturnedValue = GET_BIT(PINC,Copy_u8PinNumber); break;
				case DIO_PORTD : * Copy_Pu8_ReturnedValue = GET_BIT(PIND,Copy_u8PinNumber); break;
				default   :  Local_ERROR_STATE=NOK;             break;
			}
			
	}
	
	return Local_ERROR_STATE;
}

u8 DIO_u8SetPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortDirection){
	u8 Local_ERROR_STATE = OK;
	
	
		if( Copy_u8PortDirection == DIO_PORT_OUTPUT || Copy_u8PortName == DIO_PORT_INPUT ){
			
			switch(Copy_u8PortName)
			
			{
				case DIO_PORTA : DDRA=Copy_u8PortDirection; break;
				case DIO_PORTB : DDRB=Copy_u8PortDirection; break;
				case DIO_PORTC : DDRC=Copy_u8PortDirection; break;
				case DIO_PORTD : DDRD=Copy_u8PortDirection; break;
				default   :  Local_ERROR_STATE=NOK;    break;
			}
			
		}

		else {
			Local_ERROR_STATE= NOK;
		}
	
	
	
	return Local_ERROR_STATE;	
}
u8 DIO_u8SetPortValue(u8 Copy_u8PortName, u8 Copy_u8PortValue){
	u8 Local_ERROR_STATE = OK;
	
	
	if(Copy_u8PortValue == DIO_PORT_LOW || Copy_u8PortValue == DIO_PORT_HIGH ){
		
		switch(Copy_u8PortName)
		
		{
			case DIO_PORTA : PORTA=Copy_u8PortValue; break;
			case DIO_PORTB : PORTB=Copy_u8PortValue; break;
			case DIO_PORTC : PORTC=Copy_u8PortValue; break;
			case DIO_PORTD : PORTD=Copy_u8PortValue; break;
			default   :  Local_ERROR_STATE=NOK;    break;
		}
		
	}

	else {
		Local_ERROR_STATE= NOK;
	}
	
	
	
	return Local_ERROR_STATE;
}
u8 DIO_u8GetPortValue(u8 Copy_u8PortName, u8 * Copy_Pu8_ReturnedValue){
	u8 Local_ERROR_STATE = OK;
			
		switch(Copy_u8PortName)
		
		{
			case DIO_PORTA : * Copy_Pu8_ReturnedValue = PINA; break;
			case DIO_PORTB : * Copy_Pu8_ReturnedValue = PINB; break;
			case DIO_PORTC : * Copy_Pu8_ReturnedValue = PINC; break;
			case DIO_PORTD : * Copy_Pu8_ReturnedValue = PIND; break;
			default   :  Local_ERROR_STATE=NOK;    break;
		}
	
	return Local_ERROR_STATE;	
	
}
