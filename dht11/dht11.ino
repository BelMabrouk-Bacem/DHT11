
//#include <DallasTemperature.h>

//#include <DHT.h>
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// ------------------------------------------------------------------
// for DHT11, ( Capteur Temperature + Humidité )
//      VCC: 5V or 3V
//      GND: GND
//      DATA: pinDHT11
#include <SimpleDHT.h>
int pinDHT11 = 13;
SimpleDHT11 dht11;
int err = SimpleDHTErrSuccess;
// =======================================================================
void setup() {
  Serial.begin(9600);
  // Initialisation de l'écran LCD
  lcd.begin(16, 2); // 16 colonnes et 2 lignes
}
// =======================================================================+
void loop() {
  // Affichage sur le terminal
  Serial.println("=================================");
  // Lecture de la température et de l'humidité ------------------
  byte temperature = 0;
  byte humidity = 0;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    // Si on n'arrive pas à lire les données.
    Serial.print("Read DHT11 failed, err="); Serial.println(err); delay(1000);
    return;
  }
  Serial.print("Température : "); Serial.print((int)temperature); Serial.println(" °C");
  Serial.print("Humidité : ");    Serial.print((int)humidity); Serial.println(" %");
  // Ecran LCD --------------------------------------------------
  lcd.setCursor(0, 0);
  lcd.print("Temperature: "); lcd.print((int)temperature); lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humidite   : ");    lcd.print((int)humidity);    lcd.print("%");
  delay(2000);
}
