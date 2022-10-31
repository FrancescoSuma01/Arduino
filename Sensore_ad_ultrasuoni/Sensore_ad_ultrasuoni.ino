const int triggerPort = 9;
const int echoPort = 10; 
const int triggerPort1 = 3;
const int echoPort1 = 4; 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode (triggerPort, OUTPUT);
  pinMode (echoPort, INPUT);
  pinMode (triggerPort1, OUTPUT);
  pinMode (echoPort1, INPUT);
  lcd.begin ();
  lcd.backlight();
}

void loop() {
  digitalWrite (triggerPort, LOW);
  digitalWrite (triggerPort, HIGH);
  delayMicroseconds (10);
  digitalWrite (triggerPort, LOW);

  digitalWrite (triggerPort1 LOW);
  digitalWrite (triggerPort1, HIGH);
  delayMicroseconds (10);
  digitalWrite (triggerPort1, LOW);


  long durata = pulseIn (echoPort, HIGH);
  long distanza = 0.034 * durata / 2;
  long durata1 = pulseIn (echoPort1, HIGH);
  long distanza1 = 0.034 * durata / 2;
  lcd.setCursor(1, 0);
  lcd.print(distanza);
  lcd.println (" cm    ");  
  delay(1000);
  lcd.setCursor(1, 1);
  lcd.print(distanza1);
  lcd.println (" cm    ");  
  delay(1000);
}
