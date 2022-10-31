#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//porta sda A4 scl A5

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
 lcd.begin(); // Inializiamo l'LCD
 lcd.backlight(); // Accendi la luce nera  e stampa un messaggio
}


void loop(){
  digitalWrite(3, OUTPUT);
  lcd.setCursor(0, 0); //dove deve iniziare a scrivere nel display
  lcd.print("     Hello"); // cosa deve scrivere 
  lcd.setCursor(0, 1); //dove deve iniziare a scrivere nel display
  lcd.print("     World");
  delay(2000);  
}
