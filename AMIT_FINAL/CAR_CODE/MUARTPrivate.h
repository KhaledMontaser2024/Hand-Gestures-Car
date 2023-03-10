/*
    title: MUART Driver Private
    author: m.nour
    last update: 24/12/21
*/

#ifndef _MUART_PRIVATE_H_
#define _MUART_PRIVATE_H_

    #include "L_bitmath.h"
    #include "L_stdu.h"

    #define UDR *((volatile u8*) 0x2c)
    #define UCSRA *((u8*) 0x2b)
    #define UCSRB *((u8*) 0x2a)
    #define UCSRC *((u8*) 0x40)
    #define UBRRH UCSRC
    #define UBRRL *((u8*) 0x29)
    
    typedef enum ucsra 
    {   
        pe = 2,
        dor,
        fe,
        udre,
        txc,
        rxc
    }ucsra;

    typedef enum ucsrb
    {
        txb8,
        rxb8,
        ucsz2,
        txen,
        rxen,
        udrie,
        txcie,
        rxcie
    }ucsrb;

    typedef enum ucsrc
    {
        ucsz0 = 1,
        ucsz1,
        usbs,
        upm0,
        upm1,
        ursel = 7
    }ucsrc;

#endif