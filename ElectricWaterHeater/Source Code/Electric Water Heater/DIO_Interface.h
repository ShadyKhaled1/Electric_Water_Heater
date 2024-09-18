#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3

 #define DIO_PIN0	0
 #define DIO_PIN1	1
 #define DIO_PIN2	2
 #define DIO_PIN3	3
 #define DIO_PIN4	4
 #define DIO_PIN5	5
 #define DIO_PIN6	6
 #define DIO_PIN7	7
 
 #define DIO_PIN_OUTPUT	1
 #define DIO_PIN_INPUT	0
 
  #define DIO_PIN_HIGH	1 
  #define DIO_PIN_LOW	0
 
 #define DIO_PORT_OUTPUT	0XFF
 #define DIO_PORT_INPUT		0
 
 #define DIO_PORT_HIGH		0XFF
 #define DIO_PORT_LOW		0



u8 DIO_u8SetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinDirection);
u8 DIO_u8SetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
u8 DIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 * Copy_Pu8_ReturnedValue);

u8 DIO_u8SetPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortDirection);
u8 DIO_u8SetPortValue(u8 Copy_u8PortName, u8 Copy_u8PortValue);
u8 DIO_u8GetPortValue(u8 Copy_u8PortName, u8 * Copy_Pu8_ReturnedValue);



#endif