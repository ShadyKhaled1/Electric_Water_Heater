
#ifndef TIMER2_REGISTER_H_
#define TIMER2_REGISTER_H_
 
 /*TIMER0 Registers*/
#define TCCR2        (*(( volatile u8 *)0X45))
#define TCNT2        (*(( volatile u8 *)0X44))
#define OCR2         (*(( volatile u8 *)0X43))
#define TIMSK        (*(( volatile u8 *)0X59))
#define TIFR         (*(( volatile u8 *)0X58))


#endif