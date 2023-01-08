#define trig 13
#define echo 12

#define uv 8

#define in1 2
#define in2 4
#define enA 3

#define in3 5
#define in4 7
#define enB 6

long duration;
int distance;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(uv,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enB,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);
  distance = (duration*0.034)/2;

  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(distance < 3)
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(enA,100);
    digitalWrite(enB,100);
    delay(10000);

    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(enA,0);
    digitalWrite(enB,0);

    digitalWrite(uv,HIGH);
    delay(30000);
    digitalWrite(uv,LOW);
    delay(1000);
  }
  else {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(enA,0);
    digitalWrite(enB,0);

    digitalWrite(uv,LOW);
    delay(1000);
  }
}
