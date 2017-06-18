int switchPin=8;
int ledPin=11;
boolean lastButton=LOW;
int ledLevel = 0;
boolean currentButton = LOW;

void setup()
{
  pinMode(switchPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  if(last!=current)
  {
    delay(5);
    current=digitalRead(switchPin);
  }
  return current;
}

void loop()
{
  currentButton = debounce(lastButton);
  if(lastButton==LOW && currentButton==HIGH)
  {
     ledLevel = ledLevel + 40;
  }
 lastButton = currentButton;  
 if(ledLevel > 255) ledLevel = 0;
 analogWrite(ledPin,ledLevel);
}

