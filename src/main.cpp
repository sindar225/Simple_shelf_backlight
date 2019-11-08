#include <Arduino.h>
#include <LowPower.h>

#define LED_PIN 9
#define IR_TRIGGER 2

void led_fade_in();
void led_fade_out();
void change_state();
void wake_up();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(IR_TRIGGER, INPUT);
  analogWrite(LED_PIN, 0);
}

void loop() {
  attachInterrupt(digitalPinToInterrupt(IR_TRIGGER), wake_up, CHANGE);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  detachInterrupt(0);
}

void wake_up() {
  int ir_trigger = digitalRead(IR_TRIGGER);
  ir_trigger == HIGH ? led_fade_in() : led_fade_out();
}

void led_fade_in() {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(LED_PIN, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}

void led_fade_out() {
  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(LED_PIN, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}
