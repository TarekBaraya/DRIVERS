#include "SSD.h"
#include "SSD_CFG.h"

#define F_CPU 16000000UL
#include <util/delay.h>

void SSD_INIT(void)
{
	PIN_MODE(SSD_PIN_A, OUTPUT);
	PIN_MODE(SSD_PIN_B, OUTPUT);
	PIN_MODE(SSD_PIN_C, OUTPUT);
	PIN_MODE(SSD_PIN_D, OUTPUT);
	PIN_MODE(SSD_PIN_E, OUTPUT);
	PIN_MODE(SSD_PIN_F, OUTPUT);
	PIN_MODE(SSD_PIN_G, OUTPUT);
	PIN_MODE(SSD_EN_1,  OUTPUT);
	PIN_MODE(SSD_EN_2,  OUTPUT);
}

void SSD_DISPLAY_DIGIT(u8 number, u8 ssd)
{
	switch(ssd)
	{
		case R_SSD:
			PIN_WRITE(SSD_EN_2, LOW);
			PIN_WRITE(SSD_EN_1, HIGH);
		break;
		
		case L_SSD:
			PIN_WRITE(SSD_EN_1, LOW);
			PIN_WRITE(SSD_EN_2, HIGH);
		break;
		default:
		break;
	}
	switch(number)
	{
		case 0:
		PIN_WRITE(SSD_PIN_A, HIGH);
		PIN_WRITE(SSD_PIN_B, HIGH);
		PIN_WRITE(SSD_PIN_C, HIGH);
		PIN_WRITE(SSD_PIN_D, HIGH);
		PIN_WRITE(SSD_PIN_E, HIGH);
		PIN_WRITE(SSD_PIN_F, HIGH);
		PIN_WRITE(SSD_PIN_G, LOW);
		break;
		
		case 1:
		PIN_WRITE(SSD_PIN_A, LOW);
		PIN_WRITE(SSD_PIN_B, HIGH);
		PIN_WRITE(SSD_PIN_C, HIGH);
		PIN_WRITE(SSD_PIN_D, LOW);
		PIN_WRITE(SSD_PIN_E, LOW);
		PIN_WRITE(SSD_PIN_F, LOW);
		PIN_WRITE(SSD_PIN_G, LOW);
		break;
		
		case 2:
		PIN_WRITE(SSD_PIN_A, HIGH);
		PIN_WRITE(SSD_PIN_B, HIGH);
		PIN_WRITE(SSD_PIN_C, LOW);
		PIN_WRITE(SSD_PIN_D, HIGH);
		PIN_WRITE(SSD_PIN_E, HIGH);
		PIN_WRITE(SSD_PIN_F, LOW);
		PIN_WRITE(SSD_PIN_G, HIGH);
		break;
		
		case 3:
		PIN_WRITE(SSD_PIN_A, HIGH);
		PIN_WRITE(SSD_PIN_B, HIGH);
		PIN_WRITE(SSD_PIN_C, HIGH);
		PIN_WRITE(SSD_PIN_D, HIGH);
		PIN_WRITE(SSD_PIN_E, LOW);
		PIN_WRITE(SSD_PIN_F, LOW);
		PIN_WRITE(SSD_PIN_G, HIGH);
		break;
		
		case 4:
		PIN_WRITE(SSD_PIN_A, LOW);
		PIN_WRITE(SSD_PIN_B, HIGH);
		PIN_WRITE(SSD_PIN_C, HIGH);
		PIN_WRITE(SSD_PIN_D, LOW);
		PIN_WRITE(SSD_PIN_E, LOW);
		PIN_WRITE(SSD_PIN_F, HIGH);
		PIN_WRITE(SSD_PIN_G, HIGH);
		break;
		
		case 5:
		PIN_WRITE(SSD_PIN_A, HIGH);
		PIN_WRITE(SSD_PIN_B, LOW);
		PIN_WRITE(SSD_PIN_C, HIGH);
		PIN_WRITE(SSD_PIN_D, HIGH);
		PIN_WRITE(SSD_PIN_E, LOW);
		PIN_WRITE(SSD_PIN_F, HIGH);
		PIN_WRITE(SSD_PIN_G, HIGH);
		break;
		
		case 6:
		PIN_WRITE(SSD_PIN_A, HIGH);
		PIN_WRITE(SSD_PIN_B, LOW);
		PIN_WRITE(SSD_PIN_C, HIGH);
		PIN_WRITE(SSD_PIN_D, HIGH);
		PIN_WRITE(SSD_PIN_E, HIGH);
		PIN_WRITE(SSD_PIN_F, HIGH);
		PIN_WRITE(SSD_PIN_G, HIGH);
		break;
		
		case 7:
		PIN_WRITE(SSD_PIN_A, HIGH);
		PIN_WRITE(SSD_PIN_B, HIGH);
		PIN_WRITE(SSD_PIN_C, HIGH);
		PIN_WRITE(SSD_PIN_D, LOW);
		PIN_WRITE(SSD_PIN_E, LOW);
		PIN_WRITE(SSD_PIN_F, LOW);
		PIN_WRITE(SSD_PIN_G, LOW);
		break;
		
		case 8:
		PIN_WRITE(SSD_PIN_A, HIGH);
		PIN_WRITE(SSD_PIN_B, HIGH);
		PIN_WRITE(SSD_PIN_C, HIGH);
		PIN_WRITE(SSD_PIN_D, HIGH);
		PIN_WRITE(SSD_PIN_E, HIGH);
		PIN_WRITE(SSD_PIN_F, HIGH);
		PIN_WRITE(SSD_PIN_G, HIGH);
		break;
		
		case 9:
		PIN_WRITE(SSD_PIN_A, HIGH);
		PIN_WRITE(SSD_PIN_B, HIGH);
		PIN_WRITE(SSD_PIN_C, HIGH);
		PIN_WRITE(SSD_PIN_D, HIGH);
		PIN_WRITE(SSD_PIN_E, LOW);
		PIN_WRITE(SSD_PIN_F, HIGH);
		PIN_WRITE(SSD_PIN_G, HIGH);
		break;
		
		default:
		break;
	}
}

void SSD_DISPLAY(u8 full_number)
{
	u8 l_number = full_number / 10;
	u8 r_number = full_number % 10;
	
	SSD_DISPLAY_DIGIT(l_number, L_SSD);
	_delay_ms(5);
	SSD_DISPLAY_DIGIT(r_number, R_SSD);
	_delay_ms(5);
}

void SSD_COUNT_DOWN(u8 full_number)
{
	u8 counter;
	u8 i;
	u8 l_number, r_number;
	for(counter = full_number; counter>=0; counter--)
	{
	l_number = counter / 10;
	r_number = counter % 10;
	for(i=0; i<50; i++)
	{
	SSD_DISPLAY_DIGIT(l_number, L_SSD);
	_delay_ms(5);
	SSD_DISPLAY_DIGIT(r_number, R_SSD);
	_delay_ms(5);
	}
	if(counter == 0)
	{
		break;
	}
	}
}

void SSD_COUNT_UP(u8 full_number)
{
	u8 counter;
	u8 i;
	u8 l_number, r_number;
	for(counter = 0; counter<=full_number; counter++)
	{
		l_number = counter / 10;
		r_number = counter % 10;
		for(i=0; i<50; i++)
		{
			SSD_DISPLAY_DIGIT(l_number, L_SSD);
			_delay_ms(5);
			SSD_DISPLAY_DIGIT(r_number, R_SSD);
			_delay_ms(5);
		}
		if(counter == full_number)
		{
			for(;;)
			{
			l_number = full_number / 10;
			r_number = full_number % 10;
			SSD_DISPLAY_DIGIT(l_number, L_SSD);
			_delay_ms(5);
			SSD_DISPLAY_DIGIT(r_number, R_SSD);
			_delay_ms(5);
			}
		}
	}
}

void SSD_DISPLAY_BLINK(u8 full_number)
{
	u8 l_number = full_number / 10;
	u8 r_number = full_number % 10;
	u8 i;
	for(i=0; i<50; i++)
	{
		SSD_DISPLAY_DIGIT(l_number, L_SSD);
		_delay_ms(5);
		SSD_DISPLAY_DIGIT(r_number, R_SSD);
		_delay_ms(5);
	}
	PIN_WRITE(SSD_EN_1, LOW);
	PIN_WRITE(SSD_EN_2, LOW);
	_delay_ms(500);
}

