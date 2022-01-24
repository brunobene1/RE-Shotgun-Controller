#include "mpu6050.h"

void mpu6050_setup()
{
  // ----- Initializes I2C communication -----
  Wire.begin();
  Wire.beginTransmission(I2C_ADDRESS_MPU6050);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  
  // ----- Gyroscope scale configuration -----
  /*
   * Wire.write(0b00000000); //Scale +/- 250°/s ; Divide by 131
   * Wire.write(0b00001000); //Scale +/- 500°/s ; Divide by 65.6
   * Wire.write(0b00010000); //Scale +/- 1000°/s ; Divide by 32.8
   * Wire.write(0b00011000); //Scale +/- 2000°/s ; Divide by 16.4
   */
   
  Wire.beginTransmission(I2C_ADDRESS_MPU6050);
  Wire.write(GYROSCOPE_REGISTER);
  Wire.write(0b00000000);
  Wire.endTransmission();

  // ----- Accelerometer scale configuration -----
  /*
   * Wire.write(0b00000000); //Scale +/- 2g ; Divide by 16384
   * Wire.write(0b00001000); //Scale +/- 4g ; Divide by 8192
   * Wire.write(0b00010000); //Scale +/- 8g ; Divide by 4096
   * Wire.write(0b00011000); //Scale +/- 16g ; Divide by 2048
   */
   
  Wire.beginTransmission(I2C_ADDRESS_MPU6050);
  Wire.write(ACCELEROMETER_REGISTER);
  Wire.write(0b00000000);
  Wire.endTransmission();
}

void mpu6050_read_data(int* AccX, int* AccY, int* AccZ, int* Temp, int* GyrX, int* GyrY, int* GyrZ)
{
  // ----- I2C -----
  Wire.beginTransmission(I2C_ADDRESS_MPU6050);
  Wire.write(0x3B); //Starts at this register
  Wire.endTransmission(false);
  Wire.requestFrom(I2C_ADDRESS_MPU6050, 14, true); //14 bytes requested

  // ----- Reading the SDA -----
  *AccX = Wire.read() << 8 | Wire.read(); //0x3B (ACCEL_XOUT_H) or 0x3C (ACCEL_XOUT_L)
  *AccY = Wire.read() << 8 | Wire.read(); //0x3D (ACCEL_YOUT_H) or 0x3E (ACCEL_YOUT_L)
  *AccZ = Wire.read() << 8 | Wire.read(); //0x3F (ACCEL_ZOUT_H) or 0x40 (ACCEL_ZOUT_L)
  *Temp = Wire.read() << 8 | Wire.read(); //0x41 (TEMP_OUT_H) or 0x42 (TEMP_OUT_L)
  *GyrX = Wire.read() << 8 | Wire.read(); //0x43 (GYRO_XOUT_H) or 0x44 (GYRO_XOUT_L)
  *GyrY = Wire.read() << 8 | Wire.read(); //0x45 (GYRO_YOUT_H) or 0x46 (GYRO_YOUT_L)
  *GyrZ = Wire.read() << 8 | Wire.read(); //0x47 (GYRO_ZOUT_H) or 0x48 (GYRO_ZOUT_L)
}
