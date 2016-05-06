/** 
 * Header de Piece.cxx
 *
 * @file Piece.h
 */
#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>

using namespace std;

class Echiquier;
/**
 * Declaration d'une classe modélisant une piece de jeu d'echec.
 */
class Piece 
{
private:
  int m_x;
  int m_y;
  bool m_white;  
  
public:
  Piece();
  Piece(int x, int y, bool white);
  virtual ~Piece();
  void init( int x, int y, bool white );
  void move( int x, int y );
  int x();
  int y();
  bool isWhite();
  bool isBlack();
  void affiche();
  virtual bool mouvementValide(Echiquier &e, int x, int y){};
}; 



class Fou: virtual public Piece // Tuong
{ 
public:
  Fou( int x, int y, bool white) : Piece(x,y,white){}
  bool mouvementValide(Echiquier &e, int x, int y);
};



class Tour: virtual public Piece // Xe
{
public:
  Tour(int x, int y, bool white) : Piece(x,y,white){}
  bool mouvementValide(Echiquier &e, int x, int y);
};



class Dame: public Tour, Fou // Hau
{
public:
  Dame(int x, int y, bool white) : Tour(x,y,white),Fou(x,y,white), Piece(x,y,white) {}
  bool mouvementValide(Echiquier &e, int x, int y);
};



class Roi: public Dame
{
public:
  Roi(int x, int y, bool white) : Dame(x,y,white), Piece(x,y,white){ }
  bool mouvementValide(Echiquier &e, int x, int y);
};



class Cavalier: virtual public Piece // Ma
{
public:
  Cavalier(int x, int y, bool white) : Piece(x,y,white){}
  bool mouvementValide(Echiquier &e, int x, int y);
};



class Pion: virtual public Piece // Tot
{
  public:
  Pion(int x, int y, bool white) : Piece(x,y,white) {}
  bool mouvementValide(Echiquier &e, int x, int y);

};

#endif // !defined Piece_h
