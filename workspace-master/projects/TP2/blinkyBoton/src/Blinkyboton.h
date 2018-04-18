
#ifndef BLINKYBOTON_H_
#define BLINKYBOTON_H_

#include "sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'blinkyboton'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Blinkyboton_main_region_EsperaBoton,
	Blinkyboton_main_region_Antirrebote,
	Blinkyboton_main_region_Presionado,
	Blinkyboton_regionParpadeo_Parpadea,
	Blinkyboton_regionParpadeo_Parpadea_r1_Apagado,
	Blinkyboton_regionParpadeo_Parpadea_r1_Encendido,
	Blinkyboton_regionParpadeo_Apagado,
	Blinkyboton_last_state
} BlinkybotonStates;

/*! Type definition of the data structure for the BlinkybotonIface interface scope. */
typedef struct
{
	sc_boolean boton;
} BlinkybotonIface;

/*! Type definition of the data structure for the BlinkybotonInternal interface scope. */
typedef struct
{
	sc_boolean evToggle_raised;
	sc_boolean evBlinky_raised;
	sc_integer deBounce;
} BlinkybotonInternal;

/*! Type definition of the data structure for the BlinkybotonTimeEvents interface scope. */
typedef struct
{
	sc_boolean blinkyboton_main_region_Antirrebote_tev0_raised;
	sc_boolean blinkyboton_tev0_raised;
} BlinkybotonTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define BLINKYBOTON_MAX_ORTHOGONAL_STATES 2

/*! 
 * Type definition of the data structure for the Blinkyboton state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	BlinkybotonStates stateConfVector[BLINKYBOTON_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	BlinkybotonIface iface;
	BlinkybotonInternal internal;
	BlinkybotonTimeEvents timeEvents;
} Blinkyboton;

/*! Initializes the Blinkyboton state machine data structures. Must be called before first usage.*/
extern void blinkyboton_init(Blinkyboton* handle);

/*! Activates the state machine */
extern void blinkyboton_enter(Blinkyboton* handle);

/*! Deactivates the state machine */
extern void blinkyboton_exit(Blinkyboton* handle);

/*! Performs a 'run to completion' step. */
extern void blinkyboton_runCycle(Blinkyboton* handle);

/*! Raises a time event. */
extern void blinkyboton_raiseTimeEvent(const Blinkyboton* handle, sc_eventid evid);

/*! Gets the value of the variable 'boton' that is defined in the default interface scope. */ 
extern sc_boolean blinkybotonIface_get_boton(const Blinkyboton* handle);
/*! Sets the value of the variable 'boton' that is defined in the default interface scope. */ 
extern void blinkybotonIface_set_boton(Blinkyboton* handle, sc_boolean value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean blinkyboton_isActive(const Blinkyboton* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean blinkyboton_isFinal(const Blinkyboton* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean blinkyboton_isStateActive(const Blinkyboton* handle, BlinkybotonStates state);

#ifdef __cplusplus
}
#endif 

#endif /* BLINKYBOTON_H_ */
