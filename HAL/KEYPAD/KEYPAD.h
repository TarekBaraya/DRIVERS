#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STD_TYPES.h"

#define PRESSED		0
#define RELEASED	1

void KEYPAD_INIT(void);
u8 KEYPAD_READ(void);

#endif /* KEYPAD_H_ */