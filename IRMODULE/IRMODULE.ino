

void setup() {
  pinMode(A1,INPUT);
  pinMode(A2,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(A2,HIGH);
  digitalWrite(A0,LOW);
  Serial.begin(9600);

}

void loop() {
  Serial.println(analogRead(A0));
  delay(500);
  if(analogRead(A0)>63){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }

}
