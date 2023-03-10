/*
    title: bitmath library
    author: a7
    version: 2
    last update: 23/8/21
*/

#ifndef _L_BITMATH_H_
#define _L_BITMATH_H_

#define SET_BIT(REG, BIT) REG |= (0x01 << BIT)
#define CLEAR_BIT(REG, BIT) REG &= ~(0x01 << BIT)
#define TOGGLE_BIT(REG, BIT) REG ^= (0x01 << BIT) 
#define GET_BIT(REG, BIT) ((REG >> BIT) & 0x01)
#define SET_NIBBLE_LOW(REG) REG |= 0x0F
#define SET_NIBBLE_HIGH(REG) REG |= 0xF0
#define CLEAR_NIBBLE_LOW(REG) REG &= 0xF0
#define CLEAR_NIBBLE_HIGH(REG) REG &= 0x0F 
#define TOGGLE_NIBBLE_LOW(REG) REG ^= 0x0F
#define TOGGLE_NIBBLE_HIGH(REG) REG ^= 0xF0
#define SET_BYTE(REG) REG = 0xFF
#define CLEAR_BYTE(REG) REG = 0x00
#define TOGGLE_BYTE(REG) REG ^= 0xFF

#endif