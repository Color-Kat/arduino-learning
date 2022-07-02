// Include libs
// #include <Servo.h>

#define button_pin 2
#define nano_lamp 13

unsigned long last_time;
boolean light = 0;

void setup() {
    Serial.begin(9600);
    pinMode(speaker_pin, INPUT_PULLUP);
    pinMode(nano_lamp, OUTPUT);
}
  
void loop() {
    boolean button = !digitalRead(button_pin);


    if(button == 1) digitalWrite(nano_lamp, 1);
    else digitalWrite(nano_lamp, 0);
    
  
//    if(millis() - last_time > 1000) {
//        last_time = millis();
//        digitalWrite(nano_lamp, light);
//        light = !light;
//    }
}
