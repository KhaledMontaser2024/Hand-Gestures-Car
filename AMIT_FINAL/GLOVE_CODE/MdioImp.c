/*
title: DIO Driver private
author:M.Nour
version: 0
date:12/11/2022
*/
#include "MdioHeader.h"
#include "MdioPrivate.h"



void SetPortDir(u8 ARGPortNameU8,u8 ARGPortDirU8)
{
    switch (ARGPortNameU8)
    {
    case PA:
        ARGPortDirU8 = ARGPortDirU8 == LOWER_NIPPLE_INPUT ? CLEAR_NIBBLE_LOW(PORTA->ddr) : ARGPortDirU8;
        ARGPortDirU8 = ARGPortDirU8 == LOWER_NIPPLE_OUTPUT ? SET_NIBBLE_LOW(PORTA->ddr) : ARGPortDirU8 ;
        ARGPortDirU8 = ARGPortDirU8 == HIGHER_NIPPLE_INPUT ? CLEAR_NIBBLE_HIGH(PORTA->ddr) : ARGPortDirU8;
        ARGPortDirU8 = ARGPortDirU8 == HIGHER_NIPPLE_OUTPUT ? SET_NIBBLE_HIGH(PORTA->ddr) : ARGPortDirU8 ;
        PORTA->ddr=ARGPortDirU8;
         if(ARGPortDirU8==INPUT_PULLUP)
        {   
            CLEAR_BYTE(PORTA->ddr);
            SET_BYTE(PORTA->port);
        }
        if(ARGPortDirU8==LOWER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_LOW(PORTA->ddr);
            SET_NIBBLE_LOW(PORTA->port);
        }
         if(ARGPortDirU8==HIGHER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_HIGH(PORTA->ddr);
            SET_NIBBLE_HIGH(PORTA->port);
        }
        break;
    case PB:
        ARGPortDirU8 = ARGPortDirU8 == LOWER_NIPPLE_INPUT ? CLEAR_NIBBLE_LOW(PORTB->ddr) : ARGPortDirU8;
        ARGPortDirU8 = ARGPortDirU8 == LOWER_NIPPLE_OUTPUT ? SET_NIBBLE_LOW(PORTB->ddr) : ARGPortDirU8 ;
        ARGPortDirU8 = ARGPortDirU8 == HIGHER_NIPPLE_INPUT ? CLEAR_NIBBLE_HIGH(PORTB->ddr) : ARGPortDirU8;
        ARGPortDirU8 = ARGPortDirU8 == HIGHER_NIPPLE_OUTPUT ? SET_NIBBLE_HIGH(PORTB->ddr) : ARGPortDirU8 ;
        PORTB->ddr=ARGPortDirU8;
         if(ARGPortDirU8==INPUT_PULLUP)
        {   
            CLEAR_BYTE(PORTB->ddr);
            SET_BYTE(PORTB->port);
        }
        if(ARGPortDirU8==LOWER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_LOW(PORTB->ddr);
            SET_NIBBLE_LOW(PORTB->port);
        }
         if(ARGPortDirU8==HIGHER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_HIGH(PORTB->ddr);
            SET_NIBBLE_HIGH(PORTB->port);
        }
        break;
    case PC:
        ARGPortDirU8 = ARGPortDirU8 == LOWER_NIPPLE_INPUT ? CLEAR_NIBBLE_LOW(PORTC->ddr) : ARGPortDirU8;
        ARGPortDirU8 = ARGPortDirU8 == LOWER_NIPPLE_OUTPUT ? SET_NIBBLE_LOW(PORTC->ddr) : ARGPortDirU8 ;
        ARGPortDirU8 = ARGPortDirU8 == HIGHER_NIPPLE_INPUT ? CLEAR_NIBBLE_HIGH(PORTC->ddr) : ARGPortDirU8;
        ARGPortDirU8 = ARGPortDirU8 == HIGHER_NIPPLE_OUTPUT ? SET_NIBBLE_HIGH(PORTC->ddr) : ARGPortDirU8 ;
        PORTC->ddr=ARGPortDirU8;
        if(ARGPortDirU8==INPUT_PULLUP)
        {   
            CLEAR_BYTE(PORTC->ddr);
            SET_BYTE(PORTC->port);
        }
        if(ARGPortDirU8==LOWER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_LOW(PORTC->ddr);
            SET_NIBBLE_LOW(PORTC->port);
        }
        if(ARGPortDirU8==HIGHER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_HIGH(PORTC->ddr);
            SET_NIBBLE_HIGH(PORTC->port);
        }
        break;
    case PD:
        ARGPortDirU8 = ARGPortDirU8 == LOWER_NIPPLE_INPUT ? CLEAR_NIBBLE_LOW(PORTD->ddr) : ARGPortDirU8;
        ARGPortDirU8 = ARGPortDirU8 == LOWER_NIPPLE_OUTPUT ? SET_NIBBLE_LOW(PORTD->ddr) : ARGPortDirU8 ;
        ARGPortDirU8 = ARGPortDirU8 == HIGHER_NIPPLE_INPUT ? CLEAR_NIBBLE_HIGH(PORTD->ddr) : ARGPortDirU8;
        ARGPortDirU8 = ARGPortDirU8 == HIGHER_NIPPLE_OUTPUT ? SET_NIBBLE_HIGH(PORTD->ddr) : ARGPortDirU8 ;
        PORTD->ddr=ARGPortDirU8;
         if(ARGPortDirU8==INPUT_PULLUP)
        {   
            CLEAR_BYTE(PORTD->ddr);
            SET_BYTE(PORTD->port);
        }
        if(ARGPortDirU8==LOWER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_LOW(PORTD->ddr);
            SET_NIBBLE_LOW(PORTD->port);
        }
         if(ARGPortDirU8==HIGHER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_HIGH(PORTD->ddr);
            SET_NIBBLE_HIGH(PORTD->port);
        }
        break;
    default:
        break;
    }
    return;
}
void SetPortValue(u8 ARGPortNameU8,u8 ARGPortValueU8)
{
    switch (ARGPortNameU8)
    {
    case PA:
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_LOW ? CLEAR_NIBBLE_LOW(PORTA->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_HIGH ? SET_NIBBLE_LOW(PORTA->port) : ARGPortValueU8 ;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_LOW ? CLEAR_NIBBLE_HIGH(PORTA->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_HIGH ? SET_NIBBLE_HIGH(PORTA->port) : ARGPortValueU8;
        PORTA->port=ARGPortValueU8;
        break;
    case PB:
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_LOW ? CLEAR_NIBBLE_LOW(PORTB->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_HIGH ? SET_NIBBLE_LOW(PORTB->port) : ARGPortValueU8 ;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_LOW ? CLEAR_NIBBLE_HIGH(PORTB->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_HIGH ? SET_NIBBLE_HIGH(PORTB->port) : ARGPortValueU8;
        PORTB->port=ARGPortValueU8;
        break;
    case PC:
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_LOW ? CLEAR_NIBBLE_LOW(PORTC->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_HIGH ? SET_NIBBLE_LOW(PORTC->port) : ARGPortValueU8 ;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_LOW ? CLEAR_NIBBLE_HIGH(PORTC->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_HIGH ? SET_NIBBLE_HIGH(PORTC->port) : ARGPortValueU8;
        PORTC->port=ARGPortValueU8;
        break;
    case PD:
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_LOW ? CLEAR_NIBBLE_LOW(PORTD->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_HIGH ? SET_NIBBLE_LOW(PORTD->port) : ARGPortValueU8 ;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_LOW ? CLEAR_NIBBLE_HIGH(PORTD->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_HIGH ? SET_NIBBLE_HIGH(PORTD->port) : ARGPortValueU8;
        PORTD->port=ARGPortValueU8;
        break;
    default:
        break;
    }
    return;
}
u8 ReadPortValue(u8 ARGPortNameU8)
{
    switch (ARGPortNameU8)
    {
    case PA:
        return PORTA->pin;
        break;
    case PB:
        return PORTB->pin;
        break;
    case PC:
        return PORTC->pin;
        break;
    case PD:
        return PORTD->pin;
        break;
    default:
        break;
    }
    return 0;
}
void SetPinDir(u8 ARGPortNameU8,u8 ARGPinNumU8,u8 ARGPinDirU8)
{
    switch(ARGPinDirU8){
        case INPUT:
            switch (ARGPortNameU8)
            {
            case PA:
                CLEAR_BIT(PORTA->ddr,ARGPinNumU8);
                break;
            case PB:
                CLEAR_BIT(PORTB->ddr,ARGPinNumU8);
                break;
            case PC:
                CLEAR_BIT(PORTC->ddr,ARGPinNumU8);
                break;
            case PD:
                CLEAR_BIT(PORTD->ddr,ARGPinNumU8);
                break;
            default:
                break;
            }
            break;
        case OUTPUT:
            switch (ARGPortNameU8)
            {
            case PA:
                SET_BIT(PORTA->ddr,ARGPinNumU8);
                break;
            case PB:
                SET_BIT(PORTB->ddr,ARGPinNumU8);
                break;
            case PC:
                SET_BIT(PORTC->ddr,ARGPinNumU8);
                break;
            case PD:
                SET_BIT(PORTD->ddr,ARGPinNumU8);
                break;
            default:
                break;
            }
    }  
    return;   
}
void SetPinValue(u8 ARGPortNameU8,u8 ARGPinNumU8,u8 ARGPinValueU8)
{
    switch(ARGPinValueU8){
        case LOW:
            switch (ARGPortNameU8)
            {
            case PA:
                CLEAR_BIT(PORTA->port,ARGPinNumU8);
                break;
            case PB:
                CLEAR_BIT(PORTB->port,ARGPinNumU8);
                break;
            case PC:
                CLEAR_BIT(PORTC->port,ARGPinNumU8);
                break;
            case PD:
                CLEAR_BIT(PORTD->port,ARGPinNumU8);
                break;
            default:
                break;
            }
            break;
        case HIGH:
            switch (ARGPortNameU8)
            {
            case PA:
                SET_BIT(PORTA->port,ARGPinNumU8);
                break;
            case PB:
                SET_BIT(PORTB->port,ARGPinNumU8);
                break;
            case PC:
                SET_BIT(PORTC->port,ARGPinNumU8);
                break;
            case PD:
                SET_BIT(PORTD->port,ARGPinNumU8);
                break;
            default:
                break;
            }
            break;
    }

   return;         
}
u8 ReadPinValue(u8 ARGPortNameU8,u8 ARGPinNumU8)
{
    switch (ARGPortNameU8)
    {
    case PA:
        return GET_BIT(PORTA->pin,ARGPinNumU8);
        break;
    case PB:
        return GET_BIT(PORTB->pin,ARGPinNumU8);
        break;
    case PC:
       return GET_BIT(PORTC->pin,ARGPinNumU8);
        break;
    case PD:
       return GET_BIT(PORTD->pin,ARGPinNumU8);
        break;
    default:
        break;
    }
    return 0;
}
void TogglePort(u8 ARGPortNameU8)
{
    switch (ARGPortNameU8)
    {
    case PA:
        TOGGLE_BYTE(PORTA -> port);
        break;
    case PB:
        TOGGLE_BYTE(PORTB -> port);
        break;
    case PC:
        TOGGLE_BYTE(PORTC -> port);
        break;
    case PD:
        TOGGLE_BYTE(PORTD -> port);
        break;    
    default:
        break;
    }
}
void TogglePin(u8 ARGPortNameU8, u8 ARGPinNumU8)
{
    switch (ARGPortNameU8)
    {
    case PA:
        TOGGLE_BIT(PORTA -> port, ARGPinNumU8);
        break;
    case PB:
        TOGGLE_BIT(PORTB -> port, ARGPinNumU8);
        break;
    case PC:
        TOGGLE_BIT(PORTC -> port, ARGPinNumU8);
        break;
    case PD:
        TOGGLE_BIT(PORTD -> port, ARGPinNumU8);
        break;    
    default:
        break;
    }
}