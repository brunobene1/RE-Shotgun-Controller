#include "mouse_inputs.h"

void mouse_inputs_setup()
{
  pinMode(RIGHT_MOUSE_BUTTON, INPUT_PULLUP);
  pinMode(LEFT_MOUSE_BUTTON, INPUT_PULLUP);  
  Mouse.begin();
}

void mouse_inputs_buttons()
{
  // ----- Mouse left click -----
  if(digitalRead(LEFT_MOUSE_BUTTON) == 0)
  {
    Mouse.press(MOUSE_LEFT);
  }
  else
  {
    Mouse.release(MOUSE_LEFT);
  }
  
  // ----- Mouse right click -----
  if(digitalRead(RIGHT_MOUSE_BUTTON) == 0)
  {
    Mouse.press(MOUSE_RIGHT);
  }
  else
  {
    Mouse.release(MOUSE_RIGHT);
  }
}


void mouse_inputs_mouse_position(int* Xaxis, int* Yaxis)
{
  // ----- Y axis -----
  if(((*Yaxis/GYROSCOPE_DIVISION_CORRECTION)< -2) )
  {
    Mouse.move(0, -1*(*Yaxis/GYROSCOPE_DIVISION_CORRECTION), 0);
  }
  
  if( ((*Yaxis/GYROSCOPE_DIVISION_CORRECTION) > 3))
  {
    Mouse.move(0, -1*(*Yaxis/GYROSCOPE_DIVISION_CORRECTION)*1.15, 0);
  }

  // ----- X axis -----
  if( ((*Xaxis/GYROSCOPE_DIVISION_CORRECTION) >2))
  {
    Mouse.move(-1*(*Xaxis/GYROSCOPE_DIVISION_CORRECTION)*1.25, 0, 0);
  }

  if(((*Xaxis/GYROSCOPE_DIVISION_CORRECTION)< -2) )
  {
    Mouse.move(-1*(*Xaxis/GYROSCOPE_DIVISION_CORRECTION)*1, 0, 0);
  }
}
