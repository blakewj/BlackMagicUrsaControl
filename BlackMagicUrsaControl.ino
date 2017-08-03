//#include "Arduino.h"
#include <BMDSDIControl.h>
#include <String.h>
#include <Ethernet.h>
#include <SD.h>
const int shieldAddress = 0x6E;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //physical mac address
byte ip[] = { 192, 168, 10, 180 }; // ip
byte subnet[] = { 255, 255, 255, 0 }; //subnet mask
EthernetServer server(80); //server port
String readString = String(100); //string for fetching data from address
//BMD_SDICameraControl_I2C  sdiCameraControl(shieldAddress);
File webFile;

///////////////////////
String teststring = String(100);
String finalstring = String(100);
String flag = String(2);
int ind1 = 0;
int ind2 = 0;
int pos = 0;
//////////////////////

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, LOW);


//----turn off Ethernet to load SD card----//

  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
//----enable serial data print�----//

  Serial.begin(9600); 
//---- Starting SD Card Int----//
  
  Serial.print("Starting SD..");
  if(!SD.begin(4)) Serial.println("failed");
  else Serial.println("ok");


//-----Start Ethernet Connection-------//
  Ethernet.begin(mac, ip, subnet);
  digitalWrite(10,HIGH);
  server.begin();
  Serial.println("Ready");
//--------------------------------//

//---- Turn on control overrides----//


}
void loop() {



//---- Create a client connection
EthernetClient client = server.available();
if (client) {
	while (client.connected()) {
		if (client.available()) {
			char c = client.read();
			//----read char by char HTTP request----//
			if (readString.length() < 100) {
				//----store characters to string----//
				readString+=(c);}

//----if HTTP request has ended----//
if (c == '\n') {
	client.println("HTTP/1.1 200 OK"); //send new page
	client.println("Content-Type: text/html");

  Serial.println(readString);
 // if (readString.equals ("GET /%22?AF%22 HTTP/1.1")) { //test for servo control sring
	pos = readString.length(); 								//capture string length
	ind1 = readString.indexOf("#");						//find start of HTTP string "AF"
	teststring = readString.substring(ind1,pos);			//capture front part of command string
	ind2 = teststring.indexOf("%");						//Find The End Of The HTTP String
	finalstring = readString.substring(ind1, ind2 + ind1);	//capturing the servo command string from readString
	
            if(finalstring=="AF"){
            	Serial.println("im a fuction");
            	//AutoFocus();
            	Serial.println(finalstring);}
             if(finalstring=="AWB"){
             Serial.println("im a fuction");
              //AutoAppeture();
              Serial.println(finalstring);}

        
          File myFile = SD.open("index.htm");
          if (myFile) {
            // read from the file until there's nothing else in it:
            while (myFile.available()) {
              client.write(myFile.read());
            }
            // close the file:
            myFile.close();

          }





          ///////////////////
          //now output HTML data header
         // client.println("HTTP/1.1 204 Zoomkat");
          //client.println();
          //client.println();
          delay(1);
          //stopping client
          client.stop();

          /////////////////////
          //clearing string for next read
          readString = "";
          teststring = "";
          finalstring = "";

        }
      }
    }
  }
  }/*
 void AutoAppeture() {
  // This sends an Auto Iris adjustment command, with a simple camera control packet.
  sdiCameraControl.begin();
  sdiCameraControl.setOverride(true);
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
    sdiCameraControl.begin();
    sdiCameraControl.setOverride(true);
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


*/



