
task main() {
  while (true) {
    motor[leftmotor] = vexRT[Ch3];
    motor[rightmotor] = vexRT[Ch3];
    while (vexRT[Ch1] < 0) {
      motor[leftmotor] = vexRT[Ch1];
      motor[rightmotor] = vexRT[Ch1] * -1;
    }
    while (vexRT[Ch1] > 0) {
      motor[rightmotor] = vexRT[Ch1];
      motor[leftmotor] = vexRT[Ch1] * -1;
    }
  }
}
