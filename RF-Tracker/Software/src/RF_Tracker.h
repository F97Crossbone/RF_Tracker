#ifndef _TONE_DEMO_H
#define _TONE_DEMO_H
/*------------------------------------------------------------------------------
 *                          Silicon Laboratories, Inc.
 *                           http://www.silabs.com
 *                               Copyright 2010
 *------------------------------------------------------------------------------
 *
 *    FILE:       tone_demo.h
 *    TARGET:     Si4010
 *    TOOLCHAIN:  Generic
 *    DATE:       May 05, 2010, Wednesday
 *    RELEASE:    2.1 (MPech), ROM version 02.00
 *
 *------------------------------------------------------------------------------
 *
 *    DESCRIPTION:
 *      This file defines a top level header for the tone_demo module.
 *      It should be included in all C files in the tone_demo module.
 *
 *------------------------------------------------------------------------------
 *
 *    INCLUDES:
 */
#include "si4010.h"

// Maximum length of the data buffer to transmit in bytes 
#define bTone_MaxFrameSize_c       (4)
// Requested time interval in between major frequency retuning
// events in 0.256s units. Change this value to set the periodic
// tuning interval. The output PA is turned off during tuning
// for about ~6ms 
#define wTuneInterval_c         (235U)  // 235 .. 60s 

#define FREQUENCY				(216000000.0)
#define CHANNEL_SEP				(50000.0)

#define MODE_TRANSMIT				(0)
#define MODE_START_CHANNEL_SELECT	(1)
#define MODE_CHANNEL_SELECT			(2)
#define MODE_STOP_CHANNEL_SELECT	(3)

void readbackChannel();

BYTE					channel;

// button-related

#define PTS_SIZE 10U

// 10 button presses before processing
tBsr_PtsElement xdata 	ptsArray[PTS_SIZE];

// setup control struct
tBsr_Setup		xdata	bsrSetup;

// return struct
WORD					ptsButton;

BYTE 					buttonState;

LWORD					holdStart;
BYTE					changingChannel;
BYTE					readback;
BYTE					canInc;
BYTE					mode; // 0 = default, 1 = transition into channel change, 2 = channel change, 3 = transition out of channel change

// Constant array which holds the frame
BYTE const code abTone_FrameArray[bTone_MaxFrameSize_c]
        = {0xff,0x00,0xff,0x00};

static tFCast_XoSetup xdata     rXoSetup;

/* Structure for setting up the ODS .. must be in XDATA */
  tOds_Setup xdata rOdsSetup;

/* Structure for setting up the PA .. must be in XDATA */
  tPa_Setup xdata  rPaSetup;

/* Other variables .. can be in either memory. */
  BYTE xdata    *pbFrameHead;
  LWORD         lTime;
  BYTE          bTune;
  LWORD         hour_time;
  LWORD         second_time;

//------------------------------------------------------------------------------

#endif // _TONE_DEMO_H
