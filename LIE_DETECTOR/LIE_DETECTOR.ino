int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int buzzerPin = 7;
int potPin = 1;
int sensorPin = 0;
long red = 0xFF0000;
long green = 0x00FF00;
long blue = 0x000080;
int band = 10;
// adjust for sensitivity
void setup()
{
  Serial.begin(9600);
  pinMode(potPin, INPUT);   //This is to set the input resistance that comes from potentiometer A1
  pinMode(sensorPin, INPUT);  //This is to set the input resistance from the skin
  pinMode(redPin, OUTPUT);  //This is to set the output for RED Led
  pinMode(greenPin, OUTPUT);  //This is to set the output for green Led 
  pinMode(bluePin, OUTPUT); //This is to set the output for blue(or transparent) Led
  pinMode(buzzerPin, OUTPUT); //This is to set the output for buzzer

}
void loop()       //This loops highlights the basic working of the detector
{
  int gsr = analogRead(sensorPin);
  int pot = analogRead(potPin);
  if (gsr > pot + band)   //This condition if true indicates the lie
  {
    setColor(red);
    beep();
  }
  else if (gsr < pot - band)  //This condition if true indicates the need of adjusting the resistance
  {
    setColor(blue);
  }
  else        //This condition becomes  true for other condition becomes false and is at normal resistance
  {
    setColor(green);
  }
}
void setColor(long rgb)     //This functions sets the colour
{
  int red = rgb >> 16;
  int green = (rgb >> 8) & 0xFF;
  int blue = rgb & 0xFF;
  analogWrite(redPin, 255 - red);
  analogWrite(greenPin, 255 - green);
  analogWrite(bluePin, 255 - blue);
}
void beep()       //This function is to beep the buzzer
{
  // 5 Khz for 1/5th second
  for (int i = 0; i < 1000; i++)
  {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(500);
  }
}
