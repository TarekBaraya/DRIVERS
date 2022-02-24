#ifndef SSD_H_
#define SSD_H_

#include "STD_TYPES.h"
#include "SSD_CFG.h"
#include "DIO.h"

void SSD_INIT(void); 
void SSD_DISPLAY(u8);
void SSD_COUNT_DOWN(u8);
void SSD_COUNT_UP(u8);
void SSD_DISPLAY_BLINK(u8);
void SSD_DISPLAY_DIGIT(u8, u8);

#endif /* SSD_H_ */