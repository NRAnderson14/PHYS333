/* nand.ino
 * Arduino program to NAND three input pins,
 *  putting the output on another
 */

/* Our input pins are 2, 3, and 4
 * Our output pin is 7
 */
#define in_2 2
#define in_3 3
#define in_4 4
#define out  7

int a, b, c;

void setup() {
    pinMode(in_2, INPUT);
    pinMode(in_3, INPUT);
    pinMode(in_4, INPUT);
    pinMode(out, OUTPUT);
    a = 0;
    b = 0;
    c = 0;
}

void loop() {
    a = digitalRead(in_2);
    b = digitalRead(in_3);
    c = digitalRead(in_4);
    digitalWrite(out, nand(a, b, c));
}

/* nand function
 * Returns the NAND of three inputs
 */
int nand(int n_1, int n_2, int n_3) {
    return ~(n_1 && n_2 && n_3);
}
