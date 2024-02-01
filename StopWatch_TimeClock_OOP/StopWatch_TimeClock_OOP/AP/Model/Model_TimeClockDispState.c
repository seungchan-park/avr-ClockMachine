#include "Model_TimeClockDispState.h"

uint8_t timeClockDispState;

uint8_t Model_getTimeClockDispStateData()
{
	return timeClockDispState;
}

void Model_setTimeClockDispStateData(uint8_t state)
{
	timeClockDispState = state;
}