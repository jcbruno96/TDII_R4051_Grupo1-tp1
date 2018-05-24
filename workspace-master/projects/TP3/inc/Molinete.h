
#ifndef MOLINETE_H_
#define MOLINETE_H_

#include "sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'Molinete'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Molinete_main_region_Bloqueado,
	Molinete_main_region_Desbloqueado,
	Molinete_last_state
} MolineteStates;

/*! Type definition of the data structure for the MolineteInternal interface scope. */
typedef struct
{
	sc_integer vContador;
	sc_boolean evEmpujar_raised;
	sc_boolean evMoneda_raised;
} MolineteInternal;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define MOLINETE_MAX_ORTHOGONAL_STATES 1

/*! 
 * Type definition of the data structure for the Molinete state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	MolineteStates stateConfVector[MOLINETE_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	MolineteInternal internal;
} Molinete;

/*! Initializes the Molinete state machine data structures. Must be called before first usage.*/
extern void molinete_init(Molinete* handle);

/*! Activates the state machine */
extern void molinete_enter(Molinete* handle);

/*! Deactivates the state machine */
extern void molinete_exit(Molinete* handle);

/*! Performs a 'run to completion' step. */
extern void molinete_runCycle(Molinete* handle);



/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean molinete_isActive(const Molinete* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean molinete_isFinal(const Molinete* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean molinete_isStateActive(const Molinete* handle, MolineteStates state);

#ifdef __cplusplus
}
#endif 

#endif /* MOLINETE_H_ */
