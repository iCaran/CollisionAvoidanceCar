#include<AFMotor.h>

int leftMotorTerminal=1;
int rightMotorTerminal=4;
int trig=5;
int echo=6;
int duration, distance;

AF_DCMotor leftMotor(leftMotorTerminal);
AF_DCMotor rightMotor(rightMotorTerminal);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void scan(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);   
  digitalWrite(trig, HIGH); // Transmit Waves For 10us
  delayMicroseconds(10);
  duration = pulseIn(echo, HIGH); // Recieve Reflected Waves
  distance = duration / 58.2; // Get Distance
  Serial.println(distance);
  delay(10);
}

void go(){
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
  delay(100);
}

void stop(){
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
  delay(1000);
}

void rev(){
  leftMotor.run(BACKWARD);
  rightMotor.run(BACKWARD);
  delay(500);
}

void left(){
  rightMotor.run(FORWARD);
  delay(500);
}

void right(){
  leftMotor.run(FORWARD);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  scan();
  if (distance > 20){
    go();
  }
  else{
    //stop
    stop();

    //go back
    rev();

    //stop
    stop();

    // turn left
    left();
    scan();
    if(distance<20){
      right();
    }
  }
}
