/* Driving an array of 8 LEDs with a shift register */

#define S1 2
#define S0 3

#define CLOCK 8
#define SERIAL_OUT 7
#define CLEAR 11

int clock_sig;
int serial_data;

void setup() {
    pinMode(S1, OUTPUT);
    pinMode(S0, OUTPUT);
    pinMode(CLOCK, OUTPUT);
    pinMode(SERIAL_OUT, OUTPUT);

    clock_sig = 0;
    serial_data = 1;

    // Shift register shifts left when S0 is low and S1 is high
    digitalWrite(S0, LOW);
    digitalWrite(S1, HIGH);

    digitalWrite(CLEAR, HIGH);
}

void loop() {
    digitalWrite(CLOCK, clock_sig);
    clock_sig = !clock_sig;

    digitalWrite(SERIAL_OUT, serial_data);
    if (serial_data > 4) {
        serial_data = 1;
        clear_all();
    } else {
        serial_data++;
    }

    digitalWrite(CLOCK, clock_sig);
    clock_sig = !clock_sig;

    delay(500);
}

void clear_all() {
    for (int i = 0; i < 4; i++) {
        digitalWrite(CLOCK, LOW);
        digitalWrite(SERIAL_OUT, LOW);
        digitalWrite(CLOCK, HIGH);
    }
}
