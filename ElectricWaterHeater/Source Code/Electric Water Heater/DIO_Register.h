/***********************************************************/
/***********************************************************/
/*******************NAME: Shady Khaled Mohamed**************/
/*******************LAYER: MCAL                *************/
/*******************DATE: 19/8/2024           **************/
/*******************VERSION: V1.0             **************/
/***********************************************************/
/***********************************************************/

#ifndef _DIO_REGISTER_H
#define _DIO_REGISTER_H

#define PORTA ( *( volatile u8 * ) 0x3b )
#define DDRA  ( *( volatile u8 * ) 0x3A )
#define PINA  ( *( volatile u8 * ) 0x39 )

#define PORTB ( *( volatile u8 * ) 0x38 )
#define DDRB  ( *( volatile u8 * ) 0x37 )
#define PINB  ( *( volatile u8 * ) 0x36 )

#define PORTC ( *( volatile u8 * ) 0x35 )
#define DDRC  ( *( volatile u8 * ) 0x34 )
#define PINC  ( *( volatile u8 * ) 0x33 )

#define PORTD ( *( volatile u8 * ) 0x32 )
#define DDRD  ( *( volatile u8 * ) 0x31 )
#define PIND  ( *( volatile u8 * ) 0x30 )





#endif