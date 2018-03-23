#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define WACHTTIJD 750   // Maak van wachttijd een constante

// Hier wordt het lcd scherm ingesteld
int led[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Totaal van 8 elementen
LiquidCrystal_I2C lcd(0x38, 16, 2);   // Zet het i2c adres op 0x38 16 karakters en 2 regels.

void setup() {
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  lcd.setCursor(2, 0);      //Zet de cursor op posite 4  regel 0
  lcd.print("Jan Middel");

  // put your setup code here, to run once:
  // ga door alle leds heen en zet ze op output mode
  // Let op: Ik heb hier geen {} gebruikt omdat er maar 1 regel onderdeel is van de lus
  for (char index=0; index < 8; index++)
    pinMode(led[index], OUTPUT);
    
}

void loop() {
  // ga door alle leds heen en zet ze aan of uit
  // Let op: Hier wordt {} gebruikt om meerdere regels samen te pakken
  for (char index=0; index < 8; index++) {
    // Check dat de index > 0 is. Als dat het geval is dan pak index-1; anders gebruik positie 8
    digitalWrite(led[ (index==0) ? 8 : index-1 ], LOW);    // Zet de vorige ronde op laag
    digitalWrite(led[index], HIGH);     // Zet deze ronden op HOOG
    delay (WACHTTIJD);
  }
  
  //lcd.setCursor(1, 1);
  //lcd.print(plaats);
}
