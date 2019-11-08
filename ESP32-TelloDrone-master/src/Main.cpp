#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <TelloDrone.h>
#include <string.h>


TelloDrone drone;

void sendCommand(string cmd)
{
  Serial.print("Executing command: ");
  Serial.println(cmd.c_str());
  drone.sendCommand(cmd);   
  Serial.println(drone.getResponse().c_str());
  delay (10000);
}

void setup(){
  // Initilize hardware serial:
  Serial.begin(9600);
  drone.connect("tello2", "");
  //drone.connect("TelloEDU-15", "");
}

void loop(){
  //only send data when drone is connected to wifi
  if(drone.connected)
  {
    sendCommand("command");
    sendCommand("battery?");
    sendCommand("takeoff");
    delay(3000);
    sendCommand("mon");
    sendCommand("go 50 50 0 40 m1");
    sendCommand("jump 50 50 0 40 m1 m2");
    sendCommand("go 50 50 0 40 m2");
    sendCommand("land");
    delay(5000);
    sendCommand("takeoff");
    sendCommand("jump 50 50 0 40 m2 m3");
    sendCommand("go 50 50 0 40 m3");
    sendCommand("jump 50 50 0 40 m3 m4");
    sendCommand("go 50 50 0 40 m4");
    sendCommand("land");

  }
  Serial.println("...repeating in 5 sec..."); 
  delay(5000);
}



