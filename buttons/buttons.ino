#define button_pin 2
#define nano_lamp 13

boolean isButtonPressed = 0;
boolean light = 0;

void setup() {
    Serial.begin(9600);
    pinMode(button_pin, INPUT_PULLUP);
    pinMode(nano_lamp, OUTPUT);
}
  
void loop() {
    boolean button = !digitalRead(button_pin);

    if(button == 1 && isButtonPressed == 0) {
        Serial.println("Кнопка нажата");
        isButtonPressed = 1;
        light = !light;
    }
    if(button == 0 && isButtonPressed == 1) {
        isButtonPressed = 0;
        Serial.println("Кнопка отпущена");
    }

    
    
    digitalWrite(nano_lamp, light);
}
