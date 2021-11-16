#include <Servo.h> 

const int POS_MIN=550; 
const int POS_MAX=2330; 

const int broche_servo=9;

int S=0;//position

int C=0;//stockage

Servo mon_servo;  

void setup()   {

Serial.begin(115200); 

mon_servo.attach(broche_servo, POS_MIN, POS_MAX);  

pinMode(broche_servo, OUTPUT); //met la broche en sortie

//  position initiale du servomoteur
mon_servo.write(S);
delay(200);
}

void loop(){ 

if (Serial.available()>0) { 

  C=Serial.read(); 
  C=C-48;
  S=map(C,0,9,0,180);
  mon_servo.write(S);

  delay (2000);

}
if(C=='R')
C=POS_MIN;

} 
