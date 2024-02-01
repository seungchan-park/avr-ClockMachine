#ifndef SERVICE_STOPWATCH_H_
#define SERVICE_STOPWATCH_H_
#include <avr/io.h>
#include "../Model/Model_StopWatchState.h"
#include "../Presenter/Presenter.h"
#include "../Model/Model_TimeModeState.h"

void StopWatch_init();
void StopWatch_incMilisec();
void StopWatch_run();

#endif 