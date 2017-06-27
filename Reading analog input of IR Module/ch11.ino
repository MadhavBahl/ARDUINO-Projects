int sensePin = 0;
int powerPin = 12;

void setup() {
  analogReference(DEFAULT);
  pinMode(powerPin,OUTPUT);
  Serial.begin(9600);
  digitalWrite(powerPin,HIGH);
}

void loop() {
  int val;
  val = analogRead(sensePin);
  Serial.write(val);
  Serial.write("\n");
  delay(500);
}
