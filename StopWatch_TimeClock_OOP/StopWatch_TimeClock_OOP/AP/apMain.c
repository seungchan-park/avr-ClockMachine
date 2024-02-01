#include "apMain.h"

ISR(TIMER0_OVF_vect) // overflow interrupt 조건
{
	FND_ISR_Process();
	TCNT0 = 130; // 1ms 주기마다 발생하도록 하는 조건
}

ISR(TIMER2_COMP_vect) // CTC interrupt
{
	StopWatch_incMilisec();
	TimeClock_incMilisec();
}

void apMain_init()
{
	Listener_init();
	Presenter_init();
	StopWatch_init();
	TimeClock_init();
	
	TIM0_init();
	TIM2_init();
	sei();
	
	Model_setStopWatchStateData(STOP);
	Model_setTimeModeStateData(TIMECLOCK);
	Model_setTimeClockDispStateData(HOUR_MIN);
}

void apMain_excute()
{
	Listener_checkEvent();
	StopWatch_run();
	TimeClock_run();
}