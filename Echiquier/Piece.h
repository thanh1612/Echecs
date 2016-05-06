#ifndef PIECE_H
#define PIECE_H


class Piece
{
private:
  int m_x;
  int m_y;
  bool m_white;

public:
  Piece();
  Piece(int x, int y, bool white);
  void init( int x, int y, bool white );
  void move( int x, int y );
  int x();
  int y();
  bool isWhite();
  bool isBlack();
  void affiche();
};

#endif // PIECE_H
