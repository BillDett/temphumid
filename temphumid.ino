/* Arduino example code for DHT11, DHT22/AM2302 and DHT21/AM2301 temperature and humidity sensors. More info: www.makerguides.com */
// Include the libraries:
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <LiquidCrystal.h>

// Set DHT pin:
#define DHTPIN 2
// Set DHT type, uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11 
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor for normal 16mhz Arduino:
DHT dht = DHT(DHTPIN, DHTTYPE);

// Initalize the LCD Display
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  // Setup sensor:
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements:
  delay(2000);
  lcd.setCursor(0, 0);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // Read the humidity in %:
  float h = dht.readHumidity();
  // Read the temperature as Fahrenheit:
  float f = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again):
  if (isnan(h) || isnan(f)) {
    lcd.print("No data");
    lcd.setCursor(0, 1);
    lcd.print("from sensor");
    return;
  }
  lcd.print("Temp: ");
  lcd.print(f);
  lcd.print("F");
  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  lcd.print(h);
  lcd.print("%");
  
}
