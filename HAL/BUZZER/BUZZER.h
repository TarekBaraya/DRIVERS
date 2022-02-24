#ifndef BUZZER_H_
#define BUZZER_H_

#define F_CPU 16000000UL
#include <util/delay.h>

void BUZZER_ON(void);
void BUZZER_OFF(void);
void BUZZER_TOG(void);
void BUZZER_INIT(void);
void BUZZER_ONE(void);
void BUZZER_TWO(void);
void BUZZER_THREE(void);



#endif /* BUZZER_H_ */