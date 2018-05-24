#include "Aplicacion.h"


void vTask_FSM(void * a)
{
	Molinete fsm;
	molinete_init(&fsm);
	molinete_enter(&fsm);

	while (1)
	{
		molinete_runCycle(&fsm);
		vTaskDelay(1 / portTICK_RATE_MS);
	}
}

int main(void)
{
	init_hardware();
	xTaskCreate(vTask_FSM, (const char *)"Task_FSM", configMINIMAL_STACK_SIZE*4, 0, tskIDLE_PRIORITY+1, 0);
	vTaskStartScheduler();
	for(;;);
}
