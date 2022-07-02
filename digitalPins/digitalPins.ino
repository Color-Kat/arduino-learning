// Include libs
// #include <Servo.h>

#define button_pin 2
#define nano_lamp 13

unsigned long last_time;
boolean light = 0;

void setup() {
    Serial.begin(9600);
    pinMode(button_pin, INPUT);
    pinMode(nano_lamp, OUTPUT);
}
  
void loop() {
    boolean button = digitalRead(button_pin);
    digitalWrite(nano_lamp, 1);

    Serial.println(button);

    if(button == 1) light = 1;
    else light = 0;

    
    
  
//    if(millis() - last_time > 1000) {
//        last_time = millis();
//        digitalWrite(nano_lamp, light);
//        light = !light;
//    }
}
