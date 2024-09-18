

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "SS_Interface.h"
#include "DIO_Register.h"
#include "DIO_Interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>



// Seven Segment Initialization

void SS_Init(){
		//SEVEN SEGMENT 
		DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
		DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
		DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
		DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
		
		//SEVEN SEGMENT Transistors 
		
		DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
		DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_OUTPUT);
}
// Function to display a number on a single 7-segment display
void SS_DISPLAY(u8 number){
	ASSIGN_BIT(PORTA, 4, GET_BIT(number, 0));
	ASSIGN_BIT(PORTA, 5, GET_BIT(number, 1));
	ASSIGN_BIT(PORTA, 6, GET_BIT(number, 2));
	ASSIGN_BIT(PORTA, 7, GET_BIT(number, 3));
}

// Function to select which 7-segment display is active
void SS_SELECTED_DISPLAY(u8 display){
	DIO_u8SetPinValue(DIO_PORTB, DIO_PIN1, DIO_PIN_LOW);   // Turn off both displays
	DIO_u8SetPinValue(DIO_PORTB, DIO_PIN0, DIO_PIN_LOW);   // Turn off both displays
	
	if (display == 1) {
		DIO_u8SetPinValue(DIO_PORTB, DIO_PIN1, DIO_PIN_HIGH);  // Enable display 1 (e.g., PB1)
	}
	else if (display == 2) {
		DIO_u8SetPinValue(DIO_PORTB, DIO_PIN0, DIO_PIN_HIGH);  // Enable display 2 (e.g., PB2)
	}
}

// Function to display two digits on two 7-segment displays using multiplexing
void SS_DOUBLE_DIGIT_DISPLAY(u8 number){
	u8 units = number % 10;  // Extract the units digit
	u8 tens = number / 10;   // Extract the tens digit
	
	for (u8 count = 0; count < 20; count++) {   // Loop to refresh the display
		SS_SELECTED_DISPLAY(1);   // Select first 7-segment display
		SS_DISPLAY(units);        // Display the units digit
		_delay_ms(10);             // Small delay for multiplexing
		
		SS_SELECTED_DISPLAY(2);   // Select second 7-segment display
		SS_DISPLAY(tens);         // Display the tens digit
		_delay_ms(10);             // Small delay for multiplexing

	DIO_u8SetPinValue(DIO_PORTB, DIO_PIN1, DIO_PIN_LOW);   // Turn off both displays
	DIO_u8SetPinValue(DIO_PORTB, DIO_PIN0, DIO_PIN_LOW);   // Turn off both displays
	}
}

void SS_ONE_SEC_BLINK (){
	DIO_u8SetPinValue(DIO_PORTB, DIO_PIN0, DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB, DIO_PIN1, DIO_PIN_LOW);
	_delay_ms(1000);
}

void SS_OUT(u8 number){
	if (number > 9) {
		SS_DOUBLE_DIGIT_DISPLAY(number);  // Display two digits for numbers greater than 9
	}
	else {
		SS_SELECTED_DISPLAY(1);           // Select first display
		SS_DISPLAY(number);               // Display single digit for numbers 0 to 9
	}
}




