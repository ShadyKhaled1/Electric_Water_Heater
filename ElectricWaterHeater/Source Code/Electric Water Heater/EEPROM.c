#include "EEPROM.h"
/*
Bit 3 – EERIE: EEPROM Ready Interrupt Enable
Bit 2 – EEMWE: EEPROM Master Write Enable
Bit 1 – EEWE: EEPROM Write Enable
Bit 0 – EERE: EEPROM Read Enable*/
#include <avr/io.h>
/*EEPROM Write Function*/
void eepromWrite(unsigned int addr,unsigned char dat){

	while(EECR&(1<<EEWE));
	/*Set up address and data registers*/
	EEAR=addr;
	EEDR=dat;
	/*Write logical 1 to EEMWE*/
	EECR|=(1<<EEMWE);
	/*Start eeprom write by setting EEWE*/
	EECR|=(1<<EEWE);
}

/*EEPROM Read Function*/
unsigned char eepromRead(unsigned int addr){
	/*Wait for completion of previous write*/
	while(EECR&(1<<EEWE));
	/*Set up address register*/
	EEAR=addr;
	/*Start eeprom read by writing EERE*/
	EECR|=(1<<EERE);
	/*Return data from data register*/
	return EEDR;
}