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
    //temp controls joystick
    float rotation = 0;
    float throttle = 0;

    // Set the throttle of the robot based on what key is pressed
    rotation = -1 * PestoLink.getAxis(0);
    throttle =  1 * PestoLink.getAxis(1);

    // Make the robot drive
    drivetrain.arcadeDrive(throttle, rotation);
  
    //servo test code
    if (PestoLink.buttonHeld(1)) {
        aimServo.write(180);
    }
    else {
        aimServo.write(0);
    }

    PestoLink.update();
}
