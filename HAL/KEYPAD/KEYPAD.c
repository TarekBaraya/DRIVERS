#include "STD_TYPES.h"
#include "KEYPAD.h"
#include "KEYPAD_CFG.h"
#include "DIO.h"

#define F_CPU 16000000UL
#include <util/delay.h>

u8 arr [4][4] = {{ '1' ,'2' , '3' , '+' },
				 { '4' ,'5' , '6' , '-' },
				 { '7' ,'8' , '9' , '*' },
				 { '=' ,'0' , '#' , '/' }};

void KEYPAD_INIT(void)
{
	PIN_MODE(KEYPAD_R0,OUTPUT);
	PIN_MODE(KEYPAD_R1,OUTPUT);
	PIN_MODE(KEYPAD_R2,OUTPUT);
	PIN_MODE(KEYPAD_R3,OUTPUT);
	
	PIN_WRITE(KEYPAD_R0,HIGH);
	PIN_WRITE(KEYPAD_R1,HIGH);
	PIN_WRITE(KEYPAD_R2,HIGH);
	PIN_WRITE(KEYPAD_R3,HIGH);
	
	PIN_MODE(KEYPAD_C0,INPUT);
	PIN_MODE(KEYPAD_C1,INPUT);
	PIN_MODE(KEYPAD_C2,INPUT);
	PIN_MODE(KEYPAD_C3,INPUT);

}
u8 KEYPAD_READ(void)
{
	u8 reading = 0;
	u8 r = 0;
	u8 c = 0;
	u8 value = RELEASED;
	for (r=KEYPAD_R0;r<=KEYPAD_R3;r++)
	{
		PIN_WRITE(r,LOW);
		for (c=KEYPAD_C0;c<=KEYPAD_C3;c++)
		{
			value = PIN_READ(c);
			if(value == PRESSED)
			{
				_delay_ms(120);
				value = PIN_READ(c);
				if (value == PRESSED)
				{
					while(PIN_READ(c) == PRESSED);
					reading =  arr[r - KEYPAD_R0][c - KEYPAD_C0];
				}
			}
		}
		PIN_WRITE(r,HIGH);
	}
	return reading;
}

