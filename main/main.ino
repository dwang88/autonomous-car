#define trigPin1 3 
#define echoPin1 4 
#define trigPin2 12
#define echoPin2 13

const byte pwml = 5;
const byte pwmr = 6;
const byte pwml2 = 10;
const byte pwmr2 = 9;
long duration;
int distance;
long duration2;
int distance2;
 
void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  Serial.begin(9600);
 
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  //pinMode(pwml, OUTPUT);
  //pinMode(pwmr, OUTPUT);

  pinMode(pwml2, OUTPUT);
  pinMode(pwmr2, OUTPUT);
}

/*
  int sensor1() {
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance = duration * 0.034 / 2; 
  return distance;
}
*/

int sensor2() {
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.0343 / 2;
  return distance2;
}
 
void loop(){
  //Serial.println(sensor1());
  //delay(50);
  //Serial.println(sensor2());
  //delay(50);

  //analogWrite(pwmr2, 150);
  analogWrite(pwml, 150);

  //analogWrite(pwmr, 50);
  
  /* int s1 = sensor1();
  int s2 = sensor2();

  if(s1 < 50) {
    String myString1 = String(s1);
    Serial.println("Stop!" + myString1);
    delay(50);
    // analogWrite(pwml, 0);
  }

  /*while(s2 < 50) {
    String myString2 = String(s2);
    Serial.println("Stop. Object's distance from car: " + myString2 + "cm");
    analogWrite(pwml, 0);
    //analogWrite(pwmr, 0);
  }

  while(s1 < 50) {
    String myString1 = String(s1);
    Serial.println("Stop. Object's distance from car: " + myString1 + "cm");
    analogWrite(pwml, 0);
    //analogWrite(pwmr, 0);
  }
  delay(10);
  
  /*for (int i = 0; i > 255; i++){
    analogWrite(pwml, i);
    delay(10);
  }
  delay(500);
  for (int i = 0; i > 255; i++){
    analogWrite(pwmr, i);
    delay(10);
  }
  delay(500);*/
  
}

