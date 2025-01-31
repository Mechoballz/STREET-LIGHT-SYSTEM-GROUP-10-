#include <LiquidCrystal.h>

// Initialize the LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define LDR_PIN A0  // LDR connected to Analog Pin A0

// LED Pins
const int ledPins[] = {2, 3, 4, 5, 6, 7};  // LEDs connected to digital pins
const int ledCount = 6; // Total number of LEDs

void setup() {
    pinMode(LDR_PIN, INPUT);
    
    // Initialize LED pins as output
    for (int i = 0; i < ledCount; i++) {
        pinMode(ledPins[i], OUTPUT);
    }

    // Initialize LCD
    lcd.begin(16, 2);  // Ensure you have the correct number of columns and rows
    lcd.print("GROUP 10 AUTO STREET LIGHT ACTIVE");
    delay(2000);
    lcd.clear();
}

void loop() {
    int ldrValue = analogRead(LDR_PIN);  // Read LDR value

    // Display the LDR value on the LCD
    // lcd.setCursor(0, 0);
    // lcd.print("LDR Value: ");
    // lcd.print(ldrValue);
    // lcd.print("  ");  // Clear extra digits

    if (ldrValue < 500) {  // Adjust threshold based on environment
        lcd.setCursor(0, 1);
        lcd.print("BELLS NIGHTTIME     ");
        
        // Turn ON LEDs
        for (int i = 0; i < ledCount; i++) {
            digitalWrite(ledPins[i], HIGH);
        }
    } else {
        lcd.setCursor(0, 1);
        lcd.print("BELLS DAYTIME     ");
        
        // Turn OFF LEDs
        for (int i = 0; i < ledCount; i++) {
            digitalWrite(ledPins[i], LOW);
        }
    }
    
    delay(500);  // Small delay for stable readings
}
