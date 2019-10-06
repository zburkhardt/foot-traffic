#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 

String occupChange[20][5];
size_t attempt = 0, roomA = 4, roomB = 12;
bool tagOneHere = false, tagTwoHere = false;

// Init array that will store new NUID 
byte nuidPICC[4];

void setup() {
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

  // Zero out the 2D array
  for (size_t i = 0; i < 20; ++i) {
    for (size_t j = 0; j < 5; ++j) {
      occupChange[i][j] = "0";
    }
  }

  menu();
  digitalWrite(7, HIGH);

}

void loop() {
 // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! rfid.PICC_IsNewCardPresent()) {
    if (Serial.available())
    {
      String recievedData = Serial.readString();
      
      if (recievedData == "1")
      {
        summary();
        menu();
      }
      else if (recievedData == "2")
      {
        accessLog();
        menu();
      }
    }
    return;
  }

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;
    
    // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }

    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
   
    printHex(rfid.uid.uidByte, rfid.uid.size);

}

/**
 * Helper routine to dump a byte array as hex values to Serial. 
 */
void printHex(byte *buffer, byte bufferSize) {
  /* for (byte i = 0; i < bufferSize; i++) {
    if (buffer[i] < 0x10)
    {
      occupChange[attempt][0][i] = " 0";
    }
    else
    {
      occupChange[attempt][0][i] = " ";
    } */
    
  // Serial.print(buffer[i] < 0x10 ? " 0" : " ");
   String id0 = "", id1 = "", id2 = "", id3 = "";
   id0 = buffer[0];
   id1 = buffer[1];
   id2 = buffer[2];
   id3 = buffer[3];
   occupChange[attempt][0] = (id0 + id1 + id2 + id3);

   if (occupChange[attempt][0] == "5910323226")
   {
     occupChange[attempt][1] = "Lee Nestor";
     if (!tagOneHere)
     {
       tagOneHere = true;
       occupChange[attempt][4] = "1";
       ++roomA;
     }
     else
     {
       tagOneHere = false;
       occupChange[attempt][4] = "0";
       --roomA;
     }
   }
   else if (occupChange[attempt][0] == "1671879860")
   {
     if (!tagTwoHere)
     {
       tagTwoHere = true;
       occupChange[attempt][4] = "1";
       ++roomA;
     }
     else
     {
       tagTwoHere = false;
       occupChange[attempt][4] = "0";
       --roomA;
     }
     occupChange[attempt][1] = "Zach Burkhardt";
   }

  int evHour = ((((millis() / 1000) / 60) / 60) % 24), evMin = (((millis() / 1000) / 60) % 60), evSec = ((millis() / 1000) % 60);
  String stHour(evHour), stMin(evMin), stSec(evSec);
  if (stHour == "0")
    stHour = "00";
  if (stMin == "0")
    stMin = "00";
  if (stSec == "0")
    stSec = "00";
  occupChange[attempt][3] = (stHour + ":" + stMin + ":" + stSec);

  occupChange[attempt][2] = "A";

  ++attempt;
  delay(1500);
}

void menu() {
  Serial.println("BUILDING OCCUPANCY");
  Serial.println("--------------");
  Serial.println("Menu: 1) Occupancy Summary");
  Serial.println("      2) Access Log");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
}

void summary() {
  Serial.println("");
  Serial.println("OCCUPANCY SUMMARY");
  Serial.println("--------------");
  Serial.print("Room A: ");
  Serial.println(roomA);
  Serial.print("Room B: ");
  Serial.println(roomB);
  Serial.println("--------------");
  Serial.print("Total number of occupants in building: ");
  Serial.println(roomA + roomB);
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
}

void accessLog() {
  Serial.println("");
  Serial.println("--------------");
  Serial.println("");
  Serial.println("#############");
  for (size_t i = 0; i < attempt; ++i) {
    if (occupChange[0][0] == "0")
      Serial.println("No Log Events");
    if (occupChange[i][0] != "0")
    {
      Serial.print("ID TAG: ");
      Serial.println(occupChange[i][0]);
      Serial.print("NAME: ");
      Serial.println(occupChange[i][1]);
      Serial.print("ROOM: ");
      Serial.println(occupChange[i][2]);
      Serial.print("TIME: ");
      Serial.println(occupChange[i][3]);
      Serial.print("CHANGE: ");
      if (occupChange[i][4] == "0")
        Serial.println("Exit");
      else
        Serial.println("Entry");
      Serial.println("#############");
    }
  }
  
  Serial.println("");
  Serial.println("--------------");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
}
