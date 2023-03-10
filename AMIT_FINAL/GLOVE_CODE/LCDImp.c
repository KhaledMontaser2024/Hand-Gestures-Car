/*
title: LCD Driver imp
author:M.Nour
version: 0
date:25/11/2022

*/

#include "LCDHeader.h"

void LcdInit(u8 ARGSetNumOfLinesU8)
{   
    _delay_ms(100);
    //data bits from LSB to MSB 
    SetPinDir(PA, pin4, OUTPUT);
    SetPinDir(PA, pin5, OUTPUT);
    SetPinDir(PA, pin6, OUTPUT);
    SetPinDir(PA, pin7, OUTPUT);

    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);

    //Rs
    SetPinDir(PB, pin1, OUTPUT);
    //RW
    SetPinDir(PB, pin2, OUTPUT);
    //EN
    SetPinDir(PB, pin3, OUTPUT);

    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    SetPinValue(PB, pin3, LOW);
    
    // init
    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, HIGH);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);

    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);

    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);

    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, ARGSetNumOfLinesU8);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);

    ClearLcd();
    ReturnHomeLcd();
   
    return;
}
void ClearLcd()
{
    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);

    SetPinValue(PA, pin4, HIGH);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);
    _delay_ms(5);
    return;
}
void ReturnHomeLcd()
{   
    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);

    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, HIGH);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);
    _delay_ms(5);
    return;
}
void SetCursorSettings(u8 ARGSetCursorONorOFFU8,u8 ARGSetCursorBlinkU8)
{
    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);

    SetPinValue(PA, pin4, ARGSetCursorBlinkU8 == LCDON ? HIGH : LOW);
    SetPinValue(PA, pin5, ARGSetCursorONorOFFU8 == LCDON ? HIGH : LOW);
    SetPinValue(PA, pin6, HIGH);
    SetPinValue(PA, pin7, HIGH);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);
   _delay_ms(5);

    return;
}
void ShiftCursorDisplay(u8 ARGSetShiftCursorDisplayU8, u8 ARGShiftLeftorRightU8)
{
    SetPinValue(PA, pin4, HIGH);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);

    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, ARGShiftLeftorRightU8);   // choose direction left or right
    SetPinValue(PA, pin7, ARGSetShiftCursorDisplayU8); // choose which to shift cursor or display
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);
    _delay_ms(5);
    
    return;
}
void SetPosition(u8 ARGSetLineU8,u8 ARGSetCharacterU8)
{
    switch (ARGSetLineU8)
    {
    case LCD1Line:
        ARGSetCharacterU8 = ARGSetCharacterU8 > 0xf ? 0xf : ARGSetCharacterU8; //line 1
        break;
    case LCD2Line:
        ARGSetCharacterU8 = ARGSetCharacterU8 > 0xf ? 0x4f : ARGSetCharacterU8 + 0x40; // line 2
        break;
    default:
        break;
    }
        SetPinValue(PA, pin4, GET_BIT(ARGSetCharacterU8 ,4) ?  HIGH : LOW);
        SetPinValue(PA, pin5, GET_BIT(ARGSetCharacterU8 ,5) ?  HIGH : LOW);
        SetPinValue(PA, pin6, GET_BIT(ARGSetCharacterU8 ,6) ?  HIGH : LOW);
        SetPinValue(PA, pin7, HIGH);
    
        SetPinValue(PB, pin1, LOW);
        SetPinValue(PB, pin2, LOW);
        _delay_ms(1);
        SetPinValue(PB, pin3, HIGH);
        _delay_ms(1);
        SetPinValue(PB, pin3, LOW);
        _delay_ms(1);

        SetPinValue(PA, pin4,GET_BIT(ARGSetCharacterU8 ,0) ?  HIGH : LOW );
        SetPinValue(PA, pin5,GET_BIT(ARGSetCharacterU8 ,1) ?  HIGH : LOW );
        SetPinValue(PA, pin6,GET_BIT(ARGSetCharacterU8 ,2) ?  HIGH : LOW );
        SetPinValue(PA, pin7,GET_BIT(ARGSetCharacterU8 ,3) ?  HIGH : LOW );
    
        SetPinValue(PB, pin1, LOW);
        SetPinValue(PB, pin2, LOW);
        _delay_ms(1);
        SetPinValue(PB, pin3, HIGH);
        _delay_ms(1);
        SetPinValue(PB, pin3, LOW);
        _delay_ms(1);
        _delay_ms(5);
        return;
}
void WriteLcd(u8* ARGStringU8ptr)
{
    u8 cnt = 0 ;
    while ('\0' != ARGStringU8ptr[cnt])
    {   
        if(ARGStringU8ptr[cnt] == '\n')
        {
            SetPosition(LCD2Line,0);
        }
        else
        {
        SetPinValue(PA, pin4, GET_BIT(ARGStringU8ptr[cnt], 4) ? HIGH : LOW);
        SetPinValue(PA, pin5, GET_BIT(ARGStringU8ptr[cnt], 5) ? HIGH : LOW);
        SetPinValue(PA, pin6, GET_BIT(ARGStringU8ptr[cnt], 6) ? HIGH : LOW);
        SetPinValue(PA, pin7, GET_BIT(ARGStringU8ptr[cnt], 7) ? HIGH : LOW);
    
        SetPinValue(PB, pin1, HIGH);
        SetPinValue(PB, pin2, LOW);
        _delay_ms(1);
        SetPinValue(PB, pin3, HIGH);
        _delay_ms(1);
        SetPinValue(PB, pin3, LOW);
        _delay_ms(1);

        SetPinValue(PA, pin4, GET_BIT(ARGStringU8ptr[cnt], 0) ? HIGH : LOW);
        SetPinValue(PA, pin5, GET_BIT(ARGStringU8ptr[cnt], 1) ? HIGH : LOW);
        SetPinValue(PA, pin6, GET_BIT(ARGStringU8ptr[cnt], 2) ? HIGH : LOW);
        SetPinValue(PA, pin7, GET_BIT(ARGStringU8ptr[cnt], 3) ? HIGH : LOW);
    
        SetPinValue(PB, pin1, HIGH);
        SetPinValue(PB, pin2, LOW);
        _delay_ms(1);
        SetPinValue(PB, pin3, HIGH);
        _delay_ms(1);
        SetPinValue(PB, pin3, LOW);
        _delay_ms(1); 
        } 
        cnt++;
    }
    
    return;
}

