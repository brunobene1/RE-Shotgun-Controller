#ifndef KEYBOARD_INPUTS_H
#define KEYBOARD_INPUTS_H


#include <Arduino.h>
#include <Keyboard.h>
#include "debug.h"
#include "mouse_inputs.h"

// ----- Pins -----
#define RELOAD_BUTTON_PIN 4
#define SPRINT_BUTTON 7
#define BLOCK_MOUSE_BUTTON 8
#define JOYSTICK_X_AXIS A3
#define JOYSTICK_Y_AXIS A2
#define JOYSTICK_SW 16

// ----- Keys -----
#define KEY_LEFT_SHIFT 129
#define KEY_d 100 
#define KEY_a 97  
#define KEY_w 119
#define KEY_s 115
#define KEY_r 114
#define KEY_e 101
#define KEY_TAB 179
#define KEY_BACKSPACE 178
#define KEY_SPACE 32

/**
 * \brief Setup the keyboard.
 */
void keyboard_inputs_setup();

/**
 * \brief Reads the joystick inputs
 */
void keyboard_inputs_joystick();

/**
 * \brief Reads the other keys inputs
 */
void keyboard_inputs_other_keys();

/**
 * \brief Secret keyboard buttons using the MPU6050
 * 
 * \param[in] not_used_axis The tird MPU Gyroscope axis
 */
void keyboard_inputs_secret_buttons(int* not_used_axis);

#endif /* KEYBOARD_INPUTS_H */
