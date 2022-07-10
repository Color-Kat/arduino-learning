#define mosfet_pin 3

boolean mosfet = 0; // State of the mosfet

unsigned long last_click = 0;

void setup() {
    Serial.begin(9600);
    pinMode(mosfet_pin, OUTPUT);
}
  
void loop() {

    if(millis() - last_click > 1500){
        last_click = millis();
      
        mosfet = !mosfet;
    }

    Serial.println(mosfet);

    digitalWrite(mosfet_pin, mosfet);
}
