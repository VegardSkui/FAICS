/* FAICS 1.0
 * Forsker'n Awesome Indoor Climate Software
 * 
 * Made by some students at HVS
 */

// Include libraries
#include <DHT.h>
#include <LiquidCrystal.h>

// Initialize the LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Initialize the humidity/temperature sensor
DHT dht(7, DHT11);

void setup()
{
    // Set the serial bitrate
    Serial.begin(9600);

    // Set up the LCD's number of columns and rows
    lcd.begin(16, 2);

    // Start the humidity/temperature sensor
    dht.begin();
}

void loop()
{
    // Read the humidity
    float h = dht.readHumidity();

    // Read the temperature in celsius from the LM35 sensor
    float c = ((5.0 * analogRead(A2) * 100.0) / 1024 - 32) / 1.8;

    // Read the pressure and convert to hPa
    float p = ((analogRead(A1) / 1024.0) + 0.095) / 0.000009 / 100;

    // Print the data to Serial
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print("%/t, Temperature: ");
    Serial.print(c);
    Serial.print(" deg.C, Pressure: ");
    Serial.print(p);
    Serial.println(" hPa");

    // Clear the screen and reset the cursor position
    lcd.clear();
    lcd.setCursor(0, 0);
    
    // Print the data to the LCD
    lcd.print("H ");
    lcd.print(h);
    lcd.print(", C ");
    lcd.print(c);
    lcd.setCursor(0, 1);
    lcd.print("P ");
    lcd.print(p);

    // Delay before next loop
    delay(500);
}
