#include<SoftwareSerial.h>

#define START_CMD_CHAR '>'          //Indicate Start Of A Sensor Reading Set 
#define END_CMD_CHAR '\n'           //Indicate End Of A Sensor Reading Set
#define DIV_CMD_CHAR ','
//Sensor Reading Set Is In The Form : " >(Sensor Type),(Reading Count),(First Dimension Value),(Second Dimension Value),(Third Dimension Value) "


#define motor1pin1 13
#define motor1pin2 12
#define motor2pin1 10
#define motor2pin2 11

void stopr()
{
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,LOW); 
}

void stopl()
{
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,LOW);
}
void forwardr()
{
  digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor1pin2,LOW);  
}

void forwardl()
{
  digitalWrite(motor2pin1,HIGH);
  digitalWrite(motor2pin2,LOW);
}


void backwardr()
{
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,HIGH);
}

void backwardl()
{
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin1,HIGH);
}

SoftwareSerial BT(9,8);

float value0, value1, value2;


void setup() {
  //pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
  Serial.flush();
  BT.flush();
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
}

void loop()
{
  BT.flush();                          
  int sensorType = 0; 
  char getChar = ' ';  //read serial
  // wait for incoming data
  if (BT.available() < 1) 
  {
    return; // If Serial Is Empty, Return To loop().
  }
  getChar = BT.read();
  if (getChar != START_CMD_CHAR)
  {
    return; // If No Command Start Flag, Return To loop().
  }
  // Parse Incoming Data
  // Syntax Of Incoming Data : [  >(Sensor Type - Integer),(Count - Integer),(Value 0 - Float),(Value 1 - Float),(Value 2 - Float)\n   ]  
  //start:
  sensorType = BT.parseInt(); // Read Sensor Type
  BT.parseInt();  // Read Total Logged Sensor Readings
  value0 = BT.parseFloat();  // 1st Value Of Sensor
   value1 = BT.parseFloat();  // 2nd Value Of Sensor
   value2 = BT.parseFloat();

  if (sensorType==3)
  {    // 3rd Value Of Sensor
     if(value0<=180)
     if(value1>0)
     {
        forwardl();
        forwardr();
     }
     else
     {
        backwardl();
        backwardr();
     }
     else
     if(value2<0)
     {  forwardl();
        stopr();
     }
     else
     {
        forwardr();
        stopl();
     }
  }
 
  //goto start;
}
