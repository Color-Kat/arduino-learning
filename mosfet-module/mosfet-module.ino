#define button_pin 13
#define mosfet_pin 2

boolean isButtonPressed = 0; // State of button
boolean mosfet = 0; // State of the mosfet

unsigned long last_click = 0;

void setup() {
    Serial.begin(9600);
    pinMode(button_pin, INPUT_PULLUP);
    pinMode(mosfet_pin, OUTPUT);
}
  
void loop() {
    boolean button = !digitalRead(button_pin);

    if(button == 1 && isButtonPressed == 0 && millis() - last_click > 50){
        last_click = millis();
      
        isButtonPressed = 1;
        mosfet = !mosfet;
    }
    if(button == 0 && isButtonPressed == 1) {
        isButtonPressed = 0;
    }

    Serial.println(mosfet);

    digitalWrite(mosfet_pin, mosfet);
}
