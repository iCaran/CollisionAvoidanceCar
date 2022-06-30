#include<AFMotor.h>
#include <Servo.h>

Servo myservo; 
int leftMotorTerminal=1;
int rightMotorTerminal=4;
int ir=6;
int ob, lOB;

AF_DCMotor leftMotor(leftMotorTerminal);
AF_DCMotor rightMotor(rightMotorTerminal);

void setup() {
  // put your setup code here, to run once:
  pinMode(ir,INPUT);
  Serial.begin(9600);
  myservo.attach (10); 
  myservo.write(89); 
}

void scan(){
  ob=digitalRead(ir);
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
  if (ob==1){
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
    lOB=ob;
    
    //scan right
    servoRight();
    scan();

    //center servo
    myservo.write(89); 
    
    //chose direction
    if(lOB>0){
      left();
    } else if (ob>0) {
      right();
    }
    
  }
}
