/*
 *  Program to "race" a line around the edge of a seven segment display
 */

void setup() {
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);

    //Initialize all of our pins to high
    for (int i = 8; i <= 13; i++) {
        digitalWrite(i, HIGH);
    }
}

void loop() {
    for (int i = 8; i <= 13; i++) {
        digitalWrite(i, LOW);
        delay(250);
        digitalWrite(i, HIGH);  //Remember to turn the pin off again
    }
}
