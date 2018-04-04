/* Program to model the function of a rice cooker
 *
 * Pin 7 is the notification LED for the initial heating phase, so
 *   it will be on when the cooker is heating the rice and water to boiling
 * Pin 8 is the notification LED for the warming phase, which is on when
 *   the cooker is maintaining the temperature of the cooked rice
 * Pin 9 is the drive signal for the heater, where the PWM output will
 *   control how much heat the heater is putting out
 * Analog pin 0 is the input from the temperature sensor
 *
 * Pins 2 and 3, when on, control the heating and warming modes 
 *   respectively
 */

#define LED_HEATING 7
#define LED_WARMING 8
#define HEATER_CONTROL 9
#define TEMP_IN 0
#define HEATING_ON 2
#define WARMING_ON 3

// The frequency for the PWM heater control
unsigned int freq;

void setup() {
    pinMode(LED_HEATING, OUTPUT);
    pinMode(LED_WARMING, OUTPUT);
    pinMode(HEATER_CONTROL, OUTPUT);
    pinMode(HEATING_ON, INPUT);
    pinMode(WARMING_ON, INPUT);
    freq = 0;
}

void loop() {
    // Both buttons can't be on at the same time
    if (digitalRead(HEATING_ON)) {
        unsigned int heating_start = millis();
        
        // It takes ten minutes to cook the rice
        while (millis() - heating_start < 600000) {
            digitalWrite(LED_HEATING, HIGH);
            heating_cycle();
        }
    } 
    else if (digitalRead(WARMING_ON)) {
        while (digitalRead(WARMING_ON)) {
            digitalWrite(LED_WARMING, HIGH);
            warming_cycle();
        }
    } 
    else {
        digitalWrite(LED_HEATING, LOW);
        digitalWrite(LED_WARMING, LOW);
    }
}

void heating_cycle() {
    float temp = readTemp(TEMP_IN);
    // Water shouldn't get over 212F, as energy is lost to steam after that
    if (temp > 212.0) {
        reduce_heat();
    } else if (temp < 212.0) {
        increase_heat();
    }

    delay(200);
}

void warming_cycle() {
    float temp = readTemp(TEMP_IN);
    // We should keep the rice at around 160-170F
    if (temp < 160) {
        increase_heat();
    } else if (temp > 170) {
        reduce_heat();
    }

    delay(200);
}

float readTemp(int pin) {
    int value;
    float celsius, fahr;
    value = analogRead(pin);
    celsius  = ((float)value*4.9 - 500) / 10;
    fahr = (celsius*9/5 + 32);
    return fahr;
}

void reduce_heat() {
    // Can't have negatives
    if (freq > 19)
        freq -= 20;
    analogWrite(HEATER_CONTROL, freq);
}

void increase_heat() {
    // Can't go over 255
    if (freq < 236)
        freq += 20;
    analogWrite(HEATER_CONTROL, freq);
}
