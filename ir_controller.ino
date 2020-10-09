#define BLYNK_PRINT Serial
#define IR_OFF    0xF740BF  // 
#define IR_ON     0xF7C03F  // 
#define IR_R      0xF720DF  // 
#define IR_G      0xF7A05F  // 
#define IR_B      0xF7609F  // 
#define IR_STROBE 0xF7F00F  // 
#define IR_W      0xF7E01F  // 
#define IR_P      0xF750AF  // 

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <IRremote.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "AUTH CODE";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SSIS";
char pass[] = "PASSWORD";

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(4, 2); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 19200

ESP8266 wifi(&EspSerial);
IRsend irsend;

void setup()
{
  // Debug console
  Serial.begin(9600);
  delay(10);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
}

BLYNK_WRITE(V1){
  if (param.asInt() == 1){
    irsend.sendNEC(IR_ON, 32);
  }
}

BLYNK_WRITE(V2){
  if (param.asInt() == 1){
    irsend.sendNEC(IR_OFF, 32);
  }
}

BLYNK_WRITE(V3){
  if (param.asInt() == 1){
    irsend.sendNEC(IR_R, 32);
  }
}

BLYNK_WRITE(V4){
  if (param.asInt() == 1){
    irsend.sendNEC(IR_G, 32);
  }
}

BLYNK_WRITE(V5){
  if (param.asInt() == 1){
    irsend.sendNEC(IR_B, 32);
  }
}

BLYNK_WRITE(V6){
  if (param.asInt() == 1){
    irsend.sendNEC(IR_STROBE, 32);
  }
}

BLYNK_WRITE(V7){
  if (param.asInt() == 1){
    irsend.sendNEC(IR_W, 32);
  }
}

BLYNK_WRITE(V8){
  if (param.asInt() == 1){
    irsend.sendNEC(IR_P, 32);
  }
}

void loop()
{
  Blynk.run();
}
