#ifndef HMODEL_STOPWATCHSTATE_H_
#define HMODEL_STOPWATCHSTATE_H_
#include <avr/io.h>

enum{STOP, RUN, RESET};

uint8_t Model_getStopWatchStateData();
void Model_setStopWatchStateData(uint8_t state);

#endif 