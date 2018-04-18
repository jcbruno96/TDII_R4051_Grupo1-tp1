#include "main.h"
#include "board.h"

void initHardware(void)
{
	Board_Init();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);
}


void SysTick_Handler(void)
{
	static int espera = DELAY_MS;
	int i;
	if(!--espera)
	{
		espera = DELAY_MS;
		for(i=2;i<6;i++) Board_LED_Toggle(i);
	}
}

int main(void)
{
	initHardware();

	while (1)
	{
	}
}
