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

#include "notes.h"

Enum_Notes jingle_bells_notes[] = {E, E, E, E, E, E, E, G, C, D, E, F, F, F, F, F, E, E, E, E, D, D, E, D, G};
uint8_t jingle_bells_beats[] =    {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 0};

Enum_Notes ode_to_joy_notes[] = {E, E, F, G, G, F, E, D, C, C, D, E, E, D, D,
                                 E, E, F, G, G, F, E,D, C, C ,D ,E, D, C, C, 
                                 D, D, E, C, D, F, E, C, D, F, E, D, C, D, G,
                                 E, E, F, G, G, F, E, D, C, C, D, E, D, C, C};
uint8_t ode_to_joy_beats[] =    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0};

#endif