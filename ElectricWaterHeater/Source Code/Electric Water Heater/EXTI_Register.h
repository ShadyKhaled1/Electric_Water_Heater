/***********************************************************/
/***********************************************************/
/*******************NAME: Shady Khaled Mohamed**************/
/*******************LAYER: MCAL                *************/
/*******************DATE: 19/8/2024           **************/
/*******************VERSION: V1.0             **************/
/***********************************************************/
/***********************************************************/

#ifndef _EXTI_REGISTER_H
#define _EXTI_REGISTER_H

#define GICR   ( *( volatile u8 * ) 0x5B ) //PIE
#define GIFR   ( *( volatile u8 * ) 0x5A ) //PIF
#define MCUCR  ( *( volatile u8 * ) 0x55 ) //Sense Control INT0 , INT1
#define MCUCSR ( *( volatile u8 * ) 0x54 ) //Sense Control INT2


#endif