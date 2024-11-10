#include "Arduino.h"
#include "ArduinoR4DigitDisplay.h"

void top(int s, uint8_t frame[8][12]){ 
frame[1][0+s] = 1; 
frame[1][1+s] = 1; 
frame[1][2+s] = 1; 
}

void ul(int s, uint8_t frame[8][12]){ 
frame[1][0+s] = 1; 
frame[2][0+s] = 1; 
frame[3][0+s] = 1; 
}

void ur(int s, uint8_t frame[8][12]){ 
frame[1][2+s] = 1; 
frame[2][2+s] = 1; 
frame[3][2+s] = 1; 
}

void br(int s, uint8_t frame[8][12]){ 
frame[4][2+s] = 1; 
frame[5][2+s] = 1; 
}

void bl(int s, uint8_t frame[8][12]){ 
frame[4][0+s] = 1; 
frame[5][0+s] = 1; 
}

void mid(int s, uint8_t frame[8][12]){ 
frame[3][0+s] = 1; 
frame[3][1+s] = 1; 
frame[3][2+s] = 1; 
}

void bot(int s, uint8_t frame[8][12]){ 
frame[5][0+s] = 1; 
frame[5][1+s] = 1; 
frame[5][2+s] = 1; 
}

void one(int s, uint8_t frame[8][12]){ 
ur(s, frame); 
br(s, frame); 
}

void two(int s, uint8_t frame[8][12]){
top(s, frame); 
ur(s, frame); 
mid(s, frame); 
bl(s, frame); 
bot(s, frame); 
}

void three(int s, uint8_t frame[8][12]){ 
top(s, frame); 
ur(s, frame); 
mid(s, frame); 
br(s, frame); 
bot(s, frame); 
}

void four(int s, uint8_t frame[8][12]){ 
ur(s, frame); 
ul(s, frame); 
mid(s, frame); 
br(s, frame); 
}

void five(int s, uint8_t frame[8][12]){ 
top(s, frame); 
ul(s, frame); 
mid(s, frame); 
br(s, frame); 
bot(s, frame); 
}

void six(int s, uint8_t frame[8][12]){ 
top(s, frame); 
ul(s, frame); 
mid(s, frame); 
bl(s, frame); 
br(s, frame); 
bot(s, frame); 
}

void seven(int s, uint8_t frame[8][12]){ 
top(s, frame); 
ur(s, frame); 
br(s, frame); 
}

void eight(int s, uint8_t frame[8][12]){
top(s, frame); 
ur(s, frame); 
ul(s, frame); 
mid(s, frame); 
br(s, frame); 
bl(s, frame); 
bot(s, frame); 
}

void nine(int s, uint8_t frame[8][12]){ 
top(s, frame); 
ur(s, frame); 
ul(s, frame); 
mid(s, frame); 
br(s, frame); 
}

void zero(int s, uint8_t frame[8][12]){ 
top(s, frame); 
ur(s, frame); 
ul(s, frame); 
br(s, frame); 
bl(s, frame); 
bot(s, frame); 
}

void drawNumber(int num, uint8_t frame[8][12]){ 
if (num > 999){ 
num = 999; 
} else if (num < 0){ 
num = 0; 
} 

int milsDigit = num / 100; 
int tensDigit = (num / 10) % 10; 
int unitsDigit = num % 10; 

  if (milsDigit == 0){
    zero(1, frame);
  } else if (milsDigit == 1){
    one(1, frame);
  } else if (milsDigit == 2){
    two(1, frame);
  } else if (milsDigit == 3){
    three(1, frame);
  } else if (milsDigit == 4){
    four(1, frame);
  }else if (milsDigit == 5){
    five(1, frame);
  }else if (milsDigit == 6){
    six(1, frame);
  }else if (milsDigit == 7){
    seven(1, frame);
  }else if (milsDigit == 8){
    eight(1, frame);
  }else if (milsDigit == 9){
    nine(1, frame);
  } 

  if (tensDigit == 0){
    zero(5, frame);
  } else if (tensDigit == 1){
    one(5, frame);
  } else if (tensDigit == 2){
    two(5, frame);
  } else if (tensDigit == 3){
    three(5, frame);
  } else if (tensDigit == 4){
    four(5, frame);
  }else if (tensDigit == 5){
    five(5, frame);
  }else if (tensDigit == 6){
    six(5, frame);
  }else if (tensDigit == 7){
    seven(5, frame);
  }else if (tensDigit == 8){
    eight(5, frame);
  }else if (tensDigit == 9){
    nine(5, frame);
  }   

  if (unitsDigit == 0){
    zero(9, frame);
  } else if (unitsDigit == 1){
    one(9, frame);
  } else if (unitsDigit == 2){
    two(9, frame);
  } else if (unitsDigit == 3){
    three(9, frame);
  } else if (unitsDigit == 4){
    four(9, frame);
  } else if (unitsDigit == 5){
    five(9, frame);
  } else if (unitsDigit == 6){
    six(9, frame);
  } else if (unitsDigit == 7){
    seven(9, frame);
  } else if (unitsDigit == 8){
    eight(9, frame);
  } else if (unitsDigit == 9){
    nine(9, frame);
  } 
	
}
