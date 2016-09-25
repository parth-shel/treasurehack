#include "TinyGPS++.h"
#include "SoftwareSerial.h"

SoftwareSerial serial_connection(10, 11); //RX=pin 10, TX=pin 11
TinyGPSPlus gps;
void setup()
{
  Serial.begin(9600);
  serial_connection.begin(9600);
  Serial.println("Welcome to Treasure Hack!");
  Serial.println("working on it...");
}

void loop()
{
  while(serial_connection.available())
  {
    gps.encode(serial_connection.read());
  }
  if(gps.location.isUpdated())
  {
    /*
    //Get the latest info from the gps object which it derived from the data sent by the GPS unit
    Serial.println("Satellite Count:");
    Serial.println(gps.satellites.value());
    Serial.println("Latitude:");
    Serial.println(gps.location.lat(), 6);
    Serial.println("Longitude:");
    Serial.println(gps.location.lng(), 6);
    Serial.println("Speed MPH:");
    Serial.println(gps.speed.mph());
    Serial.println("Altitude Feet:");
    Serial.println(gps.altitude.feet());
    Serial.println("");
    */

     if(distanceCalc(33.776840,-84.396522, gps.location.lat(), gps.location.lng()) <= 0.00027448) {
      Serial.println("near Klaus Advanced Computing Building, GA Tech.");
      Serial,println("Let's play Treasure Hack!!! ");
      lvl0();

  }
}

double distanceCalc(double y1,double  x1, double y2, double x2)
{
  return(sqrt(sq(y2-y1) + sq(x2-x1)));
}

void lvl0 ()
{
  Serial.println(" This is level 0");
      //test 
      Serial.println(" //insert hint here");
}

