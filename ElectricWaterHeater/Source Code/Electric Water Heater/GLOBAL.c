
#include "GLOBAL.h"

// Definition of global variables
volatile u8 SET_TEMP_UP = 0;
volatile u8 SET_TEMP_DOWN = 0;
volatile u8 CURRENT_TEMP=88;
volatile u8 SET_TEMP=60;
volatile u32 SS_EXIT_COUNTER=0;
volatile u32 TEMP_SENSE_COUNTER=0;
volatile u8 ON_OFF=0;
volatile u8  CHANGE_IN_POWER_STATE_FLAG=0;

volatile u8 Reading_Counter=0;
volatile u32 Readings_Sum=0;
volatile u8 AVG_TEMP=0;
volatile u8 Heater_Led_Flag=0;
volatile u32 Heater_Blink_Counter=0;
volatile u8 Heater_OnOff_switch=0;
