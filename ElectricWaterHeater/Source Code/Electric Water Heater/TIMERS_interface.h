

#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

#define TIMER0_CTC_MODE            0
#define TIMER0_OVF_MODE            1
#define TIMER0_Fast_PWM_MODE       2
#define TIMER0_Phase_Correct_MODE  3

void TIMER0_voidInit(void);
u8 TIMER0_u8CallBackFunction(u8 copy_modeID , void (*Application_function)(void));


#endif
