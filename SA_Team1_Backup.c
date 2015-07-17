#pragma config(Sensor, in1,    LineFollower,   sensorLineFollower)
#pragma config(Sensor, dgtl1,  Bump,           sensorTouch)
#pragma config(Motor,  port1,           LeftDrive,     tmotorVex393_HBridge, openLoop, reversed, driveLeft)
#pragma config(Motor,  port3,           ArmMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           ActMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           ArmMotor2,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          RightDrive,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*Code for Swept Away VEX Challenge CTD: By Archan Das and Adam Kalman and Theodore Gikas.
Anyone can use this code if they want to. */

/* This function will give us driver control. */
void setmotorspeed (int speed) {
	motor[LeftDrive] = speed;
	motor[RightDrive] = speed;
}
void zeropointturn (int speed, bool direction) {
	if (direction == true) {
		motor[LeftDrive] = speed;
		motor[RightDrive] = -1 * speed;
	}
	else {
		motor[LeftDrive] = -1 * speed;
		motor[RightDrive] = speed;
	}
}
void drivercontrol()
{
	while (true) //Do forever
	{
		motor[ArmMotor] = vexRT[Ch2];
		motor[ActMotor] = vexRT[Ch3];
		motor[ArmMotor2] = vexRT[Ch3];
		//Give control of drivetrain motors.
		//The code below allows us to control the arm and scoop
		if (vexRT[Btn5U] == 1)
		{
			zeropointturn(127, true);
		}
		else if(vexRT[Btn5D] == 1)
		{
			zeropointturn(63, true);
		}
		else
		{
			setmotorspeed(0);
		}
		if (vexRT[Btn6U] == 1)
		{
			zeropointturn(127, false);
		}
		else if (vexRT[Btn6D] == 1)
		{
			zeropointturn(63, false);
		}
		else
		{
			setmotorspeed(0);
		}
		if (vexRT[Btn8U] == 1)
		{
			motor[RightDrive] = 127;
		}
		else if (vexRT[Btn8D] == 1) {
			motor[RightDrive] = -127;
		}
		else if (vexRT[Btn8R] == 1) {
			motor[RightDrive] = 63;
		}
		else if (vexRT[Btn8L] == 1) {
			motor[RightDrive] = -63;
		}
		else {
			motor[RightDrive] = 0;
		}
		if (vexRT[Btn7U] == 1)
			{
				motor[LeftDrive] = 127;
			}
		else if (vexRT[Btn7D] == 1) {
			motor[LeftDrive] = -127;
		}
		else if (vexRT[Btn7R] == 1) {
			motor[LeftDrive] = 63;
		}
		else if (vexRT[Btn7L] == 1) {
			motor[LeftDrive] = -63;
		}
		else {
			motor[LeftDrive] = 0;
		}
	}
}
		int t = 0;
		/*The setmotorspeed function simply sets the speed of both
		motors at once. Saving space and time. (For the coder)*/
		//Begin the code
		task main()
		{
			//Autonomous code, should start right next to a ball pointing at it.
			clearTimer(T4); //Clear the timer so we can use it
			while (t < 17500) //While it has not been the 20 sec autonomous period.
			{
				// The code below goes to get balls.
				motor[LeftDrive] = 50;
				motor[RightDrive] = 50;
				wait1Msec(100);
				motor[ArmMotor] = 127;
				wait1Msec(500);
				motor[ArmMotor] = 0;
				motor[LeftDrive] = 127;
				motor[RightDrive] = -127;
				wait1Msec(900);
				//Now, the robot will find the goal.
				while(SensorValue[LineFollower]<1500)
				{
					motor[LeftDrive] = 127;
					motor[RightDrive] = 127; //Drive until we find the line
				}
				motor[LeftDrive] = -127;
				motor[RightDrive] = 127; //Turn in place
				wait1Msec(600);
				while (SensorValue[Bump] == 0)
				{
					motor[LeftDrive] = 127; //Travel fowards until we hit the wall.
					motor[RightDrive] = 127;
				}
				motor[ArmMotor] = -50;
				motor[ActMotor] = -127; //Raise the arm, and dump the scoop
				wait1Msec(500);
				t = time1[T4];

			}

			/*20 Sec. Autonomous period has ended, so now we begin
			the user controlled period. This will run infinetly.
			The drivercontrol code can be found above.
			(Outside of the main function)*/
			drivercontrol();

		}
