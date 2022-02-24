#ifndef RELAY_H_
#define RELAY_H_

#include "RELAY.h"
#include "RELAY_CFG.h"
#include "DIO.h"
#include "STD_TYPES.h"

void RELAY_INIT(u8);
void RELAY_ON(u8);
void RELAY_OFF(u8);
void RELAY_TOG(u8);


#endif /* RELAY_H_ */