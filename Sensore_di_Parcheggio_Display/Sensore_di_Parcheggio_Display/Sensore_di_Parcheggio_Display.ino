#include <LiquidCrystal_I2C.h>

const int triggerPort = 13;
const int echoPort = 12; 
const int led = 11;

unsigned long t1, dt;
int tblink = 100;
int statoled = LOW;
int freq = 220;

//porta sda A4 scl A5
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() { 
  pinMode(triggerPort, OUTPUT);
  pinMode(echoPort, INPUT);
  pinMode(led, OUTPUT);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  long distanza = misura();
  lcd.setCursor(0, 0);
  lcd.print("distanza: ");
  lcd.setCursor(10, 0);
  lcd.print(distanza);

  if (distanza < 10) {
    digitalWrite(led, HIGH);
    tone(10, 880);
  } else if (distanza > 50) {
    digitalWrite(led, LOW);
    noTone(10);
  } else {
    tblink = map(distanza, 10, 50, 30, 300); //5-40 dist max e min, 30-300 millisecond max e min
    freq = map(distanza, 10, 50, 880, 220); //5-40 dist max e min, 880-220 frequenza max e min

    dt = millis() - t1;
    if (dt >= tblink) {
      statoled = !statoled;
      digitalWrite(led, statoled);
      t1 = millis();
      if (statoled) {
        tone(10, freq, 100);  //pin, frequenza, durata(millisecond)
      } else {
        //noTone(10);  
      }
    }   
  } 
  
  delay(100);
}

long misura() {
  //porta bassa l'uscita del trigger
  digitalWrite( triggerPort, LOW );
  //invia un impulso di 10microsec su trigger
  digitalWrite( triggerPort, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( triggerPort, LOW );
   
  long durata = pulseIn( echoPort, HIGH ); 
  long distanza = 0.034 * durata / 2;
  return distanza;
    
}
