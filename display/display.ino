#include <microDS18B20.h>
#include <GyverTimers.h>
#include "GyverTM1637.h"

// Термометр
MicroDS18B20<5> ds;

// Дисплей
#define CLK 6
#define DIO 7
GyverTM1637 disp(CLK, DIO);

//uint32_t Now, clocktimer;
//boolean flag;

int temperature;

void setup(){
  Serial.begin(9600);

  disp.clear();
  disp.brightness(7);  // яркость, 0 - 7 (минимум - максимум)
  disp.clear();
  disp.displayByte(_t, _e, _a, _empty);
//  Timer2.setPeriod(3000);
//  Timer2.enableISR();
}

void loop() {
  static uint32_t timer = millis();
  if(millis() - timer >= 1000){
      timer = millis();

      if(ds.readTemp()){
          temperature = ds.getTemp();
          Serial.println(temperature);
//          disp.clear();
          disp.displayInt(temperature);
      }
      ds.requestTemp();
  }
}

//ISR(TIMER2_A) {
//  disp.clear();
//  disp.displayInt(temperature);
//}
