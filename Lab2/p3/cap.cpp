/*
 * cap.cpp -- Capacitor stuff
 */

#define OUT_PIN 13

void setup() {
    pinMode(OUT_PIN, OUTPUT);
}

void loop() {
    //for (int i = 1; i < 1000; i++)
        //PWM(OUT_PIN, i);
    //for (int i = 1000; i > 0; i--)
        //PWM(OUT_PIN, i);
    PWM(OUT_PIN, 500);
}

void PWM(int pin, int duty) {
    digitalWrite(pin, HIGH);

    for (int i = 0; i <= 1000; i++) {
        if (i == duty) {
            digitalWrite(pin, LOW);
        }
    }
}

