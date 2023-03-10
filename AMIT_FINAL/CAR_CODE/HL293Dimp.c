/*
    title: L293(H bridge) Driver imp.
    author: Khaled Montaser
*/

#include "HL293DHeader.h"



void L293D_Init()
{

   
    DDRC=0xFF;         //// portc output
    DDRD |= (1<<PD4); //// H_en1
  	DDRD |= (1<<PD5);//// H_en2
	
	TCCR1A = (1<<COM1A1) + (1<<WGM11) + (1<<COM1B1); 
  	TCCR1B = (1<<WGM13) + (1<<WGM12) + (1<<CS10); // prescaler = none; 
  	ICR1 = 0xffff;
    OCR1A =0;
	OCR1B =0;	

        
}

void L293D_SetMotorDir(u8 ARGSelectMotorU8,u8 ARGSetMotorU8)
{

    switch (ARGSelectMotorU8)
    {
    case MOTOR_A:
   
        switch (ARGSetMotorU8)
         {
            case FORWARD:

                PORTC_io &=(~(1<<PC3))+(~(1<<PC4));
                PORTC_io |=(1<<PC3)+(0<<PC4);
            
                break;      
            case BACKWARD:
               
                PORTC_io &=(~(1<<PC3))+(~(1<<PC4));
                PORTC_io |=(0<<PC3)+(1<<PC4);
               
                break;   
            case STOP:
                PORTC_io &=(~(1<<PC3))+(~(1<<PC4));
                break;

            default:
                break;
            }
    
    case MOTOR_B:
   
        switch (ARGSetMotorU8)
         {
         case FORWARD:
             PORTC_io &=(~(1<<PC5))+(~(1<<PC6));
             PORTC_io |=(1<<PC5)+(0<<PC6);
             break;      
         case BACKWARD:
             PORTC_io &=(~(1<<PC5))+(~(1<<PC6));
             PORTC_io |=(0<<PC5)+(1<<PC6);
             break;       
         case STOP:
             PORTC_io &=(~(1<<PC5))+(~(1<<PC6));
             break;
         default:
             break;
         }

        break;
    
    default:
        break;
    }   
    
    
 
}

void L293D_SetMotorSpeed(u8 ARGSetMotorSpeed_0_100_U8)
{
    u16 Speed = ARGSetMotorSpeed_0_100_U8*655.0;
    OCR1A = Speed;
    OCR1B = Speed;
return;
}

