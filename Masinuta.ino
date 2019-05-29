
#define enA  10
#define in1  9
#define in2  8
#define enB  13
#define in4  12
#define in3  11

const int trigPinLeft = 4;
const int echoPinLeft = 5;

const int trigPinRight = 7;
const int echoPinRight = 6;

const int ledPinLeft = 2;
const int ledPinRight = 3;

const bool semnalLeft = true;
const bool semnalRight = true;

long durationRight;
int distanceRight;

long durationLeft;
int distanceLeft;

int motorSpeedA = 150;
int motorSpeedB = 150;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(trigPinLeft,OUTPUT);
  pinMode(echoPinLeft,INPUT);
  Serial.begin(9600);
  
  pinMode(trigPinRight,OUTPUT);
  pinMode(echoPinRight,INPUT);

  pinMode(ledPinLeft,OUTPUT);
  pinMode(ledPinRight,OUTPUT);
  
}

void loop() {

    digitalWrite(trigPinLeft,LOW);
    delayMicroseconds(4);

    digitalWrite(trigPinLeft,HIGH);
    delayMicroseconds(4);

    digitalWrite(trigPinLeft, LOW);
    durationLeft = pulseIn(echoPinLeft, HIGH);
    distanceLeft = durationLeft*0.034/2;

    digitalWrite(trigPinRight,LOW);
    delayMicroseconds(4);

    digitalWrite(trigPinRight,HIGH);
    delayMicroseconds(4);

    digitalWrite(trigPinRight, LOW);
    durationRight = pulseIn(echoPinRight, HIGH);
    distanceRight = durationRight*0.034/2;
  
  if(distanceLeft < 30){
  
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);

     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
  

  /* if(semnalLeft == false)
     {
            digitalWrite(ledPinLeft,LOW);
             delay(50);
        }
       else
      {
             digitalWrite(ledPinLeft,HIGH);
             delay(50);
          } */
    
     motorSpeedA = 150;
     motorSpeedB = 80;

     analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
     analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
  }
  
 else if(distanceRight < 30){
  
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
   digitalWrite(ledPinRight,HIGH);
  
    /*   if(semnalRight == true)
      {
            digitalWrite(ledPinRight,LOW);
              delay(50);
     
            }
       else
      {
              digitalWrite(ledPinRight,HIGH);
     
        }
      */
   
      motorSpeedA = 80;
      motorSpeedB = 150;
  
      analogWrite(enA, motorSpeedA);
      analogWrite(enB, motorSpeedB);
  }

  else{
    
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    
      motorSpeedA = 150;
      motorSpeedB = 150;
    
      digitalWrite(ledPinLeft,LOW);
      digitalWrite(ledPinRight,LOW);
   
      analogWrite(enA, motorSpeedA);
      analogWrite(enB, motorSpeedB);
    }
    
  Serial.print("Distance: ");
  Serial.println(distanceLeft,distanceRight);
}
