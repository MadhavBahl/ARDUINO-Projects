int buttonPin = 8;

void setup()
{
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
}
void loop()
{
  Serial.print(digitalRead(buttonPin));
  Serial.print("\n");
  delay(1000);
}

