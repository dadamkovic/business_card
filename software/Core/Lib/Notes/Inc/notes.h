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

#include "stm32f0xx_hal.h"

typedef enum{
    NOTES_OK,
    NOTES_FAIL
}TDef_NotesStatus;

typedef enum{
    C,
    C_MOL,
    D,
    D_MOL,
    E,
    F,
    F_MOL,
    G,
    G_MOL,
    A,
    A_MOL,
    B
}Enum_Notes;

typedef TDef_NotesStatus (TDef_changeCompare)(uint32_t comp);
typedef TDef_NotesStatus (TDef_changeTop)(uint32_t top);
typedef TDef_NotesStatus (TDef_outputOn)(uint32_t duration);
typedef TDef_NotesStatus (TDef_OutputOff)();

TDef_NotesStatus setupNotes(TDef_changeCompare *usrChngComp,
                            TDef_changeTop *usrChngTop,
                            TDef_outputOn *usrOutputOn,
                            TDef_OutputOff *usrOutputOff);

TDef_NotesStatus setBeat(uint16_t beat);
TDef_NotesStatus playNote(Enum_Notes note, uint8_t octave, uint8_t beats);

#endif