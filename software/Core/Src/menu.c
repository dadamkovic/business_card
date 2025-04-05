/**
 * @file menu.c
 * @author Daniel (daniel@techcraftblog.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "menu.h"

menuFunc menuScreen;
static uint8_t buffer[BUFFER_SIZE];
static uint32_t tail, head = 0;


uint8_t resume[] =  "Name: Daniel Adamkovic\n\r"
                    "Date of birth: 09/10/1997\n\r"
                    "Nationality: Slovak\n\r"
                    "Education: University of Zilina - Cybernetics (Masters Degree)\n\r\n\r"
                    "Work experience:\n\r"
                    "- 2021-2023 Brose Prievidza, Slovakia - Electronics Project Engineer\n\r"
                    "- 2023 - (current) Brose North America, Auburn Hills, MI - Electronics Project Engineer\n\r"
                    "About me:\n\r\n\r"
                    "Lorem ipsum....\n\r\0";


TDef_MenuStatus resolveMenu(){
  uint8_t tx_buffer[] = "Select one of below:\n\r[0] Song\n\r[1] Tetris\n\r[2] Resume\n\n\r\0";
  uint8_t sel = 0;
  CDC_Transmit_FS(tx_buffer, sizeof(tx_buffer));
  
  bufferFlush();
  while (bufferElements() == 0)HAL_Delay(100);
  bufferPop(&sel, 1);

  switch(sel - 0x30){
    case SONG_MENU:
      menuScreen = songMenu;
      break;
    case GAME_MENU:
      menuScreen = gameMenu;
      break;
    case RESUME_MENU:
      menuScreen = resumeMenu;
      break;
    default:
      menuScreen = eraseMenu;
      break;
  }

  menuScreen();

  return MENU_OK;
}


TDef_MenuStatus eraseMenu(){
  uint8_t tx_buffer[] = "_c\r\0";
  tx_buffer[0] = 0x1b;

  CDC_Transmit_FS(tx_buffer, sizeof(tx_buffer));
  HAL_Delay(100);

  return MENU_OK;
}


TDef_MenuStatus songMenu(){
  static uint8_t tx_buffer_ode[] = "! PLAYING SONG - ODE TO JOY !\n\n\r\0";
  static uint8_t tx_buffer_jingle[] = "! PLAYING SONG - JINGLE BELLS !\n\n\r\0";
  static uint8_t tx_buffer_thanks[] = "THANKS FOR LISTENING\n\r\0";
  static uint8_t tx_buffer_sel[] = "Select song:\n\r[0] Jingle Bells\n\r[1] Ode to Joy\n\r\n\r\0";
  uint8_t sel = 0;

  eraseMenu();

  CDC_Transmit_FS(tx_buffer_sel, sizeof(tx_buffer_sel));
  
  bufferFlush();
  while (bufferElements() == 0)HAL_Delay(100);
  bufferPop(&sel, 1);

  switch(sel - 0x30){
    case JINGLE_BELLS:
      eraseMenu();
      CDC_Transmit_FS(tx_buffer_jingle, sizeof(tx_buffer_jingle));
      playSong(JINGLE_BELLS);
      break;
    case ODE_TO_JOY:
      eraseMenu();
      CDC_Transmit_FS(tx_buffer_ode, sizeof(tx_buffer_ode));
      playSong(ODE_TO_JOY);
      break;
    default:
      return songMenu();
      break;
  }
  
  CDC_Transmit_FS(tx_buffer_thanks, sizeof(tx_buffer_thanks));
  HAL_Delay(1000);
  eraseMenu();

  return MENU_OK;
}


TDef_MenuStatus gameMenu(){
  uint8_t tx_buffer[] = "PLAYING TETRIS <PLACEHOLDER>\n\r\0";

  eraseMenu();

  CDC_Transmit_FS(tx_buffer, sizeof(tx_buffer));
  HAL_Delay(5000);
  eraseMenu();

  return MENU_OK;
}

TDef_MenuStatus resumeMenu(){
  //uint8_t tx_buffer1[] = "THIS IS MY RESUME <PLACEHOLDER>\n\r\0";
  uint8_t tx_buffer2[] = "PRESS ANY KEY WHEN READY\n\r\0";
  eraseMenu();

  CDC_Transmit_FS(resume, sizeof(resume));
  HAL_Delay(2000);
  CDC_Transmit_FS(tx_buffer2, sizeof(tx_buffer2));

  bufferFlush();
  while (bufferElements() == 0)HAL_Delay(100);
  bufferFlush();
  eraseMenu();

  return MENU_OK;
}


TDef_MenuStatus bufferAdd(uint8_t *data, uint32_t len){

  if((head <= tail) && ((BUFFER_SIZE-tail+head) < len))return MENU_FAIL;
  if((head > tail) && ((head - tail) < len))return MENU_FAIL;

  for(uint32_t idx=0; idx < len; idx++){
    buffer[tail] = data[idx%BUFFER_SIZE];
    tail = (tail+1) % BUFFER_SIZE; 
  }

  return MENU_OK;
}

TDef_MenuStatus bufferPop(uint8_t *buff, uint32_t len){
  
  //not enough space between head and tail
  if((head < tail) && ((tail-head) < len))return MENU_FAIL;
  //head is ahead of tail
  if((tail < head) && (BUFFER_SIZE-head+tail) < len)return MENU_FAIL;
  //buffer is empty
  if(head == tail)return MENU_FAIL;
  
  for(uint32_t idx=head; idx<len; idx++){
    buff[idx] = buffer[head%BUFFER_SIZE];
    head = (head+1) % BUFFER_SIZE;
  }

  return MENU_OK;
}

uint32_t bufferElements(){
  if(head == tail)return 0;
  if(head < tail)return (tail - head);
  if(head > tail)return (BUFFER_SIZE-head+tail);

  return MENU_OK;
}

TDef_MenuStatus bufferFlush(){
  head = 0;
  tail = 0;

  return MENU_OK;
}
