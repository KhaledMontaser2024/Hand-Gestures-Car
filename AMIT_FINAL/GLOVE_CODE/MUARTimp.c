/*
    title: MUART Driver imp
    author: m.nour
    last update: 24/12/21
*/

#include "MUARTHeader.h"
#include "MUARTPrivate.h"

void SetUARTConfig(u8 ARGSetParityU8, u8 ARGSetStopBitModeU8, u8 ARGSetCharSizeU8, u8 ARGSetBuadRateConfigU8)
{   
    SET_BIT(UCSRC, ursel);
    switch (ARGSetParityU8)
    {
    case MUART_PARITY_DISABLED:
        CLEAR_BIT(UCSRC, upm0);
        CLEAR_BIT(UCSRC, upm1);
        break;
    case MUART_PARITY_ODD:
        CLEAR_BIT(UCSRC, upm0);
        SET_BIT(UCSRC, upm1);
        break;
    case MUART_PARITY_EVEN:
        SET_BIT(UCSRC, upm0);
        SET_BIT(UCSRC, upm1);
        break;
    default:
        break;
    }
    switch (ARGSetStopBitModeU8)
    {
    case MUART_ONE_STOP_BIT:
        CLEAR_BIT(UCSRC, usbs);
        break;
    case MUART_TWO_STOP_BIT:
        SET_BIT(UCSRC, usbs);
        break;
    default:
        break;
    }
    switch (ARGSetCharSizeU8)
    {
    case MUART_5BIT:
        CLEAR_BIT(UCSRC, ucsz0);        
        CLEAR_BIT(UCSRC, ucsz1);
        CLEAR_BIT(UCSRB, ucsz2);        
        break;
    case MUART_6BIT:
        SET_BIT(UCSRC, ucsz0);
        CLEAR_BIT(UCSRC, ucsz1);
        CLEAR_BIT(UCSRB, ucsz2);
        break;
    case MUART_7BIT:
        CLEAR_BIT(UCSRC, ucsz0);
        SET_BIT(UCSRC, ucsz1);
        CLEAR_BIT(UCSRB, ucsz2);
        break;
    case MUART_8BIT:
        SET_BIT(UCSRC, ucsz0);
        SET_BIT(UCSRC, ucsz1);
        CLEAR_BIT(UCSRB, ucsz2);
        break;
    case MUART_9BIT:
        SET_BIT(UCSRC, ucsz0);
        SET_BIT(UCSRC, ucsz1);
        SET_BIT(UCSRB, ucsz2);
        break;
    default:
        break;
    }
    CLEAR_BIT(UCSRC, ursel);
    CLEAR_BYTE(UBRRH);
    UBRRL = ARGSetBuadRateConfigU8;
    return;
}
u16 SerialReadFrame()
{   
    CLEAR_BIT(UCSRB, txen);
    SET_BIT(UCSRB, rxen);
    while(0 == GET_BIT(UCSRA, rxc))
    {
        asm("NOP");
    }
    return GET_BIT(UCSRB, rxb8) << 9 | UDR ;
}
void SerialReadStr(u8* ARGStrbufferU8PTR)
{   
    u16 len = 0;
    u8 charbuff;
    charbuff = SerialReadFrame();
    while('\0' != charbuff && '\n' != charbuff)
    {
        ARGStrbufferU8PTR[len] = charbuff;
        len++;
        charbuff = SerialReadFrame();
    }
    ARGStrbufferU8PTR[len-1] = '\0';
    return;
}
void SerialWriterFrame(u16 ARGDataU16)
{
    CLEAR_BIT(UCSRB, rxen);
    SET_BIT(UCSRB, txen);
    while(0 == GET_BIT(UCSRA, udre))
    {
        asm("NOP");
    }
    if(1 == GET_BIT(ARGDataU16, 9))
    {
        SET_BIT(UCSRB, txb8);
    }
    else
    {
        CLEAR_BIT(UCSRB, txb8);
    }
    UDR = (u8) ARGDataU16;
    while (0 == GET_BIT(UCSRA, txc))
    {
        asm("NOP");
    }
    return;
}
void SerialWrieStr(u8* ARGStrbufferU8PTR)
{
    u16 len = 0;
    while('\0' != ARGStrbufferU8PTR[len])
    {
        SerialWriterFrame((u16)ARGStrbufferU8PTR[len]);
        len++;
    }
    return;
}