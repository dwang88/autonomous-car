#define echoPin1 11 // attach pin D11 Arduino to pin Echo of HC-SR04
#define echoPin2 13 // attach pin D13 Arduino to pin Echo of HC-SR04
#define trigPin1 10 //attach pin D10 Arduino to pin Trig of HC-SR04
#define trigPin2 12 //attach pin D9 Arduino to pin Trig of HC-SR04


long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
long duration2;
int distance2;

void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin2, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}

int sensor1() {
  digitalWrite(trigPin1, LOW); 
  delay(20);
  digitalWrite(trigPin1, HIGH);
  delay(20);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance = duration * 0.034 / 2; // velocity = distance * time
  return distance;
}


int sensor2() {
  digitalWrite(trigPin2, LOW);
  delay(20);
  digitalWrite(trigPin2, HIGH);
  delay(20);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2; // velocity = distance * time --> distance = velocity/time --> divided by 2 since it has to bounce (travel x2 distance)
  return distance2;
}

void loop(){
  Serial.println(sensor1());
  delay(50);
  Serial.println(sensor2());
  delay(50);
}

