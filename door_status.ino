#include <Blynk.h>



#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "d05103541a4243df99e3985ba7644df9";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Ray Corp";
char pass[] = "madhupatna";
int flag=0;

void notifyOnButtonPress()
{
  int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==1 && flag==0) {
    Serial.println("Someone Opened the door");

    
    //   We allow 1 notification per 15 seconds for now.
    Blynk.notify("Alert : Someone Opened the door");
    flag=1;
  }
  else if (isButtonPressed==0)
  {
    flag=0;
  }
  
 
}

void setup()
{
  // Debug console
  Serial.begin(9600);

Blynk.begin(auth, ssid, pass);
  // Setup notification button on pin D1
  pinMode(D1,INPUT_PULLUP);
 timer.setInterval(16000L,notifyOnButtonPress);
 
}
void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
