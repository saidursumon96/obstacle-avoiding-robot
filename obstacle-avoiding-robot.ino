#include <Servo.h>
#define ENA 10
#define ENB 9
#define IN1 2
#define IN2 3
#define IN3 5
#define IN4 6

#define trigPin 12
#define echoPin 11

void setup() {
  Serial.begin(9600);
  Serial.println("Motor test!");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);  
}

void loop() {

  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance < 25) {
    Serial.println ("Close Obstacle detected!" );
    Serial.println ("Obstacle Details:");
    Serial.print ("Distance From Robot is " );
    Serial.print (distance);
    Serial.print ( " CM!");
    Serial.println (" The obstacle is declared.");
    Serial.println (" Turning !");
    motorA(2,20);
    motorB(2,20);
    delay (250);
    motorA(1,20);
    motorB(2,50);
  }
  else {
    Serial.println ("No obstacle detected. going forward");
    delay (15);
    motorA(1,35);
    motorB(1,35);
  }
}

void motorA(int mode, int percent){
  int duty = map(percent, 0, 100, 0, 255);
  
  switch(mode){
    case 0: digitalWrite(ENA, LOW);
            break;
      
    case 1: digitalWrite(IN1, HIGH);   
            digitalWrite(IN2, LOW);  
            analogWrite(ENA, duty);  
            break;
      
    case 2: digitalWrite(IN1, LOW);   
            digitalWrite(IN2, HIGH);  
            analogWrite(ENA, duty);  
            break;
      
    case 3: digitalWrite(IN1, LOW);   
            digitalWrite(IN2, LOW);  
            analogWrite(ENA, duty);      
            break;
  }
}

  void motorB(int mode, int percent){
    int duty = map(percent, 0, 100, 0, 255);
  
  switch(mode){
    case 0: digitalWrite(ENB, LOW);
            break;
      
    case 1: digitalWrite(IN3, HIGH);   
            digitalWrite(IN4, LOW);   
            analogWrite(ENB, duty);  
            break;
      
    case 2: digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);  
            analogWrite(ENB, duty);  
            break;
      
    case 3: digitalWrite(IN3, LOW);
            digitalWrite(IN4, LOW);  
            analogWrite(ENB, duty);  
            break;
  }
}


