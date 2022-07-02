// Include libs
// #include <Servo.h>

#define speaker_pin 1

int multiplier = 100;
byte red = 255; // 0-255
const float pi = 3.14;

// For some delay
unsigned long last_time;

void setup() {
  float circleLength = (float)100 / pi;
  Serial.begin(9600);
  Serial.println("hello tea maker");
  Serial.println(circleLength);
}
  
void loop() {
  // Read and display numbers
  if(Serial.available() > 0) {
//    int data = Serial.read() - '0'; // Change data type to int
    int data = Serial.parseInt();
    Serial.println(data);
  }

  if(millis() - last_time > 1000) {
    last_time = millis();
    Serial.println("sec");
    
  }
}
