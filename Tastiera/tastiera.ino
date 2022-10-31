#include <Keypad.h>

const byte ROWS = 4; // Quattro righe
const byte COLS = 4; // Quattro colonne
// Definizione mappa della tastiera
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = { 4, 5, 6, 7 }; // Riga0,1,2,3.
byte colPins[COLS] = { 8, 9, 10, 11}; // Colonna0,1,2,3
// Creazione della tastiera
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
}
void loop()
{
  char key = kpd.getKey();
  if (key) {
    Serial.println(key);
  }
}
