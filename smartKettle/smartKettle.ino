#include <microDS18B20.h>

// ПОдключаем термометр DS18b20
MicroDS18B20<6> ds;

#define button_pin 2
#define relay_pin 3

int state = 0; // State of the kettle

void setup() {
    Serial.begin(9600);
    pinMode(button_pin, INPUT_PULLUP);
    pinMode(relay_pin, OUTPUT);
    pinMode(6, INPUT);

    digitalWrite(relay_pin, 1);
}
  
void loop() {
    // Button
    static unsigned long last_click = 0;
    boolean button = !digitalRead(button_pin);

    if(button == 1 && millis() - last_click > 1000){
        last_click = millis();
        if(state == 0) state = 1;
        else state = 0;
    }

//    Serial.println(state);

    // Temperature
    static unsigned long last_request = 0;
    if(millis() - last_request > 1000) {
        if(ds.readTemp()){
            int temp = ds.getTemp();
            if(state == 1 && temp < 65) {
                Serial.println(temp);
                digitalWrite(relay_pin, 0);
            } else {
                digitalWrite(relay_pin, 1);
                state = 0;
            }
        }
      
        ds.requestTemp();
    }
    
//    if(button == 0 && isButtonPressed == 1) {
//        isButtonPressed = 0;
//    }

//    Serial.println(relay);

    
}
