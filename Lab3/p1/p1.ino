#define out_pin 13

void setup() {
    pinMode(out_pin, OUTPUT);
}

void loop() {
    // We need 3.27 volts as an output here
    // This is 65.4% of 5V
    // So, in theory, this happens when the function is given a duty of 654 (out of 1000)
    // PWM(out_pin, 654);
    // In practice, this gives 3.29V as an output
    PWM(out_pin, 649);
    // The above generates 3.27V
}

void PWM(int pin, int duty) {
    digitalWrite(pin, HIGH);

    for (int i = 0; i <= 1000; i++) {
        if (i == duty) {
            digitalWrite(pin, LOW);
        }
    }
}
