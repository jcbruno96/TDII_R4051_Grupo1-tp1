#include "main.h"
#include "board.h"
#include "../inc/pulsadores.h"
#include "../inc/TimerTicks.h"
#include "Blinkyfsm.h"
#include "BlinkyfsmRequired.h"
#define NTIMERS	1

Blinkyfsm statechart;
TimerTicks timers[NTIMERS];
volatile bool SysTickFlag;

static void initHardware(void)
{
	Board_Init();
	InitPulsadores();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);
}


void blinkyfsmIface_opSetearLed(const Blinkyfsm* handle, const sc_boolean estado)
{
	Board_LED_Set(0,estado);
}

void blinkyfsm_setTimer(Blinkyfsm* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic)
{
	SetNewTimerTick(timers,NTIMERS,evid,time_ms,periodic);
}

void blinkyfsm_unsetTimer(Blinkyfsm* handle, const sc_eventid evid)
{
	UnsetTimerTick(timers,NTIMERS,evid);
}


void SysTick_Handler(void)
{
	SysTickFlag = true;
}



int main(void)
{
	int i;
	SysTickFlag = false;
	InitTimerTicks(timers,NTIMERS);
	blinkyfsm_init(&statechart);
	blinkyfsm_enter(&statechart);
	initHardware();

	while (1)
	{
		if(SysTickFlag)
		{
			SysTickFlag = false;
			UpdateTimers(timers,NTIMERS);
			for(i=0; i<NTIMERS; i++)
			{
				if(IsPendEvent(timers,NTIMERS,timers[i].evid))
				{
					blinkyfsm_raiseTimeEvent(&statechart,timers[i].evid);
					MarkAsAttEvent(timers,NTIMERS,timers[i].evid);
				}
			}
			blinkyfsm_runCycle(&statechart);
		}
	}
}
