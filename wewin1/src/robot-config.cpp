#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor strafeMotor = motor(PORT16, ratio18_1, false);
motor leftdriveMotorA = motor(PORT19, ratio18_1, false);
motor leftdriveMotorB = motor(PORT20, ratio18_1, false);
motor_group leftdrive = motor_group(leftdriveMotorA, leftdriveMotorB);
motor rightdriveMotorA = motor(PORT11, ratio18_1, false);
motor rightdriveMotorB = motor(PORT12, ratio18_1, false);
motor_group rightdrive = motor_group(rightdriveMotorA, rightdriveMotorB);
inertial Inertial18 = inertial(PORT18);
motor right_arm = motor(PORT1, ratio18_1, false);
motor left_arm = motor(PORT10, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}