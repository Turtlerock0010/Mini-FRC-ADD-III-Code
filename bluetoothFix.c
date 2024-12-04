//NOTE: copy and replace everything from the old code in the arduino IDE
#include <Alfredo_NoU2.h>
#include <PestoLink-Receive.h>
#include <ArduinoBLE.h>

//no need to define code here

void setup() {
    // I like to mew
    BLE.begin();
    Serial.begin(9600);
    PestoLink.begin("Anthony Demetri Demarcus III");
}