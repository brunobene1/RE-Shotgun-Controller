#ifndef MPU6050_H
#define MPU6050_H


#include <Arduino.h>
#include "Wire.h"

#define I2C_ADDRESS_MPU6050 0x68
#define GYROSCOPE_REGISTER 0x1B
#define ACCELEROMETER_REGISTER 0x1C

/**
 * \brief Setup the mouse.
 */
void mpu6050_setup();

/**
 * \brief Reads the MPU6050 data
 * 
 * \param[in] AccX X axis of the Accelerometer
 * 
 * \param[in] AccY Y axis of the Accelerometer
 * 
 * \param[in] AccZ Z axis of the Accelerometer
 * 
 * \param[in] Temp Not used
 * 
 * \param[in] GyrX X axis of the Gyroscope
 * 
 * \param[in] GyrY y axis of the Gyroscope
 * 
 * \param[in] GyrZ z axis of the Gyroscope
 */
void mpu6050_read_data(int* AccX, int* AccY, int* AccZ, int* Temp, int* GyrX, int* GyrY, int* GyrZ);


#endif /* MPU6050_H */
