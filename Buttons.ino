// Button Control
int buttonPins[15] = {13, 15, 25, 26, 27, 14, 23, 22, 21, 19, 18, 17, 16, 32, 35};           // Fill in { } with list of Button pins
int buttonNums[15] = {1,  13,  6,  4,  5,  3,  2,  9,  7,  10, 11, 12, 8, 14, 15};           // Store Button Number Assignments (1 - 15) (This can be used to adjust button mapping in game later on)
//Mapped for Krunker.io

Bounce * buttons = new Bounce[15];  // Creates an array of Bounce objects 

// initButtons loops through the array of Bounce2 buttons and attaches them as inputs.
// It also sets an interval of 5ms for responsiveness
void initButtons(){
  for (int i = 0; i < 15; i++)
  {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(5);
  }
}

// updateButtons loops through the array of Bounce2 buttons and updates them.
// If the buttons rose, then the respective button is pressed in the bleGamepad library
// If the buttons fell, then the respective button is released in the bleGamepad library
void updateButtons(){
  for (int i = 0; i < 15; i++)
  {
    buttons[i].update();
    if (buttons[i].rose())
    {
      bleGamepad.press(buttonNums[i]);
    }
    if (buttons[i].fell())
    {
      bleGamepad.release(buttonNums[i]);
    }
  }
}
