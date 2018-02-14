/*
 * Program to display 'fireworks' on 5 LEDs
 */

#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS 0

int pin;
int higher;
int lower;

void setup() {
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
}

void loop() {
    pin = choosePin();
    analogWrite(pin, MAX_BRIGHTNESS);
    delay(500);
    analogWrite(pin, MIN_BRIGHTNESS);

    higher = nextHigherPin(pin);
    lower = nextLowerPin(pin);

    analogWrite(higher, MAX_BRIGHTNESS/2);
    analogWrite(lower, MAX_BRIGHTNESS/2);

    delay(500);

    analogWrite(higher, MIN_BRIGHTNESS);
    analogWrite(lower, MIN_BRIGHTNESS);

    for (int i = 1; i < 4; i++) {
        higher = nextHigherPin(higher);
        lower = nextLowerPin(lower);

        analogWrite(higher, MAX_BRIGHTNESS/(2 * i));
        analogWrite(lower, MAX_BRIGHTNESS/(2 * i));

        delay(500);

        analogWrite(higher, MIN_BRIGHTNESS);
        analogWrite(lower, MIN_BRIGHTNESS);
    }

    delay(500);
}

int choosePin() {
    int res;

    res = random(5, 11);

    if (res == 7) {
        res = 6;
    } else if (res == 8) {
        res == 9;
    }

    return res;
}

int nextHigherPin(int currPin) {
    switch (currPin) {
        case 5: return 6;
        case 6: return 9;
        case 9: return 10;
        case 10: return 11;
        case 11: return 0;
        default: return 0;
    }
}

int nextLowerPin(int currPin) {
    switch (currPin) {
        case 5: return 0;
        case 6: return 5;
        case 9: return 6;
        case 10: return 9;
        case 11: return 10;
        default: return 0;
    }
}
