#include "BUZZER.h"
#include "BUZZER_CFG.h"
#include "DIO.h"
void BUZZER_ON(void)
{
	PIN_WRITE(BUZZER_PIN, HIGH);
}
void BUZZER_OFF(void)
{
	PIN_WRITE(BUZZER_PIN, LOW);
}
void BUZZER_TOG(void)
{
	PIN_TOG(BUZZER_PIN);
}
void BUZZER_INIT(void)
{
	PIN_MODE(BUZZER_PIN,OUTPUT);
}
void BUZZER_ONE(void)
{
	BUZZER_ON();
	_delay_ms(100);
	BUZZER_OFF();
}
void BUZZER_TWO(void)
{
	BUZZER_ON();
	_delay_ms(100);
	BUZZER_OFF();
	_delay_ms(100);
	BUZZER_ON();
	_delay_ms(100);
	BUZZER_OFF();
}
void BUZZER_THREE(void)
{
	BUZZER_ON();
	_delay_ms(100);
	BUZZER_OFF();
	_delay_ms(100);
	
	BUZZER_ON();
	_delay_ms(100);
	BUZZER_OFF();
	_delay_ms(100);
	
	BUZZER_ON();
	_delay_ms(100);
	BUZZER_OFF();
	_delay_ms(100);
}
void BUZZER_LONG(void)
{
	BUZZER_ON();
	_delay_ms(2000);
	BUZZER_OFF();
}