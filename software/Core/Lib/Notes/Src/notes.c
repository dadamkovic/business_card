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
#include "notes_defs.h"
#include "songs.h"

uint16_t u16_notes[] = {16, 17, 18, 19, 20, 21, 23, 24, 26, 28, 29, 30};

TDef_changeCompare *changeCompare;
TDef_changeTop *changeTop;
TDef_outputOn *outputOn;
TDef_OutputOff *outputOff;
uint16_t u16_base_beat;

/**
 * @brief Performs one-time-only setup needed for the nodes library to function
 *
 * @param usrChngComp Function that changes compare value of the oyutput register
 * @param usrChngTop Function that changes the maximum value of the timer counter
 * @param usrOutputOn Function that turns on the timer
 * @param usrOutputOff Function that turns off the timer
 * @return TDef_NotesStatus
 */
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

/**
 * @brief Changes the duration of one beat
 *
 * @param usrBeat Beatu dration in ms
 * @return TDef_NotesStatus
 */
TDef_NotesStatus setBeat(uint16_t usrBeat)
{
  u16_base_beat = usrBeat;
  return NOTES_OK;
}

TDef_NotesStatus playNote(Enum_Notes note, uint8_t octave, uint8_t beats)
{
  uint16_t freq = u16_notes[note];
  freq *= octave;
  uint16_t top = (uint16_t)TIMER_FREQ / freq;
  changeTop(top);
  changeCompare(top / 2);

  outputOn(u16_base_beat * beats);
  HAL_Delay(u16_base_beat / 2);

  return NOTES_OK;
}


TDef_NotesStatus playSong(Tdef_SongSelection sel)
{
  Enum_Notes *song_notes = NULL;
  uint8_t *song_beats = NULL;

  switch (sel)
  {
    case JINGLE_BELLS:
      song_notes = jingle_bells_notes;
      song_beats = jingle_bells_beats;
      break;
    case ODE_TO_JOY:
      song_notes = ode_to_joy_notes;
      song_beats = ode_to_joy_beats;
      break;
  }

  if(song_notes == NULL || song_beats == NULL)return NOTES_FAIL;

  uint8_t idx = 0;

  while(song_notes[idx] != END){
    playNote(song_notes[idx], 2, song_beats[idx]);
    idx++;
  }
  return NOTES_OK;
}
