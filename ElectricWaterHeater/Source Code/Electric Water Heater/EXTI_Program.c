#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "EXTI_Register.h"
#include "EXTI_Config.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"

static void (*Global_APP_INT0_ptrFunction)(void)=NULL;
static void (*Global_APP_INT1_ptrFunction)(void)=NULL;
static void (*Global_APP_INT2_ptrFunction)(void)=NULL;

u8 EXTI_voidPeripheralINT_enable(u8 copy_u8IntID,u8 copy_u8SenseControl){
	u8 Local_ERROR_STATE = OK;	
	switch(copy_u8IntID){
		case EXTI_INT0_ID:
		
		//enable PIE
		SET_BIT(GICR,6);
		
		// Set Sense CTRL
		switch(copy_u8SenseControl){
			case EXTI_SENSE_CTRL_LOW_LEVEL:
			
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			
			break;
			case EXTI_SENSE_CTRL_RISING_EDGE:
			
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);			
			
			break;
			case EXTI_SENSE_CTRL_FALLING_EDGE:
			
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			
			break;
			case EXTI_SENSE_CTRL_ON_CHANGE:
			
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			
			break;
			default   :  Local_ERROR_STATE=NOK;             break;
				
		}
		
		break;
		case EXTI_INT1_ID:
		//enable PIE
		SET_BIT(GICR,7);
		
		// Set Sense CTRL
		switch(copy_u8SenseControl){
			case EXTI_SENSE_CTRL_LOW_LEVEL:
			
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			
			break;
			case EXTI_SENSE_CTRL_RISING_EDGE:
			
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			
			break;
			case EXTI_SENSE_CTRL_FALLING_EDGE:
			
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			
			break;
			case EXTI_SENSE_CTRL_ON_CHANGE:
			
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			
			break;
			default   :  Local_ERROR_STATE=NOK;             break;
			
		}
		break;
		case EXTI_INT2_ID:
		//enable PIE
		SET_BIT(GICR,5);
		
		// Set Sense CTRL
		switch(copy_u8SenseControl){
			case EXTI_SENSE_CTRL_RISING_EDGE:
			
			SET_BIT(MCUCSR,6);
			
			break;
			case EXTI_SENSE_CTRL_FALLING_EDGE:
			
			CLR_BIT(MCUCSR,6);
			
			break;
			default   :  Local_ERROR_STATE=NOK;             break;
			
		}
		break;
		default   :  Local_ERROR_STATE=NOK;             break;
		
	}	
	return Local_ERROR_STATE;
}
u8 EXTI_voidPeripheralINT_disable(u8 copy_u8IntID){
	u8 Local_ERROR_STATE = OK;	
	
	switch(copy_u8IntID){
		case EXTI_INT0_ID:
		CLR_BIT(GICR,6);
		
		break;
		
		case EXTI_INT1_ID:
		CLR_BIT(GICR,7);
		
		break;
		
		case EXTI_INT2_ID:
		CLR_BIT(GICR,5);
		
		break;
		
		default   :  Local_ERROR_STATE=NOK;             break;
		
		
	}
	return Local_ERROR_STATE;
	
	
}


u8 EXTI_u8CallBackFuntion(u8 copy_u8IntID,void (*copy_pvoidAppFunction)(void))
{
	u8 local_err_state=OK;

	if(copy_pvoidAppFunction != NULL)
	{
		switch(copy_u8IntID)
		{
			case EXTI_INT0_ID :
			Global_APP_INT0_ptrFunction=copy_pvoidAppFunction;
			
			break;
			case EXTI_INT1_ID :
			Global_APP_INT1_ptrFunction=copy_pvoidAppFunction;
			break;
			case EXTI_INT2_ID :
			Global_APP_INT2_ptrFunction=copy_pvoidAppFunction;
			break;
			default: local_err_state=NOK; break;
		}
		
		
	}
	else
	{
		local_err_state=NOK;
	}
	return local_err_state;
	
}


void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){
	
	if(Global_APP_INT0_ptrFunction!=NULL){
		Global_APP_INT0_ptrFunction();
	}
	else{
		
	}
	
}
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	
	if(Global_APP_INT1_ptrFunction!=NULL){
		Global_APP_INT1_ptrFunction();
	}
	else{
		
	}
	
}
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void){

	if(Global_APP_INT2_ptrFunction!=NULL){
		Global_APP_INT2_ptrFunction();
	}
	else{
		
	}

}