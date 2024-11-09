#include <ArduinoR4DigitDisplay.h>
#include "Arduino_LED_Matrix.h"
#include "RTC.h"

ArduinoLEDMatrix matrix;

volatile bool irqFlag = false;
volatile bool ledState = false;    
int contador = 0; 

 
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

   // Este código hace un contador de 000 a 999 segundos y para un tiempo preciso utiliza el RTC del Arduino UNO R4.

   if(irqFlag==true){
        
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
  
/*   // Descomente estas lineas si solo requiere un contador de 000 a 999 
 
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
     delay(1000);

  }
*/

}

void periodicCallback()
{
  irqFlag = true;
}
