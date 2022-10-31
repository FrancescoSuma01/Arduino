// --------------------------------------
// i2c_scanner
//
// Versione 1
// Questo programma (o codice simile)
// può essere trovato in molti posti.
// Ad esempio sul forum Arduino.cc.
// L'autore originale non è noto.
// Versione 2, giugno 2012, utilizzando Arduino 1.0.1
// Adattato per essere il più semplice possibile dall'utente Krodal di Arduino.cc
// Versione 3, 26 febbraio 2013
// V3 di louarnold
// Versione 4, 3 marzo 2013, utilizzando Arduino 1.0.3
// dall'utente Arduino.cc Krodal.
// Modifiche di Louarnold rimosse.
// Scansione indirizzi modificati da 0 ... 127 a 1 ... 119,
// secondo lo scanner i2c di Nick Gammon
// https://www.gammon.com.au/forum/?id=10896
// Versione 5, 28 marzo 2013
// Come versione 4, ma ora viene eseguita la scansione dell'indirizzo a 127.
// Un sensore sembra utilizzare l'indirizzo 120.
// Versione 6, 27 novembre 2015.
// Aggiunto in attesa della comunicazione seriale Leonardo.
//
//
// Questo schizzo verifica gli indirizzi standard a 7 bit
// I dispositivi con un indirizzo bit più alto potrebbero non essere visualizzati correttamente.
//
 
#include <Wire.h>
 
 
void setup ( )
{
  Filo. begin ( ) ;
 
  Seriale. inizio ( 9600 ) ;
  while ( ! Serial ) ;             // Leonardo: attendi il monitor seriale
  Seriale. println ( " \ n I2C Scanner" ) ;
}
 
 
void loop ( )
{
  errore di byte , indirizzo ;
  int nDevices ;
 
  Seriale. println ( "Scansione ..." ) ;
 
  nDevices = 0 ;
  per ( indirizzo = 1 ; indirizzo < 127 ; indirizzo ++ )
  {
    // i2c_scanner utilizza il valore di ritorno di
    // il Write.endTransmisstion per vedere se
    // un dispositivo ha confermato l'indirizzo.
    Filo. beginTransmission ( indirizzo ) ;
    errore = Filo. endTransmission ( ) ;
 
    if ( errore == 0 )
    {
      Seriale. print ( "Dispositivo I2C trovato all'indirizzo 0x" ) ;
      if ( indirizzo < 16 )
        Seriale. print ( "0" ) ;
      Seriale. print ( indirizzo , HEX ) ;
      Seriale. println ( "!" ) ;
 
      nDevices ++;
    }
    altrimenti se ( errore == 4 )
    {
      Seriale. print ( "Errore sconosciuto all'indirizzo 0x" ) ;
      if ( indirizzo < 16 )
        Seriale. print ( "0" ) ;
      Seriale. println ( indirizzo , HEX ) ;
    }    
  }
  if ( nDevices == 0 )
    Seriale. println ( "Nessun dispositivo I2C trovato \ n " ) ;
  altro
    Seriale. println ( "fatto \ n " ) ;
 
  ritardo ( 5000 ) ;           // aspetta 5 secondi per la prossima scansione
}
