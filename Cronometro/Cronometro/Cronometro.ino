#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode (1, OUTPUT);
  pinMode (2, INPUT);
  pinMode (3, OUTPUT);
  pinMode (4, INPUT);
  lcd.begin(); // Inializiamo l'LCD
  lcd.backlight();
}

void loop() {
  digitalWrite(2, LOW);
  if(2, HIGH){
    lcd.setCursor(0, 0); //dove deve iniziare a scrivere nel display
    lcd.print("Ciao mondo"); // cosa deve scrivere 
    lcd.setCursor(0, 1); //dove deve iniziare a scrivere nel display
    lcd.print("      World");
  }
}
