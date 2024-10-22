#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Adjust I2C address if needed (Use 0x27 if 0x3F does not work)
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SIGN LANGUAGE");
  
  pinMode(13, OUTPUT);
}

void loop() {
  int s1 = analogRead(A0);
  int s2 = analogRead(A1);
  int s3 = analogRead(A2);
  int s4 = analogRead(A3);

  // Print sensor values for debugging purposes
  Serial.print("Sensor 1 (s1): ");
  Serial.println(s1);
  Serial.print("Sensor 2 (s2): ");
  Serial.println(s2);
  Serial.print("Sensor 3 (s3): ");
  Serial.println(s3);
  Serial.print("Sensor 4 (s4): ");
  Serial.println(s4);

  // Decision logic based on sensor readings
  if (s1 < 150) {
    digitalWrite(13, LOW);
    Serial.println("WashRoom");
    lcd.setCursor(0, 1);
    lcd.print("WASHROOM        ");
    delay(2000);
  } else if (s2 < 200) {
    digitalWrite(13, HIGH);
    Serial.println("Drink Water");
    lcd.setCursor(0, 1);
    lcd.print("DRINK WATER     ");
    delay(2000);
  } else if (s3 < 150) {
    digitalWrite(13, LOW);
    Serial.println("Food");
    lcd.setCursor(0, 1);
    lcd.print("FOOD            ");
    delay(2000);
  } else if (s4 < 130) {
    digitalWrite(13, HIGH);
    Serial.println("Fruit");
    lcd.setCursor(0, 1);
    lcd.print("FRUIT           ");
    delay(2000);
  } else {
    // Default case if no condition is met
    Serial.println("Nothing detected");
    lcd.setCursor(0, 1);
    lcd.print("NOTHING         ");
  }
}
