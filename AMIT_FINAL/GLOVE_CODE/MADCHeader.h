/*
title: ADC Driver Header
author:M.Nour
version: 0
date:3/12/2022

*/

#ifndef _ADCHEADER_H
#define _ADCHEADER_H

#include "L_bitmath.h"
#include "L_stdu.h"
#include <util/delay.h>

#define ADC_ON 0x00
#define ADC_OFF 0xff

#define AVCC 0x00
#define INTERNAL 0xff

#define GND 0x1f
#define BANDGAP1V22 0x1e

typedef enum adc
{
    adc0 = 0,
    adc1,
    adc2,
    adc3,
    adc4,
    adc5,
    adc6,
    adc7
}adc;

void ADCInit();
void ADC_getDigitalValue(u8 channelNum, u16* digitalValue);

#endif