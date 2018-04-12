#include <DHT.h>
#include <DHT_U.h>



#include <DHT.h>

// Libraries einbinden

#include <LiquidCrystal.h>

dht11 DHT11;
#define DHT11PIN 8

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

void setup()
{
  lcd.begin(16, 2);
  lcd.print("Initialisierung...");
  lcd.clear();
}

void loop()
{
  int chk = DHT11.read(DHT11PIN);

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print((float)DHT11.temperature, 2);
  lcd.print(" C");
  
  lcd.setCursor(0, 1);
  lcd.print("RelF: ");
  lcd.print((float)DHT11.humidity, 2);
  lcd.print(" %");
  
  delay(2000);
}
