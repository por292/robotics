// full code for boardgame
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd1(0x26, 16, 2);
LiquidCrystal_I2C lcd2(0x27, 16, 2);


const int btnPin = (13);
bool last_btn_state = LOW;
bool btn_state = LOW;
unsigned long btn_deb = 100;
unsigned long last_btn_deb = 0;
bool btn_toggle = false;


const int echoPin = (10);
const int trigPin = (9);
bool sensorEnable = false;


const int TSPin = (5);
bool TS_state = LOW;
bool last_TS_state = LOW;
unsigned long hold = 100;
unsigned long last_hold = 0;
bool hold_toggle = false;

int TS_state1 = LOW;
const int TSPin1 = (7);
int duration, distance;

int lastRead = LOW;
const unsigned long debounceDelay = 50;
unsigned long lastDebounceTime = 0;


void setup() {
 // lcd1.init();
  lcd1.begin();
  lcd1.backlight();
 // lcd2.init();
  lcd2.begin();
  lcd2.backlight();
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(TSPin, INPUT);
  pinMode(TSPin1, INPUT);
  Serial.begin(9600);
}
void loop()

{
  P1();
  //P2();
  btn_press();
  Off();
  On();
}
long microsecondsToCentimetres(long microseconds) {
  return microseconds / 29 / 2;
}


void btn_press() {
  if (millis() - last_btn_deb >= btn_deb)  
  {
    btn_state = digitalRead(btnPin);  
    if (btn_state != last_btn_state)  
    {
      last_btn_deb = millis();
      last_btn_state = btn_state;
      if (btn_state == HIGH) {
        btn_toggle = !btn_toggle;
      }
    }
  }
}
void Off() {

  btn_press();
  if (btn_toggle == true) {
    lcd1.clear();
    lcd2.clear();
    lcd1.noBacklight();
    lcd2.noBacklight();
    digitalWrite(trigPin, LOW);
    lcd1.setCursor(0, 0);
    lcd1.print("");
    lcd2.setCursor(0, 0);
    lcd2.print("");
  }
  delay(100);
}
void On() {
  //P1();
  //P2();
  btn_press();
  if (btn_toggle == false) {
    lcd1.backlight();
    lcd2.backlight();
    lcd1.setCursor(0, 0);
    lcd1.print("Ready to play P1");
    lcd1.setCursor(0, 1);
    lcd1.print("TouchSensorStart");
    lcd2.setCursor(0, 0);
    lcd2.print("Ready to play P2");
    lcd2.setCursor(0, 1);
    lcd2.print("TouchSensorStart");

    int touch = digitalRead(TSPin);
    Serial.println(touch);
    int touch1 = digitalRead(TSPin1);
    Serial.println(touch1);

 

   /* if (digitalRead(TSPin) == HIGH)
    {
     lcd1.clear();
     lcd1.print("P1 turn");
     
    }
    else if( digitalRead(TSPin) == LOW)
    {
      lcd2.clear();
      lcd2.print("");
    }
    if (digitalRead(TSPin1) == HIGH)
    {
     lcd2.clear();
     lcd2.print("P2 turn");
     
    }
    else if( digitalRead(TSPin1) == LOW)
    {
      lcd1.clear();
      lcd1.print("P2 turn");
    }*/


    /*digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2;
    Serial.println(distance);*/
  }
  if (hold_toggle == false){
      P1();
      delay(1000);
  }
}
void P1()
{
  int reading = digitalRead(TSPin);
  if (reading != lastRead) {
    lastDebounceTime = millis();
  }
   if ((millis() - lastDebounceTime) > debounceDelay) {
    // stable state detected
    static int stableState = LOW;
    if (reading != stableState) {
      stableState = reading;
      // toggle on rising edge (LOW->HIGH). If your module is active LOW, change to falling edge.
      if (stableState == HIGH) {
        TS_state = !TS_state;
        digitalWrite(TSPin, TS_state ? HIGH : LOW);
        Serial.println(TS_state ? "ON" : " OFF");
      }
    }
   }
 /*if (millis() - last_hold >= hold)  
  {
    TS_state = digitalRead(TSPin);  
    if (TS_state != last_TS_state)  
    {
      last_hold = millis();
      last_TS_state = TS_state;
      if (TS_state == HIGH) {
        hold_toggle = !hold_toggle;
        lcd1.clear();
        lcd1.println("P1 turn");
        delay(1000);
      }
    }*/
  //}
}
void P2()
{
  
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
