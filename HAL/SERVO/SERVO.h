#ifndef SERVO_H_
#define SERVO_H_

void SERVO_INIT(void);
void SERVO_SET_FREQ(u8);
void SERVO_SET_ANGLE(u32);
void SERVO_START(void);
void SERVO_STOP(void);

#endif /* SERVO_H_ */