int sensePin = 0;
int irLed = 8;
int ledPin = 13;

void setup() {
  analogReference(DEFAULT);
  Serial.begin(9600);
  pinMode(irLed,OUTPUT);
  pinMode(ledPin,OUTPUT);
  digitalWrite(irLed,HIGH);
  digitalWrite(ledPin,LOW);
  //pinMode(sensePin,INPUT);
}

void loop() {
  int val;
  digitalWrite(ledPin,HIGH);
  val=analogRead(sensePin);
  Serial.println("LED ON");     
  Serial.println(val);          
  delay(1000);
  digitalWrite(irLed,LOW);
  val=analogRead(sensePin);    
  Serial.println("LED OFF");
  Serial.println(val);          
  delay(1000);
  
}
