/* Program to keep babies alive in an incubator
 * Hook up the TMP36 to analog pin 0,
 * and hook up the heater relay (led) to pin 13
 */
#define BABY_TEMP_READER 0
#define BABY_HEATER 13


void setup() {
    pinMode(BABY_HEATER, OUTPUT);
}

void loop() {
    // If it gets too cold, warm it up, and vice versa
    if (readTemp(BABY_TEMP_READER) < 98.0) {
        digitalWrite(BABY_HEATER, HIGH);
    } else if (readTemp(BABY_TEMP_READER) > 100.0) {
        digitalWrite(BABY_HEATER, LOW);
    }
}

float readTemp(int pin) {
    int value;
    float celsius, fahr;
    value = analogRead(pin);
    celsius  = ((float)value*4.9 - 500) / 10;
    fahr = (celsius*9/5 + 32);
    return fahr;
}
