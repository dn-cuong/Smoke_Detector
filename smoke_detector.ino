int sensorValue_1,sensorValue_2;
const int led_1 = 8, led_2 = 11, buzz_1 = 5, buzz_2 = 7;

void setup(){
Serial.begin(9600);    
pinMode(led_1,OUTPUT);
pinMode(led_2,OUTPUT);
pinMode(buzz_1,OUTPUT);
pinMode(buzz_2,OUTPUT);
}              


void loop(){
sensorValue_1 = analogRead(1);     
sensorValue_2 = analogRead(3); 

if (sensorValue_1 > 150){
  digitalWrite(led_1, HIGH);
  digitalWrite(buzz_1,HIGH);
}
else {
  digitalWrite(led_1,LOW);   
}
if (sensorValue_2 > 150){
  digitalWrite(led_2, HIGH);
  digitalWrite(buzz_1,HIGH);
}
else {
  digitalWrite(led_2,LOW); 
}

if ((sensorValue_1 < 150) && (sensorValue_2 < 150)){
  digitalWrite(buzz_1,LOW);
}

Serial.println(String(sensorValue_1) + "," + String(sensorValue_2) + "," + String((sensorValue_1 + sensorValue_2)/2));
delay(200);
}                          
