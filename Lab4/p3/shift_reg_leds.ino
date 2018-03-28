/* Driving an array of 8 LEDs with a shift register */

#define LEFT_SWITCH 2
#define RIGHT_SWITCH 3
#define LEFT_SERIAL_OUT 6
#define RIGHT_SERIAL_OUT 7
#define CLOCK 8

int clock_sig;
int serial_data;
bool left_on = false;
bool right_on = false;

void setup() {
    pinMode(LEFT_SWITCH, INPUT);
    pinMode(RIGHT_SWITCH, INPUT);
    pinMode(CLOCK, OUTPUT);
    pinMode(LEFT_SERIAL_OUT, OUTPUT);
    pinMode(RIGHT_SERIAL_OUT, OUTPUT);

    clock_sig = 0;
    serial_data = 1;
}

void loop() {
    if (digitalRead(LEFT_SWITCH))
        left_on = true;
    else
        left_on = false;

    if (digitalRead(RIGHT_SWITCH))
        right_on = true;
    else
        right_on = false;

    digitalWrite(CLOCK, clock_sig);
    clock_sig = !clock_sig;

    if (serial_data > 5) {
        serial_data = 1;
        clear_all(LEFT_SERIAL_OUT);
        clear_all(RIGHT_SERIAL_OUT);
    } else {
        serial_data++;
    }

    // 'signal' 0000 - 0001 - 0011 - 0111 - 1111
    if (left_on)
        digitalWrite(LEFT_SERIAL_OUT, serial_data);

    if (right_on)
        digitalWrite(RIGHT_SERIAL_OUT, serial_data);

    digitalWrite(CLOCK, clock_sig);
    clock_sig = !clock_sig;

    delay(250);
}

/* I know there is a clear bit on the chip, but I cannot figure out how it works
    So instead, just shift low into the register 4 times */
void clear_all(int pin) {
    for (int i = 0; i < 4; i++) {
        digitalWrite(CLOCK, LOW);
        digitalWrite(pin, LOW);
        digitalWrite(CLOCK, HIGH);
    }
}
