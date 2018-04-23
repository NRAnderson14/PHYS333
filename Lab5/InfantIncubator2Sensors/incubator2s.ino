#define BABY_TEMP_READER_1 0
#define BABY_TEMP_READER_2 0
#define BABY_HEATER 13

void setup() {
    pinMode(BABY_HEATER, OUTPUT);
}

void loop() {
    // Same as before, just check two sensors and see if
    //  they agree before proceeding
    if (readTemp(BABY_TEMP_READER_1) < 98.0 && 
        readTemp(BABY_TEMP_READER_2) < 98.0) {
        digitalWrite(BABY_HEATER, HIGH);
    } else if (readTemp(BABY_TEMP_READER_1) > 100.0 &&
                readTemp(BABY_TEMP_READER_2) > 100.0) {
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
