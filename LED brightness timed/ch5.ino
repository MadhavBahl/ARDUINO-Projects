int ledPin = 11;
int ledLevel = 0;
void setup() {
  pinMode(ledPin,OUTPUT);

}

void loop() {
  if( ledLevel>250 ) ledLevel=0;
  analogWrite(ledPin,ledLevel);
  ledLevel = ledLevel + 51;
  delay(500);

}
