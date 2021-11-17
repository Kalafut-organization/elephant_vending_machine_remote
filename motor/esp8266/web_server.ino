#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid     = "Elephant-Vending-Machine";
const char* password = "password"; //before uploading to the Wifi Shield, change this to the router's password

ESP8266WebServer server(80);

MDNSResponder mdns;
  
String strResponse;

// Set static IP
IPAddress local_IP(192, 168, 0, 14);
// Set gateway
IPAddress gateway(192, 168, 0, 1);

IPAddress subnet(255, 255, 0, 0);
  
  
void setup(void){
  
Serial.begin(115200);
while (!Serial) {
 ; // wait for serial port to connect. Needed for native USB port only
}

if (!WiFi.config(local_IP, gateway, subnet)) {
 Serial.println("STA Failed to configure");
}

WiFi.begin(ssid, password);
Serial.println("");
  
while (WiFi.status() != WL_CONNECTED) {
 delay(1000);
 Serial.print(".");
}
Serial.println("");
Serial.print("Connected to ");
Serial.println(ssid);
Serial.print("IP address: ");
Serial.println(WiFi.localIP());
Serial.println(WiFi.macAddress());

if (mdns.begin("esp8266", WiFi.localIP())) {
 Serial.println("MDNS responder started");
}
  
server.on("/", [](){
 server.send(200, "text/plain", "connected");
});

server.on("/motor", handlePost);

// Start WiFi server
server.begin();
Serial.println("HTTP server started");
}

void loop(void){
 server.handleClient();
}

void handlePost() {
  if (server.hasArg("plain") == false) {
    server.send(200, "text/plain", "No body in request");
    return;
  }
  String sig = server.arg("plain");
  
  // Send signal over serial
  Serial.println(sig);

  while (!Serial.available()){
    ; //wait until arduino prints to serial
  }
  // Get response from arduino
  strResponse = Serial.readString();

  //Send response to client
  server.send(200, "text/plain", strResponse);
}
