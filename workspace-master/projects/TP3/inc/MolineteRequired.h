
#ifndef MOLINETEREQUIRED_H_
#define MOLINETEREQUIRED_H_

#include "sc_types.h"
#include "Molinete.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- molineteIface_opBloquear
	- molineteIface_opDesbloquear
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/
extern void molineteIface_opBloquear(const Molinete* handle, const sc_boolean Estado);
extern void molineteIface_opDesbloquear(const Molinete* handle, const sc_boolean Estado);





#ifdef __cplusplus
}
#endif 

#endif /* MOLINETEREQUIRED_H_ */
