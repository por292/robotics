// full code for boardgame
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd1(0x26,16,2);
LiquidCrystal_I2C lcd2(0x27,16,2);


const int btnPin = (13);  
bool last_btn_state = LOW; 
bool btn_state = LOW; 
unsigned long btn_deb = 100; 
unsigned long last_btn_deb = 0; 
bool btn_toggle = false; 
const int echoPin = (10);
const int trigPin = (9); 
bool sensorEnable = false; 
const int ClkPin = (7);
const int CsPin = (6);
const int DinPin = (5);
int duration, distance;


void setup()
{
lcd1.init();
lcd1.backlight();
lcd2.init();
lcd2.backlight(); 
pinMode(btnPin, INPUT_PULLUP);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600); 
}
void loop()

{
  btn_press();
  Off();
  On();
}
long microsecondsToCentimetres(long microseconds)
{
  return microseconds / 29 / 2;
}



void btn_press() {
  if (millis() - last_btn_deb >= btn_deb) // wait for debounce time
  {
    btn_state = digitalRead(btnPin); // read btn state
    if (btn_state != last_btn_state) // check btn state
    {
      last_btn_deb = millis(); 
      last_btn_state = btn_state; 
      if (btn_state == HIGH)
      {
        btn_toggle = !btn_toggle; 
      }
    }
  }
}
void Off()
{
  btn_press();
  if (btn_toggle == true) {
    lcd1.clear();
    lcd2.clear();
    lcd1.noBacklight();
    lcd2.noBacklight();  
   digitalWrite(trigPin, LOW); 
    lcd1.setCursor(0,0);
    lcd1.print("");
    lcd2.setCursor(0,0);
    lcd2.print("");
  }
  delay(100);
}
void On()
{
  btn_press();
  if (btn_toggle == false) {
    lcd1.backlight();
    lcd2.backlight();  
    lcd1.setCursor(0,0);
    lcd1.print("Ready to play P1");
    lcd1.setCursor(0,1);
    lcd1.print("TouchSensorStart");
    lcd2.setCursor(0,0);
    lcd2.print("Ready to play P2");
    lcd2.setCursor(0,1);
    lcd2.print("TouchSensorStart");
   /* long duration, cm;
   
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
    delay(100);*/
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2;
    Serial.println(distance);
  }
}


//LCD Saanner for its adress
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
