
#ifndef BLINKYCOMPUESTO_H_
#define BLINKYCOMPUESTO_H_

#include "sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'blinkyCompuesto'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	BlinkyCompuesto_main_region_Parpadea,
	BlinkyCompuesto_main_region_Parpadea_r1_Apagado,
	BlinkyCompuesto_main_region_Parpadea_r1_Encendido,
	BlinkyCompuesto_main_region_Apagado,
	BlinkyCompuesto_last_state
} BlinkyCompuestoStates;

/*! Type definition of the data structure for the BlinkyCompuestoInternal interface scope. */
typedef struct
{
	sc_boolean evToggle_raised;
	sc_boolean evBlinky_raised;
} BlinkyCompuestoInternal;

/*! Type definition of the data structure for the BlinkyCompuestoTimeEvents interface scope. */
typedef struct
{
	sc_boolean blinkyCompuesto_tev0_raised;
	sc_boolean blinkyCompuesto_tev1_raised;
} BlinkyCompuestoTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define BLINKYCOMPUESTO_MAX_ORTHOGONAL_STATES 1

/*! 
 * Type definition of the data structure for the BlinkyCompuesto state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	BlinkyCompuestoStates stateConfVector[BLINKYCOMPUESTO_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	BlinkyCompuestoInternal internal;
	BlinkyCompuestoTimeEvents timeEvents;
} BlinkyCompuesto;

/*! Initializes the BlinkyCompuesto state machine data structures. Must be called before first usage.*/
extern void blinkyCompuesto_init(BlinkyCompuesto* handle);

/*! Activates the state machine */
extern void blinkyCompuesto_enter(BlinkyCompuesto* handle);

/*! Deactivates the state machine */
extern void blinkyCompuesto_exit(BlinkyCompuesto* handle);

/*! Performs a 'run to completion' step. */
extern void blinkyCompuesto_runCycle(BlinkyCompuesto* handle);

/*! Raises a time event. */
extern void blinkyCompuesto_raiseTimeEvent(const BlinkyCompuesto* handle, sc_eventid evid);


/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean blinkyCompuesto_isActive(const BlinkyCompuesto* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean blinkyCompuesto_isFinal(const BlinkyCompuesto* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean blinkyCompuesto_isStateActive(const BlinkyCompuesto* handle, BlinkyCompuestoStates state);

#ifdef __cplusplus
}
#endif 

#endif /* BLINKYCOMPUESTO_H_ */
