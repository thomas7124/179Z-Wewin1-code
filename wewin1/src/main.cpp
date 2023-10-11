/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// strafeMotor          motor         16              
// leftdrive            motor_group   19, 20          
// rightdrive           motor_group   11, 12          
// Inertial18           inertial      18              
// right_arm            motor         1               
// left_arm             motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}
int left_percent = 0;
int right_percent = 0;
int strafe_percent = 0;
int forward_percent = 0;
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    left_percent = Controller1.Axis1.position(percent) + Controller1.Axis2.position(percent);
    right_percent = Controller1.Axis1.position(percent) - Controller1.Axis2.position(percent);
    forward_percent = Controller1.Axis3.position(percent);
    strafe_percent = Controller1.Axis4.position(percent);
    if (forward_percent > 10){
      leftdrive.spin(forward, forward_percent, percent);
      rightdrive.spin(forward, -1*forward_percent, percent);
    }
    else if (forward_percent < -10){
      leftdrive.spin(forward, forward_percent, percent);
      rightdrive.spin(forward, -1*forward_percent, percent);
    }
    else{
    printf("bruh");
    leftdrive.spin(forward, left_percent, percent);
    rightdrive.spin(forward, right_percent, percent);
    }


    if (Controller1.ButtonR1.pressing() == true){
      right_arm.spin(forward, 45, percent);
    }
    if (Controller1.ButtonR2.pressing() == true){
      right_arm.spin(forward, -45, percent);
    }


    if (Controller1.ButtonL2.pressing() == true){
      left_arm.spin(forward, 45, percent);
    }
    if (Controller1.ButtonL1.pressing() == true){
      left_arm.spin(forward, -45, percent);
    }


    strafeMotor.spin(forward, strafe_percent, percent);
    
    
  
    

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
