#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
long duration, cm, inches;
int distance;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int trigPin = 13;    // Trigger
int echoPin = 12;    // Echo



void setup()
{
  Serial.begin (9600);
  
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}


void loop()
{
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
Serial.println(distance);
  
  
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.setCursor(10,0);
  lcd.print(distance);
  lcd.print("     ");
  lcd.setCursor(14,0);
  lcd.print("cm");
  delay(250);
}
