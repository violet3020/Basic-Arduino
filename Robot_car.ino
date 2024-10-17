/* Program for a two wheel robot car
Author Talent Yolanda Ndlovu Date:17/10/24 With help from UoS Electronics and Electrical Diamond +  */
const int TRIG=6;
const int ECHO=7;
const int Red=2;
const int Blue=4;
const int Green=8;
const int Distance_Threshold=200; //this is the distance at which the LED must light up in cm

float duration_us,distance_cm;// these variables will change

//decalaring the values for the motor
const int forwardPin=13;//this pin must be on to move the motor forward
const int backwardPin=12;
const int forwardPin2=10;
const int backwardPin2=11;
const int delayTime=200;

void setup()
{
Serial.begin(9600);
pinMode(TRIG,OUTPUT);
pinMode(ECHO,INPUT);
pinMode (Red,OUTPUT);
pinMode (Blue,OUTPUT);
pinMode (Green,OUTPUT);
  
pinMode(forwardPin,OUTPUT); 
pinMode(backwardPin,OUTPUT);
  pinMode(forwardPin2,OUTPUT); 
pinMode(backwardPin2,OUTPUT);
  
}
void loop()
{
  //generate 10 microsecond pulse to trig pin
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  //measure duration of pulse from ECHO pin
  duration_us=pulseIn(ECHO,HIGH);
  distance_cm=0.017*duration_us;

  if (distance_cm<Distance_Threshold){
    if (distance_cm<(Distance_Threshold/2)){
    digitalWrite(Red,HIGH);
      digitalWrite(Green,LOW);
    digitalWrite(Blue,LOW);
      //stop
  digitalWrite(forwardPin,LOW);
  digitalWrite(backwardPin,LOW);
  digitalWrite(forwardPin2,LOW);
  digitalWrite(backwardPin2,LOW);
  delay(delayTime);
      //move backwards
  digitalWrite(forwardPin,LOW);
  digitalWrite(backwardPin,HIGH);
  digitalWrite(forwardPin2,LOW);
  digitalWrite(backwardPin2,HIGH);
  delay(delayTime);
      //stop
  digitalWrite(forwardPin,LOW);
  digitalWrite(backwardPin,LOW);
  digitalWrite(forwardPin2,LOW);
  digitalWrite(backwardPin2,LOW);
  delay(delayTime);
    
  //turn     
  digitalWrite(backwardPin,LOW);
  digitalWrite(forwardPin2,HIGH);
  digitalWrite(backwardPin2,LOW);
      delay(delayTime);
      
  }
  else{
    digitalWrite(Blue,HIGH);
    digitalWrite(Red,LOW);
    digitalWrite(Green,LOW);
      digitalWrite(forwardPin2,HIGH);
  digitalWrite(backwardPin2,LOW);
    digitalWrite(forwardPin,HIGH); 
  }
  }
  else {
    digitalWrite(Red,LOW);
    digitalWrite(Blue,LOW);
    digitalWrite(Green,HIGH);
    //move forward
  digitalWrite(forwardPin,HIGH);
  digitalWrite(backwardPin,LOW);
    digitalWrite(forwardPin2,HIGH);
  digitalWrite(backwardPin2,LOW);
  delay(delayTime);
  }
Serial.print("distance: ");
Serial.print(distance_cm);
Serial.println("cm");
delay(500);
}