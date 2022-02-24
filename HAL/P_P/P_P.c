#include "STD_TYPES.h"
#include "P_P.h"
#include "DIO.h"
#include "P_P_CFG.h"

void P_P_INIT(u8 p_b)
{
	PIN_MODE(P_B_COMMON_GND,OUTPUT);
	PIN_WRITE(P_B_COMMON_GND,LOW);
	
	switch(p_b)
	{
		case P_B_1:
			PIN_MODE(P_B_1_PIN,INPUT); 
			PIN_PULL_UP(P_B_1_PIN, ENABLE);
		break;
		
		case P_B_2:
			PIN_MODE(P_B_2_PIN,INPUT);
			PIN_PULL_UP(P_B_2_PIN, ENABLE);
		break;
		
		case P_B_3:
			PIN_MODE(P_B_3_PIN,INPUT);
			PIN_PULL_UP(P_B_3_PIN, ENABLE);
		break;
		
		case P_B_4:
			PIN_MODE(P_B_4_PIN,INPUT);
			PIN_PULL_UP(P_B_4_PIN, ENABLE);
		break;
		
		default:
		break;
	}
}
u8 P_P_READ(u8 p_b)
{
	u8 value = 0; 
	switch(p_b)
	{
		case P_B_1:
			value = PIN_READ(P_B_1_PIN);
		break;
		
		case P_B_2:
			value = PIN_READ(P_B_2_PIN);
		break;
		
		case P_B_3:
			value = PIN_READ(P_B_3_PIN);
		break;
		
		case P_B_4:
			value = PIN_READ(P_B_4_PIN);
		break;
		
		default:
		break;
	}
	return value;
}
