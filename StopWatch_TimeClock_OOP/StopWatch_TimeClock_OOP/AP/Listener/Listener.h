#ifndef LISTENER_H_
#define LISTENER_H_
#include <avr/io.h>
#include "../Model/Model_StopWatchState.h"
#include "../../Driver/Button/Button.h"
#include "../Model/Model_TimeModeState.h"
#include "../Model/Model_TimeClockDispState.h"



void Listener_init();
void Listener_checkEvent();
void Listener_stopWatchEvent();

#endif /* LISTENER_H_ */