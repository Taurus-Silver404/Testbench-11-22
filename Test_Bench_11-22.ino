const int touchSensor1 = 4; //connected to Digital pin 
const int touchSensor2 = 5; //connected to Digital pin 
const int stepPin = 6;
const int dirPin = 7; 
const int enablePin = A1;
int customDelay,customDelayMapped; // Defines variables

void setup(){
  Serial.begin(9600); // Communication speed
  pinMode(touchSensor1, INPUT);
  pinMode(touchSensor2, INPUT);
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(enablePin,OUTPUT);
}

void loop(){

customDelayMapped = speedUp(); // Gets custom delay values from the custom speedUp function
  // Makes pules with custom delay, depending on the Potentiometer, from which the speed of the motor depends
  
 if(digitalRead(touchSensor1) == HIGH && digitalRead(touchSensor2) == HIGH)
  {
 digitalWrite(enablePin, HIGH);    // Stop motor if touchSensor 1&2 are HIGH

  }
 else
 {
  digitalWrite(enablePin, LOW);
 }
 
  if(digitalRead(touchSensor1)==HIGH)       //Read Touch sensor signal
   { 
  digitalWrite(dirPin, HIGH);    // Change direction.
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(customDelayMapped);   //Dictates the motor speed
  digitalWrite(stepPin, LOW);
  delayMicroseconds(customDelayMapped);   //Dictates the motor speed
   }
   
  if(digitalRead(touchSensor2)==HIGH)       //Read Touch sensor signal
  {
  digitalWrite(dirPin, LOW);    // Change direction.
  digitalWrite(stepPin, LOW);
  delayMicroseconds(customDelayMapped);   //Dictates the motor speed
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(customDelayMapped);   //Dictates the motor speed
  }
  
}

  // Function for reading the Potentiometer
  int speedUp() {
  int customDelay = analogRead(A0); // Reads the potentiometer
  int newCustom = map(customDelay, 0, 1023, 300,4000); // Converts the read values of the potentiometer from 0 to 1023 into desireded delay values (300 to 4000)
  return newCustom;  

}
