#pragma config(Sensor, in1,    LineFollower,   sensorLineFollower)
#pragma config(Sensor, dgtl1,  Bump,           sensorTouch)
#pragma config(Sensor, dgtl3,  Sonar,          sensorSONAR_inch)
#pragma config(Motor,  port1,           LeftDrive,     tmotorVex393_HBridge, openLoop, reversed, driveLeft)
#pragma config(Motor,  port3,           ArmMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           ActMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          RightDrive,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*Code for Swept Away VEX Challenge CTD: By Archan Das and Adam Kalman.
Anyone can use this code if they want to. */
void drivercontrol(int LeftMotor, int RightMotor, int ArmMotor, int ActMotor)// gives user control
{
	while (true)
	{
		motor[RightMotor] = vexRT[Ch2];
		motor[LeftMotor] = vexRT[Ch3];
		motor[ArmMotor] = 0;
		motor[ActMotor] = 0;
		if (vexRT[Btn5U] == 1)
		{
			motor[ArmMotor] = 127;
		}
		else if(vexRT[Btn5D] == 1)
		{
			motor[ArmMotor] = -127;
		}
		else
		{
			motor[ArmMotor] = 0;
		}
		if (vexRT[Btn6U] == 1)
		{
			motor[ActMotor] = 127;
		}
		else if (vexRT[Btn6D] == 1)
		{
			motor[ActMotor] = -127;
		}
		else
		{
			motor[ActMotor] = 0;
		}
	}
}
int t = 0;


task main()
{
	//autonomous code, should start right next to a ball pointing at it.
	clearTimer(T4);
	while (t < 17500)
	{
		motor[LeftDrive] = 50;
		motor[RightDrive] = 50;
		wait1Msec(100);
		motor[ArmMotor] = 127;
		wait1Msec(500);
		motor[ArmMotor] = 0;
		motor[LeftDrive] = 127;
		motor[RightDrive] = -127;
		wait1Msec(900);
		while(SensorValue[LineFollower]<1500)
		{
			motor[LeftDrive] = 127;
			motor[RightDrive] = 127;
		}
		motor[LeftDrive] = -127;
		motor[RightDrive] = 127;
		wait1Msec(600);
		while (SensorValue[Bump] == 0)
		{
			motor[LeftDrive] = 127;
			motor[RightDrive] = 127;
		}
		motor[ArmMotor] = -50;
		motor[ActMotor] = -127;
		wait1Msec(500);
		t = time1[T4];

	}

	//gives user control.
	drivercontrol(LeftDrive, RightDrive, ArmMotor, ActMotor);

}
