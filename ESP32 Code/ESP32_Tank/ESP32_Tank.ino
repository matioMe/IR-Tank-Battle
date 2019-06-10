#include <WiFi.h>
#include "ESP32Servo.h"

#define MOTEURG   22
#define MOTEURD   21 


#define FREQ 20000
#define PWMCHANNELMD 4
#define PWMCHANNELMG 5
#define RESOLUTION 8

#define ARRET 127


// the number of the LED pin
const char ledPin = 2;  // 16 corresponds to GPIO16
const char enable = 23;
const char TOUR = 19;

// setting PWM properties
const int freq = 500;
const int ledChannel = 3;
const int resolution = 8;
const int minUs = 500;
const int maxUs = 2500;

const char* ssid     = "TankHub";     //name access
const char* password = "lpselpselpse";//passeword

WiFiServer MyServer(80);
WiFiClient MyClient;
Servo Tour;

IPAddress IPServRaspberry(10,3,141,1);   // addresse server de la raspberry PI

void setup(){
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  ledcSetup(PWMCHANNELMD, FREQ, RESOLUTION);
  ledcSetup(PWMCHANNELMG, FREQ, RESOLUTION);

 // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);
  ledcAttachPin(enable, ledChannel);
  ledcAttachPin(MOTEURD, PWMCHANNELMD);
  ledcAttachPin(MOTEURG, PWMCHANNELMG);
  Tour.attach(TOUR, minUs, maxUs);
  
   Serial.begin(115200);
   Serial.println();
   Serial.println();
   Serial.print("Connecting to ");
   Serial.println(ssid);

   ledcWrite(ledChannel, 0);
   WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {   //Wait internet connection
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.println("WiFi connected.");
    Serial.println("My IP Address: ");
    Serial.println(WiFi.localIP());

    MyServer.begin();                    //Start my server
    
    while(!MyClient.connect(IPServRaspberry, 4242)) {}
    Serial.println("connected");
    MyClient.println("GET /STATUS");                             
    Serial.println(MyClient.readStringUntil('\r'));
    if(MyClient.readStringUntil('\r') == "START"){
      ledcWrite(ledChannel, 255);
      Serial.println("DEMARRAGE");
    }
    else{
      ledcWrite(ledChannel, 0);
      Serial.println("ARRET");
    }
    
  ledcWrite(PWMCHANNELMD,ARRET);
  ledcWrite(PWMCHANNELMG,ARRET);
  Tour.write(90);
}
 
void loop(){
  static char TourPos = 90;
  WiFiClient ClientExtern = MyServer.available();   // listen for incoming clients
  
  if (ClientExtern) {                             // if you get a client,
    Serial.println("Client ext connected.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the clien
    while (ClientExtern.connected()) {            // loop while the client's connected
      
    
      if (ClientExtern.available()) {             // if there's bytes to read from the client,
        currentLine = ClientExtern.readStringUntil('\r'); 
        ClientExtern.stop();
        //currentLine.remove(11);         
        Serial.println(currentLine);                    // print it out the serial monitor

        if (currentLine.endsWith("GET /Up HTTP/1.1")) {          
          Serial.println("On avance!!");
         
          ledcWrite(PWMCHANNELMD,(ARRET+127));
          ledcWrite(PWMCHANNELMG,(ARRET+127));
        }
        if (currentLine.endsWith("GET /Rien HTTP/1.1")) {      
          Serial.println("On avance!!");
           
           ledcWrite(PWMCHANNELMD,ARRET);
           ledcWrite(PWMCHANNELMG,ARRET);
        }
        if (currentLine.endsWith("GET /Left HTTP/1.1")) {       
          
           ledcWrite(PWMCHANNELMD,(ARRET+127));
           ledcWrite(PWMCHANNELMG,(ARRET-127));
        }
        if (currentLine.endsWith("GET /Right HTTP/1.1")) {     
          
           ledcWrite(PWMCHANNELMG,(ARRET+127));
           ledcWrite(PWMCHANNELMD,(ARRET-127));
        }
        if (currentLine.endsWith("GET /Down HTTP/1.1")) {        
          
          ledcWrite(PWMCHANNELMG,0);
          ledcWrite(PWMCHANNELMD,0);
        }
        if (currentLine.endsWith("GET /CanonL HTTP/1.1")) {   
          if(TourPos < 180){
              TourPos += 5;
              Tour.write(TourPos);
          }            
        }
        if (currentLine.endsWith("GET /CanonR HTTP/1.1")) {   
          if(TourPos > 5){
              TourPos -= 5;
              Tour.write(TourPos);
          }    
        }
        if (currentLine.endsWith("GET /Shot HTTP/1.1")) {      
          
        }
        if (currentLine.endsWith("GET /START")) {                    
           Serial.println("START recu");
           ledcWrite(ledChannel, 255);
        }
        if (currentLine.endsWith("GET /STOP")) {                     
           Serial.println("STOP recu");
           ledcWrite(ledChannel, 0);          
        } 
      }
    }      
  }
}
