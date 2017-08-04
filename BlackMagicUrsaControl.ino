#include "Arduino.h"
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
BMD_SDICameraControl_I2C  sdiCameraControl(shieldAddress);


///////////////////////
String Slice = String(50);
String header = String(50);
String slideVal = String(50);
int SliderStart =0;
int SliderEnd =0;
int startS = 0;
int endS = 0;
int lenS = 0;
float SliceVal;
int SliceValInt;

//////////////////////

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, LOW);


//----turn off Ethernet to load SD card----//

  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
//----enable serial data printï¿½----//

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

startS = readString.indexOf("?")+1; //find start of HTTP string "?"

SliderStart = readString.indexOf("&");
header = readString.substring(startS,SliderStart);

endS = readString.indexOf("%");
slideVal = readString.substring(SliderStart+1, endS);
Serial.println(readString);



            


if(header =="MF"){
   
   
   Serial.println(header);
   SliceVal = slideVal.toFloat();
   Serial.println(SliceVal);
   
   Serial.println("Manual Focus");
   MFocus(SliceVal);}
        

 if(header=="FS"){
   
   Serial.println(header);
   
   SliceVal = slideVal.toFloat();
   Serial.println(slideVal);
   Apeture(SliceVal);
   Serial.println("Manual F-stop");
              }

 if(header=="SG"){
   
   Serial.println(header);
   SliceValInt = slideVal.toInt();
    Serial.println(SliceValInt);
   SensorGain(SliceValInt);
   Serial.println("Sensor Gain");
          
 }
 if(header=="MWB"){
   
   Serial.println(header);
   SliceValInt = slideVal.toInt();
   Serial.println(SliceValInt);
   MWhiteBalance(SliceValInt);
   Serial.println("Manual White Balance");
          
 }

 if(header=="EXP"){
   
   Serial.println(header);
   SliceValInt = slideVal.toInt();
   Serial.println(SliceValInt);
   Exposure(SliceValInt);
   Serial.println("Exposure");
          
 }
 
if(header=="AF"){
AutoFocus();
Serial.println(header);
}
if(header=="AAP");{
AutoAppeture();
Serial.println(header);}           

             
             
            

        
          File myFile = SD.open("index.htm");
         
          if (myFile) {
            // read from the file until there's nothing else in it:
            while (myFile.available()) {
              client.write(myFile.read());
             
            }
            // close the file:
            myFile.close();
           ;

          }


          delay(1);
          //stopping client
          client.stop();

          /////////////////////
          //clearing string for next read
          readString = "";
          Slice = "";
          header = "";

        }
      }
    }
  }
}
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
  sdiCameraControl.begin();
  sdiCameraControl.setOverride(true);
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
  sdiCameraControl.begin();
  sdiCameraControl.setOverride(true);
  sdiCameraControl.writeCommandInt8(
      1,         // Destination:    Camera 1
      1,         // Category:       video
      1,         // Param:          White balance
      0,         // Operation:      Assign Value
      sensor );}

void MWhiteBalance(int WB){
  sdiCameraControl.begin();
  sdiCameraControl.setOverride(true);
      sdiCameraControl.writeCommandInt16(
      1,         // Destination:    Camera 1
      1,         // Category:       video
      2,         // Param:          White balance
      0,         // Operation:      Assign Value
      WB );}

void Exposure(int Exposure){
  sdiCameraControl.begin();
  sdiCameraControl.setOverride(true);
      sdiCameraControl.writeCommandInt16(
      1,         // Destination:    Camera 1
      1,         // Category:       Lens
      6,         // Param:          Zoom (Normalised)
      0,         // Operation:      Assign Value
      Exposure );}

void MFocus(float focus){
  sdiCameraControl.begin();
  sdiCameraControl.setOverride(true);
      sdiCameraControl.writeCommandInt16(
      1,         // Destination:    Camera 1
      0,         // Category:       Lens
      0,         // Param:         focus
      0,         // Operation:      Assign Value
      focus );}







