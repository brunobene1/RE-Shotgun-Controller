#ifndef MOUSE_INPUTS_H
#define MOUSE_INPUTS_H


#include <Arduino.h>
#include <Mouse.h>
#include "Wire.h"
#include "mpu6050.h"
#include "debug.h"

// ----- Pins -----
#define RIGHT_MOUSE_BUTTON 6
#define LEFT_MOUSE_BUTTON 5
// ----- Pins end -----

/**
 * \brief Setup the mouse.
 */
void mouse_inputs_setup();

/**
 * \brief Reads the mouse right and left buttons inputs
 */
void mouse_inputs_buttons();

/**
 * \brief Converts the MPU6050 inputs to mouse position
 * 
 * \param[in] Xaxis X axis of the Gyroscope
 * 
 * \param[in] Yaxis y axis of the Gyroscope
 * 
 */
void mouse_inputs_mouse_position(int* Xaxis, int* Yaxis);

#endif /* MOUSE_INPUTS_H */
