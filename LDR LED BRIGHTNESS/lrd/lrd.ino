int sensorPin = 0;
int ledPin = 11;

void setup() {
  analogReference(DEFAULT);
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  Serial.println(analogRead(sensorPin));
  delay(500);
  if(analogRead(sensorPin) < 500)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
}
