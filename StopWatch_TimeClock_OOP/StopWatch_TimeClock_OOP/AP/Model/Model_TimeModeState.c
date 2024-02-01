#include "Model_TimeModeState.h"

uint8_t timeModeStateData;

uint8_t Model_getTimeModeStateData()
{
	return timeModeStateData;
}

void Model_setTimeModeStateData(uint8_t state)
{
	timeModeStateData = state;
}