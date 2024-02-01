#include "Presenter.h"

void Presenter_init()
{
	LCD_init();
	FND_init();
}

void Presenter_dispStopWatchData(uint8_t hour, uint8_t min, uint8_t sec, uint16_t milisec)
{
	uint16_t stopWatchData;
	char buff[30];
	static uint8_t prevSec = 0xff;
	
	if(sec != prevSec)
	{
		prevSec = sec;
		sprintf(buff, "StopWatch");
		LCD_writeStringXY(0, 2, buff);
		sprintf(buff, "%02d : %02d : %02d : %02d", hour, min, sec, milisec/10);
		LCD_writeStringXY(1, 0, buff);
	}
	
	stopWatchData = (min%10 * 1000) + (sec * 10) + (milisec / 100 % 10);
	FND_setFndData(stopWatchData);
	
	
}

void Presenter_dispTimeClockData(uint8_t hour, uint8_t min, uint8_t sec, uint16_t milisec)
{
	uint16_t tiemClockData;
	uint8_t timeClockDispState;
	char buff[30];
	static uint8_t prevSec = 0xff;
	
	if(sec != prevSec)
	{
		prevSec = sec;
		sprintf(buff, "TimeClock");
		LCD_writeStringXY(0, 2, buff);
		sprintf(buff, "%02d : %02d : %02d : %02d", hour, min, sec, milisec/10);
		LCD_writeStringXY(1, 0, buff);
	}
	
	timeClockDispState = Model_getTimeClockDispStateData();
	
	switch(timeClockDispState)
	{
		case HOUR_MIN:
		tiemClockData = hour*100 + min;
		FND_setFndData(tiemClockData);
		break;
		case SEC_MIL:
		tiemClockData = sec*100 + milisec/10;
		FND_setFndData(tiemClockData);
		break;
	}
	if ((milisec/10)<50)
	{
		FND_colonOn();
	}
	else
	{
		FND_colonOff();
	}
}