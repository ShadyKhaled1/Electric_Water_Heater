#ifndef _EEPROM_H_
#define _EEPROM_H_


void eepromWrite(unsigned int addr,unsigned char dat);
unsigned char eepromRead(unsigned int addr);


#endif
