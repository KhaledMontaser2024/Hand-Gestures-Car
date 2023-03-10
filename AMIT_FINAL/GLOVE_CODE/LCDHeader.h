/*
title: LCD Driver header
author:M.Nour
version: 0
date:25/11/2022

*/
#ifndef _LCD_HEADER_H
#define _LCD_HEADER_H

#include "L_stdu.h"
#include "L_bitmath.h"
#include "MdioHeader.h"
#include <util/delay.h>

#define LCD1Line LOW
#define LCD2Line HIGH
#define LCDON HIGH
#define LCDOFF LOW
#define CURSOR LOW
#define DISPLAY HIGH
#define LEFT LOW
#define RIGHT HIGH


void LcdInit(u8 ARGSetNumOfLinesU8);
void ClearLcd();
void ReturnHomeLcd();
void SetCursorSettings(u8 ARGSetCursorLCDONorOFFU8,u8 ARGSetCursorBlinkU8);
void ShiftCursorDisplay(u8 ARGSetShiftCursorDisplayU8, u8 ARGShiftLeftorRightU8);
void SetPosition(u8 ARGSetLineU8,u8 ARGSetCharacterU8);
void WriteLcd(u8* ARGStringU8ptr);
#endif