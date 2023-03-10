/*
title: DIO Driver private
author:M.Nour
version: 0
date:12/11/2022
*/
#ifndef _MDIO__PRIVATE_H
#define _MDIO_PRIVATE_H
 
#include "L_bitmath.h"
#include "L_stdu.h"

typedef struct Port_type
{
    u8 pin;
    u8 ddr;
    u8 port;

}PortType;

#define PORTA ((volatile PortType*)0x39)
#define PORTB ((volatile PortType*)0x36)
#define PORTC ((volatile PortType*)0x33)
#define PORTD ((volatile PortType*)0x30)
#endif