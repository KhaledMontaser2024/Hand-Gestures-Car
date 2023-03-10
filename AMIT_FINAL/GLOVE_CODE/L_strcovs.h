/*
    title: string conversion library
    author: a7
    version: 0
    last update: 9/12/22
*/

#ifndef _L_STRCOVS_H_
#define _L_STRCOVS_H_

#include <stdio.h>
#include <stdlib.h>
#include "L_bitmath.h"
#include "L_stdu.h"

void convIntToString(s64 ARGInt, u8* ARGString);
void convFloatToString(f128 ARGFloat, u8* ARGString);
s64 convStringToInt(u8* ARGString);
f128 convStringTofloat(u8* ARGString);

#endif