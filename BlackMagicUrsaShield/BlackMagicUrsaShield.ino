
//zoomkat 5-24-10
// http://www.arduino.cc/en/Tutorial/TextString for WString.h
#include <String.h>
#include <Ethernet.h>
#include <SD.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //physical mac address
byte ip[] = { 192, 168, 10, 180 }; // ip in lan
byte subnet[] = { 255, 255, 255, 0 }; //subnet mask
EthernetServer server(80); //server port
String readString = String(100); //string for fetching data from address

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
  //enable serial data print 
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
  Serial.print("Starting SD..");
  if(!SD.begin(4)) Serial.println("failed");
  else Serial.println("ok");
  //start Ethernet
  Ethernet.begin(mac, ip, subnet);
  digitalWrite(10,HIGH);
  server.begin();
  

  
  Serial.println("Ready");
}
void loop() {
  // Create a client connection
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();

        //read char by char HTTP request
        if (readString.length() < 100) {

          //store characters to string 
          readString+=(c);
        }

        //if HTTP request has ended
        if (c == '\n') {
          client.println("HTTP/1.1 200 OK"); //send new page
          client.println("Content-Type: text/html");
          ///////////////
          //Serial.println(readString);
          //readString looks like "GET /%22?AF%22 HTTP/1.1"
         // if (readString.equals ("GET /%22?AF%22 HTTP/1.1")) { //test for servo control sring
            //readString.replace('%', '?');
            pos = readString.length(); //capture string length
            //find start of servo command string (?)
            ind1 = readString.indexOf("AF");
            //capture front part of command string
            teststring = readString.substring(ind1,pos);
            //locate the end of the command string
            ind2 = teststring.indexOf("%22");
            //capturing the servo command string from readString
            finalstring = readString.substring(ind1, ind2 + ind1);
            //print "finalstring" to com port;
            if(readString.equals("AF"));{Serial.println("im a fuction");}
            Serial.println(finalstring); //print string with CR
          //}
       /*   if (readString == ("Slidervalue")) {
            ind1 = readString.indexOf('u');
            ind2 = readString.indexOf('&');
            finalstring = readString.substring(ind1 + 1, ind2);
            finalstring.replace('e', '#');
            finalstring.replace('=', 'p');
            Serial.println(finalstring);

          }*/
            //File myFile = SD.open("boom.htm");
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
  }





