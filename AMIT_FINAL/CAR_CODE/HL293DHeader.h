/*
    title: L293(H bridge) Driver Header
    author: Khaled Montaser
*/
#ifndef _HL293D_HEADER_H
#define _HL293D_HEADER_H

    #include"L_stdu.h"
    #include "avr/io.h"

    #define FORWARD 0
    #define BACKWARD 1
   // #define RIGHT 2
   // #define LEFT 3
    #define STOP 4
    #define MOTOR_A 0
    #define MOTOR_B 1


    void L293D_Init();
    void L293D_SetMotorDir(u8 ARGSelectMotorU8,u8 ARGSetMotorU8);
    void L293D_SetMotorSpeed( u8 ARGSetMotorSpeed_0_100_U8);

#endif
