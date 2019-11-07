#include <Arduino.h>
#include <LowPower.h>

#define PIN 7
#define IR 15

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN, OUTPUT);
  pinMode(IR, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int ir_distance = analogRead(IR);
  if (ir_distance > 30) { // Open
    digitalWrite(PIN, HIGH);
  } else  { // Closed
    digitalWrite(PIN, LOW);
  }
  LowPower.idle(SLEEP_1S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, 
                SPI_OFF, USART0_OFF, TWI_OFF);

}