#include <microDS18B20.h>
#include <GyverTimers.h>
#include <GyverTM1637.h>

// Термометр
MicroDS18B20<A2> ds;

// Дисплей
#define CLK 12
#define DIO 11
GyverTM1637 disp(CLK, DIO);

// Реле
#define relay_pin 8
boolean isRelay = false;

//uint32_t Now, clocktimer;
//boolean flag;

int temperature;

void setup(){
  Serial.begin(9600);

  pinMode(relay_pin, OUTPUT);

  disp.clear();
  disp.brightness(7);  // яркость, 0 - 7 (минимум - максимум)
  disp.clear();
  disp.displayByte(_t, _e, _a, _empty);
}

void loop() {
  static uint32_t timer = millis();
  if(millis() - timer >= 1000){
      timer = millis();

      isRelay = !isRelay;
      digitalWrite(relay_pin, isRelay);

      if(ds.readTemp()){
          temperature = ds.getTemp();
          Serial.println(temperature);
          disp.displayInt(temperature);
      }
      ds.requestTemp();
  }
}
