#define out_pin 13

void setup() {
    pinMode(out_pin, OUTPUT);
}

void loop() {
    // 1.22v for 100ms, and then 3.77v for 200ms
    // The PWM function takes about 700us to run

    // 139 * 700us = 100ms
    for (int i = 0; i < 139; i++) {
        // 1.22v is 24.4% of 5v
        PWM(out_pin, 241);
    }

    // 286 * 700us = 200ms
    for (int i = 0; i < 286; i++) {
        // 3.77v is 75.4% of 5v
        PWM(out_pin, 752);
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
