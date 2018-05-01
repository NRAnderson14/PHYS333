#include <RTClib.h>

RTC_DS1307 rtc;

void setup() {
    Serial.begin(57600);
    rtc.begin();
}

void loop() {
    DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print("/");
    Serial.print(now.month(), DEC);
    Serial.print("/");
    Serial.print(now.day(), DEC);
    Serial.print("\t");
    Serial.print(now.hour(), DEC);
    Serial.print(":");
    Serial.println(now.minute(), DEC);

    delay(5000);
}
