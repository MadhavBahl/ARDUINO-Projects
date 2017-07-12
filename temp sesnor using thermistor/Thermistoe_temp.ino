#include<math.h>

double Thermistor(int RawADC) {
  double Temp;
  Temp = log(10000.0 * ((1024.0/RawADC-1)));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))*Temp );
  Temp = Temp - 273.15;
  Temp = (Temp * 9.0)/5.0 + 32.0;
  return Temp;
}
  
void setup(){
  Serial.begin(9600);
}

void loop(){
  int val;
  double temp;
  val=analogRead(0);
  temp = Thermistor(val);
  temp = temp-32;
  temp = temp*.5556;
  temp=temp+1;
  Serial.print(temp);
  Serial.print("\n");
  delay(1000);
}
<<<<<<< HEAD

=======

>>>>>>> def5ba820730d3a9149c441afc1fb545dcbabb7c
