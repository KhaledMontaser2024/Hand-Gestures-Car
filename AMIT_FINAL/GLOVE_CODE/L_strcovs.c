 /*
    title: string conversion library
    author: a7
    version: 0
    last update: 9/12/22
*/

#include "L_strcovs.h"

void convIntToString(s64 ARGInt, u8* ARGString)
{
    itoa(ARGInt, (char*)ARGString, 10);
    return;
}
s64 convStringToInt(u8* ARGString)
{
   return atoi((char*)ARGString);
}
f128 convStringTofloat(u8* ARGString)
{
    return atof((char*)ARGString);
}
