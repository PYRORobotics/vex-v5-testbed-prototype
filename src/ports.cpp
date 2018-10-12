#include "../include/api.h"

pros::Controller Joystick(pros::E_CONTROLLER_MASTER);

// V5 Smart Ports
pros::Motor DrivetrainMotorFL(1,0);
pros::Motor DrivetrainMotorFM(2,0);
pros::Motor DrivetrainMotorFR(3,0);
pros::Motor DrivetrainMotorRL(4,1);
pros::Motor DrivetrainMotorRM(5,1);
pros::Motor DrivetrainMotorRR(6,1);

pros::Motor FlywheelMotor1(7,0);
pros::Motor FlywheelMotor2(8,1);
pros::Motor FlywheelMotorHood(9,0);

pros::Motor PreFlywheelMotor1(10,0);
pros::Motor PreFlywheelMotor2(11,1);
