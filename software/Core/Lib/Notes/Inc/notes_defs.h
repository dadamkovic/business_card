#ifndef NOTES_DEF
#define NOTES_DEF

#include "inttypes.h"

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
    B,
    END
}Enum_Notes;

typedef enum{
    JINGLE_BELLS,
    ODE_TO_JOY
}Tdef_SongSelection;

typedef TDef_NotesStatus (TDef_changeCompare)(uint32_t comp);
typedef TDef_NotesStatus (TDef_changeTop)(uint32_t top);
typedef TDef_NotesStatus (TDef_outputOn)(uint32_t duration);
typedef TDef_NotesStatus (TDef_OutputOff)();

#endif