/*
 * Lab 2 Part 1
 * Jan 24 2018
 */

#define DELAY 25

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    accuratePWM(LED_BUILTIN, 502, 1);
    //for (int duty = 1; duty < 1000; duty++) {
        //PWM(LED_BUILTIN, duty);
        //accuratePWM(LED_BUILTIN, duty, 500);
        //delayMicroseconds(DELAY);
    //}

    /*for (int duty = 1000; duty > 1; duty--) {
        //PWM(LED_BUILTIN, duty);
        accuratePWM(LED_BUILTIN, duty, 500);
        //delayMicroseconds(DELAY);
    }

    delayMicroseconds(DELAY);*/
}

/*
 * PWM()
 * Takes two parameters, the pin to write to, and the duty cycle out of 1000
 */
void PWM(int pin, int duty) {
    digitalWrite(pin, HIGH);

    for (int i = 0; i <= 1000; i++) {
        if (i == duty) {
            digitalWrite(pin, LOW);
        }
    }
}

void accuratePWM(int pin, int duty, int width) {
    for (int i = 1; i <= 1000; i++) {
        if (i <= duty) {
            digitalWrite(pin, HIGH);
            delayMicroseconds(width);
        } else {
            digitalWrite(pin, LOW);
            delayMicroseconds(width);
        }
    }
}
