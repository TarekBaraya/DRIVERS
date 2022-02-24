#include "STD_TYPES.h"
#include "LM35.h"
#include "ADC.h"

void LM35_INIT()
{
	ADC_INIT();
}
u16 LM35_READ()
{
	u16 reading = ADC_READ();
	
	return reading/2.046;
}
