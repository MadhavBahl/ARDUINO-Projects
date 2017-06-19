int ledPin[5] = { 13 , 12 ,11 , 10 , 9 };
int count = 0;
void setup() {
  int i;
  for(i=0;i<5;i++)
  {
    pinMode(ledPin[i],OUTPUT);
  }
}

void loop() {
  int i;
  for(i=0;i<5;i++)
  {
    digitalWrite(ledPin[i],HIGH);
    delay(250);
    digitalWrite(ledPin[i],LOW);
  }
  for(i=3;i>0;i--)
  {
    digitalWrite(ledPin[i],HIGH);
    delay(250);
    digitalWrite(ledPin[i],LOW);
  }
  count++;
  if(count%2 == 0)
  {
    for(i=0;i<6;i++)
    {
      digitalWrite(ledPin[1],HIGH);
      delay(150);
      digitalWrite(ledPin[1],LOW);
      digitalWrite(ledPin[3],HIGH);
      delay(150);
      digitalWrite(ledPin[3],LOW);
    }
  }
}
