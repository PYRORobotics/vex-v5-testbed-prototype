#include "../include/main.h"

int process = 0;
double distTraveled = 0;
bool velIsLocked = 0;
int setVel = 0;

void mainCenter()
{
	//if(process == 0)
	process = 1;
	//else process = 0;
}
void toFlywheel()
{
	process = 1;
}
void selectedFlywheel()
{
	process = 2;
}
void toDrivetrain()
{
	process = 3;
}
void selectedDrivetrain()
{
	process = 4;
}


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	//pros::Controller master(pros::E_CONTROLLER_MASTER);
//	pros::Motor left_mtr(1);
	//pros::Motor right_mtr(2);



	while (true) {

		switch(process)
		{
			case 0:
				pros::lcd::print(0, "");
	      pros::lcd::print(1, "PYRO Robotics | VEX U");
	      pros::lcd::print(2, "2018-2019 TURNING POINT");
	      pros::lcd::print(3, "");
	      pros::lcd::print(4, "v5 Prototyping Testbed");
	      pros::lcd::print(5, "");
	      pros::lcd::print(6, "");
	      pros::lcd::print(7, "[   -    ]         [  Continue  ]        [    -   ]");
				//printCenteredButton(7, "-", "Continue", "-");
	      pros::lcd::register_btn0_cb(NULL);
	      pros::lcd::register_btn1_cb(mainCenter);
	      pros::lcd::register_btn2_cb(NULL);
				if(Joystick.get_digital(DIGITAL_B))
				{
					mainCenter();
					while(Joystick.get_digital(DIGITAL_B))
					{
						pros::delay(10);
					}
				}
				break;
			case 1:
				pros::lcd::print(0, "");
				pros::lcd::print(1, "Flywheel");
				pros::lcd::print(2, "");
				pros::lcd::print(3, "Control the flywheel using the joysticks.");
				pros::lcd::print(4, "");
				pros::lcd::print(5, "");
				pros::lcd::print(6, "");
				pros::lcd::print(7, "[   <-   ]          [ Select  ]          [   ->   ]");
				pros::lcd::register_btn0_cb(toDrivetrain);
				pros::lcd::register_btn1_cb(selectedFlywheel);
				pros::lcd::register_btn2_cb(toDrivetrain);
				if(Joystick.get_digital(DIGITAL_LEFT)) toDrivetrain();
				if(Joystick.get_digital(DIGITAL_RIGHT)) toDrivetrain();
				if(Joystick.get_digital(DIGITAL_B))
				{
					selectedFlywheel();
					while(Joystick.get_digital(DIGITAL_B))
					{
						pros::delay(10);
					}
				}
				break;
			case 2:
				pros::lcd::print(0, "");
				pros::lcd::print(1, "Flywheel SELECTED");
				pros::lcd::print(2, "");
				pros::lcd::print(3, "Control the flywheel using the joysticks.");
				pros::lcd::print(4, "");
				pros::lcd::print(5, "RPM: %f", FlywheelMotor1.get_actual_velocity() * 15);
				pros::lcd::print(6, "");
				pros::lcd::print(7, "[   -    ]          [   Back   ]         [    -   ]");
				pros::lcd::register_btn0_cb(NULL);
				pros::lcd::register_btn1_cb(toFlywheel);
				pros::lcd::register_btn2_cb(NULL);


				if(velIsLocked)
				{
					//FlywheelMotor1.move_velocity(setVel);
					//FlywheelMotor2.move_velocity(setVel);
					FlywheelMotor1.move_voltage(setVel);
					FlywheelMotor2.move_voltage(setVel);
					FlywheelMotorHood = Joystick.get_analog(ANALOG_RIGHT_Y) * 30/127;
				}
				else
				{
					FlywheelMotor1 = Joystick.get_analog(ANALOG_LEFT_Y);
					FlywheelMotor2 = Joystick.get_analog(ANALOG_LEFT_Y);
					FlywheelMotorHood = Joystick.get_analog(ANALOG_RIGHT_Y) * 30/127;
				}

				if(Joystick.get_digital(DIGITAL_B))
				{
					toFlywheel();
					while(Joystick.get_digital(DIGITAL_B))
					{
						pros::delay(10);
					}
				}
				if(Joystick.get_digital(DIGITAL_A))
				{
					velIsLocked == 0? velIsLocked = 1 : velIsLocked = 0;
					setVel = FlywheelMotor1.get_voltage();
					while(Joystick.get_digital(DIGITAL_A))
					{
						pros::delay(10);
					}
				}

				PreFlywheelMotor1 = 0;
				PreFlywheelMotor2 = 0;
				if(Joystick.get_digital(DIGITAL_R1))
				{
					PreFlywheelMotor1 = 80;
					PreFlywheelMotor2 = 80;
					while(Joystick.get_digital(DIGITAL_R1))
					{
						pros::delay(10);
					}
				}
				else if(Joystick.get_digital(DIGITAL_L1))
				{
					PreFlywheelMotor1 = -80;
					PreFlywheelMotor2 = -80;
					while(Joystick.get_digital(DIGITAL_L1))
					{
						pros::delay(10);
					}
				}
				break;
			case 3:
				pros::lcd::print(0, "");
				pros::lcd::print(1, "Drivetrain");
				pros::lcd::print(2, "");
				pros::lcd::print(3, "Control the drive using the joysticks.");
				pros::lcd::print(4, "");
				pros::lcd::print(5, "");
				pros::lcd::print(6, "");
				pros::lcd::print(7, "[   <-   ]          [ Select  ]          [   ->   ]");
				pros::lcd::register_btn0_cb(toFlywheel);
				pros::lcd::register_btn1_cb(selectedDrivetrain);
				pros::lcd::register_btn2_cb(toFlywheel);

				if(Joystick.get_digital(DIGITAL_LEFT)) toFlywheel();
				if(Joystick.get_digital(DIGITAL_RIGHT)) toFlywheel();
				if(Joystick.get_digital(DIGITAL_B))
				{
					selectedDrivetrain();
					distTraveled = 0;
					while(Joystick.get_digital(DIGITAL_B))
					{
						pros::delay(10);
					}
				}
				break;
			case 4:
				distTraveled += DrivetrainMotorFL.get_actual_velocity() * 4.125 * M_PI * 20 / 60000;

				pros::lcd::print(0, "");
				pros::lcd::print(1, "Drivetrain SELECTED");
				pros::lcd::print(2, "");
				pros::lcd::print(3, "Control the drive using the joysticks.");
				pros::lcd::print(4, "Calc. Displacement (in): %f", distTraveled);
				pros::lcd::print(5, "Velocity: %f", DrivetrainMotorFL.get_actual_velocity() * 4.125 * M_PI);
				pros::lcd::print(6, "");
				pros::lcd::print(7, "[   -    ]          [   Back   ]         [    -   ]");
				pros::lcd::register_btn0_cb(NULL);
				pros::lcd::register_btn1_cb(toDrivetrain);
				pros::lcd::register_btn2_cb(NULL);

				DrivetrainMotorFL = Joystick.get_analog(ANALOG_LEFT_Y);
				DrivetrainMotorFM = Joystick.get_analog(ANALOG_LEFT_Y);
				DrivetrainMotorFR = Joystick.get_analog(ANALOG_LEFT_Y);
				DrivetrainMotorRL = Joystick.get_analog(ANALOG_RIGHT_Y);
				DrivetrainMotorRM = Joystick.get_analog(ANALOG_RIGHT_Y);
				DrivetrainMotorRR = Joystick.get_analog(ANALOG_RIGHT_Y);

				if(Joystick.get_digital(DIGITAL_B))
				{
					toDrivetrain();
					while(Joystick.get_digital(DIGITAL_B))
					{
						pros::delay(10);
					}
				}
				break;
		}

		//pros::lcd::print(0, "1234");
		//int left = master.get_analog(ANALOG_LEFT_Y);
		//int right = master.get_analog(ANALOG_RIGHT_Y);

		//left_mtr = left;
		//right_mtr = right;
		pros::delay(20);
	}
}
