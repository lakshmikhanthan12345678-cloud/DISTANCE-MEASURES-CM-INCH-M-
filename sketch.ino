#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define TRIG_PIN 12
#define ECHO_PIN 13
#define LED_PIN_1 16
#define LED_PIN_2 17
#define LED_PIN_3 18
#define LED_PIN_4 19

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
Serial.begin(9600);
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
pinMode(LED_PIN_1, OUTPUT);
pinMode(LED_PIN_2, OUTPUT);
pinMode(LED_PIN_3, OUTPUT);
pinMode(LED_PIN_4, OUTPUT);
lcd.init();
lcd.backlight();
}

void loop() {
long duration, distance_cm, distance_inches;
float distance_m, distance_km;

digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds (10);
digitalWrite(TRIG_PIN, LOW);

duration = pulseIn(ECHO_PIN, HIGH);
distance_cm = duration / 58; 
distance_inches = duration / 148; 
distance_m = distance_cm / 100.0; 
distance_km = distance_m / 1000.0; 

Serial.print("Distance: ");
Serial.print(distance_cm);
Serial.print(" cm, ");
Serial.print(distance_inches);
Serial.print(" inches, ");
Serial.print(distance_m);
Serial.print(" m, ");
Serial.print(distance_km);
Serial.println(" km ");

if (distance_cm < 10) {
digitalWrite(LED_PIN_1, HIGH);
digitalWrite(LED_PIN_2, HIGH);
digitalWrite(LED_PIN_3, HIGH);
digitalWrite(LED_PIN_4, HIGH);
} else if (distance_cm < 20) {
digitalWrite(LED_PIN_1, HIGH);
digitalWrite(LED_PIN_2, HIGH);
digitalWrite(LED_PIN_3, HIGH);
digitalWrite(LED_PIN_4, LOW);
} else if (distance_cm <30) {
digitalWrite(LED_PIN_1, HIGH);
digitalWrite(LED_PIN_2, HIGH);
digitalWrite(LED_PIN_3, LOW);
digitalWrite(LED_PIN_4, LOW);
} else if (distance_cm < 40) {
digitalWrite(LED_PIN_1, HIGH);
digitalWrite(LED_PIN_2, LOW);
digitalWrite(LED_PIN_3, LOW);
digitalWrite(LED_PIN_4, LOW);
} else {
digitalWrite(LED_PIN_1, LOW);
digitalWrite(LED_PIN_2, LOW);
digitalWrite(LED_PIN_3, LOW);
digitalWrite(LED_PIN_4, LOW);
}

lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Distance: ");
lcd.print(distance_cm);
lcd.print("cm");

delay(1000);
}