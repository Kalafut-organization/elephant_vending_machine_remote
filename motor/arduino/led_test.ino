int LED1 = 13;
int LED2 = 12;
int LED3 = 11;

void setup () {
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  Serial.begin(115200);
  
}

void loop () {
  int sig = 0;
  if (Serial.available() > 0)
    sig = Serial.parseInt();
  if (sig == 1)
  {
     digitalWrite(LED1, HIGH);
     delay(500);
     digitalWrite(LED1, LOW);
     delay(500);
     Serial.println("Motor 1 activated");
  } else if (sig == 2)
  {
     digitalWrite(LED2, HIGH);
     delay(500);
     digitalWrite(LED2, LOW);
     delay(500);   
     Serial.println("Motor 2 activated");
  } else if (sig == 3)
  {
     digitalWrite(LED3, HIGH);
     delay(500);
     digitalWrite(LED3, LOW);
     delay(500);   
     Serial.println("Motor 3 activated");
  }
  
}
