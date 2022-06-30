#include<AFMotor.h>
#include <Servo.h>

Servo myservo; 
int leftMotorTerminal=1;
int rightMotorTerminal=4;
int trig=5;
int echo=6;
int duration, distance, l_Dist_Temp;

AF_DCMotor leftMotor(leftMotorTerminal);
AF_DCMotor rightMotor(rightMotorTerminal);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myservo.attach (10); 
  myservo.write(89); 
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
  delay(500);
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
  delay(500);
}

void servoLeft(){
  myservo.write(134);
  delay(15);
}

void servoRight(){
  myservo.write(44);
  delay(15);
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

    //scan left
    servoLeft();
    scan();
    l_Dist_Temp=distance;
    
    //scan right
    servoRight();
    scan();

    //center servo
    myservo.write(89); 

    //chose direction
    if(l_Dist_Temp<distance){
      right();
    } else {
      left();
    }
    
  }
}
