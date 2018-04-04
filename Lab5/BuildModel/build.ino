#define IN_PIN 0

int value = 0;
long since = 0;
float celsius  = 0.0;
float fahr = 0.0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    value = analogRead(IN_PIN);
    since = millis() - since;
    celsius  = ((float)value*4.9 - 500) / 10;
    fahr = (celsius*9/5 + 32);
    Serial.print("Fahrenheit reading: ");
    Serial.print(fahr);
    Serial.print("\t Time: ");
    Serial.println(since);
    delay(1000);
}
