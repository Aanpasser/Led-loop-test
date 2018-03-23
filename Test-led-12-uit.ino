
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Hier wordt het lcd scherm ingesteld
int led[] = {2, 3, 4, 5, 6, 7, 8, 9};
int wachtlus (750);
int teller;
int plaats;
LiquidCrystal_I2C lcd(0x38, 16, 2); // Zet het i2c adres op 0x38 16 karakters en 2 regels.

//

void setup()
{
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  lcd.setCursor(2, 0);      //Zet de cursor op posite 4  regel 0
  lcd.print("Jan Middel");


  // put your setup code here, to run once:
  for (teller = 2; teller <= 9; teller++)
  pinMode(led[teller],OUTPUT);}


void loop()
{

  //
  for (plaats = 0 ; plaats < 8; plaats++);
  delay (wachtlus);
  digitalWrite(led[plaats], HIGH);
  //lcd.setCursor(1, 1);
  //lcd.print(plaats);

}
