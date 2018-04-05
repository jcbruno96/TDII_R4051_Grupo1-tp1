/* Copyright 2016, Pablo Ridolfi
 * All rights reserved.
 *
 * This file is part of Workspace.
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
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
 
#ifndef CIAAIO_H_
#define CIAAIO_H_

#include "chip.h"

#define ciaaDigitalInputs() ((uint8_t)((Chip_GPIO_ReadValue(LPC_GPIO_PORT,3) & (0x0F<<11))>>7)|(Chip_GPIO_ReadValue(LPC_GPIO_PORT,2) & 0x0F))

typedef struct
{
	int port;
	int bit;
}ciaaPin_t;

typedef enum
{
	TEC1,
	TEC2,
	TEC3,
	TEC4
}edu_ciaa_nxp_tec_e;

typedef enum
{
	LEDR,
	LEDG,
	LEDB,
	LED1,
	LED2,
	LED3
}edu_ciaa_nxp_led_e;

void ciaaIOInit(void);
uint32_t ciaaWriteOutput(uint32_t outputNumber, uint32_t value);
uint32_t ciaaReadInput(uint32_t inputNumber);
uint32_t ciaaReadOutput(uint32_t outputNumber);
void ciaaToggleOutput(uint32_t outputNumber);

#endif /* CIAAIO_H_ */
