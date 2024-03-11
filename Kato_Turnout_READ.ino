//The sensor is connected to pin A0 on an arduino

int sensorValue;
int sensorstatus=0;
int Value;
int Transmit=4;
void setup() {
  Serial.begin(9600);
  pinMode(Transmit,OUTPUT);

}

void loop() {
 for (int i =1; i<=10; i++){
  sensorValue = sensorValue + analogRead(A0);
  delay(100);
 }
 sensorValue = sensorValue/10.0;
 delay(30);

delay(100);
Value=sensorstatus;


if (sensorValue > 100){
 sensorstatus=1;
 digitalWrite(Transmit,LOW);
  }
if (sensorValue < 100){
 sensorstatus=0;
 digitalWrite(Transmit,HIGH);
  }
 if ((Value != sensorstatus) && (sensorstatus==1)){
  Serial.println("Turnout STRAIGHT");
  Value = sensorstatus;
 }
  if ((Value != sensorstatus) && (sensorstatus==0)){
  Serial.println("Turnout DIVERGE");
  Value = sensorstatus;
 }
}
