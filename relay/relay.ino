#define button_pin 10
#define relay_pin 13

boolean isButtonPressed = 0; // State of button
boolean relay = 0; // State of the relay

unsigned long last_click = 0;

void setup() {
    Serial.begin(9600);
    pinMode(button_pin, INPUT_PULLUP);
    pinMode(relay_pin, OUTPUT);
}
  
void loop() {
    boolean button = !digitalRead(button_pin);

    if(button == 1 && isButtonPressed == 0 && millis() - last_click > 50){
        last_click = millis();
      
        isButtonPressed = 1;
        relay = !relay;
    }
    if(button == 0 && isButtonPressed == 1) {
        isButtonPressed = 0;
    }

    Serial.println(relay);

    digitalWrite(relay_pin, relay);
}
