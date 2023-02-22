/*------------------------------------------------------------------------------
 *                          Silicon Laboratories, Inc.
 *                           http://www.silabs.com
 *                               Copyright 2010
 *------------------------------------------------------------------------------
 *
 *    FILE:       isr_rtc.c
 *    TARGET:     Si4010
 *    TOOLCHAIN:  Generic
 *    DATE:       May 05, 2010, Wednesday
 *    RELEASE:    2.1 (MPech), ROM version 02.00, trim 3
 *
 *------------------------------------------------------------------------------
 *
 *    DESCRIPTION:
 *      This module contains the interrupt service routine for
 *      the real time clock (RTC). It is triggered when
 *      a RTC timer times out. The RTC must be set from main
 *      application and in this example it assumes that it is set
 *      to tick at 5ms intervals.
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
 *      This is the interrupt service routine for RTC tailored
 *      for tone example ONLY! In regular applicaion the BSR
 *      service routine would be called from here as well.
 *
 *      Use the same RB1 for all the ISR at the same priority level.
 *
 *------------------------------------------------------------------------------
 */

void    vIsr_Rtc(void) interrupt INTERRUPT_RTC using 1  // Use RB1
{

// Clear the RTL interrupt flag 
  RTC_CTRL &= (~M_RTC_INT);

// Since we are ticking at 5ms, add 5 to the master time to keep
// master time units at [ms]
  vSys_IncMasterTime( 5UL );

  vBsr_Service();
}

//------------------------------------------------------------------------------




