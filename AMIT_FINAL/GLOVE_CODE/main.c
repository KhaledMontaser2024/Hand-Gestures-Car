#include "MdioHeader.h"
#include "MUARTHeader.h"
#include "MADCHeader.h"
#include "LCDHeader.h"
#include "L_strcovs.h"
#include "util/delay.h"


#define FORWARD_BIT 7
#define BACKWARD_BIT 6
#define RIGHT_BIT 5
#define LEFT_BIT 4



int main()
{   
   ///////Functions initialization//////////
   ADCInit();
   SetUARTConfig(MUART_PARITY_DISABLED, MUART_ONE_STOP_BIT, MUART_8BIT, MUART_BUAD9600);
   SetPinDir(PC,pin0,OUTPUT);
   
   
   /////////variabls ////////////
   u16 flx1,flx2,flx3,flx4,flx5;       //// flex sensors 
   u8 Movement;                        //// data to send 


    while (1)
    {   
        ///////////reading data from fingers using ADC //////////
        ADC_getDigitalValue(adc0 , &flx1);      //pinky
        ADC_getDigitalValue(adc1 , &flx2);      //ring 
        ADC_getDigitalValue(adc2 , &flx3);      //middle
        ADC_getDigitalValue(adc3 , &flx4);      //index
        ADC_getDigitalValue(adc4 , &flx5);      //thumb
        
        
        Movement = 0;
        
        /*first three bits in movement is for setting the speed levels */

        ////////////thumb finger (flex_5) setting speed level/////////
        if(flx5 <= 558 && flx5 > 516) //speed level 1
        {
           Movement = 1; 
        }
        else if(flx5 <= 516 && flx5 > 475) //speed level 2
        {
           Movement = 2; 
        }
        else if(flx5 <= 475 && flx5 > 433) //speed level 3
        {
           Movement = 3; 
        }
        else if(flx5 <= 433 && flx5 > 392) //speed level 4
        {
           Movement = 4; 
        }

        

        
        /*flex_1 & flex_2 & flex_3 & flex_4 are for setting direction 
        and assign it to the high nibble of movement*/
        
        ////////////////Idel mode///////////////
        if((flx1 > 593) && (flx2 > 593) && (flx3 > 593) && (flx4 > 565)) 
        {   
            CLEAR_NIBBLE_HIGH(Movement); // 0000 xxxx
            SerialWriterFrame(Movement); // sending (movement) via UART
        }
        
        /////////////Forward///////////////////
        else if((flx1 > 570) && (flx2 < 550) && (flx3 < 550) && (flx4 > 565))
        {   
            SET_BIT(Movement, FORWARD_BIT); // 1000 xxxx
            SerialWriterFrame(Movement);
        }
        
        ////////////Backward///////////////
        else if((flx1 < 520) && (flx2 < 520) && (flx3 < 520) && (flx4 < 520))
        {   
            SET_BIT(Movement, BACKWARD_BIT); // 0100 xxxx
            SerialWriterFrame(Movement);
        }

        ///////////Right/////////////////
        else if((flx1 < 550) && (flx2 < 513) && (flx3 < 513) && (flx4 > 565))
        {   
            SET_BIT(Movement, RIGHT_BIT); // 0010 xxxx
            SerialWriterFrame(Movement);
        }

        /////////Left////////////////////
        else if((flx1 > 540) && (flx2 > 545) && (flx3 < 530) && (flx4 < 450))
        {   
            SET_BIT(Movement, LEFT_BIT); // 0001 xxxx
            SerialWriterFrame(Movement);
        }                    
    
    }


    return 0;
}
