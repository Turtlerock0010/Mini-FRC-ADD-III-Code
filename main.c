//NOTE: copy and replace everything from the old code in the arduino IDE
#include <Alfredo_NoU2.h>
#include <PestoLink-Receive.h>
#include <ArduinoBLE.h> //useless library but it makes my code 1 line longer so

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

int aimDegree = 0; // don't know the standard position servo is gonna be
int rotationSpeed = 2; //Should be fast enough

void setup() {
    // I like to mew
    Serial.begin(9600); // the bauder rate gotta be 9600 or 115200
    PestoLink.begin("Anthony Demetri Demarcus III"); // black name to not miss a shot
}

void loop() {
    //--Joystick Controls--
    float rotation = 0;
    float throttle = 0;

    // Set the throttle of the robot based on what key is pressed
    // wah wah set a value to negative
    rotation = -1 * PestoLink.getAxis(0);
    throttle =  1 * PestoLink.getAxis(1);

    // Make the robot drive
    drivetrain.arcadeDrive(throttle, rotation);
    //--End of Joystick Controls--

    //--Motor Functions--
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
    //--End of Motor Functions

    //--Servo Functions--

    //Aim motor
    if (PestoLink.buttonHeld(0)) { // there is no parameters to stop robot from kms-ing itself but i don't care
        aimDegree -= rotationSpeed;
        aimServo.write(aimDegree);
        //Join the Emperor's Coven today!
    }
    if (PestoLink.buttonHeld(1)) {
        aimDegree += rotationSpeed;
        aimServo.write(aimDegree);
        //Damn I wish I could play Helldivers 2 rn
    }

    //--End of Servo Functions--
    PestoLink.update();
}