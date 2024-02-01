#ifndef SERVICE_TIMECLOCK_H_
#define SERVICE_TIMECLOCK_H_
#include <avr/io.h>
#include "../Model/Model_TimeModeState.h"
#include "../Presenter/Presenter.h"
	
void TimeClock_init();
void TimeClock_incMilisec();
uint16_t TimeClock_run();

#endif /* SERVICE_TIMECLOCK_H_ */