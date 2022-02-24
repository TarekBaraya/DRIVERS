#include "TIMER1.h"
#include "TIMER1_CFG.h"
#include "SERVO.h"
#include "SERVO_CFG.h"
#include "STD_TYPES.h"
void SERVO_INIT(void)
{
	PWM_1_INIT();
	PWM_1_SET_FREQ(SERVO_FREQ);
}
void SERVO_SET_ANGLE(u32 angle)
{
	PWM_1_SET_DUTY_CYCLE(((angle * 5) / SERVO_MAX_ANGLE) + 5);
}
void SERVO_START(void)
{
	PWM_1_START();
}
void SERVO_STOP(void)
{
	PWM_1_STOP();
}