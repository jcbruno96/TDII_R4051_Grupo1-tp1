
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Blinkyfsm.h"
#include "BlinkyfsmRequired.h"
/*! \file Implementation of the state machine 'blinkyfsm'
*/

/* prototypes of all internal functions */
static sc_boolean blinkyfsm_check__lr0(const Blinkyfsm* handle);
static sc_boolean blinkyfsm_check_main_region_Apagado_tr0_tr0(const Blinkyfsm* handle);
static sc_boolean blinkyfsm_check_main_region_Encendido_tr0_tr0(const Blinkyfsm* handle);
static void blinkyfsm_effect__lr0(Blinkyfsm* handle);
static void blinkyfsm_effect_main_region_Apagado_tr0(Blinkyfsm* handle);
static void blinkyfsm_effect_main_region_Encendido_tr0(Blinkyfsm* handle);
static void blinkyfsm_enact(Blinkyfsm* handle);
static void blinkyfsm_enact_main_region_Apagado(Blinkyfsm* handle);
static void blinkyfsm_enact_main_region_Encendido(Blinkyfsm* handle);
static void blinkyfsm_exact(Blinkyfsm* handle);
static void blinkyfsm_enseq_main_region_Apagado_default(Blinkyfsm* handle);
static void blinkyfsm_enseq_main_region_Encendido_default(Blinkyfsm* handle);
static void blinkyfsm_enseq_main_region_default(Blinkyfsm* handle);
static void blinkyfsm_exseq_main_region_Apagado(Blinkyfsm* handle);
static void blinkyfsm_exseq_main_region_Encendido(Blinkyfsm* handle);
static void blinkyfsm_exseq_main_region(Blinkyfsm* handle);
static void blinkyfsm_react_main_region_Apagado(Blinkyfsm* handle);
static void blinkyfsm_react_main_region_Encendido(Blinkyfsm* handle);
static void blinkyfsm_react_main_region__entry_Default(Blinkyfsm* handle);
static void blinkyfsm_clearInEvents(Blinkyfsm* handle);
static void blinkyfsm_clearOutEvents(Blinkyfsm* handle);


void blinkyfsm_init(Blinkyfsm* handle)
{
	sc_integer i;

	for (i = 0; i < BLINKYFSM_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Blinkyfsm_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	blinkyfsm_clearInEvents(handle);
	blinkyfsm_clearOutEvents(handle);


}

void blinkyfsm_enter(Blinkyfsm* handle)
{
	/* Default enter sequence for statechart blinkyfsm */
	blinkyfsm_enact(handle);
	blinkyfsm_enseq_main_region_default(handle);
}

void blinkyfsm_exit(Blinkyfsm* handle)
{
	/* Default exit sequence for statechart blinkyfsm */
	blinkyfsm_exseq_main_region(handle);
	blinkyfsm_exact(handle);
}

sc_boolean blinkyfsm_isActive(const Blinkyfsm* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Blinkyfsm_last_state)
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
sc_boolean blinkyfsm_isFinal(const Blinkyfsm* handle)
{
   return bool_false;
}

static void blinkyfsm_clearInEvents(Blinkyfsm* handle)
{
	handle->internal.evCambia_raised = bool_false;
	handle->timeEvents.blinkyfsm_tev0_raised = bool_false;
}

static void blinkyfsm_clearOutEvents(Blinkyfsm* handle)
{
}

void blinkyfsm_runCycle(Blinkyfsm* handle)
{
	
	blinkyfsm_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < BLINKYFSM_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Blinkyfsm_main_region_Apagado :
		{
			blinkyfsm_react_main_region_Apagado(handle);
			break;
		}
		case Blinkyfsm_main_region_Encendido :
		{
			blinkyfsm_react_main_region_Encendido(handle);
			break;
		}
		default:
			break;
		}
	}
	
	blinkyfsm_clearInEvents(handle);
}

void blinkyfsm_raiseTimeEvent(const Blinkyfsm* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(BlinkyfsmTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean blinkyfsm_isStateActive(const Blinkyfsm* handle, BlinkyfsmStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Blinkyfsm_main_region_Apagado :
			result = (sc_boolean) (handle->stateConfVector[0] == Blinkyfsm_main_region_Apagado
			);
			break;
		case Blinkyfsm_main_region_Encendido :
			result = (sc_boolean) (handle->stateConfVector[0] == Blinkyfsm_main_region_Encendido
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}




/* implementations of all internal functions */

static sc_boolean blinkyfsm_check__lr0(const Blinkyfsm* handle)
{
	return handle->timeEvents.blinkyfsm_tev0_raised;
}

static sc_boolean blinkyfsm_check_main_region_Apagado_tr0_tr0(const Blinkyfsm* handle)
{
	return handle->internal.evCambia_raised;
}

static sc_boolean blinkyfsm_check_main_region_Encendido_tr0_tr0(const Blinkyfsm* handle)
{
	return handle->internal.evCambia_raised;
}

static void blinkyfsm_effect__lr0(Blinkyfsm* handle)
{
	handle->internal.evCambia_raised = bool_true;
}

static void blinkyfsm_effect_main_region_Apagado_tr0(Blinkyfsm* handle)
{
	blinkyfsm_exseq_main_region_Apagado(handle);
	blinkyfsm_enseq_main_region_Encendido_default(handle);
}

static void blinkyfsm_effect_main_region_Encendido_tr0(Blinkyfsm* handle)
{
	blinkyfsm_exseq_main_region_Encendido(handle);
	blinkyfsm_enseq_main_region_Apagado_default(handle);
}

/* Entry action for statechart 'blinkyfsm'. */
static void blinkyfsm_enact(Blinkyfsm* handle)
{
	/* Entry action for statechart 'blinkyfsm'. */
	blinkyfsm_setTimer(handle, (sc_eventid) &(handle->timeEvents.blinkyfsm_tev0_raised) , 125, bool_true);
}

/* Entry action for state 'Apagado'. */
static void blinkyfsm_enact_main_region_Apagado(Blinkyfsm* handle)
{
	/* Entry action for state 'Apagado'. */
	blinkyfsmIface_opSetearLed(handle, bool_false);
}

/* Entry action for state 'Encendido'. */
static void blinkyfsm_enact_main_region_Encendido(Blinkyfsm* handle)
{
	/* Entry action for state 'Encendido'. */
	blinkyfsmIface_opSetearLed(handle, bool_true);
}

/* Exit action for state 'blinkyfsm'. */
static void blinkyfsm_exact(Blinkyfsm* handle)
{
	/* Exit action for state 'blinkyfsm'. */
	blinkyfsm_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.blinkyfsm_tev0_raised) );		
}

/* 'default' enter sequence for state Apagado */
static void blinkyfsm_enseq_main_region_Apagado_default(Blinkyfsm* handle)
{
	/* 'default' enter sequence for state Apagado */
	blinkyfsm_enact_main_region_Apagado(handle);
	handle->stateConfVector[0] = Blinkyfsm_main_region_Apagado;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Encendido */
static void blinkyfsm_enseq_main_region_Encendido_default(Blinkyfsm* handle)
{
	/* 'default' enter sequence for state Encendido */
	blinkyfsm_enact_main_region_Encendido(handle);
	handle->stateConfVector[0] = Blinkyfsm_main_region_Encendido;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
static void blinkyfsm_enseq_main_region_default(Blinkyfsm* handle)
{
	/* 'default' enter sequence for region main region */
	blinkyfsm_react_main_region__entry_Default(handle);
}

/* Default exit sequence for state Apagado */
static void blinkyfsm_exseq_main_region_Apagado(Blinkyfsm* handle)
{
	/* Default exit sequence for state Apagado */
	handle->stateConfVector[0] = Blinkyfsm_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Encendido */
static void blinkyfsm_exseq_main_region_Encendido(Blinkyfsm* handle)
{
	/* Default exit sequence for state Encendido */
	handle->stateConfVector[0] = Blinkyfsm_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for region main region */
static void blinkyfsm_exseq_main_region(Blinkyfsm* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of blinkyfsm.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Blinkyfsm_main_region_Apagado :
		{
			blinkyfsm_exseq_main_region_Apagado(handle);
			break;
		}
		case Blinkyfsm_main_region_Encendido :
		{
			blinkyfsm_exseq_main_region_Encendido(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state Apagado. */
static void blinkyfsm_react_main_region_Apagado(Blinkyfsm* handle)
{
	/* The reactions of state Apagado. */
	if (blinkyfsm_check__lr0(handle) == bool_true)
	{ 
		blinkyfsm_effect__lr0(handle);
	} 
	if (blinkyfsm_check_main_region_Apagado_tr0_tr0(handle) == bool_true)
	{ 
		blinkyfsm_effect_main_region_Apagado_tr0(handle);
	} 
}

/* The reactions of state Encendido. */
static void blinkyfsm_react_main_region_Encendido(Blinkyfsm* handle)
{
	/* The reactions of state Encendido. */
	if (blinkyfsm_check__lr0(handle) == bool_true)
	{ 
		blinkyfsm_effect__lr0(handle);
	} 
	if (blinkyfsm_check_main_region_Encendido_tr0_tr0(handle) == bool_true)
	{ 
		blinkyfsm_effect_main_region_Encendido_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void blinkyfsm_react_main_region__entry_Default(Blinkyfsm* handle)
{
	/* Default react sequence for initial entry  */
	blinkyfsm_enseq_main_region_Apagado_default(handle);
}


