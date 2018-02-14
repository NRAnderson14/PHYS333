/*
 * PWM functions
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
