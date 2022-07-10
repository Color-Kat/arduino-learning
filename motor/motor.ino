#define motor_pin_in 2
#define motor_pin_pwm 3

void setup() {
    Serial.begin(9600);
    pinMode(motor_pin_in, OUTPUT);
    pinMode(motor_pin_pwm, OUTPUT);
}
  
void loop() {
    static int speed = -200;
    static boolean increase = true;
    static long last_time = 0;

    if(millis() - last_time > 150) {
        last_time = millis();
        
        if(speed < 200 && increase) speed += 10;
        else{
          speed -= 10;
          increase = false;
          if(speed < -200) increase = true;
        }
    }

    if(speed > 0) {
        Serial.print("FORWARD ");
        Serial.println(speed);
        analogWrite(motor_pin_pwm, speed);
        digitalWrite(motor_pin_in, 0);
    } else if (speed < 0) {
        Serial.print("BACKWARD ");
        Serial.println(speed + 255);
        analogWrite(motor_pin_pwm, -speed);
        digitalWrite(motor_pin_in, 1);
    }
    else {
        // stop
        Serial.println("stop");
        analogWrite(motor_pin_pwm, 0);
        digitalWrite(motor_pin_in, 0);
    }
}
