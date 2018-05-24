/*
 * Aplicacion.h
 *
 *  Created on: 23 de may. de 2018
 *      Author: sebas
 */

#ifndef WORKSPACE_MASTER_PROJECTS_TP3_INC_APLICACION_H_
#define WORKSPACE_MASTER_PROJECTS_TP3_INC_APLICACION_H_

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "main.h"
#include "Molinete.h"
#include "MolineteRequired.h"

#define	 PIN_LED 22
#define	 PUERTO_LED	0

void	init_hardware	(void);


#endif /* WORKSPACE_MASTER_PROJECTS_TP3_INC_APLICACION_H_ */
