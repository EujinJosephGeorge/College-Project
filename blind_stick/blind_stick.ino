#define echo1 2
#define trig1 4
#define echo2 5
#define trig2 7
#define buzzer 11
int duration1, distance1, duration2, distance2;
void setup() {
pinMode(trig1, OUTPUT);
pinMode(echo1, INPUT);
pinMode(trig2, OUTPUT);
pinMode(echo2, INPUT);
Serial.begin(9600);
pinMode(buzzer, OUTPUT);
}

void loop() {
//sensor1
digitalWrite(trig1,LOW);
delayMicroseconds(2);
digitalWrite(trig1, HIGH);
delayMicroseconds(100);
duration1=pulseIn(echo1,HIGH);
//Sensor2
digitalWrite(trig2,LOW);
delayMicroseconds(2);
digitalWrite(trig2, HIGH);
delayMicroseconds(100);
duration2=pulseIn(echo2,HIGH);

if(distance1<120||distance2<60){
digitalWrite(buzzer,HIGH);
delay(500);
digitalWrite(buzzer, LOW);
delay(500);
distance1=(duration1/2)/29.1;
Serial.println("Short range = ");
Serial.println(distance1);
if(distance2<=60){
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(500);
  distance2=(duration2/2)/29.1;
Serial.println("Long range = ");
Serial.println(distance2);
  }
}
else{
  digitalWrite(buzzer, LOW);
  }
}

