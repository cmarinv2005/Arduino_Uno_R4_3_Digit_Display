#include <ArduinoR4DigitDisplay.h>
#include "Arduino_LED_Matrix.h"
#include "RTC.h"

ArduinoLEDMatrix matrix;

volatile bool irqFlag = false;
volatile bool ledState = false;    
int contador = 0; 

uint8_t apagar[8][12] = {
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
   
void setup() {
  Serial.begin(115200);
  matrix.begin();
  RTC.begin();

  RTCTime mytime(10, Month::NOVEMBER, 2024, 123, 37, 00, DayOfWeek::SATURDAY, SaveLight::SAVING_TIME_ACTIVE);
  RTC.setTime(mytime);

  if (!RTC.setPeriodicCallback(periodicCallback, Period::ONCE_EVERY_1_SEC)) {
    Serial.println("ERROR: periodic callback not set");
  }

}


void loop(){


   if(irqFlag==true){
    
  //  contador = contador + 1;
        
    uint8_t frame[8][12] = {
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    }; 

     matrix.renderBitmap(frame, 8, 12);  
      
     drawNumber(contador,frame);
     matrix.renderBitmap(frame, 8, 12);   

     contador = contador + 1;

     if(contador>=999){
      contador=0;
     }
     
     irqFlag = false;
   
   }
  
/*
     for(int i=0; i<=999; i++){           

     uint8_t frame[8][12] = {
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
     }; 
     
     matrix.renderBitmap(frame, 8, 12);    
     
     drawNumber(i,frame);
     matrix.renderBitmap(frame, 8, 12);
     delay(500);

  }
*/

}

void periodicCallback()
{
  irqFlag = true;
}
