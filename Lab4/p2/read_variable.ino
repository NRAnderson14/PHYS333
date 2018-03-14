/* read_variable.ino
 * Arduino program to light the system LED when
 *  pin 7 reads an input.
 * Used to determine the minimum voltage that
 *  the arduino will consider high.
 */

// Input is pin 7, output is the builtin LED (13)
#define in_pin 7
#define out_led 13

void setup() {
    pinMode(in_pin, INPUT);
    pinMode(out_led, OUTPUT);
}

void loop() {
    digitalWrite(out_led, digitalRead(in_pin));
}
