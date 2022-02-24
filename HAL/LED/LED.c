#include "DIO.h"
//#include "BIT_math.h"
#include "REG.h"
#include "LED.h"
#include "STD_TYPES.h"
#include "LED_CFG.h"

void LED_ON(u8 led)
{
		switch(led)
		{
			case B_LED:
			PIN_WRITE(B_LED_PIN, HIGH);
			break;
			
			case G_LED:
			PIN_WRITE(G_LED_PIN, HIGH);
			break;
			
			case R_LED:
			PIN_WRITE(R_LED_PIN, HIGH);
			
			break;
		}
}
void LED_OFF(u8 led)
{
	switch(led)
	{
		case B_LED:
		PIN_WRITE(B_LED_PIN, LOW);
		break;
		
		case G_LED:
		PIN_WRITE(G_LED_PIN, LOW);
		break;
		
		case R_LED:
		PIN_WRITE(R_LED_PIN, LOW);
		
		break;
	}
}
void LED_INIT(u8 led)
{
	switch(led)
	{
		case B_LED:
		PIN_MODE(B_LED_PIN, OUTPUT);
		break;
		
		case G_LED:
		PIN_MODE(G_LED_PIN, OUTPUT);
		break;
		
		case R_LED:
		PIN_MODE(R_LED_PIN, OUTPUT);
		break;
	}
}

void LED_TOG(u8 led)
{
		switch(led)
		{
			case B_LED:
			PIN_TOG(B_LED_PIN);
			break;
			
			case G_LED:
			PIN_TOG(G_LED_PIN);
			break;
			
			case R_LED:
			PIN_TOG(R_LED_PIN);
			break;
		}
}