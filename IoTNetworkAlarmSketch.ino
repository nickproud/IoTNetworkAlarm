#include <ESP8266WiFi.h>
#include <Pinger.h>

const char* ssid = "your_ssid";
const char* password = "your_password";
const char* hostIP = "ip_of_host_you_are_monitoring";
#define D5 14
int SpeakerPin = 14;
Pinger pinger;
bool success = false;



void connectToWiFi()
{
  Serial.print("\n\nConnecting...");
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.print("Connected to router on IP address: ");
  Serial.println(WiFi.localIP());
}

void Alarm()
{
  digitalWrite(SpeakerPin, HIGH);
  delay(100);
  digitalWrite(SpeakerPin, LOW);
  delay(100);
  digitalWrite(SpeakerPin, HIGH);
  delay(100);
  digitalWrite(SpeakerPin, LOW);
  delay(100);
  digitalWrite(SpeakerPin, HIGH);
  delay(100);
  digitalWrite(SpeakerPin, LOW);
  delay(100);
  digitalWrite(SpeakerPin, HIGH);
  delay(100);
  digitalWrite(SpeakerPin, LOW);
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SpeakerPin, OUTPUT);
  connectToWiFi();
   
  pinger.OnEnd([](const PingerResponse& response)
  {
    if(response.TotalReceivedResponses > 0)
    {
      Serial.print("Host online\n");
      success = true;
      return true;
    }
    else
    {
      Serial.print("ERROR: Unable to reach host. Sounding alarm\n");
      success = false;
      return false;
    }

  });
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("pinging....\n");
  pinger.Ping(hostIP);
  if(!success)
  {
    Alarm();
  }
  delay(5000);
}
