/**
 * @file notes.h
 * @author Daniel Adamkovic (dadamkovic@protonmail.ch)
 * @brief 
 * @version 0.1
 * @date 15-10-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _NOTES_H_
#define _NOTES_H_

#define TIMER_FREQ 1000000
#define TIMER_MAX 65535

#include "stm32f0xx_hal.h" //replace with device specific include
#include "notes_defs.h"

TDef_NotesStatus setupNotes(TDef_changeCompare *usrChngComp,
                            TDef_changeTop *usrChngTop,
                            TDef_outputOn *usrOutputOn,
                            TDef_OutputOff *usrOutputOff);

TDef_NotesStatus setBeat(uint16_t beat);
TDef_NotesStatus playNote(Enum_Notes note, uint8_t octave, uint8_t beats);
TDef_NotesStatus playSong(Tdef_SongSelection sel);

#endif