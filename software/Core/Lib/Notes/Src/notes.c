/**
 * @file notes.c
 * @author Daniel Adamkovic (dadamkovic@protonmail.ch)
 * @brief 
 * @version 0.1
 * @date 15-10-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "notes.h"

uint16_t u16_notes[] = {16,17,18,19,20,21,23,24,26,28,29,30};

TDef_changeCompare *changeCompare;
TDef_changeTop *changeTop;
TDef_outputOn *outputOn;
TDef_OutputOff *outputOff;
uint16_t u16_base_beat;

TDef_NotesStatus setupNotes(TDef_changeCompare *usrChngComp,
                            TDef_changeTop *usrChngTop,
                            TDef_outputOn *usrOutputOn,
                            TDef_OutputOff *usrOutputOff)
{
changeCompare = usrChngComp;
changeTop = usrChngTop;
outputOn = usrOutputOn;
outputOff = usrOutputOff;

return NOTES_OK;
}

TDef_NotesStatus setBeat(uint16_t usrBeat){
    u16_base_beat = usrBeat;
    return NOTES_OK;
}


TDef_NotesStatus playNote(Enum_Notes note, uint8_t octave, uint8_t beats){
    uint16_t freq = u16_notes[note];
    freq *= octave;
    uint16_t top = (uint16_t)TIMER_FREQ / freq;
    changeTop(top);
    changeCompare(top/2);
    
    outputOn(u16_base_beat*beats);
    HAL_Delay(u16_base_beat/2);
    
    return NOTES_OK;
}

