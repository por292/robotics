const int soundPin = A0;
const int led1 = 11;
const int led2 = 10;
const int led3 = 9;
const int led4 = 8;
const int led5 = 7;
void setup() {

  Serial.begin(9600);
  pinMode(soundPin, INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);

}

 

void loop() {

  Serial.println(analogRead(soundPin));
  delay(50);
  digitalWrite(led1, 255);
  digitalWrite(led2, 255);
  digitalWrite(led3, 255);
  digitalWrite(led4, 255);
  digitalWrite(led5, 255);

}
