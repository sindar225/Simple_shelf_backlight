#include <Arduino.h>
#include <LowPower.h>

#define LED_PIN 7
#define IR 15

void led_fade_in();
void led_fade_out();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(IR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ir_distance = analogRead(IR);
  if (ir_distance > 30) { // Open
    led_fade_in();
  } else  { // Closed
    led_fade_out();
  }
  LowPower.idle(SLEEP_1S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, 
                SPI_OFF, USART0_OFF, TWI_OFF);

}

void led_fade_in() {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(LED_PIN, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}

void led_fade_out() {
  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(LED_PIN, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}