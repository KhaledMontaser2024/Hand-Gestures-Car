/*
    title: MUART Driver Private
    author: m.nour
    last update: 24/12/21
*/

#ifndef _MUART_HEADER_H_
#define _MUART_HEADER_H_

    #include "L_bitmath.h"
    #include "L_stdu.h"

    #define MUART_PARITY_DISABLED 0
    #define MUART_PARITY_EVEN 2
    #define MUART_PARITY_ODD 3
    
    #define MUART_ONE_STOP_BIT 1
    #define MUART_TWO_STOP_BIT 2

    #define MUART_5BIT 5
    #define MUART_6BIT 6
    #define MUART_7BIT 7
    #define MUART_8BIT 8
    #define MUART_9BIT 9

    #define MUART_BUAD9600 103    
    #define MUART_BUAD115200 8

    void SetUARTConfig(u8 ARGSetParityU8, u8 ARGSetStopBitModeU8, u8 ARGSetCharSizeU8, u8 ARGSetBuadRateConfigU8);
    u16 SerialReadFrame();
    void SerialReadStr(u8* ARGStrbufferU8PTR);
    void SerialWriterFrame(u16 ARGDataU16);
    void SerialWrieStr(u8* ARGStrbufferU8PTR);

#endif