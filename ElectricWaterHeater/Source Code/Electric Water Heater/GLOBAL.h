
#ifndef GLOBAL_H
#define GLOBAL_H

#include "STD_TYPES.h"

// Declaration of global variables
extern volatile u8 SET_TEMP_UP;
extern volatile u8 SET_TEMP_DOWN;
extern volatile u8 CURRENT_TEMP;
extern volatile u8 SET_TEMP;
	  
extern volatile u32 SS_EXIT_COUNTER;
extern volatile u32 TEMP_SENSE_COUNTER;
extern volatile u8 ON_OFF;
extern volatile volatile u8 CHANGE_IN_POWER_STATE_FLAG;

extern volatile u8 Reading_Counter;
extern volatile u32 Readings_Sum;
extern volatile u8 AVG_TEMP;

extern volatile u8 Heater_Led_Flag;
extern volatile u32 Heater_Blink_Counter;
extern volatile u8 Heater_OnOff_switch;

#endif
