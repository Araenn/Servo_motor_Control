#include <Servo.h> 

const int POS_MIN = 550; 
const int POS_MAX = 2330; 

const int broche_servo = 9;

int S = 0; //location

int C = 0; //storage

Servo my_servo;  

void setup() {

  Serial.begin(115200); 

  my_servo.attach(pin_servo, POS_MIN, POS_MAX);  

  pinMode(pin_servo, OUTPUT); //put the pin to exit

  //  initial location of servomotor
  my_servo.write(S);
  delay(200);
}

void loop() { 

  if (Serial.available() > 0) { 

    C = Serial.read(); 
    C = C - 48;
    S = map(C, 0, 9, 0, 180);
    my_servo.write(S);

    delay (2000);

  }
  if (C == 'R')
    C = POS_MIN;
} 
