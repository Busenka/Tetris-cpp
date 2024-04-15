/**************************************
// File: Main.cpp
// Desc: Main loop of tetris game.
**************************************/

//---- Includes ----

#include "Game.h"
#include <cstdlib>

int main() {
  //---- Vars ----

  // Class for drawing stuffs, uses SDL2
  IO mIO;
  int mScreenHeight = mIO.GetScreenHeight();

  // Pieces
  Pieces mPieces;

  // Board
  Board mBoard(&mPieces, mScreenHeight);

  // Game
  Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

  // Get actual clock milliseconds (SDL2)
  unsigned long mTime1 = SDL_GetTicks();

  //---- Main loop ----

  while (!mIO.IsKeyDown(SDLK_ESCAPE)) {

    // ---- Draw ----

    mIO.ClearScreen();
    mGame.DrawScene();
    mIO.UpdateScreen();

    //---- Input ----

    int mKey = mIO.PollKey();

    switch (mKey) {
    case (SDLK_RIGHT): {
      if (mBoard.IsPossibleMovement(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece,
                                    mGame.mRotation))
        mGame.mPosX++;
      break;
    }

    case (SDLK_LEFT): {
      if (mBoard.IsPossibleMovement(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece,
                                    mGame.mRotation))
        mGame.mPosX--;
      break;
    }

    case (SDLK_DOWN): {
      if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece,
                                    mGame.mRotation))
        mGame.mPosY++;
      break;
    }

    case (SDLK_x): {
      // Check collision from up to down
      while (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece,
                                       mGame.mRotation)) {
        mGame.mPosY++;
      }

      mBoard.StorePiece(mGame.mPosX, mGame.mPosY - 1, mGame.mPiece,
                        mGame.mRotation);

      mBoard.DeletePossibleLines();

      if (mBoard.IsGameOver()) {
        mIO.GetKey();
        exit(0);
      }

      mGame.CreateNewPiece();

      break;
    }
    case (SDLK_z): {
      if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece,
                                    (mGame.mRotation + 1) % 4))
        mGame.mRotation = (mGame.mRotation + 1) % 4;

      break;
    }
    }

    // ----- Vertical movement -----

    unsigned long mTime2 = SDL_GetTicks();

    if ((mTime2 - mTime1) > WAIT_TIME) {
      if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece,
                                    mGame.mRotation)) {
        mGame.mPosY++;
      } else {
        mBoard.StorePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece,
                          mGame.mRotation);

        mBoard.DeletePossibleLines();

        if (mBoard.IsGameOver()) {
          mIO.GetKey();
          exit(0);
        }

        mGame.CreateNewPiece();
      }

      mTime1 = SDL_GetTicks();
    }
  }

  return 0;
}
