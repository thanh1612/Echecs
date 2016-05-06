#include "Piece.h"
#include <iostream>

Piece::Piece( int x, int y, bool white )
{
 //ctor
}

Piece::Piece()
{
  // ne fait rien => objet instancie mais non valide.
}

Piece::Piece(int x, int y, bool isWhite)
{
    m_x = x;
    m_y = y;
    m_white = isWhite;
}

void
Piece::init( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
}

void
Piece::move( int x, int y )
{
  m_x = x;
  m_y = y;
}

int
Piece::x()
{
  return m_x;
}

int
Piece::y()
{
  return m_y;
}

bool
Piece::isWhite()
{
  return m_white;
}

bool
Piece::isBlack()
{
    return !m_white;
}

void
Piece::affiche()
{
    cout << "Piece: x=" << m_x << " y=" << m_y << " " << endl;
}
