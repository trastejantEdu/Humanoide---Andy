// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#include <Servo.h>

Servo myservo;
Servo codoIzq;
Servo hombroIzq;

int number = 0;
int state = 0;

void setup() {
  pinMode(13,OUTPUT);
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  hombroIzq.attach(7);  // attaches the servo on pin 9 to the servo object
  codoIzq.attach(8);
  Wire.begin(0x08);                // join i2c bus with address #8
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  Serial.begin(9600);           // start serial for output
  myservo.write(90);
}

void loop() {
  delay(100);
}

// callback for sending data
void sendData(){
  Wire.write(number);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
    
  }
  int x = Wire.read();    // receive byte as an integer
  if(0<x<180){
    myservo.write(x);
  }else{
    digitalWrite(13,HIGH);
  }
  Serial.println(x);         // print the integer
  
}

void receiveData(int byteCount){

  while(Wire.available()) {    
    number = Wire.read();
    Serial.print("data received: 2");
    Serial.println(number);
  }
    if (number == 1){
    
      if (state == 0){
        digitalWrite(13, HIGH); // set the LED on
        state = 1;
      }else{
      digitalWrite(13, LOW); // set the LED off
      state = 0;
      }
    }else if((10<number) && (number<160)){
      myservo.write(number);
    }else if((161<number)&&(number<340)){
      int pos = number - 161;
      hombroIzq.write(pos);
    }else if((341<number)&&(number<521)){
      int pos = number - 341;
      codoIzq.write(pos);
    }
  }

