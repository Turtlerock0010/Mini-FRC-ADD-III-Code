//NOTE: copy and replace everything from the old code in the arduino IDE
#include <Alfredo_NoU2.h>
#include <PestoLink-Receive.h>
#include <ArduinoBLE.h>

//drive train motors init
NoU_Motor frontleftMotor(1);
NoU_Motor frontrightMotor(2);
//wiring bs that fab doesn't want to fix
NoU_Motor backleftMotor(4);
NoU_Motor backrightMotor(3);

//extra motors init
NoU_Motor pickUpMotor(5);
NoU_Motor shooterMotor(6);

//servo motors init
NoU_Motor aimServo(1);

//drive train init
NoU_Drivetrain drivetrain(&frontleftMotor, &frontrightMotor, &backleftMotor, &backrightMotor);

void setup() {
    // I like to mew
    Serial.begin(9600);
    PestoLink.begin("Anthony Demetri Demarcus III");
}

void loop() {
    //temp controls joystick
    float rotation = 0;
    float throttle = 0;

    // Set the throttle of the robot based on what key is pressed
    rotation = -1 * PestoLink.getAxis(0);
    throttle =  1 * PestoLink.getAxis(1);

    // Make the robot drive
    drivetrain.arcadeDrive(throttle, rotation);
  
    //Pickup Motor
    if (PestoLink.buttonHeld(2)) {
        pickUpMotor.set(1);
    }
    else {
        pickUpMotor.set(0);
    }

    //Shooter Motor
    if (PestoLink.buttonHeld(3)) {
        shooterMotor.set(-1);
    }
    else {
        shooterMotor.set(0);
    }

    PestoLink.update();
}