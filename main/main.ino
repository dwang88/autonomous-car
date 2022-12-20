#define TRIG_PIN_1 8
#define ECHO_PIN_1 9
#define TRIG_PIN_2 7
#define ECHO_PIN_2 6
#define TRIG_PIN_3 12
#define ECHO_PIN_3 13

const byte PWML = 3;
const byte PWMF = 5;
const byte PWML_B = 10;
const byte PWMF_B = 11;

long duration;
int distance;
long duration2;
int distance2;
long duration3;
int distance3;

void setup() {
  Serial.begin(9600);
 
  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
 
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
 
  pinMode(TRIG_PIN_3, OUTPUT);
  pinMode(ECHO_PIN_3, INPUT);
 
  pinMode(PWML_B, OUTPUT);
  pinMode(PWMF_B, OUTPUT);
}

int get_sensor_reading(int trig_pin, int echo_pin) {
  // Send trigger pulse
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  
  // Measure duration of echo pulse
  long duration = pulseIn(echo_pin, HIGH);
  
  // Calculate distance based on duration
  int distance = duration * 0.034 / 2; 
  return distance;
}

void stop_car() {
  digitalWrite(PWMF, LOW);
  digitalWrite(PWML_B, LOW);
}

void start_car() {
  digitalWrite(PWMF, HIGH);
  digitalWrite(PWML_B, HIGH);
}

void turn_car_right() {
  // Turn car right
  digitalWrite(PWMF, HIGH); 
  digitalWrite(PWML_B, LOW);
}

void turn_car_left() {
  // Turn car left
  digitalWrite(PWMF, LOW); 
  digitalWrite(PWML_B, HIGH);
}

void back_car_up() {
  // Back car up
  digitalWrite(PWML, HIGH);
