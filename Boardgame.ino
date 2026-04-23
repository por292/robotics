// full code for boardgame
#include <LiquidCrystal_I2C.h>
#include<wire.h>

LiquidCrystal_I2C lcd1(0x27, 16, 2);
LiquidCrystal_I2C lcd2(0x26, 16, 2);

int ledPin =(13); 
int trigPin = (9); 
int echoPin = (10);
int duration, distance;
void setup()
{
	lcd1.init();
	lcd1.backlight();
	lcd2.init();
	lcd2.backlight()
	pinMode (ledPin, OUTPUT); 
	pinMode (trigPin, OUTPUT);
	pinMode (echoPin, INPUT);
	Serial.begin(9600); 
}
void loop()

{
  long duration, cm;
   
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimetres(duration);
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();  
  delay(100);
}

long microsecondsToCentimetres(long microseconds)
{
  return microseconds / 29 / 2;
}

// Two LCD screens

#include <LiquidCrystal_I2C.h>
#include<wire.h>

LiquidCrystal_I2C lcd1(0x27, 16, 2);
LiquidCrystal_I2C lcd2(0x26, 16, 2);

void setup() {
  lcd1.init();
  lcd1.backlight();
  lcd2.init();
  lcd2.backlight();

}

//LCD Saanner for its adress

void loop() {
 delay(1);
 lcd1.setCursor(0, 0);
 lcd1.print("Hello World!");
 lcd2.setCursor(0, 0);
 lcd2.print("Goodbye World!");

}

#include <Wire.h>
void setup()
{
Wire.begin();
Serial.begin(9600);
Serial.println("\nI2C Scanner");
}
void loop()
{
byte error, address;
int Devices;
Serial.println("Scanning...");
Devices = 0;
for(address = 1; address < 127; address++ )
{
Wire.beginTransmission(address);
error = Wire.endTransmission();
if (error == 0)
{
Serial.print("I2C device found at address 0x");
if (address<16)
  Serial.print("0");
  Serial.print(address,HEX);
  Serial.println("  !");
  Devices++;
}
else if (error==4)
{
Serial.print("Unknown error at address 0x");
if (address<16)
  Serial.print("0");
  Serial.println(address,HEX);
}
}
if (Devices == 0)
  Serial.println("No I2C devices found\n");
else
  Serial.println("done\n");
  delay(5000);          
}
