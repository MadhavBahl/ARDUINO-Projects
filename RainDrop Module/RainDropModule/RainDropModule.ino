int inputRead;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  inputRead = analogRead(A0);

  Serial.println(inputRead);
  delay(500);
}
