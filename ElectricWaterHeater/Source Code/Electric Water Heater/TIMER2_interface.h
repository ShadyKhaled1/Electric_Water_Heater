
#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

#define TIMER2_CTC_MODE            0
#define TIMER2_OVF_MODE            1
#define TIMER2_Fast_PWM_MODE       2
#define TIMER2_Phase_Correct_MODE  3

void TIMER2_voidInit(void);
u8 TIMER2_u8CallBackFunction(u8 copy_modeID , void (*Application_function)(void));


#endif
