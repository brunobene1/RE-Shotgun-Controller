/**
 * \brief Resident Evil Shotgun Controller
 * 
 * \author Bruno Benedetti <brunobenedetti45@gmail.com>
 * 
 * \version 1.0.0
 * 
 * \date 19/01/2022
 * 
 */

// ----- Includes -----
#include "keyboard_inputs.h"
#include "debug.h"
#include "mouse_inputs.h"
#include "mpu6050.h"
// ----- Includes end -----

// ----- MPU6050 Variables -----
int AccX; //X axis of the Accelerometer
int AccY; //Y axis of the Accelerometer
int AccZ; //Z axis of the Accelerometer
int Temp; //Not used
int GyrX; //X axis of the Gyroscope
int GyrY; //Y axis of the Gyroscope
int GyrZ; //Z axis of the Gyroscope

// ----- end variables -----

void setup() 
{
  keyboard_inputs_setup();
  debug_setup();
  mouse_inputs_setup(); 
  mpu6050_setup();
}

void loop() 
{
  keyboard_inputs_joystick();
  keyboard_inputs_other_keys();
  mouse_inputs_buttons();
  mpu6050_read_data(&AccX, &AccY, &AccZ, &Temp, &GyrX, &GyrY, &GyrZ);
  //debug_mpu6050_data_accelerometer(&AccX, &AccY, &AccZ);
  debug_mpu6050_data_gyroscope(&GyrX, &GyrY, &GyrZ);
  //mouse_inputs_mouse_position(&GyrX, &GyrZ);
  mouse_inputs_mouse_position2(&GyrY, &GyrZ);
  keyboard_inputs_secret_buttons(&GyrX);
}
