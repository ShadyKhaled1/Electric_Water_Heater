

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"


#include "TIMER2_config.h"
#include "TIMER2_private.h"
#include "TIMER2_interface.h"
#include "TIMER2_register.h"

static void(* global_app_func_ctc)(void) = 0;
static void(* global_app_func_ovf)(void) = 0;

void TIMER2_voidInit(void)
{
	#if TIMER2_WAVE_GEN_MODE == TIMER2_CTC_MODE
	/*set ctc mode */
	SET_BIT(TCCR2,1);
	CLR_BIT(TCCR2,0);

	/*set prescaler*/
	TCCR2 &= 0b11111000;
	TCCR2 |= TIMER2_PRESCALER;

	/*set compare value*/
	OCR2 = TIMER2_COMPARE_MATCH_VALUE;

	/*enable ctc interrupt*/
	SET_BIT(TIMSK,7);
	
	


	#else
	#error "WRONG WAVE GENERATION MODE SELECT "
	#endif

}
u8 TIMER2_u8CallBackFunction(u8 copy_modeID , void (*Application_function)(void))
{
	
	u8 local_u8_error_state = OK;
	
	if(Application_function != NULL)
	{
		if(copy_modeID == TIMER2_CTC_MODE)
		global_app_func_ctc=Application_function;
		

		
		else
		local_u8_error_state = NOK ;
	}
	else
	{
		local_u8_error_state = NOK ;
	}
	
	return local_u8_error_state;
	
	
}

/*isr ctc*/
void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{
	if (global_app_func_ctc != NULL)
	{
		global_app_func_ctc();
	}

}

/*isr ovf*/
void __vector_5 (void) __attribute__((signal));
void __vector_5 (void)
{
	if (global_app_func_ovf != NULL)
	{
		global_app_func_ovf();
	}

}