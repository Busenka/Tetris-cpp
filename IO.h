/***********************************************************************
// File: IO.h
// Desc: Class for handling inpung and drawing, uses SDL2.
***********************************************************************/

#ifndef _IO_
#define _IO_

//---- Includes ----

#include <SDL2/SDL.h>

//---- Enums ----

enum color {
  BLACK,
  RED,
  GREEN,
  BLUE,
  CYAN,
  MAGENTA,
  YELLOW,
  WHITE,
  COLOR_MAX
}; // Colors

/*
======================================================================
// IO
======================================================================
*/

class IO {
public:
  IO();

  void DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC);
  void ClearScreen();
  int GetScreenHeight();
  int InitGraph();
  int PollKey();
  int GetKey();
  int IsKeyDown(int pKey);
  void UpdateScreen();
};

#endif // !_IO_
