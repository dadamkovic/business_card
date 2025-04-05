/**
 * @file songs.h
 * @author Daniel Adamkovic (dadamkovic@protonmail.ch)
 * @brief 
 * @version 0.1
 * @date 28-01-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _SONGS_H_
#define _SONGS_H_

#include "notes_defs.h"

#define JINGLE_BELLS 0
#define ODE_TO_JOY 1

extern Enum_Notes jingle_bells_notes[];
extern uint8_t jingle_bells_beats[];

extern Enum_Notes ode_to_joy_notes[];
extern uint8_t ode_to_joy_beats[];

#endif