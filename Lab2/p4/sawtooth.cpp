void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    for (int duty = 0; duty < 1000; duty++) {
        PWM(LED_BUILTIN, duty);
        delayMicroseconds(500);
    }

    delayMicroseconds(500);

    for (int duty = 1000; duty > 0; duty--) {
        PWM(LED_BUILTIN, duty);
        delayMicroseconds(500);
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
