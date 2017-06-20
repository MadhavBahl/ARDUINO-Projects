int ledPin[9] = { 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 };
int count1=0;
int count2=1;
void setup() {
  int i;
  for(i=0;i<9;i++)
  {
    pinMode(ledPin[i],OUTPUT);
  }

}

void loop() {
  count1++;
  count2++;
  int i;
  int j;
  for(i=0;i<9;i++)
  {
    digitalWrite(ledPin[i],HIGH);
    delay(90);
    digitalWrite(ledPin[i],LOW);
  }
  for(i=8;i>=0;i--)
  {
    digitalWrite(ledPin[i],HIGH);
    delay(90);
    digitalWrite(ledPin[i],LOW);
  }
  if(count1%2==0)
  {
    for(i=0;i<9;i+=2)
    {
      digitalWrite(ledPin[i],HIGH);
      for(j=i+1;j<9;j++)
      {
        digitalWrite(ledPin[j],HIGH);
        delay(100);
        digitalWrite(ledPin[j],LOW);
      }
      digitalWrite(ledPin[i],LOW);
    }
      for(i=8;i>=0;i-=2)
      {
        digitalWrite(ledPin[i],HIGH);
        for(j=i-1;j>=0;j--)
        {
         digitalWrite(ledPin[j],HIGH);
         delay(100);
         digitalWrite(ledPin[j],LOW);
        }
        digitalWrite(ledPin[i],LOW);
      }
  }
  int k;
  if(count2%3==0)
  {
    for(i=0,j=8;i<5;i++,j--)
    {
      for(k=0;k<4;k++)
      {
        digitalWrite(ledPin[i],HIGH);
        digitalWrite(ledPin[j],HIGH);
        delay(100);
        digitalWrite(ledPin[i],LOW);
        digitalWrite(ledPin[j],LOW);
        delay(100);
      }
      digitalWrite(ledPin[i],HIGH);
      digitalWrite(ledPin[j],HIGH);
    }
    for(i=0;i<9;i++)
    {
      delay(100);
      digitalWrite(ledPin[i],LOW);
    }
  }
}

