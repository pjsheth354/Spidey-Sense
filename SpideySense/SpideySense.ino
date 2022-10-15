#define trigPin1 3 
#define echoPin1 2 
#define trigPin2 4 
#define echoPin2 5 
#define trigPin3 7 
#define echoPin3 8 
#define right_led 9 //d
#define left_led 10//d
#define front_led 11  //d



long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor; 
void setup() { 
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT); 
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT); 
  pinMode(trigPin3, OUTPUT); 
  pinMode(echoPin3, INPUT);
  pinMode(left_led,OUTPUT); //d
  pinMode(right_led,OUTPUT); //d
  pinMode(front_led,OUTPUT); //d
  } 
void loop() {
  SonarSensor(trigPin1, echoPin1);
  RightSensor = distance; 
    if (RightSensor<=10){
      digitalWrite(right_led,HIGH);
      }
  SonarSensor(trigPin2, echoPin2);
  LeftSensor = distance; 
  if (LeftSensor<=10){
      digitalWrite(left_led,HIGH);
      }
  SonarSensor(trigPin3, echoPin3); 
  FrontSensor = distance; 
  if (FrontSensor<=10){
      digitalWrite(front_led,HIGH);
      }
  else{
    digitalWrite(front_led,LOW);
    digitalWrite(left_led,LOW);
    digitalWrite(right_led,LOW);
    }
  Serial.print(LeftSensor);
  Serial.print(" - ");
  Serial.print(FrontSensor); 
  Serial.print(" - "); 
  Serial.println(RightSensor); 
  

    } 
void SonarSensor(int trigPin,int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; 
  
  }
