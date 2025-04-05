#ifndef USER_NOTES
#define USER_NOTES

#include "tim.h"
#include "notes_defs.h"

TDef_NotesStatus chngTop(uint32_t top);
TDef_NotesStatus chngComp(uint32_t comp);
TDef_NotesStatus outOn(uint32_t delay);
TDef_NotesStatus outOff();

#endif