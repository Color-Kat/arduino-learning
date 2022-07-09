#include <microDS18B20.h>

// ПОдключаем термометр DS18b20
MicroDS18B20<5> ds;

void setup(){
  Serial.begin(9600);
}

void loop() {
  ds.requestTemp();
  delay(1000);

  if(ds.readTemp()){
      int temp = ds.getTemp();
      Serial.println(temp);
  }
}
