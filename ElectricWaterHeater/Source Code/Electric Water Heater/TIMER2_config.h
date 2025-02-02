

#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_

/*
TIMER2_PRESCALER_STOP
TIMER2_PRESCALER_1
TIMER2_PRESCALER_8
TIMER2_PRESCALER_64
TIMER2_PRESCALER_256
TIMER2_PRESCALER_1024
*/
#define TIMER2_PRESCALER   TIMER2_PRESCALER_64

#define TIMER2_COMPARE_MATCH_VALUE   250

/*
TIMER2_CTC_MODE
TIMER2_OVF_MODE
TIMER2_Fast_PWM_MODE
TIMER2_Phase_Correct_MODE
*/
#define  TIMER2_WAVE_GEN_MODE   TIMER2_CTC_MODE




#endif
