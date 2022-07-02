// Include libs
// #include <Servo.h>

#define button_pin 2
#define nano_lamp 13

unsigned long last_time;
boolean light = 0;

void setup() {
    Serial.begin(9600);
    pinMode(button_pin, INPUT_PULLUP);
    pinMode(nano_lamp, OUTPUT);
}
  
void loop() {
    boolean button = !digitalRead(button_pin);
    
    Serial.println(button);
    
    digitalWrite(nano_lamp, button);
}
