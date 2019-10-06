#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

const int IR_ROOM_A = 7;
//const int IR_ROOM_B = 8;
IRrecv irrecvA(IR_ROOM_A);
//IRrecv irrecvB(IR_ROOM_B);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecvA.enableIRIn();
  irrecvA.blink13(true);
//  irrecvB.enableIRIn();
//  irrecvB.blink13(true);

}

void loop() {
  Serial.println('A');
  if (irrecvA.decode(&results)){
        Serial.print("Room A: ");
        Serial.println(results.value, HEX);
        irrecvA.resume();
        }
   delay(1000);
/*
  if (irrecvB.decode(&results)){
        Serial.print("Room B: ");
        Serial.println(results.value, HEX);
        irrecvB.resume();
        delay(1000);
  } */
}
