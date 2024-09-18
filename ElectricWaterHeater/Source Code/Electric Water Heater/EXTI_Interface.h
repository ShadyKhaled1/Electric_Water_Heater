#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


//INT ID

#define EXTI_INT0_ID                  0
#define EXTI_INT1_ID                  1
#define EXTI_INT2_ID                  2

//Sense CTRL

#define EXTI_SENSE_CTRL_LOW_LEVEL     0
#define EXTI_SENSE_CTRL_RISING_EDGE   1
#define EXTI_SENSE_CTRL_FALLING_EDGE  2
#define EXTI_SENSE_CTRL_ON_CHANGE     3


u8 EXTI_voidPeripheralINT_enable(u8 copy_u8IntID,u8 copy_u8SenseControl);
u8 EXTI_voidPeripheralINT_disable(u8 copy_u8IntID);

u8 EXTI_u8CallBackFuntion(u8 copy_u8IntID,void (*copy_pvoidAppFunction)(void));


#endif