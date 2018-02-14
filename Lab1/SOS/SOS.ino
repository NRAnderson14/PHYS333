void setup() {
  pinMode(LED_BUILTIN, OUTPUT); //Have the built-in LED and pin 13 as output
}

void loop() {
  SOS();    //Blinks SOS in morse code
}

/*
 *  SOS()
 *  Function that runs an SOS pattern in morse code on pin 13 of the Arduino
 */
void SOS() {
  for (int s = 1; s <= 3; ++s) {
    dot();
  }
  delay(100);
  
  for (int o = 1; o <= 3; ++o) {
    dash();
  }
  delay(100);

  for (int s = 1; s <= 3; ++s) {
    dot();
  }

  delay(1500);
}

/*
 *  dot()
 *  Function that writes one morse code dot to pin 13, complements dash()
 */
void dot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);   //One unit time = 250 ms
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}

/*
 *  dash()
 *  Function that writes one morse code dash to pin 13, complements dot()
 */
void dash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(750);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}

