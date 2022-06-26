#define trigPin1 8
#define echoPin1 9
#define trigPin2 7
#define echoPin2 6
#define trigPin3 12
#define echoPin3 13
 
const byte pwml = 3;
const byte pwmr = 5;
const byte pwml2 = 10;
const byte pwmr2 = 11;
 
long duration;
int distance;
long duration2;
int distance2;
long duration3;
int distance3;
 
void setup() {
  Serial.begin(9600);
 
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
 
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
 
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
 
  pinMode(pwml2, OUTPUT);
  pinMode(pwmr2, OUTPUT); //FIX! 
}
 
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
 
int sensor3() {
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3 * 0.0343 / 2;
  return distance3;
}
 
void stop_car() {
  digitalWrite(pwmr, LOW);
  digitalWrite(pwml2, LOW);
}
 
void start_car() {
  digitalWrite(pwmr, HIGH);
  digitalWrite(pwml2, HIGH);
}
 
void car_right() {
  //turn right
  digitalWrite(pwmr, HIGH); //fowards motor 1 --> pwml2, backwards motor 1 --> pwmr2, backwards motor 2 --> pwml, forward motor 2 --> pwmr
  digitalWrite(pwml2, LOW);
}
 
void car_left() {
  //turn left
  digitalWrite(pwmr, LOW); //fowards motor 1 --> pwml2, backwards motor 1 --> pwmr2, backwards motor 2 --> pwml, forward motor 2 --> pwmr
  digitalWrite(pwml2, HIGH);
}

void car_back() {
  digitalWrite(pwml, HIGH);
  digitalWrite(pwmr2, HIGH);
}
 
void loop() {
  int s1 = sensor1();
  int s2 = sensor2();
  int s3 = sensor3();
 
  Serial.print("Sensor 1: ");
  Serial.println(sensor1());
  Serial.print("Sensor 2: ");
  Serial.println(sensor2());
  Serial.print("Sensor 3: ");
  Serial.println(sensor3());
  delay(100);

  analogWrite(pwmr, 150);
  analogWrite(pwml2, 150);
 
  while (s1 > 60) {
    if (s1 < 60) {
      digitalWrite(pwml, HIGH);
      digitalWrite(pwmr2, HIGH);
    }
    if (s2 < s3) {
      car_right();
    } 
    else if (s3 < s2) {
      car_left();
    } 
  }

  /* 
  while (s2 < 40 && s1 < 40) {
    car_right();
  } 
 
  while (s3 < 40 && s1 < 40) {
    car_left();
  } */
}
 
