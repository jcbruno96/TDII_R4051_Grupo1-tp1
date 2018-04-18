
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "BlinkyCompuesto.h"
#include "BlinkyCompuestoRequired.h"
/*! \file Implementation of the state machine 'blinkyCompuesto'
*/

/* prototypes of all internal functions */
static sc_boolean blinkyCompuesto_check__lr0(const BlinkyCompuesto* handle);
static sc_boolean blinkyCompuesto_check__lr1(const BlinkyCompuesto* handle);
static sc_boolean blinkyCompuesto_check_main_region_Parpadea_tr0_tr0(const BlinkyCompuesto* handle);
static sc_boolean blinkyCompuesto_check_main_region_Parpadea_r1_Apagado_tr0_tr0(const BlinkyCompuesto* handle);
static sc_boolean blinkyCompuesto_check_main_region_Parpadea_r1_Encendido_tr0_tr0(const BlinkyCompuesto* handle);
static sc_boolean blinkyCompuesto_check_main_region_Apagado_tr0_tr0(const BlinkyCompuesto* handle);
static void blinkyCompuesto_effect__lr0(BlinkyCompuesto* handle);
static void blinkyCompuesto_effect__lr1(BlinkyCompuesto* handle);
static void blinkyCompuesto_effect_main_region_Parpadea_tr0(BlinkyCompuesto* handle);
static void blinkyCompuesto_effect_main_region_Parpadea_r1_Apagado_tr0(BlinkyCompuesto* handle);
static void blinkyCompuesto_effect_main_region_Parpadea_r1_Encendido_tr0(BlinkyCompuesto* handle);
static void blinkyCompuesto_effect_main_region_Apagado_tr0(BlinkyCompuesto* handle);
static void blinkyCompuesto_enact(BlinkyCompuesto* handle);
static void blinkyCompuesto_enact_main_region_Parpadea_r1_Apagado(BlinkyCompuesto* handle);
static void blinkyCompuesto_enact_main_region_Parpadea_r1_Encendido(BlinkyCompuesto* handle);
static void blinkyCompuesto_enact_main_region_Apagado(BlinkyCompuesto* handle);
static void blinkyCompuesto_exact(BlinkyCompuesto* handle);
static void blinkyCompuesto_enseq_main_region_Parpadea_default(BlinkyCompuesto* handle);
static void blinkyCompuesto_enseq_main_region_Parpadea_r1_Apagado_default(BlinkyCompuesto* handle);
static void blinkyCompuesto_enseq_main_region_Parpadea_r1_Encendido_default(BlinkyCompuesto* handle);
static void blinkyCompuesto_enseq_main_region_Apagado_default(BlinkyCompuesto* handle);
static void blinkyCompuesto_enseq_main_region_default(BlinkyCompuesto* handle);
static void blinkyCompuesto_enseq_main_region_Parpadea_r1_default(BlinkyCompuesto* handle);
static void blinkyCompuesto_exseq_main_region_Parpadea(BlinkyCompuesto* handle);
static void blinkyCompuesto_exseq_main_region_Parpadea_r1_Apagado(BlinkyCompuesto* handle);
static void blinkyCompuesto_exseq_main_region_Parpadea_r1_Encendido(BlinkyCompuesto* handle);
static void blinkyCompuesto_exseq_main_region_Apagado(BlinkyCompuesto* handle);
static void blinkyCompuesto_exseq_main_region(BlinkyCompuesto* handle);
static void blinkyCompuesto_exseq_main_region_Parpadea_r1(BlinkyCompuesto* handle);
static void blinkyCompuesto_react_main_region_Parpadea_r1_Apagado(BlinkyCompuesto* handle);
static void blinkyCompuesto_react_main_region_Parpadea_r1_Encendido(BlinkyCompuesto* handle);
static void blinkyCompuesto_react_main_region_Apagado(BlinkyCompuesto* handle);
static void blinkyCompuesto_react_main_region__entry_Default(BlinkyCompuesto* handle);
static void blinkyCompuesto_react_main_region_Parpadea_r1__entry_Default(BlinkyCompuesto* handle);
static void blinkyCompuesto_clearInEvents(BlinkyCompuesto* handle);
static void blinkyCompuesto_clearOutEvents(BlinkyCompuesto* handle);


void blinkyCompuesto_init(BlinkyCompuesto* handle)
{
	sc_integer i;

	for (i = 0; i < BLINKYCOMPUESTO_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = BlinkyCompuesto_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	blinkyCompuesto_clearInEvents(handle);
	blinkyCompuesto_clearOutEvents(handle);


}

void blinkyCompuesto_enter(BlinkyCompuesto* handle)
{
	/* Default enter sequence for statechart blinkyCompuesto */
	blinkyCompuesto_enact(handle);
	blinkyCompuesto_enseq_main_region_default(handle);
}

void blinkyCompuesto_exit(BlinkyCompuesto* handle)
{
	/* Default exit sequence for statechart blinkyCompuesto */
	blinkyCompuesto_exseq_main_region(handle);
	blinkyCompuesto_exact(handle);
}

sc_boolean blinkyCompuesto_isActive(const BlinkyCompuesto* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != BlinkyCompuesto_last_state)
	{
		result =  bool_true;
	}
	else
	{
		result = bool_false;
	}
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean blinkyCompuesto_isFinal(const BlinkyCompuesto* handle)
{
   return bool_false;
}

static void blinkyCompuesto_clearInEvents(BlinkyCompuesto* handle)
{
	handle->internal.evToggle_raised = bool_false;
	handle->internal.evBlinky_raised = bool_false;
	handle->timeEvents.blinkyCompuesto_tev0_raised = bool_false;
	handle->timeEvents.blinkyCompuesto_tev1_raised = bool_false;
}

static void blinkyCompuesto_clearOutEvents(BlinkyCompuesto* handle)
{
}

void blinkyCompuesto_runCycle(BlinkyCompuesto* handle)
{
	
	blinkyCompuesto_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < BLINKYCOMPUESTO_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case BlinkyCompuesto_main_region_Parpadea_r1_Apagado :
		{
			blinkyCompuesto_react_main_region_Parpadea_r1_Apagado(handle);
			break;
		}
		case BlinkyCompuesto_main_region_Parpadea_r1_Encendido :
		{
			blinkyCompuesto_react_main_region_Parpadea_r1_Encendido(handle);
			break;
		}
		case BlinkyCompuesto_main_region_Apagado :
		{
			blinkyCompuesto_react_main_region_Apagado(handle);
			break;
		}
		default:
			break;
		}
	}
	
	blinkyCompuesto_clearInEvents(handle);
}

void blinkyCompuesto_raiseTimeEvent(const BlinkyCompuesto* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(BlinkyCompuestoTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean blinkyCompuesto_isStateActive(const BlinkyCompuesto* handle, BlinkyCompuestoStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case BlinkyCompuesto_main_region_Parpadea :
			result = (sc_boolean) (handle->stateConfVector[0] >= BlinkyCompuesto_main_region_Parpadea
				&& handle->stateConfVector[0] <= BlinkyCompuesto_main_region_Parpadea_r1_Encendido);
			break;
		case BlinkyCompuesto_main_region_Parpadea_r1_Apagado :
			result = (sc_boolean) (handle->stateConfVector[0] == BlinkyCompuesto_main_region_Parpadea_r1_Apagado
			);
			break;
		case BlinkyCompuesto_main_region_Parpadea_r1_Encendido :
			result = (sc_boolean) (handle->stateConfVector[0] == BlinkyCompuesto_main_region_Parpadea_r1_Encendido
			);
			break;
		case BlinkyCompuesto_main_region_Apagado :
			result = (sc_boolean) (handle->stateConfVector[0] == BlinkyCompuesto_main_region_Apagado
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}




/* implementations of all internal functions */

static sc_boolean blinkyCompuesto_check__lr0(const BlinkyCompuesto* handle)
{
	return handle->timeEvents.blinkyCompuesto_tev0_raised;
}

static sc_boolean blinkyCompuesto_check__lr1(const BlinkyCompuesto* handle)
{
	return handle->timeEvents.blinkyCompuesto_tev1_raised;
}

static sc_boolean blinkyCompuesto_check_main_region_Parpadea_tr0_tr0(const BlinkyCompuesto* handle)
{
	return handle->internal.evToggle_raised;
}

static sc_boolean blinkyCompuesto_check_main_region_Parpadea_r1_Apagado_tr0_tr0(const BlinkyCompuesto* handle)
{
	return handle->internal.evBlinky_raised;
}

static sc_boolean blinkyCompuesto_check_main_region_Parpadea_r1_Encendido_tr0_tr0(const BlinkyCompuesto* handle)
{
	return handle->internal.evBlinky_raised;
}

static sc_boolean blinkyCompuesto_check_main_region_Apagado_tr0_tr0(const BlinkyCompuesto* handle)
{
	return handle->internal.evToggle_raised;
}

static void blinkyCompuesto_effect__lr0(BlinkyCompuesto* handle)
{
	handle->internal.evBlinky_raised = bool_true;
}

static void blinkyCompuesto_effect__lr1(BlinkyCompuesto* handle)
{
	handle->internal.evToggle_raised = bool_true;
}

static void blinkyCompuesto_effect_main_region_Parpadea_tr0(BlinkyCompuesto* handle)
{
	blinkyCompuesto_exseq_main_region_Parpadea(handle);
	blinkyCompuesto_enseq_main_region_Apagado_default(handle);
}

static void blinkyCompuesto_effect_main_region_Parpadea_r1_Apagado_tr0(BlinkyCompuesto* handle)
{
	blinkyCompuesto_exseq_main_region_Parpadea_r1_Apagado(handle);
	blinkyCompuesto_enseq_main_region_Parpadea_r1_Encendido_default(handle);
}

static void blinkyCompuesto_effect_main_region_Parpadea_r1_Encendido_tr0(BlinkyCompuesto* handle)
{
	blinkyCompuesto_exseq_main_region_Parpadea_r1_Encendido(handle);
	blinkyCompuesto_enseq_main_region_Parpadea_r1_Apagado_default(handle);
}

static void blinkyCompuesto_effect_main_region_Apagado_tr0(BlinkyCompuesto* handle)
{
	blinkyCompuesto_exseq_main_region_Apagado(handle);
	blinkyCompuesto_enseq_main_region_Parpadea_default(handle);
}

/* Entry action for statechart 'blinkyCompuesto'. */
static void blinkyCompuesto_enact(BlinkyCompuesto* handle)
{
	/* Entry action for statechart 'blinkyCompuesto'. */
	blinkyCompuesto_setTimer(handle, (sc_eventid) &(handle->timeEvents.blinkyCompuesto_tev0_raised) , 125, bool_true);
	blinkyCompuesto_setTimer(handle, (sc_eventid) &(handle->timeEvents.blinkyCompuesto_tev1_raised) , 2 * 1000, bool_true);
}

/* Entry action for state 'Apagado'. */
static void blinkyCompuesto_enact_main_region_Parpadea_r1_Apagado(BlinkyCompuesto* handle)
{
	/* Entry action for state 'Apagado'. */
	blinkyCompuestoIface_opSetearLed(handle, bool_false);
}

/* Entry action for state 'Encendido'. */
static void blinkyCompuesto_enact_main_region_Parpadea_r1_Encendido(BlinkyCompuesto* handle)
{
	/* Entry action for state 'Encendido'. */
	blinkyCompuestoIface_opSetearLed(handle, bool_true);
}

/* Entry action for state 'Apagado'. */
static void blinkyCompuesto_enact_main_region_Apagado(BlinkyCompuesto* handle)
{
	/* Entry action for state 'Apagado'. */
	blinkyCompuestoIface_opSetearLed(handle, bool_false);
}

/* Exit action for state 'blinkyCompuesto'. */
static void blinkyCompuesto_exact(BlinkyCompuesto* handle)
{
	/* Exit action for state 'blinkyCompuesto'. */
	blinkyCompuesto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.blinkyCompuesto_tev0_raised) );		
	blinkyCompuesto_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.blinkyCompuesto_tev1_raised) );		
}

/* 'default' enter sequence for state Parpadea */
static void blinkyCompuesto_enseq_main_region_Parpadea_default(BlinkyCompuesto* handle)
{
	/* 'default' enter sequence for state Parpadea */
	blinkyCompuesto_enseq_main_region_Parpadea_r1_default(handle);
}

/* 'default' enter sequence for state Apagado */
static void blinkyCompuesto_enseq_main_region_Parpadea_r1_Apagado_default(BlinkyCompuesto* handle)
{
	/* 'default' enter sequence for state Apagado */
	blinkyCompuesto_enact_main_region_Parpadea_r1_Apagado(handle);
	handle->stateConfVector[0] = BlinkyCompuesto_main_region_Parpadea_r1_Apagado;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Encendido */
static void blinkyCompuesto_enseq_main_region_Parpadea_r1_Encendido_default(BlinkyCompuesto* handle)
{
	/* 'default' enter sequence for state Encendido */
	blinkyCompuesto_enact_main_region_Parpadea_r1_Encendido(handle);
	handle->stateConfVector[0] = BlinkyCompuesto_main_region_Parpadea_r1_Encendido;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Apagado */
static void blinkyCompuesto_enseq_main_region_Apagado_default(BlinkyCompuesto* handle)
{
	/* 'default' enter sequence for state Apagado */
	blinkyCompuesto_enact_main_region_Apagado(handle);
	handle->stateConfVector[0] = BlinkyCompuesto_main_region_Apagado;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
static void blinkyCompuesto_enseq_main_region_default(BlinkyCompuesto* handle)
{
	/* 'default' enter sequence for region main region */
	blinkyCompuesto_react_main_region__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void blinkyCompuesto_enseq_main_region_Parpadea_r1_default(BlinkyCompuesto* handle)
{
	/* 'default' enter sequence for region r1 */
	blinkyCompuesto_react_main_region_Parpadea_r1__entry_Default(handle);
}

/* Default exit sequence for state Parpadea */
static void blinkyCompuesto_exseq_main_region_Parpadea(BlinkyCompuesto* handle)
{
	/* Default exit sequence for state Parpadea */
	blinkyCompuesto_exseq_main_region_Parpadea_r1(handle);
}

/* Default exit sequence for state Apagado */
static void blinkyCompuesto_exseq_main_region_Parpadea_r1_Apagado(BlinkyCompuesto* handle)
{
	/* Default exit sequence for state Apagado */
	handle->stateConfVector[0] = BlinkyCompuesto_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Encendido */
static void blinkyCompuesto_exseq_main_region_Parpadea_r1_Encendido(BlinkyCompuesto* handle)
{
	/* Default exit sequence for state Encendido */
	handle->stateConfVector[0] = BlinkyCompuesto_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Apagado */
static void blinkyCompuesto_exseq_main_region_Apagado(BlinkyCompuesto* handle)
{
	/* Default exit sequence for state Apagado */
	handle->stateConfVector[0] = BlinkyCompuesto_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for region main region */
static void blinkyCompuesto_exseq_main_region(BlinkyCompuesto* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of blinkyCompuesto.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case BlinkyCompuesto_main_region_Parpadea_r1_Apagado :
		{
			blinkyCompuesto_exseq_main_region_Parpadea_r1_Apagado(handle);
			break;
		}
		case BlinkyCompuesto_main_region_Parpadea_r1_Encendido :
		{
			blinkyCompuesto_exseq_main_region_Parpadea_r1_Encendido(handle);
			break;
		}
		case BlinkyCompuesto_main_region_Apagado :
		{
			blinkyCompuesto_exseq_main_region_Apagado(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void blinkyCompuesto_exseq_main_region_Parpadea_r1(BlinkyCompuesto* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of blinkyCompuesto.main_region.Parpadea.r1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case BlinkyCompuesto_main_region_Parpadea_r1_Apagado :
		{
			blinkyCompuesto_exseq_main_region_Parpadea_r1_Apagado(handle);
			break;
		}
		case BlinkyCompuesto_main_region_Parpadea_r1_Encendido :
		{
			blinkyCompuesto_exseq_main_region_Parpadea_r1_Encendido(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state Apagado. */
static void blinkyCompuesto_react_main_region_Parpadea_r1_Apagado(BlinkyCompuesto* handle)
{
	/* The reactions of state Apagado. */
	if (blinkyCompuesto_check__lr0(handle) == bool_true)
	{ 
		blinkyCompuesto_effect__lr0(handle);
	} 
	if (blinkyCompuesto_check__lr1(handle) == bool_true)
	{ 
		blinkyCompuesto_effect__lr1(handle);
	} 
	if (blinkyCompuesto_check_main_region_Parpadea_tr0_tr0(handle) == bool_true)
	{ 
		blinkyCompuesto_effect_main_region_Parpadea_tr0(handle);
	}  else
	{
		if (blinkyCompuesto_check_main_region_Parpadea_r1_Apagado_tr0_tr0(handle) == bool_true)
		{ 
			blinkyCompuesto_effect_main_region_Parpadea_r1_Apagado_tr0(handle);
		} 
	}
}

/* The reactions of state Encendido. */
static void blinkyCompuesto_react_main_region_Parpadea_r1_Encendido(BlinkyCompuesto* handle)
{
	/* The reactions of state Encendido. */
	if (blinkyCompuesto_check__lr0(handle) == bool_true)
	{ 
		blinkyCompuesto_effect__lr0(handle);
	} 
	if (blinkyCompuesto_check__lr1(handle) == bool_true)
	{ 
		blinkyCompuesto_effect__lr1(handle);
	} 
	if (blinkyCompuesto_check_main_region_Parpadea_tr0_tr0(handle) == bool_true)
	{ 
		blinkyCompuesto_effect_main_region_Parpadea_tr0(handle);
	}  else
	{
		if (blinkyCompuesto_check_main_region_Parpadea_r1_Encendido_tr0_tr0(handle) == bool_true)
		{ 
			blinkyCompuesto_effect_main_region_Parpadea_r1_Encendido_tr0(handle);
		} 
	}
}

/* The reactions of state Apagado. */
static void blinkyCompuesto_react_main_region_Apagado(BlinkyCompuesto* handle)
{
	/* The reactions of state Apagado. */
	if (blinkyCompuesto_check__lr0(handle) == bool_true)
	{ 
		blinkyCompuesto_effect__lr0(handle);
	} 
	if (blinkyCompuesto_check__lr1(handle) == bool_true)
	{ 
		blinkyCompuesto_effect__lr1(handle);
	} 
	if (blinkyCompuesto_check_main_region_Apagado_tr0_tr0(handle) == bool_true)
	{ 
		blinkyCompuesto_effect_main_region_Apagado_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void blinkyCompuesto_react_main_region__entry_Default(BlinkyCompuesto* handle)
{
	/* Default react sequence for initial entry  */
	blinkyCompuesto_enseq_main_region_Parpadea_default(handle);
}

/* Default react sequence for initial entry  */
static void blinkyCompuesto_react_main_region_Parpadea_r1__entry_Default(BlinkyCompuesto* handle)
{
	/* Default react sequence for initial entry  */
	blinkyCompuesto_enseq_main_region_Parpadea_r1_Encendido_default(handle);
}


