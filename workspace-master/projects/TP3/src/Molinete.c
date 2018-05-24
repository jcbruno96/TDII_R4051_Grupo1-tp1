
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Molinete.h"
#include "MolineteRequired.h"
/*! \file Implementation of the state machine 'Molinete'
*/

/* prototypes of all internal functions */
static sc_boolean molinete_check_main_region_Bloqueado_tr0_tr0(const Molinete* handle);
static sc_boolean molinete_check_main_region_Bloqueado_tr1_tr1(const Molinete* handle);
static sc_boolean molinete_check_main_region_Desbloqueado_tr0_tr0(const Molinete* handle);
static sc_boolean molinete_check_main_region_Desbloqueado_tr1_tr1(const Molinete* handle);
static sc_boolean molinete_check_main_region_Desbloqueado_lr1_lr1(const Molinete* handle);
static void molinete_effect_main_region_Bloqueado_tr0(Molinete* handle);
static void molinete_effect_main_region_Bloqueado_tr1(Molinete* handle);
static void molinete_effect_main_region_Desbloqueado_tr0(Molinete* handle);
static void molinete_effect_main_region_Desbloqueado_tr1(Molinete* handle);
static void molinete_effect_main_region_Desbloqueado_lr1_lr1(Molinete* handle);
static void molinete_enact_main_region_Bloqueado(Molinete* handle);
static void molinete_exact_main_region_Bloqueado(Molinete* handle);
static void molinete_exact_main_region_Desbloqueado(Molinete* handle);
static void molinete_enseq_main_region_Bloqueado_default(Molinete* handle);
static void molinete_enseq_main_region_Desbloqueado_default(Molinete* handle);
static void molinete_enseq_main_region_default(Molinete* handle);
static void molinete_exseq_main_region_Bloqueado(Molinete* handle);
static void molinete_exseq_main_region_Desbloqueado(Molinete* handle);
static void molinete_exseq_main_region(Molinete* handle);
static void molinete_react_main_region_Bloqueado(Molinete* handle);
static void molinete_react_main_region_Desbloqueado(Molinete* handle);
static void molinete_react_main_region__entry_Default(Molinete* handle);
static void molinete_clearInEvents(Molinete* handle);
static void molinete_clearOutEvents(Molinete* handle);

const sc_integer MOLINETE_MOLINETEINTERNAL_CCTE = 1000;
const sc_boolean MOLINETE_MOLINETEINTERNAL_ON = bool_true;
const sc_boolean MOLINETE_MOLINETEINTERNAL_OFF = bool_false;

void molinete_init(Molinete* handle)
{
	sc_integer i;

	for (i = 0; i < MOLINETE_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Molinete_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	molinete_clearInEvents(handle);
	molinete_clearOutEvents(handle);

	/* Default init sequence for statechart Molinete */
	handle->internal.vContador = 0;

}

void molinete_enter(Molinete* handle)
{
	/* Default enter sequence for statechart Molinete */
	molinete_enseq_main_region_default(handle);
}

void molinete_exit(Molinete* handle)
{
	/* Default exit sequence for statechart Molinete */
	molinete_exseq_main_region(handle);
}

sc_boolean molinete_isActive(const Molinete* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Molinete_last_state)
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
sc_boolean molinete_isFinal(const Molinete* handle)
{
   return bool_false;
}

static void molinete_clearInEvents(Molinete* handle)
{
	handle->internal.evEmpujar_raised = bool_false;
	handle->internal.evMoneda_raised = bool_false;
}

static void molinete_clearOutEvents(Molinete* handle)
{
}

void molinete_runCycle(Molinete* handle)
{
	
	molinete_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < MOLINETE_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Molinete_main_region_Bloqueado :
		{
			molinete_react_main_region_Bloqueado(handle);
			break;
		}
		case Molinete_main_region_Desbloqueado :
		{
			molinete_react_main_region_Desbloqueado(handle);
			break;
		}
		default:
			break;
		}
	}
	
	molinete_clearInEvents(handle);
}


sc_boolean molinete_isStateActive(const Molinete* handle, MolineteStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Molinete_main_region_Bloqueado :
			result = (sc_boolean) (handle->stateConfVector[0] == Molinete_main_region_Bloqueado
			);
			break;
		case Molinete_main_region_Desbloqueado :
			result = (sc_boolean) (handle->stateConfVector[0] == Molinete_main_region_Desbloqueado
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}




/* implementations of all internal functions */

static sc_boolean molinete_check_main_region_Bloqueado_tr0_tr0(const Molinete* handle)
{
	return ((handle->internal.evMoneda_raised) && (handle->internal.vContador < MOLINETE_MOLINETEINTERNAL_CCTE)) ? bool_true : bool_false;
}

static sc_boolean molinete_check_main_region_Bloqueado_tr1_tr1(const Molinete* handle)
{
	return handle->internal.evEmpujar_raised;
}

static sc_boolean molinete_check_main_region_Desbloqueado_tr0_tr0(const Molinete* handle)
{
	return handle->internal.evMoneda_raised;
}

static sc_boolean molinete_check_main_region_Desbloqueado_tr1_tr1(const Molinete* handle)
{
	return handle->internal.evEmpujar_raised;
}

static sc_boolean molinete_check_main_region_Desbloqueado_lr1_lr1(const Molinete* handle)
{
	return (handle->internal.vContador == MOLINETE_MOLINETEINTERNAL_CCTE) ? bool_true : bool_false;
}

static void molinete_effect_main_region_Bloqueado_tr0(Molinete* handle)
{
	molinete_exseq_main_region_Bloqueado(handle);
	handle->internal.vContador += 1;
	molinete_enseq_main_region_Desbloqueado_default(handle);
}

static void molinete_effect_main_region_Bloqueado_tr1(Molinete* handle)
{
	molinete_exseq_main_region_Bloqueado(handle);
	molinete_enseq_main_region_Bloqueado_default(handle);
}

static void molinete_effect_main_region_Desbloqueado_tr0(Molinete* handle)
{
	molinete_exseq_main_region_Desbloqueado(handle);
	molinete_enseq_main_region_Desbloqueado_default(handle);
}

static void molinete_effect_main_region_Desbloqueado_tr1(Molinete* handle)
{
	molinete_exseq_main_region_Desbloqueado(handle);
	molinete_enseq_main_region_Bloqueado_default(handle);
}

static void molinete_effect_main_region_Desbloqueado_lr1_lr1(Molinete* handle)
{
	handle->internal.vContador = 0;
}

/* Entry action for state 'Bloqueado'. */
static void molinete_enact_main_region_Bloqueado(Molinete* handle)
{
	/* Entry action for state 'Bloqueado'. */
	molineteIface_opBloquear(handle, MOLINETE_MOLINETEINTERNAL_ON);
}

/* Exit action for state 'Bloqueado'. */
static void molinete_exact_main_region_Bloqueado(Molinete* handle)
{
	/* Exit action for state 'Bloqueado'. */
	molineteIface_opDesbloquear(handle, MOLINETE_MOLINETEINTERNAL_ON);
}

/* Exit action for state 'Desbloqueado'. */
static void molinete_exact_main_region_Desbloqueado(Molinete* handle)
{
	/* Exit action for state 'Desbloqueado'. */
	molineteIface_opBloquear(handle, MOLINETE_MOLINETEINTERNAL_ON);
}

/* 'default' enter sequence for state Bloqueado */
static void molinete_enseq_main_region_Bloqueado_default(Molinete* handle)
{
	/* 'default' enter sequence for state Bloqueado */
	molinete_enact_main_region_Bloqueado(handle);
	handle->stateConfVector[0] = Molinete_main_region_Bloqueado;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Desbloqueado */
static void molinete_enseq_main_region_Desbloqueado_default(Molinete* handle)
{
	/* 'default' enter sequence for state Desbloqueado */
	handle->stateConfVector[0] = Molinete_main_region_Desbloqueado;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
static void molinete_enseq_main_region_default(Molinete* handle)
{
	/* 'default' enter sequence for region main region */
	molinete_react_main_region__entry_Default(handle);
}

/* Default exit sequence for state Bloqueado */
static void molinete_exseq_main_region_Bloqueado(Molinete* handle)
{
	/* Default exit sequence for state Bloqueado */
	handle->stateConfVector[0] = Molinete_last_state;
	handle->stateConfVectorPosition = 0;
	molinete_exact_main_region_Bloqueado(handle);
}

/* Default exit sequence for state Desbloqueado */
static void molinete_exseq_main_region_Desbloqueado(Molinete* handle)
{
	/* Default exit sequence for state Desbloqueado */
	handle->stateConfVector[0] = Molinete_last_state;
	handle->stateConfVectorPosition = 0;
	molinete_exact_main_region_Desbloqueado(handle);
}

/* Default exit sequence for region main region */
static void molinete_exseq_main_region(Molinete* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of Molinete.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Molinete_main_region_Bloqueado :
		{
			molinete_exseq_main_region_Bloqueado(handle);
			break;
		}
		case Molinete_main_region_Desbloqueado :
		{
			molinete_exseq_main_region_Desbloqueado(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state Bloqueado. */
static void molinete_react_main_region_Bloqueado(Molinete* handle)
{
	/* The reactions of state Bloqueado. */
	if (molinete_check_main_region_Bloqueado_tr0_tr0(handle) == bool_true)
	{ 
		molinete_effect_main_region_Bloqueado_tr0(handle);
	}  else
	{
		if (molinete_check_main_region_Bloqueado_tr1_tr1(handle) == bool_true)
		{ 
			molinete_effect_main_region_Bloqueado_tr1(handle);
		} 
	}
}

/* The reactions of state Desbloqueado. */
static void molinete_react_main_region_Desbloqueado(Molinete* handle)
{
	/* The reactions of state Desbloqueado. */
	if (molinete_check_main_region_Desbloqueado_tr0_tr0(handle) == bool_true)
	{ 
		molinete_effect_main_region_Desbloqueado_tr0(handle);
	}  else
	{
		if (molinete_check_main_region_Desbloqueado_tr1_tr1(handle) == bool_true)
		{ 
			molinete_effect_main_region_Desbloqueado_tr1(handle);
		}  else
		{
			if (molinete_check_main_region_Desbloqueado_lr1_lr1(handle) == bool_true)
			{ 
				molinete_effect_main_region_Desbloqueado_lr1_lr1(handle);
			} 
		}
	}
}

/* Default react sequence for initial entry  */
static void molinete_react_main_region__entry_Default(Molinete* handle)
{
	/* Default react sequence for initial entry  */
	handle->internal.vContador = 0;
	molinete_enseq_main_region_Bloqueado_default(handle);
}


