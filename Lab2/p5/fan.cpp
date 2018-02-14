/*
 * fan.cpp -- Drive a computer fan
 */

#define OUT_PIN 13

void setup() {
    pinMode(OUT_PIN, OUTPUT);
    for (int i = 0; i < 8000; i++) {    // Need to get to 5v for a while to start the motor
        PWM(OUT_PIN, 1000);
    }
}

void loop() {
    //for (int i = 0; i < 30000; i++)
       //PWM(OUT_PIN, 1000);  // 850 is about the minimum to drive the motor here

    //for (int i = 0; i < 30000; i++)
        //PWM(OUT_PIN, 750);
    for (int i = 1; i < 1000; i++) {
        PWM(OUT_PIN, i); // Delay a bit
    }
}

void PWM(int pin, int duty) {
    digitalWrite(pin, HIGH);

    for (int i = 0; i <= 1000; i++) {
        if (i == duty) {
            digitalWrite(pin, LOW);
        }
    }
}
