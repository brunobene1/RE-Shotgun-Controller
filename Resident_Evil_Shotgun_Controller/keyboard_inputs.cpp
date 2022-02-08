#include "keyboard_inputs.h"

void keyboard_inputs_setup()
{
  pinMode(RELOAD_BUTTON_PIN, INPUT_PULLUP);
  pinMode(SPRINT_BUTTON, INPUT_PULLUP);
  pinMode(BLOCK_MOUSE_BUTTON, INPUT_PULLUP);
  pinMode(JOYSTICK_X_AXIS, INPUT);
  pinMode(JOYSTICK_Y_AXIS, INPUT);
  pinMode(JOYSTICK_SW, INPUT_PULLUP);  
  Keyboard.begin();
}

void keyboard_inputs_joystick()
{
  // ----- Joystick Switch -----
  if(digitalRead(JOYSTICK_SW) == 0)
  {
    Keyboard.press(KEY_TAB);
  }
  else
  {
    Keyboard.release(KEY_TAB);
  }
  
  // ----- Joystick Y Axis -----
  if(analogRead(JOYSTICK_Y_AXIS) > 600)
  {
    Keyboard.press(KEY_d);
  }
  else if (analogRead(JOYSTICK_Y_AXIS) < 400)
  {
    Keyboard.press(KEY_a);
  }
  else
  {
    Keyboard.release(KEY_d);
    Keyboard.release(KEY_a);
  }

  // ----- Joystick X Axis -----
  if(analogRead(JOYSTICK_X_AXIS) > 600)
  {
    Keyboard.press(KEY_w);
  }
  else if (analogRead(JOYSTICK_X_AXIS) < 400)
  {
    Keyboard.press(KEY_s);
  }
  else
  {
    Keyboard.release(KEY_w);
    Keyboard.release(KEY_s);
  }
}

void keyboard_inputs_other_keys()
{
  // ----- Reload button (r) -----
  if(digitalRead(RELOAD_BUTTON_PIN) == 0)
  {
    Keyboard.press(KEY_r);
  }
  else
  {
    Keyboard.release(KEY_r);
  }

  // ----- Sprint button (KEY_LEFT_SHIFT) -----
  if(digitalRead(SPRINT_BUTTON) == 0)
  {
    Keyboard.press(KEY_LEFT_SHIFT);
  }
  else
  {
    Keyboard.release(KEY_LEFT_SHIFT);
  }
}

void keyboard_inputs_secret_buttons(int* not_used_axis)
{
  // ----- Left side -----
  if((-1*(*not_used_axis)/GYROSCOPE_DIVISION_CORRECTION) == 65)
  {
    Keyboard.press(KEY_e);
  }
  else
  {
    Keyboard.release(KEY_e);
  }
  
  // ----- Right side -----
  if((-1*(*not_used_axis)/GYROSCOPE_DIVISION_CORRECTION) == -65)
  {
    Keyboard.press(KEY_BACKSPACE);
  }
  else
  {
    Keyboard.release(KEY_BACKSPACE);
  }
}
