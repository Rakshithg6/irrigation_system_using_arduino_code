//Arduino code for soil moisture sensor along with the water-pump
int sensor_pin=A0;
int output_value;
int limit=500; //Threshold value
int led=8;
int water_pump=9;
void setup () 
{
Serial.begin(9600); //To observe output in serial monitor.
pinMode (9, OUTPUT);
pinMode (8, OUTPUT);
Serial.println("reading from the sensor...");
delay (2000);
}
void loop () 
{
output_value=analogRead(sensor_pin); //It reads the moisture content from the soil.
Serial.print("Moisture");
Serial.print(output_value);
Serial.print("%");
if(output_value>limit)
{
digitalWrite(9, HIGH); //Water pump turns on.
digitalWrite(8,HIGH); //Led turns on indicating that moisture is low.
}
else
{
digitalWrite(9,LOW);
digitalWrite(8,LOW);
}
delay (1000);
}
