#ifndef _PIECES_
#define _PIECES_

//----------------------------------------------------------------
// Pieces
//----------------------------------------------------------------

class Pieces {
public:
  int GetBlockType(int pPiece, int pRotation, int pX, int pY);
  int GetXinitialPosition(int pPiece, int pRotation);
  int GetYinitialPosition(int pPiece, int pRotation);
};

#endif // _PIECES_
