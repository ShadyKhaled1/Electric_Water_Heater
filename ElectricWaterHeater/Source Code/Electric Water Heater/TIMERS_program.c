
/*LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"

/*MCAL*/
#include "TIMERS_config.h"
#include "TIMERS_private.h"
#include "TIMERS_interface.h"
#include "TIMERS_register.h"

static void(* global_app_func_ctc)(void) = 0;
static void(* global_app_func_ovf)(void) = 0;

void TIMER0_voidInit(void)
{
	#if TIMER0_WAVE_GEN_MODE == TIMER0_CTC_MODE
	/*set ctc mode */
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	/*set prescaler*/
	TCCR0 &= 0b11111000;
	TCCR0 |= TIMER0_PRESCALER;

	/*set compare value*/
	OCR0 = TIMER0_COMPARE_MATCH_VALUE;

	/*enable ctc interrupt*/
	SET_BIT(TIMSK,1);
	
	

	#elif TIMER0_WAVE_GEN_MODE == TIMER0_OVF_MODE
	/*set ovf mode */
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	/*set prescaler*/
	/*set  value*/
	/*enable ovf interrupt*/



	#elif TIMER0_WAVE_GEN_MODE == TIMER0_Fast_PWM_MODE
	/*set pwm mode */
	/*set prescaler*/
	/*set  value*/
	/*enable pwm interrupt*/

	#elif TIMER0_WAVE_GEN_MODE == TIMER0_Phase_Correct_MODE
	/*set pwm mode */
	/*set prescaler*/
	/*set  value*/
	/*enable pwm interrupt*/
	#else
	#error "WRONG WAVE GENERATION MODE SELECT "
	#endif

}
u8 TIMER0_u8CallBackFunction(u8 copy_modeID , void (*Application_function)(void))
{
	
	u8 local_u8_error_state = OK;
	
	if(Application_function != NULL)
	{
		if(copy_modeID == TIMER0_CTC_MODE)
		global_app_func_ctc=Application_function;
		
		else if (copy_modeID == TIMER0_OVF_MODE)
		global_app_func_ovf=Application_function;
		
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
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if (global_app_func_ctc != NULL)
	{
		global_app_func_ctc();
	}

}

/*isr ovf*/
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if (global_app_func_ovf != NULL)
	{
		global_app_func_ovf();
	}

}