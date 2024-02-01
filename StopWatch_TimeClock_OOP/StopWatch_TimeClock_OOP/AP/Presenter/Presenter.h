#ifndef PRESENTER_H_
#define PRESENTER_H_
#include <avr/io.h>
#include <stdio.h>
#include "../../Driver/FND/FND.h"
#include "../../Driver/LCD/LCD.h"
#include "../Model/Model_TimeClockDispState.h"

void Presenter_init();
void Presenter_dispStopWatchData(uint8_t hour, uint8_t min, uint8_t sec, uint16_t milisec);
void Presenter_dispTimeClockData(uint8_t hour, uint8_t min, uint8_t sec, uint16_t milisec);

#endif 