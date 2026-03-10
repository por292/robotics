// My Fan code

const int EnA = 7;
const int In1 = 9;
const int In2 = 8;
void setup()
{
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(EnA, OUTPUT); 
}
void goStraight()   //run both motors in the same direction
{

  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(EnA, 150);
  
  delay(20);
  // now turn off motors

  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);  
  digitalWrite(EnA, LOW);

}

void loop()
{
goStraight();
delay(10);

}


//My LED code
const int buzz = 9;
const int led1 = 7;
const int led2 = 5;
const int btn = A0;

void setup()
{
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 
}

void loop(){

if (digitalRead(btn) == HIGH){
digitalWrite(led1, 255);
  delay(250);
digitalWrite(led1, 0);
  delay(50);
digitalWrite(led2, 255);
  delay(250);
digitalWrite(led2, 0);
  delay(50);
tone (buzz,300);
 delay(250);
tone (buzz,500);
 

	}
}

//My led sound sensor 
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
  int ledMove[] = {LOW, LOW, LOW, LOW, LOW};
  int whichLed = map(analogRead(soundPin), 0, 500, 0, 5);

  for (int i = 0; i <= whichLed; i++){
    ledMove[i] = HIGH;
  }
  
  delay(100);
  }
