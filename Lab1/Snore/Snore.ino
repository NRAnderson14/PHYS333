/*
 *  Program to 'snore' an LED
 *  The LED will continuously get brighter and then dimmer forever
 */

int LED_OUT = 11;
int LED_BRIGHTNESS = 100;
int delay_time = 10;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_OUT, OUTPUT);
  analogWrite(LED_OUT, LED_BRIGHTNESS);  //Using PWM to dim the LED
}

void loop() {
  for (int i = 0; i <= 255; ++i) {  //From dim to bright
    analogWrite(LED_OUT, i);
    delay(delay_time);
  }

  for (int i = 255; i >= 0; --i) {  //From bright to dim
    analogWrite(LED_OUT, i);
    delay(delay_time);
  }
}

