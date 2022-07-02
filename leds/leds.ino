#define button_pin 6

boolean isButtonPressed = 0; // State of button

byte led_number_pin = 2;

unsigned long last_click = 0;

void setup() {
    Serial.begin(9600);
    pinMode(button_pin, INPUT_PULLUP);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
}
  
void loop() {
    boolean button = !digitalRead(button_pin);

    // Button pressed
    if(button == 1 && isButtonPressed == 0 && millis() - last_click > 100){
        last_click = millis();
        isButtonPressed = 1;

        if(led_number_pin > 4) led_number_pin = 2;

        // Turn off all leds
        digitalWrite(2, 0);
        digitalWrite(3, 0);
        digitalWrite(4, 0);

        digitalWrite(led_number_pin, 1); // Turn on the next led
        
        led_number_pin++;
    }

    // Button released
    if(button == 0 && isButtonPressed == 1) {
        isButtonPressed = 0;
    }
}
