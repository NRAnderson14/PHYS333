#define IN_PIN  2
#define OUT_PIN 6

long  sum = 0;
float res = 0.0;
int  runs = 0;

void setup() {
    Serial.begin(9600);
    pinMode(IN_PIN, INPUT);
    pinMode(OUT_PIN, OUTPUT);

    analogWrite(OUT_PIN, 60); // 60/255
}

void loop() {
    for (runs = 0; runs < 1000; runs++) {
        sum += digitalRead(IN_PIN);
        delayMicroseconds(100);
    }

    res = (float)sum / 1000.0f;
    Serial.print("The PWM average is: ");
    Serial.println(res);
    sum = 0;
}
