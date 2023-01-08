#define trig 13 //Pin Ultrasonic sensor
#define echo 12

#define uv 8 //Pin หลอดไฟUV

#define in1 2 //Pin motor A (move forwards)
#define in2 4 //Pin motor A (move backwards)
#define enA 3 //Pin motor A (speed control)

#define in3 5 //Pin motor B (move forwards)
#define in4 7 //Pin motor B (move backwards)
#define enB 6 //Pin motor B (speed control)

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
  digitalWrite(trig,LOW); //เคลียร์ค่าขา trig
  delayMicroseconds(2);

  digitalWrite(trig,HIGH); //ขา trig ส่งคลื่นเสียงออกไป 10 ไมโครวินาที
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH); //ขา echo จับเวลาที่คลื่นเสียงเดินทางมากระทบ
  distance = (duration*0.034)/2; //คำนวณระยะทาง

  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(distance < 3)
  {
    digitalWrite(in1,HIGH); //หุ่นยนต์เดินหน้าเป็นเวลา 10 วินาที
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(enA,100);
    digitalWrite(enB,100);
    delay(10000);

    digitalWrite(in1,LOW); //หุ่นยนต์หยุดเคลื่อนที่
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(enA,0);
    digitalWrite(enB,0);

    digitalWrite(uv,HIGH); //หลอดไฟUVเปิดเป็นเวลา 30 วินาที
    delay(30000);
    digitalWrite(uv,LOW);
    delay(1000);
  }
  else {
    digitalWrite(in1,LOW); //หุ่นยนต์ไม่ทำงาน
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(enA,0);
    digitalWrite(enB,0);

    digitalWrite(uv,LOW);
    delay(1000);
  }
}
