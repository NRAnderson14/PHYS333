/* sin.ino
 * Generates a sin wave on pin 7
 */

#include <math.h>

#define out_pin 7
#define pi 3.14159265

double res = 0.0;
double count = 0.0;

void setup() {
    pinMode(out_pin, OUTPUT);
}

void loop() {
    for (count = 0.0; count <= 180; count += 1) {
        res = sin(count*pi/180);
        res = res * 1000;
        if (int(count) % 4 == 0)
            PWM(out_pin, int(res), 1000);
    }
}

void PWM(int pin, int duty, int cycles) {
    digitalWrite(pin, HIGH);

    for (int i = 0; i <= cycles; i++) {
        if (i == duty) {
            digitalWrite(pin, LOW);
        }
    }
}
