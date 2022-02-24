#include "RELAY.h"
#include "RELAY_CFG.h"

void RELAY_INIT(u8 relay)
{
	switch(relay)
	{
		case 1:
			PIN_MODE(relay_1_pin, OUTPUT);
		break;
		
		case 2:
			PIN_MODE(relay_2_pin, OUTPUT);
		break;
	}
}
void RELAY_ON(u8 relay)
{
	switch(relay)
	{
		case 1:
		PIN_WRITE(relay_1_pin, HIGH);
		break;
		
		case 2:
		PIN_WRITE(relay_2_pin, HIGH);
		break;
	}
}
void RELAY_OFF(u8 relay)
{
	switch(relay)
	{
		case 1:
		PIN_WRITE(relay_1_pin, LOW);
		break;
		
		case 2:
		PIN_WRITE(relay_2_pin, LOW);
		break;
	}
}

void RELAY_TOG(u8 relay)
{
	switch(relay)
	{
		case 1:
		PIN_TOG(relay_1_pin);
		break;
		
		case 2:
		PIN_TOG(relay_2_pin);
		break;
	}
}