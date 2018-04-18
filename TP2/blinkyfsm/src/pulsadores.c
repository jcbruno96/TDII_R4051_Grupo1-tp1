#include "../inc/pulsadores.h"
#include "board.h"

void InitPulsadores(void)
{
	Chip_SCU_PinMux(1, 0, MD_PUP | MD_EZI | MD_ZI, FUNC0); /* GPIO0[4], SW1 *///Azul
	Chip_GPIO_SetPinDIRInput(LPC_GPIO_PORT, 0, 4);
	Chip_SCU_PinMux(1, 1, MD_PUP | MD_EZI | MD_ZI, FUNC0); /* GPIO0[8], SW2*///Amarillo
	Chip_GPIO_SetPinDIRInput(LPC_GPIO_PORT, 0, 8);
	Chip_SCU_PinMux(1, 2, MD_PUP | MD_EZI | MD_ZI, FUNC0); /* GPIO0[9], SW3*///Rojo
	Chip_GPIO_SetPinDIRInput(LPC_GPIO_PORT, 0, 9);
	Chip_SCU_PinMux(1, 6, MD_PUP | MD_EZI | MD_ZI, FUNC0); /* GPIO1[9], SW4*///Verde
	Chip_GPIO_SetPinDIRInput(LPC_GPIO_PORT, 1, 9);
}

int LeerPulsador(int npulsador)
{
	int puertos[NPULSADORES] =
	{ 0, 0, 0, 1 };
	int pines[NPULSADORES] =
	{ 4, 8, 9, 9 };
	int estado;
	if (npulsador >= NPULSADORES)
		return -1;
	estado = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, puertos[npulsador],
			pines[npulsador]);
	return estado;
}
