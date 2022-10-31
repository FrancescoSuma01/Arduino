
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int rosso = 12;
int verde = 13;
int pin=0;

const byte ROWS = 4; // Quattro righe
const byte COLS = 4; // Quattro colonne
// Definizione mappa della tastiera
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = { 8, 7, 6, 5 }; // Riga0,1,2,3.
byte colPins[COLS] = { 12, 11, 10, 9}; // Colonna0,1,2,3
// Creazione della tastiera
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
 pinMode(rosso, OUTPUT);
 pinMode(verde, OUTPUT);
 lcd.begin(); 
 lcd.backlight();
}

void loop() {
  digitalWrite(rosso, HIGH);
  lcd.setCursor(0, 0); //dove deve iniziare a scrivere nel display
  lcd.print("INSERISCI IL PIN");
  char key = kpd.getKey();
  if (key) {
    pin=key;
    }
    delay(1000);
  if(pin!="1234"){
    while(pin!=1234){
      lcd.setCursor(0, 0); //dove deve iniziare a scrivere nel display
      lcd.print("INSERISCI IL PIN");
      char key = kpd.getKey();
      delay(1000);
      if (key) {
        pin=key;
        }
      lcd.setCursor(0, 0); //dove deve iniziare a scrivere nel display
      lcd.print("INSERISCI IL PIN");
      char key = kpd.getKey();
      delay(1000);
      if (key) {
        pin=key;
        }
        digitalWrite(rosso, LOW);
        digitalWrite(verde, HIGH);
        lcd.setCursor(0,1); //dove deve iniziare a scrivere nel display
      lcd.print("OK!!");
      }
      }else if(pin=="1234"){
        digitalWrite(rosso, LOW);
        digitalWrite(verde, HIGH);
        lcd.setCursor(1,0); //dove deve iniziare a scrivere nel display
      lcd.print("OK!");
      }
   }
  


 
