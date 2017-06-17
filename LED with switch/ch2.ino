int switchPin=8;
int ledPin=13;

void setup()
{
  pinMode(switchPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  if(digitalRead(switchPin)==HIGH)
  {
     digitalWrite(ledPin,HIGH);
  }
  else
  {
     digitalWrite(ledPin,LOW);    
  }
}

