/*------------------------------------------------------------------------------
 *                          Silicon Laboratories, Inc.
 *                           http://www.silabs.com
 *                               Copyright 2010
 *------------------------------------------------------------------------------
 *
 *    FILE:       isr_dmd.c
 *    TARGET:     Si4010
 *    TOOLCHAIN:  Generic
 *    DATE:       May 05, 2010, Wednesday
 *    RELEASE:    2.1 (MPech), ROM version 02.00, trim 3
 *
 *------------------------------------------------------------------------------
 *
 *    DESCRIPTION:
 *      This module contains the interrupt service routine for
 *      the temperature demodulator (DMD). It is triggered when
 *      a demodulator sample is ready.
 *
 *------------------------------------------------------------------------------
 *
 *    INCLUDES:
 */
#include "si4010.h"
#include "si4010_api_rom.h"
/*------------------------------------------------------------------------------
 *
 *    FUNCTION DESCRIPTION:
 *      This is the interrupt service routine for the DMD. It clears the DMD
 *      interrupt flag and calls the vDmdTs_IsrCall() which handles the
 *      interface to the demodulator and temperature sensor.
 *
 *      Use the same RB1 for all the ISR at the same priority level.
 *
 *------------------------------------------------------------------------------
 */

void    vIsr_Dmd(void) interrupt INTERRUPT_DMD using 2  // Use RB2
{
// Clear the demodulator interrupt flag 
  vDmdTs_ClearDmdIntFlag();

// Call DMD TS function that handles skipping samples and getting the sample
// from the temperature demodulator. 
  vDmdTs_IsrCall();

  return;
}

//------------------------------------------------------------------------------
 



