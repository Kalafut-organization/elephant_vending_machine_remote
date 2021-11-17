// defines pins numbers

// Motor 1
const int dir = 2;
const int pul = 1; 
const int ena = 3;
const int buttonpin=12;
int buttonstate=0;

//Motor 2
const int buttonpin2=10;
int buttonstate2=0;
const int dir2 = 5;
const int pul2 = 4;
const int ena2 = 6;

//Motor 3
const int buttonpin3=11;
int buttonstate3=0;
const int dir3 = 8;
const int pul3 = 7;
const int ena3 = 9;

const int ledPin=13;
void setup() {



  // Sets the two pins as Outputs
//Motor 1
pinMode(pul,OUTPUT); 
pinMode(dir,OUTPUT);
pinMode(ena,OUTPUT);
digitalWrite(ena,LOW);
pinMode(buttonpin,INPUT);

//Motor 2
pinMode(pul2,OUTPUT); 
pinMode(dir2,OUTPUT);
pinMode(ena2,OUTPUT);
digitalWrite(ena2,LOW);
pinMode(buttonpin2,INPUT);

//Motor 3
pinMode(pul3,OUTPUT); 
pinMode(dir3,OUTPUT);
pinMode(ena3,OUTPUT);
digitalWrite(ena3,LOW);
pinMode(buttonpin3,INPUT);

pinMode(ledPin, OUTPUT);

Serial.begin(115200);

}

void loop() {
  int sig = 0;
  if (Serial.available() > 0)
    sig = Serial.parseInt();
  buttonstate=digitalRead(buttonpin);
  if (buttonstate==HIGH || sig == 1){
  digitalWrite(dir,LOW); //Changes the rotations direction
  // x=90/1.8=50, rotate for 90 degrees.
  for(int x = 0; x < 50; x++) {
    digitalWrite(pul,HIGH);
    delayMicroseconds(4000);
    digitalWrite(pul,LOW);
    delayMicroseconds(4000); 
    digitalWrite(ledPin, HIGH);
    }
    Serial.println("Motor 1 activated");
  }
  else{
    digitalWrite(pul,LOW); 
    digitalWrite(ledPin, LOW);
  }
  
//Motor 2
  buttonstate2=digitalRead(buttonpin2);
  if (buttonstate2==HIGH || sig == 2){
  digitalWrite(dir2,LOW); //Changes the rotations direction
  // x=90/1.8=50, rotate for 90 degrees.
  for(int x = 0; x < 50; x++) {
    digitalWrite(pul2,HIGH);
    delayMicroseconds(4000);
    digitalWrite(pul2,LOW);
    delayMicroseconds(4000); 
    digitalWrite(ledPin, HIGH);
    }
    Serial.println("Motor 2 activated");
  }
  else{
    digitalWrite(pul2,LOW);
    digitalWrite(ledPin, LOW); 
  }

//Motor 3
  buttonstate3=digitalRead(buttonpin3);
  if (buttonstate3==HIGH || sig == 3){
  digitalWrite(dir3,LOW); //Changes the rotations direction
  // x=90/1.8=50, rotate for 90 degrees.
  for(int x = 0; x < 50; x++) {
    digitalWrite(pul3,HIGH);
    delayMicroseconds(4000);
    digitalWrite(pul3,LOW);
    delayMicroseconds(4000); 
    digitalWrite(ledPin, HIGH);
    }
    Serial.println("Motor 3 activated");
  }
  else{
    digitalWrite(pul3,LOW); 
    digitalWrite(ledPin, LOW);
  }
  
  }
