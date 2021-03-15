#include <WebServer.h>
#include <WiFi.h>
#include <WiFiUdp.h>

// the IP of the machine to which you send msgs
// this should be the correct IP in most cases (see note in python code)
#define CONSOLE_IP "192.168.1.2"
#define CONSOLE_PORT 4210

const char* ssid = "ESP32";
const char* password = "12345678";

const int button1pin = 12;
const int button2pin = 14;

WiFiUDP Udp;
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
WebServer server(80);

void setup()
{
  Serial.begin(115200);

  pinMode(button1pin, INPUT);
  pinMode(button2pin, INPUT);
  
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  server.begin();

}

void loop()
{
  int total = 0;
  int button1read = digitalRead(button1pin);
  if (button1read > 0) {
    total++;
  }
  int button2read = digitalRead(button2pin);
  if (button2read > 0) {
    total++;
  }
  
  Udp.beginPacket(CONSOLE_IP, CONSOLE_PORT);
  // Just test touch pin - Touch0 is T0 which is on GPIO 4.
  Udp.printf(String(total).c_str());
  Udp.endPacket();
  delay(1000);
}
