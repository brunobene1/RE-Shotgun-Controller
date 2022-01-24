#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>
#include "keyboard_inputs.h"

#define ACCELEROMETER_DIVISION_CORRECTION 2048
#define GYROSCOPE_DIVISION_CORRECTION 500

/**
 * \brief Setup the debug configs.
 */
void debug_setup();

/**
 * \brief Prints on the serial monitor the joystick x axis inputs
 */
void debug_joystick_x_axis();

/**
 * \brief Prints on the serial monitor the joystick y axis inputs
 */
void debug_joystick_y_axis();

/**
 * \brief Prints on the serial monitor the MPU6050 data
 * 
 * \param[in] AccX X axis of the Accelerometer
 * 
 * \param[in] AccY Y axis of the Accelerometer
 * 
 * \param[in] AccZ Z axis of the Accelerometer
 * 
 */
void debug_mpu6050_data_accelerometer(int* AccX, int* AccY, int* AccZ);

/**
 * \brief Prints on the serial monitor the MPU6050 data
 * 
 * \param[in] GyrX X axis of the Gyroscope
 * 
 * \param[in] GyrY y axis of the Gyroscope
 * 
 * \param[in] GyrZ z axis of the Gyroscope
 */
void debug_mpu6050_data_gyroscope(int* GyrX, int* GyrY, int* GyrZ);


#endif /* DEBUG_H */
