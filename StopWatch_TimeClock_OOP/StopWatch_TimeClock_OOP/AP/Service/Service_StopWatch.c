#include "Service_StopWatch.h"

static uint16_t milisec;
static uint8_t sec;
static uint8_t min;
static uint8_t hour;

void StopWatch_init()
{
	milisec = 0;
	sec = 0;
	min = 0;
	hour = 0;
}

void StopWatch_incMilisec()
{
	uint8_t stopWatchState;
	stopWatchState = Model_getStopWatchStateData();
	
	if (stopWatchState == RUN)
	{
		milisec = (milisec + 1) % 1000;
	}
	else return;
	
	if (milisec) return;
	
	sec = (sec + 1) % 60;
	if (sec) return;
	
	min = (min + 1) % 60;
	if (min) return;
	
	hour = (hour + 1) % 24;
}

void StopWatch_run()
{
	uint8_t stopWatchState;
	stopWatchState = Model_getStopWatchStateData();
	
	uint8_t TimeModeState;
	TimeModeState = Model_getTimeModeStateData();
	
	if (TimeModeState != STOPWATCH) return;
	
	if (stopWatchState == RESET)
	{
		milisec = 0;
		sec = 0;
		min = 0;
		hour = 0;
	}
	
	Presenter_dispStopWatchData(hour, min, sec, milisec);
}