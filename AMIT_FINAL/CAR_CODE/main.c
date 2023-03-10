#include "MdioHeader.h"
#include "HL293DHeader.h"
#include "MUARTHeader.h"
#include "LCDHeader.h"
#include "string.h"
#include "L_strcovs.h"


#define FORWARD_BIT 7
#define BACKWARD_BIT 6
#define RIGHT_BIT 5
#define LEFT_BIT 4


int main()
{ 
///////functions initiation//////////////
  
  L293D_Init();
  LcdInit(LCD2Line);
  SetCursorSettings(LCDON, LCDON);
  SetUARTConfig(MUART_PARITY_DISABLED, MUART_ONE_STOP_BIT, MUART_8BIT, MUART_BUAD9600);



/////////Set SerialData For LEDs////////////
  
  SetPinDir(PC,pin2,OUTPUT);
  SetPinDir(PC,pin7,OUTPUT);
  SetPinDir(PD,pin3,OUTPUT);



/////////Light LEDs////////////

  SetPinValue(PC,pin2,HIGH);
  SetPinValue(PC,pin7,HIGH);
  SetPinValue(PD,pin3,HIGH);
    


//////////variabls to use////////////////
  
  u8 Display = 0;      // menipulating LCD
  u8 SerialData;       // setting SerialData of Motors
  u8 speed;           // setting speed of Motors
  u8 speedStr[3];     // desplaying speed
 
  
  
  
  while(1)
  { 
    
    SerialData = 0;
    SerialData = SerialReadFrame();
    speed = (SerialData & 0b00000111)*25;
    convIntToString(speed,speedStr);            // for displaying speed value on LCD


   ////////////Idel case/////////////////////
    if ((SerialData == speed) || (speed==0) )
    {
      ////////displaying mode//////////
      if(Display != 5)
      {
      ClearLcd();
      WriteLcd((u8*)"Idle");
      Display = 5;
      }
      
      ////////LEDs///////////////
      SetPinValue(PC,pin2,LOW);
      SetPinValue(PC,pin7,LOW);
      SetPinValue(PD,pin3,LOW);

      //////////set motor movement////////
      L293D_SetMotorDir(MOTOR_A,STOP);
      L293D_SetMotorDir(MOTOR_B,STOP);
      L293D_SetMotorSpeed(0);
    
    }


    ////////////////forward mode////////////////////
    
    else if((GET_BIT(SerialData, FORWARD_BIT) == 1) && speed != 0) //forward
    {
      ////////displaying mode//////////
      if(Display != 1)
      {
        ClearLcd();
        WriteLcd((u8*)"forward");
        Display = 1;
      }
       
      ////////displaying speed//////////
      SetPosition(LCD2Line,0);
      WriteLcd((u8*)speedStr);
      WriteLcd((u8*)" ");      

      ////////LEDs///////////////
      SetPinValue(PC,pin2,LOW);
      SetPinValue(PC,pin7,HIGH);
      SetPinValue(PD,pin3,LOW);

      
      //////////set motor movement////////
      
      L293D_SetMotorDir(MOTOR_A,FORWARD);
      L293D_SetMotorDir(MOTOR_B,FORWARD);
      L293D_SetMotorSpeed(speed);
    

    }

    /////////////////backward mode/////////////////////
    
    else if((GET_BIT(SerialData, BACKWARD_BIT) == 1) && speed != 0) //backward
    { 
      if(Display != 2)
      {
        ClearLcd();
        WriteLcd((u8*)"Backward");
        Display = 2;
      }
      
      SetPosition(LCD2Line,0);
      WriteLcd((u8*)speedStr);
      WriteLcd((u8*)" ");


      SetPinValue(PC,pin2,HIGH);
      SetPinValue(PC,pin7,LOW);
      SetPinValue(PD,pin3,HIGH);

      
      L293D_SetMotorDir(MOTOR_A,BACKWARD);
      L293D_SetMotorDir(MOTOR_B,BACKWARD);
      L293D_SetMotorSpeed(speed);
    
    }
    //////////////////right//////////////////////
    
    else if((GET_BIT(SerialData, RIGHT_BIT) == 1) && speed != 0) //right
    {
      
      if(Display != 3)
      {
      ClearLcd();
      WriteLcd((u8*)"right");
      Display = 3;
      }
      SetPosition(LCD2Line,0);
      WriteLcd((u8*)speedStr);
      WriteLcd((u8*)" ");


      SetPinValue(PC,pin2,HIGH);
      SetPinValue(PC,pin7,LOW);
      SetPinValue(PD,pin3,LOW);


      L293D_SetMotorDir(MOTOR_A,FORWARD);
      L293D_SetMotorDir(MOTOR_B,BACKWARD);
      L293D_SetMotorSpeed(speed);
    
    }
    ///////////////////left//////////////////////////
    else if((GET_BIT(SerialData, LEFT_BIT) == 1) && speed != 0) //left
    {
      if(Display != 4)
      {
        ClearLcd();
        WriteLcd((u8*)"left");
        Display = 4;
      }
      
      SetPosition(LCD2Line,0);
      WriteLcd((u8*)speedStr);
      WriteLcd((u8*)" ");


      SetPinValue(PC,pin2,LOW);
      SetPinValue(PC,pin7,LOW);
      SetPinValue(PD,pin3,HIGH);

      
      L293D_SetMotorDir(MOTOR_A,BACKWARD);
      L293D_SetMotorDir(MOTOR_B,FORWARD);
      L293D_SetMotorSpeed(speed);
    
    }
    else
    {
    }
  }
  return 0;
}