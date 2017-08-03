//#include "Arduino.h"
#include <BMDSDIControl.h>
#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>


File webFile;
const int shieldAddress = 0x6E;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 10, 20); 
EthernetServer server(80);
BMD_SDICameraControl_I2C  sdiCameraControl(shieldAddress);

void setup() {

    // disable Ethernet chip
    pinMode(10, OUTPUT);
    digitalWrite(10, HIGH);
    
    server.begin();           // start to listen for clients
    
    sdiCameraControl.begin();
  
    // Turn on control overrides
    sdiCameraControl.setOverride(true);
    Serial.begin(9600);       // for debugging
    
    // initialize SD card
    Serial.println("Initializing SD card...");
    if (!SD.begin(4)) {
        Serial.println("ERROR - SD card initialization failed!");
        return;    // init failed
    }
    Serial.println("SUCCESS - SD card initialized.");
    // check for index.htm file
    if (!SD.exists("index.htm")) {
        Serial.println("ERROR - Can't find index.htm file!");
        return;  // can't find index file
    }
    Serial.println("SUCCESS - Found index.htm file.");
    Ethernet.begin(mac, ip);  // initialize Ethernet device

 // SensorGain(8); // int8 1-16
 // AutoAppeture();// button trigger
 // Apeture(2.0)//-1.0  --  16.0
  //AutoFocus(); //button trigger
  //MWhiteBalance(5600); // int16 3200-7500
  Exposure(9);// int 16 0-n
}
void loop() {
   EthernetClient client = server.available();  // try to get client

    if (client) {  // got client?
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // client data available to read
                char c = client.read(); // read 1 byte (character) from client
                // last line of client request is blank and ends with \n
                // respond to client only after last line received
                if (c == '\n' && currentLineIsBlank) {
                    // send a standard http response header
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");
                    client.println();
                    // send web page
                    webFile = SD.open("index.htm");        // open web page file
                    if (webFile) {
                        while(webFile.available()) {
                            client.write(webFile.read()); // send web page to client
                        }
                        webFile.close();
                    }
                    break;
                }
                // every line of text received from the client ends with \r\n
                if (c == '\n') {
                    // last character on line of received text
                    // starting new line with next character read
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    // a text character was received from client
                    currentLineIsBlank = false;
                }
            } // end if (client.available())
        } // end while (client.connected())
        delay(1);      // give the web browser time to receive the data
        client.stop(); // close the connection
    } // end if (client)
}
void AutoAppeture() {
  // This sends an Auto Iris adjustment command, with a simple camera control packet.

  sdiCameraControl.writeCommandVoid(
      1,   // Destination:    Camera 1
      0,   // Category:       Lens
      5    // Param:          Auto Iris
    );
}

void Apeture(float scaledZoom){
      sdiCameraControl.writeCommandFixed16(
      1,         // Destination:    Camera 1
      0,         // Category:       Lens
      2,         // Param:          apeture fstop
      0,         // Operation:      Assign Value
      scaledZoom );
      }
  

void AutoFocus(){
  sdiCameraControl.writeCommandVoid(
      1,   // Destination:    Camera 1
      0,   // Category:       lens
      1    // Param:          Auto focus
    );}


void SensorGain(int sensor){
  sdiCameraControl.writeCommandInt8(
      1,         // Destination:    Camera 1
      1,         // Category:       video
      1,         // Param:          White balance
      0,         // Operation:      Assign Value
      sensor );}

void MWhiteBalance(int WB){
      sdiCameraControl.writeCommandInt16(
      1,         // Destination:    Camera 1
      1,         // Category:       video
      2,         // Param:          White balance
      0,         // Operation:      Assign Value
      WB );}

void Exposure(int Exposure){
      sdiCameraControl.writeCommandInt16(
      1,         // Destination:    Camera 1
      1,         // Category:       Lens
      6,         // Param:          Zoom (Normalised)
      0,         // Operation:      Assign Value
      Exposure );}


