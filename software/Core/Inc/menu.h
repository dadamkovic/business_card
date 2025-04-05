/**
 * @file menu.h
 * @author Daniel (daniel@techcraftblog.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _MENU_H_
#define _MENU_H_

#include "usb_device.h"
#include "usbd_cdc_if.h"
#include "notes.h"

#define BUFFER_SIZE 128

typedef enum{
  MENU_OK,
  MENU_FAIL
}TDef_MenuStatus;

typedef enum{
  SONG_MENU,
  GAME_MENU,
  RESUME_MENU
}TDef_MenuSelect;

typedef TDef_MenuStatus (*menuFunc)();

extern menuFunc menuScreen;

TDef_MenuStatus resolveMenu();
TDef_MenuStatus loadMenu(TDef_MenuSelect sel);
TDef_MenuStatus songMenu();
TDef_MenuStatus gameMenu();
TDef_MenuStatus resumeMenu();
TDef_MenuStatus eraseMenu();

TDef_MenuStatus bufferAdd(uint8_t *data, uint32_t len);
TDef_MenuStatus bufferPop(uint8_t *buff, uint32_t len);
uint32_t bufferElements();
TDef_MenuStatus bufferFlush();

 #endif