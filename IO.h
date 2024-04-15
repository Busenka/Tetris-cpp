/**********************************************************
// File: IO.h
// Desc: Class for handling inpung & drawing, it uses SDL for the rendering.
**********************************************************/

#ifndef _IO_
#define _IO_

//---- Includes ----

#include "SDL/SDL_GfxPrimitives/sdl_gfxprimitives.h"
#include "SDL/include/SDL.h"
#pragma comment(lib, "SDL/lib/SDL.lib")
#pragma comment(lib, "SDL/SDL_GfxPrimitives/SDL_GfxPrimitives_Static.lib")

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

//===========================================================
// IO
//===========================================================

class IO {
public:
  IO();

  void DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC);
  void ClearScreen();
  int GetScreenHeight();
  int InitGraph();
  int Pollkey();
  int Getkey();
  int IsKeyDown(int pKey);
  void UpdateScreen();
};

#endif // !_IO_
