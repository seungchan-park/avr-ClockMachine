#include "Service_TimeClock.h"

static uint16_t milisec;
static uint8_t sec;
static uint8_t min;
static uint8_t hour;

void TimeClock_init()
{
	milisec = 0;
	sec = 10;
	min = 39;
	hour =3;
}

void TimeClock_incMilisec()
{
	milisec = (milisec + 1) % 1000; // 1ms마다 milisec증가 범위: 0 ~ 999
	
	if (milisec) return; // milisec이 0이면 999까지 돌고 1000이 된것이므로 (거짓)
	
	sec = (sec + 1) % 60;
	if (sec) return;
	
	min = (min + 1) % 60;
	if (min) return;
	
	hour = (hour + 1) % 24;
}

uint16_t TimeClock_run()
{
	uint8_t TimeModeState;
	TimeModeState = Model_getTimeModeStateData();
	
	if (TimeModeState != TIMECLOCK) return;
	
	Presenter_dispTimeClockData(hour, min, sec, milisec);
}