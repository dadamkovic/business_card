#include "user_notes.h"

TDef_NotesStatus chngTop(uint32_t top)
{

    __HAL_TIM_SET_AUTORELOAD(&htim3, top);

    return NOTES_OK;
}

TDef_NotesStatus chngComp(uint32_t comp)
{
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, comp);
    return NOTES_OK;
}

TDef_NotesStatus outOn(uint32_t delay){
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
    HAL_Delay(delay);
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4);
    return NOTES_OK;
}

TDef_NotesStatus outOff(){
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4);
    return NOTES_OK;
}

