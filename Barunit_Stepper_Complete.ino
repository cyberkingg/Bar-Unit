  // defines pins numbers for horizontal movement
const int stepPin_h = 6; 
const int dirPin_h = 4; 
const int enPin_h = 7;
// defines pins numbers for verticle movement
const int stepPin_v = 5; 
const int dirPin_v = 2; 
const int enPin_v = 8;
const int lmtswitch = 12;
const int led = 13;

void updown();
void left();
void right();
void defaultpositon();
void setup() {
  
  // Sets the two pins as Outputs
  pinMode(stepPin_h,OUTPUT); 
  pinMode(dirPin_h,OUTPUT);
  pinMode(enPin_h,OUTPUT);
  digitalWrite(enPin_h,LOW);
   // Sets the two pins as Outputs
  pinMode(stepPin_v,OUTPUT); 
  pinMode(dirPin_v,OUTPUT);
  pinMode(enPin_v,OUTPUT);
  digitalWrite(enPin_v,LOW);
  pinMode(lmtswitch, INPUT);
  
}
void loop() {
 if(digitalRead(lmtswitch)== LOW && Serial.read() == 'N') 
 { 
  //digitalWrite(led, LOW);
  updown();
  right();
  updown();
  right();
  updown();
  right();
  updown();
 }
 else if(digitalRead(lmtswitch)== HIGH)
 {  
  //digitalWrite(led, HIGH);
  delay(12000) ;
  defaultpositon();
  }
  
}
void updown()
{
  digitalWrite(dirPin_v,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 6400; x++) {
    digitalWrite(stepPin_v,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin_v,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  digitalWrite(dirPin_v,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 6400; x++) {
    digitalWrite(stepPin_v,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin_v,LOW);
    delayMicroseconds(500);
  }
}
void left()
{
  digitalWrite(dirPin_h,HIGH); // Enables the motor to move in horizontal left direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 1600; x++) {    // higher the value in for loop longer the distance
    digitalWrite(stepPin_h,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin_h,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  }
  void right()
  {
     digitalWrite(dirPin_h,LOW); //Changes the rotations direction i.e. horizontal right
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 1600; x++) {
    digitalWrite(stepPin_h,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin_h,LOW);
    delayMicroseconds(500);
  }
  delay(1000);
    }
  void defaultpositon()
  {
    left();
    left();
    left();
    delay(4000);
  }
