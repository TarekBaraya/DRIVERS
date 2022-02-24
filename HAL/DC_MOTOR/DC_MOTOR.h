/*
 * DC_MOTOR.h
 *
 * Created: 21/02/2022 08:09:05 م
 *  Author: User
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_


void DC_MOTOR_INIT(void);
void DC_MOTOR_START(void);
void DC_MOTOR_STOP(void);
void DC_MOTOR_SET_SPEED(u8);
void DC_MOTOR_SET_DIR(u8);

#define CLK		0
#define ACLK	1

#endif /* DC_MOTOR_H_ */