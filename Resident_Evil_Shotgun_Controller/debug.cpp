#include "debug.h"

void debug_setup()
{
  Serial.begin(9600);
}

void debug_joystick_x_axis()
{
  Serial.print("JOYSTICK_X_AXIS : ");
  Serial.println(analogRead(JOYSTICK_X_AXIS));
}

void debug_joystick_y_axis()
{
  Serial.print("JOYSTICK_Y_AXIS : ");
  Serial.println(analogRead(JOYSTICK_Y_AXIS));
}

void debug_mpu6050_data_accelerometer(int* AccX, int* AccY, int* AccZ)
{
  Serial.print("ACCELEROMETER X AXIS : ");
  Serial.println((*AccX));
  Serial.print("ACCELEROMETER Y AXIS : ");
  Serial.println((*AccY));
  Serial.print("ACCELEROMETER Z AXIS : ");
  Serial.println((*AccZ));
}

void debug_mpu6050_data_gyroscope(int* GyrX, int* GyrY, int* GyrZ)
{
  //Serial.print("ACCELEROMETER X AXIS : ");
  Serial.println(-1*(*GyrX)/GYROSCOPE_DIVISION_CORRECTION);
  //Serial.print("ACCELEROMETER Y AXIS : ");
  //Serial.println(-1*(*GyrY)/GYROSCOPE_DIVISION_CORRECTION);
  //Serial.print("ACCELEROMETER Z AXIS : ");
  //Serial.println(-1*(*GyrZ)/GYROSCOPE_DIVISION_CORRECTION);
}
