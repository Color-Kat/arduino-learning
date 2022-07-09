#include <microDS18B20.h>

// один датчик на пине без адресации
MicroDS18B20<5> ds;

void setup(){
  Serial.begin(9600);
  ds.setResolution(9);
}

void loop() {
  ds.requestTemp();
  delay(1000);

  if(ds.readTemp()){
      int temp = ds.getTemp();
      Serial.println(temp);
  }
}
