#include<ESP8266WebServer.h>
ESP8266WebServer server; 

#define username "Keerthana"
#define password "123456789"

#define pin 13

String html="<html><head><title>ESP8266Webserver</title></head><body style=\"background: yellow\"><h1><center>IoT</center></h1><form>What do you want to do?<br><button type=\"submit\" name=\"state\"value=\"0\">LED ON</button><button type=\"submit\" name=\"state\" value=\"1\">LED OFF</button></form></body></html>";

void setup() {
  
  pinMode(pin,OUTPUT);
  Serial.begin(115200);
  WiFi.softAP(username,password);

  Serial.println(" ");
  IPAddress myIP=WiFi.softAPIP();

  Serial.print("AP IP address: ");
  Serial.println(myIP);

  server.begin();
  server.on("/led",led);

  }

void loop() {
  server.handleClient();
}

void led() {

  server.send(200, "text/html", html);

  if (server.arg("state")=="0") {
    digitalWrite(pin, HIGH);
  }

  else {
    digitalWrite(pin,LOW);
  }

} 
 
