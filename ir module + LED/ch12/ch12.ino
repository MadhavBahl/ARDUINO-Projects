int ledPin = 13;
int irPin = 8;
int val;

void setup() {
  pinMode(A0,INPUT);
  pinMode(irPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
  digitalWrite(irPin,HIGH);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A0);
  //Serial.println(val);
  //delay(50);
  if( val > 100 ) digitalWrite(ledPin,HIGH);
  else digitalWrite(ledPin,LOW);
}
