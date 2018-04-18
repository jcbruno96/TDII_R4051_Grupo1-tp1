
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Blinkyboton.h"
#include "BlinkybotonRequired.h"
/*! \file Implementation of the state machine 'blinkyboton'
*/

/* prototypes of all internal functions */
static sc_boolean blinkyboton_check__lr0(const Blinkyboton* handle);
static sc_boolean blinkyboton_check_main_region_EsperaBoton_tr0_tr0(const Blinkyboton* handle);
static sc_boolean blinkyboton_check_main_region_Antirrebote_tr0_tr0(const Blinkyboton* handle);
static sc_boolean blinkyboton_check_main_region_Antirrebote_tr1_tr1(const Blinkyboton* handle);
static sc_boolean blinkyboton_check_main_region_Antirrebote_lr0_lr0(const Blinkyboton* handle);
static sc_boolean blinkyboton_check_main_region_Presionado_tr0_tr0(const Blinkyboton* handle);
static sc_boolean blinkyboton_check_regionParpadeo_Parpadea_tr0_tr0(const Blinkyboton* handle);
static sc_boolean blinkyboton_check_regionParpadeo_Parpadea_r1_Apagado_tr0_tr0(const Blinkyboton* handle);
static sc_boolean blinkyboton_check_regionParpadeo_Parpadea_r1_Encendido_tr0_tr0(const Blinkyboton* handle);
static sc_boolean blinkyboton_check_regionParpadeo_Apagado_tr0_tr0(const Blinkyboton* handle);
static void blinkyboton_effect__lr0(Blinkyboton* handle);
static void blinkyboton_effect_main_region_EsperaBoton_tr0(Blinkyboton* handle);
static void blinkyboton_effect_main_region_Antirrebote_tr0(Blinkyboton* handle);
static void blinkyboton_effect_main_region_Antirrebote_tr1(Blinkyboton* handle);
static void blinkyboton_effect_main_region_Antirrebote_lr0_lr0(Blinkyboton* handle);
static void blinkyboton_effect_main_region_Presionado_tr0(Blinkyboton* handle);
static void blinkyboton_effect_regionParpadeo_Parpadea_tr0(Blinkyboton* handle);
static void blinkyboton_effect_regionParpadeo_Parpadea_r1_Apagado_tr0(Blinkyboton* handle);
static void blinkyboton_effect_regionParpadeo_Parpadea_r1_Encendido_tr0(Blinkyboton* handle);
static void blinkyboton_effect_regionParpadeo_Apagado_tr0(Blinkyboton* handle);
static void blinkyboton_enact(Blinkyboton* handle);
static void blinkyboton_enact_main_region_Antirrebote(Blinkyboton* handle);
static void blinkyboton_enact_regionParpadeo_Parpadea_r1_Apagado(Blinkyboton* handle);
static void blinkyboton_enact_regionParpadeo_Parpadea_r1_Encendido(Blinkyboton* handle);
static void blinkyboton_enact_regionParpadeo_Apagado(Blinkyboton* handle);
static void blinkyboton_exact(Blinkyboton* handle);
static void blinkyboton_exact_main_region_Antirrebote(Blinkyboton* handle);
static void blinkyboton_enseq_main_region_EsperaBoton_default(Blinkyboton* handle);
static void blinkyboton_enseq_main_region_Antirrebote_default(Blinkyboton* handle);
static void blinkyboton_enseq_main_region_Presionado_default(Blinkyboton* handle);
static void blinkyboton_enseq_regionParpadeo_Parpadea_default(Blinkyboton* handle);
static void blinkyboton_enseq_regionParpadeo_Parpadea_r1_Apagado_default(Blinkyboton* handle);
static void blinkyboton_enseq_regionParpadeo_Parpadea_r1_Encendido_default(Blinkyboton* handle);
static void blinkyboton_enseq_regionParpadeo_Apagado_default(Blinkyboton* handle);
static void blinkyboton_enseq_main_region_default(Blinkyboton* handle);
static void blinkyboton_enseq_regionParpadeo_default(Blinkyboton* handle);
static void blinkyboton_enseq_regionParpadeo_Parpadea_r1_default(Blinkyboton* handle);
static void blinkyboton_exseq_main_region_EsperaBoton(Blinkyboton* handle);
static void blinkyboton_exseq_main_region_Antirrebote(Blinkyboton* handle);
static void blinkyboton_exseq_main_region_Presionado(Blinkyboton* handle);
static void blinkyboton_exseq_regionParpadeo_Parpadea(Blinkyboton* handle);
static void blinkyboton_exseq_regionParpadeo_Parpadea_r1_Apagado(Blinkyboton* handle);
static void blinkyboton_exseq_regionParpadeo_Parpadea_r1_Encendido(Blinkyboton* handle);
static void blinkyboton_exseq_regionParpadeo_Apagado(Blinkyboton* handle);
static void blinkyboton_exseq_main_region(Blinkyboton* handle);
static void blinkyboton_exseq_regionParpadeo(Blinkyboton* handle);
static void blinkyboton_exseq_regionParpadeo_Parpadea_r1(Blinkyboton* handle);
static void blinkyboton_react_main_region_EsperaBoton(Blinkyboton* handle);
static void blinkyboton_react_main_region_Antirrebote(Blinkyboton* handle);
static void blinkyboton_react_main_region_Presionado(Blinkyboton* handle);
static void blinkyboton_react_regionParpadeo_Parpadea_r1_Apagado(Blinkyboton* handle);
static void blinkyboton_react_regionParpadeo_Parpadea_r1_Encendido(Blinkyboton* handle);
static void blinkyboton_react_regionParpadeo_Apagado(Blinkyboton* handle);
static void blinkyboton_react_main_region__entry_Default(Blinkyboton* handle);
static void blinkyboton_react_regionParpadeo_Parpadea_r1__entry_Default(Blinkyboton* handle);
static void blinkyboton_react_regionParpadeo__entry_Default(Blinkyboton* handle);
static void blinkyboton_clearInEvents(Blinkyboton* handle);
static void blinkyboton_clearOutEvents(Blinkyboton* handle);

const sc_integer BLINKYBOTON_BLINKYBOTONINTERNAL_DEBTIME = 20;

void blinkyboton_init(Blinkyboton* handle)
{
	sc_integer i;

	for (i = 0; i < BLINKYBOTON_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Blinkyboton_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	blinkyboton_clearInEvents(handle);
	blinkyboton_clearOutEvents(handle);

	/* Default init sequence for statechart blinkyboton */
	handle->iface.boton = bool_false;
	handle->internal.deBounce = 0;

}

void blinkyboton_enter(Blinkyboton* handle)
{
	/* Default enter sequence for statechart blinkyboton */
	blinkyboton_enact(handle);
	blinkyboton_enseq_main_region_default(handle);
	blinkyboton_enseq_regionParpadeo_default(handle);
}

void blinkyboton_exit(Blinkyboton* handle)
{
	/* Default exit sequence for statechart blinkyboton */
	blinkyboton_exseq_main_region(handle);
	blinkyboton_exseq_regionParpadeo(handle);
	blinkyboton_exact(handle);
}

sc_boolean blinkyboton_isActive(const Blinkyboton* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Blinkyboton_last_state || handle->stateConfVector[1] != Blinkyboton_last_state)
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
sc_boolean blinkyboton_isFinal(const Blinkyboton* handle)
{
   return bool_false;
}

static void blinkyboton_clearInEvents(Blinkyboton* handle)
{
	handle->internal.evToggle_raised = bool_false;
	handle->internal.evBlinky_raised = bool_false;
	handle->timeEvents.blinkyboton_main_region_Antirrebote_tev0_raised = bool_false;
	handle->timeEvents.blinkyboton_tev0_raised = bool_false;
}

static void blinkyboton_clearOutEvents(Blinkyboton* handle)
{
}

void blinkyboton_runCycle(Blinkyboton* handle)
{
	
	blinkyboton_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < BLINKYBOTON_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Blinkyboton_main_region_EsperaBoton :
		{
			blinkyboton_react_main_region_EsperaBoton(handle);
			break;
		}
		case Blinkyboton_main_region_Antirrebote :
		{
			blinkyboton_react_main_region_Antirrebote(handle);
			break;
		}
		case Blinkyboton_main_region_Presionado :
		{
			blinkyboton_react_main_region_Presionado(handle);
			break;
		}
		case Blinkyboton_regionParpadeo_Parpadea_r1_Apagado :
		{
			blinkyboton_react_regionParpadeo_Parpadea_r1_Apagado(handle);
			break;
		}
		case Blinkyboton_regionParpadeo_Parpadea_r1_Encendido :
		{
			blinkyboton_react_regionParpadeo_Parpadea_r1_Encendido(handle);
			break;
		}
		case Blinkyboton_regionParpadeo_Apagado :
		{
			blinkyboton_react_regionParpadeo_Apagado(handle);
			break;
		}
		default:
			break;
		}
	}
	
	blinkyboton_clearInEvents(handle);
}

void blinkyboton_raiseTimeEvent(const Blinkyboton* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(BlinkybotonTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean blinkyboton_isStateActive(const Blinkyboton* handle, BlinkybotonStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Blinkyboton_main_region_EsperaBoton :
			result = (sc_boolean) (handle->stateConfVector[0] == Blinkyboton_main_region_EsperaBoton
			);
			break;
		case Blinkyboton_main_region_Antirrebote :
			result = (sc_boolean) (handle->stateConfVector[0] == Blinkyboton_main_region_Antirrebote
			);
			break;
		case Blinkyboton_main_region_Presionado :
			result = (sc_boolean) (handle->stateConfVector[0] == Blinkyboton_main_region_Presionado
			);
			break;
		case Blinkyboton_regionParpadeo_Parpadea :
			result = (sc_boolean) (handle->stateConfVector[1] >= Blinkyboton_regionParpadeo_Parpadea
				&& handle->stateConfVector[1] <= Blinkyboton_regionParpadeo_Parpadea_r1_Encendido);
			break;
		case Blinkyboton_regionParpadeo_Parpadea_r1_Apagado :
			result = (sc_boolean) (handle->stateConfVector[1] == Blinkyboton_regionParpadeo_Parpadea_r1_Apagado
			);
			break;
		case Blinkyboton_regionParpadeo_Parpadea_r1_Encendido :
			result = (sc_boolean) (handle->stateConfVector[1] == Blinkyboton_regionParpadeo_Parpadea_r1_Encendido
			);
			break;
		case Blinkyboton_regionParpadeo_Apagado :
			result = (sc_boolean) (handle->stateConfVector[1] == Blinkyboton_regionParpadeo_Apagado
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}



sc_boolean blinkybotonIface_get_boton(const Blinkyboton* handle)
{
	return handle->iface.boton;
}
void blinkybotonIface_set_boton(Blinkyboton* handle, sc_boolean value)
{
	handle->iface.boton = value;
}

/* implementations of all internal functions */

static sc_boolean blinkyboton_check__lr0(const Blinkyboton* handle)
{
	return handle->timeEvents.blinkyboton_tev0_raised;
}

static sc_boolean blinkyboton_check_main_region_EsperaBoton_tr0_tr0(const Blinkyboton* handle)
{
	return (handle->iface.boton == bool_true) ? bool_true : bool_false;
}

static sc_boolean blinkyboton_check_main_region_Antirrebote_tr0_tr0(const Blinkyboton* handle)
{
	return (handle->internal.deBounce == 0 && handle->iface.boton == bool_true) ? bool_true : bool_false;
}

static sc_boolean blinkyboton_check_main_region_Antirrebote_tr1_tr1(const Blinkyboton* handle)
{
	return (handle->internal.deBounce == 0 && handle->iface.boton == bool_false) ? bool_true : bool_false;
}

static sc_boolean blinkyboton_check_main_region_Antirrebote_lr0_lr0(const Blinkyboton* handle)
{
	return ((handle->timeEvents.blinkyboton_main_region_Antirrebote_tev0_raised) && (handle->internal.deBounce > 0)) ? bool_true : bool_false;
}

static sc_boolean blinkyboton_check_main_region_Presionado_tr0_tr0(const Blinkyboton* handle)
{
	return (handle->iface.boton == bool_false) ? bool_true : bool_false;
}

static sc_boolean blinkyboton_check_regionParpadeo_Parpadea_tr0_tr0(const Blinkyboton* handle)
{
	return handle->internal.evToggle_raised;
}

static sc_boolean blinkyboton_check_regionParpadeo_Parpadea_r1_Apagado_tr0_tr0(const Blinkyboton* handle)
{
	return handle->internal.evBlinky_raised;
}

static sc_boolean blinkyboton_check_regionParpadeo_Parpadea_r1_Encendido_tr0_tr0(const Blinkyboton* handle)
{
	return handle->internal.evBlinky_raised;
}

static sc_boolean blinkyboton_check_regionParpadeo_Apagado_tr0_tr0(const Blinkyboton* handle)
{
	return handle->internal.evToggle_raised;
}

static void blinkyboton_effect__lr0(Blinkyboton* handle)
{
	handle->internal.evBlinky_raised = bool_true;
}

static void blinkyboton_effect_main_region_EsperaBoton_tr0(Blinkyboton* handle)
{
	blinkyboton_exseq_main_region_EsperaBoton(handle);
	handle->internal.deBounce = BLINKYBOTON_BLINKYBOTONINTERNAL_DEBTIME;
	blinkyboton_enseq_main_region_Antirrebote_default(handle);
}

static void blinkyboton_effect_main_region_Antirrebote_tr0(Blinkyboton* handle)
{
	blinkyboton_exseq_main_region_Antirrebote(handle);
	handle->internal.evToggle_raised = bool_true;
	blinkyboton_enseq_main_region_Presionado_default(handle);
}

static void blinkyboton_effect_main_region_Antirrebote_tr1(Blinkyboton* handle)
{
	blinkyboton_exseq_main_region_Antirrebote(handle);
	blinkyboton_enseq_main_region_EsperaBoton_default(handle);
}

static void blinkyboton_effect_main_region_Antirrebote_lr0_lr0(Blinkyboton* handle)
{
	handle->internal.deBounce = handle->internal.deBounce - 1;
}

static void blinkyboton_effect_main_region_Presionado_tr0(Blinkyboton* handle)
{
	blinkyboton_exseq_main_region_Presionado(handle);
	blinkyboton_enseq_main_region_EsperaBoton_default(handle);
}

static void blinkyboton_effect_regionParpadeo_Parpadea_tr0(Blinkyboton* handle)
{
	blinkyboton_exseq_regionParpadeo_Parpadea(handle);
	blinkyboton_enseq_regionParpadeo_Apagado_default(handle);
}

static void blinkyboton_effect_regionParpadeo_Parpadea_r1_Apagado_tr0(Blinkyboton* handle)
{
	blinkyboton_exseq_regionParpadeo_Parpadea_r1_Apagado(handle);
	blinkyboton_enseq_regionParpadeo_Parpadea_r1_Encendido_default(handle);
}

static void blinkyboton_effect_regionParpadeo_Parpadea_r1_Encendido_tr0(Blinkyboton* handle)
{
	blinkyboton_exseq_regionParpadeo_Parpadea_r1_Encendido(handle);
	blinkyboton_enseq_regionParpadeo_Parpadea_r1_Apagado_default(handle);
}

static void blinkyboton_effect_regionParpadeo_Apagado_tr0(Blinkyboton* handle)
{
	blinkyboton_exseq_regionParpadeo_Apagado(handle);
	blinkyboton_enseq_regionParpadeo_Parpadea_default(handle);
}

/* Entry action for statechart 'blinkyboton'. */
static void blinkyboton_enact(Blinkyboton* handle)
{
	/* Entry action for statechart 'blinkyboton'. */
	blinkyboton_setTimer(handle, (sc_eventid) &(handle->timeEvents.blinkyboton_tev0_raised) , 125, bool_true);
}

/* Entry action for state 'Antirrebote'. */
static void blinkyboton_enact_main_region_Antirrebote(Blinkyboton* handle)
{
	/* Entry action for state 'Antirrebote'. */
	blinkyboton_setTimer(handle, (sc_eventid) &(handle->timeEvents.blinkyboton_main_region_Antirrebote_tev0_raised) , 1, bool_true);
}

/* Entry action for state 'Apagado'. */
static void blinkyboton_enact_regionParpadeo_Parpadea_r1_Apagado(Blinkyboton* handle)
{
	/* Entry action for state 'Apagado'. */
	blinkybotonIface_opSetearLed(handle, bool_false);
}

/* Entry action for state 'Encendido'. */
static void blinkyboton_enact_regionParpadeo_Parpadea_r1_Encendido(Blinkyboton* handle)
{
	/* Entry action for state 'Encendido'. */
	blinkybotonIface_opSetearLed(handle, bool_true);
}

/* Entry action for state 'Apagado'. */
static void blinkyboton_enact_regionParpadeo_Apagado(Blinkyboton* handle)
{
	/* Entry action for state 'Apagado'. */
	blinkybotonIface_opSetearLed(handle, bool_false);
}

/* Exit action for state 'blinkyboton'. */
static void blinkyboton_exact(Blinkyboton* handle)
{
	/* Exit action for state 'blinkyboton'. */
	blinkyboton_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.blinkyboton_tev0_raised) );		
}

/* Exit action for state 'Antirrebote'. */
static void blinkyboton_exact_main_region_Antirrebote(Blinkyboton* handle)
{
	/* Exit action for state 'Antirrebote'. */
	blinkyboton_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.blinkyboton_main_region_Antirrebote_tev0_raised) );		
}

/* 'default' enter sequence for state EsperaBoton */
static void blinkyboton_enseq_main_region_EsperaBoton_default(Blinkyboton* handle)
{
	/* 'default' enter sequence for state EsperaBoton */
	handle->stateConfVector[0] = Blinkyboton_main_region_EsperaBoton;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Antirrebote */
static void blinkyboton_enseq_main_region_Antirrebote_default(Blinkyboton* handle)
{
	/* 'default' enter sequence for state Antirrebote */
	blinkyboton_enact_main_region_Antirrebote(handle);
	handle->stateConfVector[0] = Blinkyboton_main_region_Antirrebote;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Presionado */
static void blinkyboton_enseq_main_region_Presionado_default(Blinkyboton* handle)
{
	/* 'default' enter sequence for state Presionado */
	handle->stateConfVector[0] = Blinkyboton_main_region_Presionado;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Parpadea */
static void blinkyboton_enseq_regionParpadeo_Parpadea_default(Blinkyboton* handle)
{
	/* 'default' enter sequence for state Parpadea */
	blinkyboton_enseq_regionParpadeo_Parpadea_r1_default(handle);
}

/* 'default' enter sequence for state Apagado */
static void blinkyboton_enseq_regionParpadeo_Parpadea_r1_Apagado_default(Blinkyboton* handle)
{
	/* 'default' enter sequence for state Apagado */
	blinkyboton_enact_regionParpadeo_Parpadea_r1_Apagado(handle);
	handle->stateConfVector[1] = Blinkyboton_regionParpadeo_Parpadea_r1_Apagado;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state Encendido */
static void blinkyboton_enseq_regionParpadeo_Parpadea_r1_Encendido_default(Blinkyboton* handle)
{
	/* 'default' enter sequence for state Encendido */
	blinkyboton_enact_regionParpadeo_Parpadea_r1_Encendido(handle);
	handle->stateConfVector[1] = Blinkyboton_regionParpadeo_Parpadea_r1_Encendido;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state Apagado */
static void blinkyboton_enseq_regionParpadeo_Apagado_default(Blinkyboton* handle)
{
	/* 'default' enter sequence for state Apagado */
	blinkyboton_enact_regionParpadeo_Apagado(handle);
	handle->stateConfVector[1] = Blinkyboton_regionParpadeo_Apagado;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for region main region */
static void blinkyboton_enseq_main_region_default(Blinkyboton* handle)
{
	/* 'default' enter sequence for region main region */
	blinkyboton_react_main_region__entry_Default(handle);
}

/* 'default' enter sequence for region regionParpadeo */
static void blinkyboton_enseq_regionParpadeo_default(Blinkyboton* handle)
{
	/* 'default' enter sequence for region regionParpadeo */
	blinkyboton_react_regionParpadeo__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void blinkyboton_enseq_regionParpadeo_Parpadea_r1_default(Blinkyboton* handle)
{
	/* 'default' enter sequence for region r1 */
	blinkyboton_react_regionParpadeo_Parpadea_r1__entry_Default(handle);
}

/* Default exit sequence for state EsperaBoton */
static void blinkyboton_exseq_main_region_EsperaBoton(Blinkyboton* handle)
{
	/* Default exit sequence for state EsperaBoton */
	handle->stateConfVector[0] = Blinkyboton_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Antirrebote */
static void blinkyboton_exseq_main_region_Antirrebote(Blinkyboton* handle)
{
	/* Default exit sequence for state Antirrebote */
	handle->stateConfVector[0] = Blinkyboton_last_state;
	handle->stateConfVectorPosition = 0;
	blinkyboton_exact_main_region_Antirrebote(handle);
}

/* Default exit sequence for state Presionado */
static void blinkyboton_exseq_main_region_Presionado(Blinkyboton* handle)
{
	/* Default exit sequence for state Presionado */
	handle->stateConfVector[0] = Blinkyboton_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Parpadea */
static void blinkyboton_exseq_regionParpadeo_Parpadea(Blinkyboton* handle)
{
	/* Default exit sequence for state Parpadea */
	blinkyboton_exseq_regionParpadeo_Parpadea_r1(handle);
}

/* Default exit sequence for state Apagado */
static void blinkyboton_exseq_regionParpadeo_Parpadea_r1_Apagado(Blinkyboton* handle)
{
	/* Default exit sequence for state Apagado */
	handle->stateConfVector[1] = Blinkyboton_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state Encendido */
static void blinkyboton_exseq_regionParpadeo_Parpadea_r1_Encendido(Blinkyboton* handle)
{
	/* Default exit sequence for state Encendido */
	handle->stateConfVector[1] = Blinkyboton_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state Apagado */
static void blinkyboton_exseq_regionParpadeo_Apagado(Blinkyboton* handle)
{
	/* Default exit sequence for state Apagado */
	handle->stateConfVector[1] = Blinkyboton_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for region main region */
static void blinkyboton_exseq_main_region(Blinkyboton* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of blinkyboton.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Blinkyboton_main_region_EsperaBoton :
		{
			blinkyboton_exseq_main_region_EsperaBoton(handle);
			break;
		}
		case Blinkyboton_main_region_Antirrebote :
		{
			blinkyboton_exseq_main_region_Antirrebote(handle);
			break;
		}
		case Blinkyboton_main_region_Presionado :
		{
			blinkyboton_exseq_main_region_Presionado(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region regionParpadeo */
static void blinkyboton_exseq_regionParpadeo(Blinkyboton* handle)
{
	/* Default exit sequence for region regionParpadeo */
	/* Handle exit of all possible states (of blinkyboton.regionParpadeo) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Blinkyboton_regionParpadeo_Parpadea_r1_Apagado :
		{
			blinkyboton_exseq_regionParpadeo_Parpadea_r1_Apagado(handle);
			break;
		}
		case Blinkyboton_regionParpadeo_Parpadea_r1_Encendido :
		{
			blinkyboton_exseq_regionParpadeo_Parpadea_r1_Encendido(handle);
			break;
		}
		case Blinkyboton_regionParpadeo_Apagado :
		{
			blinkyboton_exseq_regionParpadeo_Apagado(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void blinkyboton_exseq_regionParpadeo_Parpadea_r1(Blinkyboton* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of blinkyboton.regionParpadeo.Parpadea.r1) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Blinkyboton_regionParpadeo_Parpadea_r1_Apagado :
		{
			blinkyboton_exseq_regionParpadeo_Parpadea_r1_Apagado(handle);
			break;
		}
		case Blinkyboton_regionParpadeo_Parpadea_r1_Encendido :
		{
			blinkyboton_exseq_regionParpadeo_Parpadea_r1_Encendido(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state EsperaBoton. */
static void blinkyboton_react_main_region_EsperaBoton(Blinkyboton* handle)
{
	/* The reactions of state EsperaBoton. */
	if (blinkyboton_check__lr0(handle) == bool_true)
	{ 
		blinkyboton_effect__lr0(handle);
	} 
	if (blinkyboton_check_main_region_EsperaBoton_tr0_tr0(handle) == bool_true)
	{ 
		blinkyboton_effect_main_region_EsperaBoton_tr0(handle);
	} 
}

/* The reactions of state Antirrebote. */
static void blinkyboton_react_main_region_Antirrebote(Blinkyboton* handle)
{
	/* The reactions of state Antirrebote. */
	if (blinkyboton_check__lr0(handle) == bool_true)
	{ 
		blinkyboton_effect__lr0(handle);
	} 
	if (blinkyboton_check_main_region_Antirrebote_tr0_tr0(handle) == bool_true)
	{ 
		blinkyboton_effect_main_region_Antirrebote_tr0(handle);
	}  else
	{
		if (blinkyboton_check_main_region_Antirrebote_tr1_tr1(handle) == bool_true)
		{ 
			blinkyboton_effect_main_region_Antirrebote_tr1(handle);
		}  else
		{
			if (blinkyboton_check_main_region_Antirrebote_lr0_lr0(handle) == bool_true)
			{ 
				blinkyboton_effect_main_region_Antirrebote_lr0_lr0(handle);
			} 
		}
	}
}

/* The reactions of state Presionado. */
static void blinkyboton_react_main_region_Presionado(Blinkyboton* handle)
{
	/* The reactions of state Presionado. */
	if (blinkyboton_check__lr0(handle) == bool_true)
	{ 
		blinkyboton_effect__lr0(handle);
	} 
	if (blinkyboton_check_main_region_Presionado_tr0_tr0(handle) == bool_true)
	{ 
		blinkyboton_effect_main_region_Presionado_tr0(handle);
	} 
}

/* The reactions of state Apagado. */
static void blinkyboton_react_regionParpadeo_Parpadea_r1_Apagado(Blinkyboton* handle)
{
	/* The reactions of state Apagado. */
	if (blinkyboton_check_regionParpadeo_Parpadea_tr0_tr0(handle) == bool_true)
	{ 
		blinkyboton_effect_regionParpadeo_Parpadea_tr0(handle);
	}  else
	{
		if (blinkyboton_check_regionParpadeo_Parpadea_r1_Apagado_tr0_tr0(handle) == bool_true)
		{ 
			blinkyboton_effect_regionParpadeo_Parpadea_r1_Apagado_tr0(handle);
		} 
	}
}

/* The reactions of state Encendido. */
static void blinkyboton_react_regionParpadeo_Parpadea_r1_Encendido(Blinkyboton* handle)
{
	/* The reactions of state Encendido. */
	if (blinkyboton_check_regionParpadeo_Parpadea_tr0_tr0(handle) == bool_true)
	{ 
		blinkyboton_effect_regionParpadeo_Parpadea_tr0(handle);
	}  else
	{
		if (blinkyboton_check_regionParpadeo_Parpadea_r1_Encendido_tr0_tr0(handle) == bool_true)
		{ 
			blinkyboton_effect_regionParpadeo_Parpadea_r1_Encendido_tr0(handle);
		} 
	}
}

/* The reactions of state Apagado. */
static void blinkyboton_react_regionParpadeo_Apagado(Blinkyboton* handle)
{
	/* The reactions of state Apagado. */
	if (blinkyboton_check_regionParpadeo_Apagado_tr0_tr0(handle) == bool_true)
	{ 
		blinkyboton_effect_regionParpadeo_Apagado_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void blinkyboton_react_main_region__entry_Default(Blinkyboton* handle)
{
	/* Default react sequence for initial entry  */
	blinkyboton_enseq_main_region_EsperaBoton_default(handle);
}

/* Default react sequence for initial entry  */
static void blinkyboton_react_regionParpadeo_Parpadea_r1__entry_Default(Blinkyboton* handle)
{
	/* Default react sequence for initial entry  */
	blinkyboton_enseq_regionParpadeo_Parpadea_r1_Encendido_default(handle);
}

/* Default react sequence for initial entry  */
static void blinkyboton_react_regionParpadeo__entry_Default(Blinkyboton* handle)
{
	/* Default react sequence for initial entry  */
	blinkyboton_enseq_regionParpadeo_Parpadea_default(handle);
}


