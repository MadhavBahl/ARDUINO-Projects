/*===============================*/
/*===This is my first Program====*/
/*===============================*/

int ledPin=8;

void setup()
{
  //initializing pins as outputs
  pinMode(ledPin,OUTPUT);  
}

void loop()
{
  digitalWrite(ledPin,HIGH);
  delay(1000);
  digitalWrite(ledPin,LOW);
  delay(1000);
}

