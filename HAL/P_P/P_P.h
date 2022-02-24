﻿#ifndef P_P_H_
#define P_P_H_

#include "STD_TYPES.h"

void P_P_INIT(u8);
u8 P_P_READ(u8);

#define P_B_1		1
#define P_B_2		2
#define P_B_3		3
#define P_B_4		4

#define PRESSED		0
#define RELEASED	1

#define P_B_COMMON_GND		PB7
#define P_B_1_PIN			PD2
#define P_B_2_PIN			PD3
#define P_B_3_PIN			PD4
#define P_B_4_PIN			PD5

#endif /* P_P_H_ */