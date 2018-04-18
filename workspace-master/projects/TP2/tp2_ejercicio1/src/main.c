/* Copyright 2016
 * All rights reserved.
 *
 * This file is part of lpc1769_template.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.*/


/*==================[inclusions]=============================================*/

#include "../../tp2_ejercicio1/inc/main.h"

#include "../../tp2_ejercicio1/inc/FreeRTOSConfig.h"
#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/


/*==================[internal functions declaration]=========================*/


static void initHardware(void);

/*==================[internal data definition]===============================*/

#define REFRESH_RATE_ms 500
#define TIEMPO_DE_DIAGNOSTICO_ms 2000

#define MASK_REDLIGHT	1
#define MASK_GREENLIGHT	2
#define MASK_BLUELIGHT	4

unsigned int tiempo_de_diagnostico = TIEMPO_DE_DIAGNOSTICO_ms;

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

static void initHardware(void)
{
	SystemCoreClockUpdate();

	    Board_Init();
	   // Chip_GPIO_SetPinDirOutput(LPC_GPIO, num_puerto, num_pin);
	   // Chip_GPIO_SetPinDirInput(LPC_GPIO, num_puerto, num_pin);
	   // Chip_GPIO_GetPinState(LPC_GPIO, num_puerto, num_pin);
	    Chip_IOCON_PinMuxSet(LPC_IOCON,0,26,FUNC0);
	    Chip_IOCON_PinMuxSet(LPC_IOCON,2,0,FUNC0);
	    Chip_IOCON_PinMuxSet(LPC_IOCON,2,1,FUNC0);

	    Chip_GPIO_SetPinDIROutput(LPC_GPIO,0,26); //Azul
	    Chip_GPIO_SetPinDIROutput(LPC_GPIO,2,0); // Rojo
	    Chip_GPIO_SetPinDIROutput(LPC_GPIO,2,1); // Verde


}

void JuegoDeLuces(void *pvParameters)
{
	unsigned int estado_de_salidas = 1; //random

	portTickType xMeDesperte;
	xMeDesperte = xTaskGetTickCount();

	//Loop infinito
	while(1)
	{
		estado_de_salidas++;
		if(estado_de_salidas == 8)
		{
			estado_de_salidas = 0x1;
		}

		//Red activity
		if (estado_de_salidas&MASK_REDLIGHT)
			 // Chip_GPIO_SetPinOutLow(LPC_GPIO, num_puerto, num_pin);
			Chip_GPIO_SetPinOutLow(LPC_GPIO,2,0);

		else
			 // Chip_GPIO_SetPinOutHigh(LPC_GPIO, num_puerto, num_pin);
			 Chip_GPIO_SetPinOutHigh(LPC_GPIO,2,0);

		//Green activity
		if (estado_de_salidas&MASK_GREENLIGHT)

			Chip_GPIO_SetPinOutLow(LPC_GPIO,2,1);

		else
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,2,1);

		//Blue activity
		if (estado_de_salidas&MASK_BLUELIGHT)
			Chip_GPIO_SetPinOutLow(LPC_GPIO,0,26);

		else
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,0,26);


		//Con el delay de la tarea, la suspendo hasta finalizar el tiempo
		vTaskDelayUntil(&xMeDesperte,REFRESH_RATE_ms/portTICK_RATE_MS);

	}

}

void Diagnostico(void *pvParameters)
{

	// vPrintString("Comienza el diagnostico\n");
	//Loop infinito
	while(1)
	{
		//IMPORTANTE:
		//Este loop pretende simular un conjunto de funciones que
		//insumen un tiempo para realizar el diagnostico del equipo
		//Pero NO es aceptable tener al micro dentro de esta tarea
		//haciendo nada, esto es solo un ejemplo.
		if(!tiempo_de_diagnostico)
		{
			//vPrintString("Termina el diagnostico\n");
			Board_LED_Set(0, 1);
			vTaskDelay(TIEMPO_DE_DIAGNOSTICO_ms/portTICK_RATE_MS);
			tiempo_de_diagnostico = TIEMPO_DE_DIAGNOSTICO_ms;
			Board_LED_Set(0, 0);
			//vPrintString("Comienza el diagnostico\n");
		}

	}

}

int main(void) {

	// TODO: insert code here

	//Incialización del Hardware
	initHardware();

	//Trace del RTOS
	//traceSTART();
	//
	//Creación de las tareas
	// xTaskCreate( pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask )
	xTaskCreate(	JuegoDeLuces, (signed portCHAR* )
					"Luces",
					configMINIMAL_STACK_SIZE,
					NULL,
					tskIDLE_PRIORITY+2,
					NULL );

	xTaskCreate(	Diagnostico, ( signed portCHAR* )
					"Diag",
					configMINIMAL_STACK_SIZE,
					NULL,
					tskIDLE_PRIORITY+1,
					NULL );

	//Inicio el Scheduler
	vTaskStartScheduler();

	// Enter an infinite loop, just incrementing a counter
	volatile static int i = 0 ;
	while(1) {
		i++ ;
	}
	return 0 ;
}

void vApplicationTickHook ( void )
{
	if(tiempo_de_diagnostico)
		tiempo_de_diagnostico--;
}


void vApplicationIdleHook ( void )
{
	__ASM volatile ("wfi");
}

