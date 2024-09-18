



#ifndef _ADC_REGISTER_H_
#define _ADC_REGISTER_H_



#define ADMUX          ( * ( volatile u8 * ) 0x27 )
#define ADCSRA         ( * ( volatile u8 * ) 0x26 )
#define SFIOR          ( * ( volatile u8 * ) 0x50 )
#define ADCH           ( * ( volatile u8 * ) 0x25 )
#define ADCL           ( * ( volatile u8 * ) 0x24 )
#define ADC_10_BIT_DATA     ( * ( volatile u16 * ) 0x24 )

#endif