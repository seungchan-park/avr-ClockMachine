#ifndef MODEL_TIMEMODESTATE_H_
#define MODEL_TIMEMODESTATE_H_
#include "avr/io.h"

enum{TIMECLOCK, STOPWATCH};
	
uint8_t Model_getTimeModeStateData();
void Model_setTimeModeStateData(uint8_t state);

#endif /* MODEL_TIMECLOCKSTATE_H_ */