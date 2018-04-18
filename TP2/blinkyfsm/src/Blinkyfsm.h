
#ifndef BLINKYFSM_H_
#define BLINKYFSM_H_

#include "sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'blinkyfsm'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Blinkyfsm_main_region_Apagado,
	Blinkyfsm_main_region_Encendido,
	Blinkyfsm_last_state
} BlinkyfsmStates;

/*! Type definition of the data structure for the BlinkyfsmInternal interface scope. */
typedef struct
{
	sc_boolean evCambia_raised;
} BlinkyfsmInternal;

/*! Type definition of the data structure for the BlinkyfsmTimeEvents interface scope. */
typedef struct
{
	sc_boolean blinkyfsm_tev0_raised;
} BlinkyfsmTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define BLINKYFSM_MAX_ORTHOGONAL_STATES 1

/*! 
 * Type definition of the data structure for the Blinkyfsm state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	BlinkyfsmStates stateConfVector[BLINKYFSM_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	BlinkyfsmInternal internal;
	BlinkyfsmTimeEvents timeEvents;
} Blinkyfsm;

/*! Initializes the Blinkyfsm state machine data structures. Must be called before first usage.*/
extern void blinkyfsm_init(Blinkyfsm* handle);

/*! Activates the state machine */
extern void blinkyfsm_enter(Blinkyfsm* handle);

/*! Deactivates the state machine */
extern void blinkyfsm_exit(Blinkyfsm* handle);

/*! Performs a 'run to completion' step. */
extern void blinkyfsm_runCycle(Blinkyfsm* handle);

/*! Raises a time event. */
extern void blinkyfsm_raiseTimeEvent(const Blinkyfsm* handle, sc_eventid evid);


/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean blinkyfsm_isActive(const Blinkyfsm* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean blinkyfsm_isFinal(const Blinkyfsm* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean blinkyfsm_isStateActive(const Blinkyfsm* handle, BlinkyfsmStates state);

#ifdef __cplusplus
}
#endif 

#endif /* BLINKYFSM_H_ */
