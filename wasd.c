//NOTE: copy and replace everything from the old code in the arduino IDE
#include <Alfredo_NoU2.h>
#include <PestoLink-Receive.h>

//drive train motors init
NoU_Motor frontleftMotor(1);
NoU_Motor frontrightMotor(2);
NoU_Motor backleftMotor(3);
NoU_Motor backrightMotor(4);

//servos init
NoU_Servo aimServo(1);

//drive train init
NoU_Drivetrain drivetrain(&frontleftMotor, &frontrightMotor, &backleftMotor, &backrightMotor);

void setup() {
    // I like to mew
    Serial.begin(9600);
    PestoLink.begin("Anthony Demetri Demarcus III");
}

void loop() {
    //--temp controls--
  
    //button 1 forward
    if (PestoLink.buttonHeld(1)) {
        frontleftMotor.set(1);
        frontrightMotor.set(1);
        backleftMotor.set(1);
        backrightMotor.set(1);
    }
    else {
        frontleftMotor.set(0);
        frontrightMotor.set(0);
        backleftMotor.set(0);
        backrightMotor.set(0);
    }

    //button 5 backward
    if (PestoLink.buttonHeld(5)) {
        frontleftMotor.set(-1);
        frontrightMotor.set(-1);
        backleftMotor.set(-1);
        backrightMotor.set(-1);
    }
    else {
        frontleftMotor.set(0);
        frontrightMotor.set(0);
        backleftMotor.set(0);
        backrightMotor.set(0);
    }

    //button 4 left
    if (PestoLink.buttonHeld(4)) {
        frontleftMotor.set(-1);
        frontrightMotor.set(1);
        backleftMotor.set(-1);
        backrightMotor.set(1);
    }
    else {
        frontleftMotor.set(0);
        frontrightMotor.set(0);
        backleftMotor.set(0);
        backrightMotor.set(0);
    }

    //button 6 left
    if (PestoLink.buttonHeld(6)) {
        frontleftMotor.set(1);
        frontrightMotor.set(-1);
        backleftMotor.set(1);
        backrightMotor.set(-1);
    }
    else {
        frontleftMotor.set(0);
        frontrightMotor.set(0);
        backleftMotor.set(0);
        backrightMotor.set(0);
    }

    //servo test code
    if (PestoLink.buttonHeld(0)) {
        aimServo.write(180);
    }
    else {
        aimServo.write(0);
    }

    PestoLink.update();
}
