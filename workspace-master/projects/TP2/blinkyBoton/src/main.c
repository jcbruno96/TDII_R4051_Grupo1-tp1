#include "main.h"
#include "board.h"
#include "../inc/pulsadores.h"
#include "../inc/TimerTicks.h"
#include "Blinkyboton.h"
#include "BlinkybotonRequired.h"
#define NTIMERS	4

Blinkyboton statechart;
TimerTicks timers[NTIMERS];
volatile bool SysTickFlag;

static void initHardware(void)
{
	Board_Init();
	InitPulsadores();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);
}


void blinkybotonIface_opSetearLed(const Blinkyboton* handle, const sc_boolean estado)
{
	Board_LED_Set(0,estado);
}

void blinkyboton_setTimer(Blinkyboton* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic)
{
	SetNewTimerTick(timers,NTIMERS,evid,time_ms,periodic);
}

void blinkyboton_unsetTimer(Blinkyboton* handle, const sc_eventid evid)
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
	blinkyboton_init(&statechart);
	blinkyboton_enter(&statechart);
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
					blinkyboton_raiseTimeEvent(&statechart,timers[i].evid);
					MarkAsAttEvent(timers,NTIMERS,timers[i].evid);
				}
			}
			blinkybotonIface_set_boton(&statechart,!LeerPulsador(0));
			blinkyboton_runCycle(&statechart);
		}
	}
}
