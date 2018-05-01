#include <Adafruit_Si7021.h>
#include <RTClib.h>
#include <SD.h>
//#include <TimerOne.h>

Adafruit_Si7021 sensor = Adafruit_Si7021();
RTC_DS1307 rtc;
File sound_data_file;

int reading;
float average;
char time_reading[40];

void setup() {

    Serial.begin(115200);
    rtc.begin();
    SD.begin(10);
    Serial.println("Starting...");
    
    reading = 0;
    average = 0.0;

    pinMode(13, OUTPUT);

//    OCR0A = 0x64;
//    TIMSK0 |= _BV(OCIE0A);
}

void loop() {
    read_data();
    delay(250);
}

void read_data() {
    DateTime now = rtc.now();
    sound_data_file = SD.open("Lab_Data.CSV", FILE_WRITE);
    Serial.print("Reading: ");
    reading = analogRead(A0);
    average = ((float)reading)/1023 * 100;
    Serial.print(reading);
    Serial.print("\t Taken at: ");
    sprintf(time_reading, "%02d:%02d:%02d",
            now.hour(), now.minute(), now.second());
    Serial.println(time_reading);

    // SD Printing
    sound_data_file.print(average);
    sound_data_file.print(",");
    sound_data_file.println(time_reading);

    sound_data_file.close();
}

