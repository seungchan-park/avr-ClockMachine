#include "Listener.h"

button_t btnRunStop, btnReset, btnMode, btnDispMode;

void Listener_init()
{
	Button_init(&btnRunStop, &DDRA, &PINA, 0);
	Button_init(&btnReset, &DDRA, &PINA, 1);
	Button_init(&btnMode, &DDRA, &PINA, 2);
	Button_init(&btnDispMode, &DDRA, &PINA, 3);
}

void Listener_checkEvent()
{
	uint8_t timeModeState = Model_getTimeModeStateData();
	switch(timeModeState)
	{
		case TIMECLOCK:
		Listener_timeClockEvent();
		if (Button_getState(&btnMode) == ACT_RELEASED)
		{
			timeModeState = STOPWATCH;
			Model_setTimeModeStateData(timeModeState);
		}
		break;
		case STOPWATCH:
		Listener_stopWatchEvent();
		if (Button_getState(&btnMode) == ACT_RELEASED)
		{
			timeModeState = TIMECLOCK;
			Model_setTimeModeStateData(timeModeState);
		}
		break;
	}
	Listener_stopWatchEvent();
}

void Listener_stopWatchEvent()
{
	uint8_t stopWatchState;
	stopWatchState = Model_getStopWatchStateData();
	
	switch(stopWatchState) // event 처리
	{
		case STOP:
		if (Button_getState(&btnRunStop)==ACT_RELEASED)
		{
			stopWatchState = RUN;
			Model_setStopWatchStateData(stopWatchState);
		}
		else if (Button_getState(&btnReset)==ACT_RELEASED)
		{
			stopWatchState = RESET;
			Model_setStopWatchStateData(stopWatchState);
		}
		break;
		
		case RUN:
		if (Button_getState(&btnRunStop)==ACT_RELEASED)
		{
			stopWatchState = STOP;
			Model_setStopWatchStateData(stopWatchState);
		}
		break;
		
		case RESET:
		stopWatchState = STOP;
		Model_setStopWatchStateData(stopWatchState);
		break;
	}
	
}

void Listener_timeClockEvent()
{
	uint8_t timeClockState;
	timeClockState = Model_getTimeClockDispStateData();
	
	switch(timeClockState) // event 처리
	{
		case HOUR_MIN:
		if (Button_getState(&btnDispMode)==ACT_RELEASED)
		{
			timeClockState = SEC_MIL;
			Model_setTimeClockDispStateData(timeClockState);
		}
		break;
		
		case SEC_MIL:
		if (Button_getState(&btnDispMode)==ACT_RELEASED)
		{
			timeClockState = HOUR_MIN;
			Model_setTimeClockDispStateData(timeClockState);
		}
		break;
	}
}