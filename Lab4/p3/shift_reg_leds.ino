/* Driving an array of 8 LEDs with a shift register */

#define CLOCK 8
#define SERIAL_OUT 7

int clock_sig;
int serial_data;

void setup() {
    pinMode(CLOCK, OUTPUT);
    pinMode(SERIAL_OUT, OUTPUT);

    clock_sig = 0;
    serial_data = 1;

}

void loop() {
    digitalWrite(CLOCK, clock_sig);
    clock_sig = !clock_sig;

    // 'signal' 0000 - 0001 - 0011 - 0111 - 1111
    digitalWrite(SERIAL_OUT, serial_data);
    if (serial_data > 5) {
        serial_data = 1;
        clear_all();
    } else {
        serial_data++;
    }

    digitalWrite(CLOCK, clock_sig);
    clock_sig = !clock_sig;

    delay(250);
}

/* I know there is a clear bit on the chip, but I cannot figure out how it works
    So instead, just shift low into the register 4 times */
void clear_all() {
    for (int i = 0; i < 4; i++) {
        digitalWrite(CLOCK, LOW);
        digitalWrite(SERIAL_OUT, LOW);
        digitalWrite(CLOCK, HIGH);
    }
}
