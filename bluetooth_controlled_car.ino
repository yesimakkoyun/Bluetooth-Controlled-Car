
/********************************************************
 * filename     : bluetooth controlled car
 * author       : yesim akkoyun
 * date         : 24/12/2021
 * description  : it is my first project with arduino but it won't be the last
 ********************************************************/

#include<Servo.h>
Servo myservo;
char dataIn = 'S' ;      //character for stop function
int pinForward = 6;     //control pin for forward driving
int pinBackward = 5;    //control pin for backward driving 
int pinLeft = 4;         //control pin for left driving 
int pinRight = 3;        //control pin for right driving 
int pinPwm1 = 11;
int pinPwm2 = 10;
char determinant;        //character for the loop of the program
char det;                //character for the loop of the program 

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);      //Control of HC-05 bluetooth module
pinMode(pinForward,OUTPUT);
pinMode(pinBackward,OUTPUT);
pinMode(pinLeft,OUTPUT);
pinMode(pinRight,OUTPUT);
pinMode(pinPwm1,OUTPUT);
pinMode(pinPwm2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(pinPwm1,HIGH);
digitalWrite(pinPwm2,HIGH);
   det = check();
   
  while (det == 'F' )        //Letter equivalent of forward drive button assigned in phone program
  {
    digitalWrite(pinForward,HIGH);
    digitalWrite(pinBackward,LOW);
    digitalWrite(pinRight,HIGH);
    digitalWrite(pinLeft,LOW);
    det = check();
  }

  while (det == 'B' )         //Letter equivalent of backward drive button assigned in phone program
  { 
    digitalWrite(pinForward,LOW);
    digitalWrite(pinBackward,HIGH);
    digitalWrite(pinRight,LOW);
    digitalWrite(pinLeft,HIGH);
    det = check();
  }

  while (det == 'L' )        //Letter equivalent of left drive button assigned in phone program
  {
    digitalWrite(pinLeft,HIGH);
    digitalWrite(pinBackward,HIGH);
    det = check();
  }

  while (det == 'R' )        //Letter equivalent of right drive button assigned in phone program
  {
    digitalWrite(pinRight,HIGH);
    digitalWrite(pinForward,HIGH);
    det = check();
  }
  
  while (det == 'X' )        //Letter equivalent of forward - left drive button assigned in phone program
  {
    digitalWrite(pinForward,HIGH);
    digitalWrite(pinLeft,HIGH);
    det = check();
  }

  while (det == 'Y' );       //Letter equivalent of forward - right drive button assigned in phone program
  {
    digitalWrite(pinForward,HIGH);
    digitalWrite(pinRight,HIGH);
    det = check();
  }

  while (det == 'Z' );       //Letter equivalent of backward - left drive button assigned in phone program
  {
    digitalWrite(pinBackward,HIGH);
    digitalWrite(pinLeft,HIGH);
    det = check();
  }
   while (det == 'T' );      //Letter equivalent of backward - right drive button assigned in phone program 
   {
    digitalWrite(pinBackward,HIGH);
    digitalWrite(pinRight,HIGH);
    det = check();
   }

   while (det == 'S' );        //Letter equivalent of Stop function assigned in phone program
   {
    digitalWrite(pinForward,LOW);
    digitalWrite(pinBackward,LOW);
    digitalWrite(pinLeft,LOW);
    digitalWrite(pinRight,LOW);
    det = check();
   }
   
  }

  int check()
  {
    if (Serial.available() > 0)    //control of the Serial port
    {
      dataIn = Serial.read();    //control of the variables which come from the phone
         if (dataIn == 'F')
         {
          determinant == 'F';
         }
         else if (dataIn == 'B')
         {
          determinant = 'B';
         }
         else if (dataIn == 'L')
         {
          determinant == 'L';
         }
         else if (dataIn == 'R')
         {
          determinant == 'R';
         }
         else if (dataIn == 'X')
         {
          determinant == 'X';
         }
         else if (dataIn == 'Y')
         {
          determinant == 'Y';
         }
         else if (dataIn == 'Z')
         {
          determinant == 'Z';
         }
         else if (dataIn == 'T')
         {
          determinant == 'T';
         }
         else if (dataIn == 'S')
         {
          determinant == 'S';
         }
         
    }
    return determinant;
}
