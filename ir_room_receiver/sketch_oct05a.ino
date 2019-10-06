#include <IRremote.h>

const int RECV_PIN = 7;
const int RECV_PIN2 = 8;
IRrecv irrecv(RECV_PIN);
IRrecv irrecv2(RECV_PIN2);
decode_results results;
decode_results results2;


void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, BIN);
        Serial.println("Reciever 1");
        if (results.value = 1000000101111110011000011001111){
       Serial.println("BOB");
        }
      
        irrecv.resume();
  }
  if (irrecv2.decode(&results2)){
    Serial.println(results2.value, HEX);
    Serial.println("Reciever 2");
    irrecv2.resume();
  }
  }
