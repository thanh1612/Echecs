/** 
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include <cmath>
#include "Piece.h"
#include <iostream>
#include "Echiquier.h"
#include <typeinfo>
using namespace std;

Piece::Piece()
{
  cout << "Une Piece creee" << endl;
  // ne fait rien => objet instancie mais non valide.
  m_x=-1;
  m_y=-1;
}

Piece::Piece(int x, int y, bool isWhite)
{
    cout << "Une Piece creee" << endl;
    m_x = x;
    m_y = y;
    m_white = isWhite;
}

Piece::~Piece()
{
  cout << "Une piece detruite" << endl;
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

bool
Pion::mouvementValide(Echiquier &e, int x,int y){
    int m_x=Piece::x(),m_y=Piece::y();
    if (e.getPiece(m_x,m_y)->isWhite())
    {
      if (m_x==x && m_y==y-1 && (e.getPiece(x,y) == NULL) || 
         (m_x==x && m_y==y-2 && y<=4 && (e.getPiece(x,y) == NULL) &&  (e.getPiece(x,y-1) == NULL)))
          return true;

      else if ((m_x==x+1 || m_x==x-1) && m_y==y-1 && 
        e.getPiece(x,y)!=NULL && e.getPiece(x,y)->isBlack())
          return true;
    }

    if (e.getPiece(m_x,m_y)->isBlack())
    {
      if (m_x==x && m_y==y+1 && (e.getPiece(x,y) == NULL) || 
         (m_x==x && m_y==y+2 && y>4 && (e.getPiece(x,y) == NULL)) &&  (e.getPiece(x,y+1) == NULL))
          return true;

      else if ((m_x==x+1 || m_x==x-1) && m_y==y+1 && 
        e.getPiece(x,y)!=NULL && e.getPiece(x,y)->isWhite())
          return true;
    }        
    return false;
}


bool
Tour::mouvementValide(Echiquier &e, int x,int y){
  int m_x=Piece::x(),m_y=Piece::y();
  if ((x>=1 && x<=8 && y>=1 && y<=8) &&
    ((m_x!=x && m_y==y) || (m_x==x && m_y!=y)))
  {
    if (m_x<x)
      for (int i=m_x+1; i<x;i++)
        if (e.getPiece(i,y)!=NULL)
          return false;

    if (m_x>x)
      for (int i=m_x-1; i>x;i--)
        if (e.getPiece(i,y)!=NULL)
          return false;

    if (m_y<y)
      for (int i=m_y+1; i<y;i++)
        if (e.getPiece(x,i)!=NULL)
          return false;    

    if (m_y>y)
      for (int i=m_y-1; i>y;i--)
        if (e.getPiece(x,i)!=NULL)
          return false;

    if (e.getPiece(x,y)==NULL)
        return true;
    else 
      if ((e.getPiece(m_x,m_y)->isWhite() && e.getPiece(x,y)->isBlack()) ||
          (e.getPiece(m_x,m_y)->isBlack() && e.getPiece(x,y)->isWhite()))
          return true;
      else return false;
  }
  else return false;
}

bool
Fou::mouvementValide(Echiquier &e, int x,int y){
  int m_x=Piece::x(),m_y=Piece::y();
  if (x>=1 && x<=8 && y>=1 && y<=8)
  {
    bool position = false;
    if (m_x>x && m_y>y && m_x-x==m_y-y)
    {
      position = true;
      int k=m_y-1;
      for (int i=m_x-1;i>x;i--)
      {
        if (e.getPiece(i,k)!=NULL)
          return false;
        k-=1;
      }
    }

    if (m_x>x && m_y<y && m_x-x==y-m_y)
    {
      position = true;
      int k=m_y+1;
      for (int i=m_x-1;i>x;i--)
      {
        if (e.getPiece(i,k)!=NULL)
          return false;
        k+=1;
      }
    }

    if (m_x<x && m_y<y && x-m_x==y-m_y)
    {
      position = true;
      int k=m_y+1;
      for (int i=m_x+1;i<x;i++)
      {
        if (e.getPiece(i,k)!=NULL)
          return false;
        k+=1;
      }
    }

    if (m_x<x && m_y>y && x-m_x==m_y-y)
    {
      position = true;
      int k=m_y-1;
      for (int i=m_x+1;i<x;i++)
      {
        if (e.getPiece(i,k)!=NULL)
          return false;
        k-=1;
      }
    }

    if (position)
    {
      if (e.getPiece(x,y)==NULL)
        return true;
      else 
        if ((e.getPiece(m_x,m_y)->isWhite() && e.getPiece(x,y)->isBlack()) ||
            (e.getPiece(m_x,m_y)->isBlack() && e.getPiece(x,y)->isWhite()))
            return true;
    }
    else return false;
  }
  return false;
}

bool
Cavalier::mouvementValide(Echiquier &e, int x,int y){
  int m_x=Piece::x(),m_y=Piece::y();
  if ((x>=1 && x<=8 && y>=1 && y<=8) &&
    ((m_x==x-1 && m_y==y-2) || (m_x==x+1 && m_y==y-2) ||
      (m_x==x+2 && m_y==y-1) || (m_x==x+2 && m_y==y+1) ||
      (m_x==x+1 && m_y==y+2) || (m_x==x-1 && m_y==y+2) ||
      (m_x==x-2 && m_y==y-1) || (m_x==x-2 && m_y==y+1)))
    {
        if (e.getPiece(x,y)==NULL)
          return true;
        else 
          if (e.getPiece(x,y)!=NULL)
          {
            if((e.getPiece(m_x,m_y)->isWhite() && e.getPiece(x,y)->isBlack()) ||
              (e.getPiece(m_x,m_y)->isBlack() && e.getPiece(x,y)->isWhite()))
                return true;
          }
    } 
  else return false;
}

bool
Dame::mouvementValide(Echiquier &e, int x,int y){
  if (Fou::mouvementValide(e,x,y) || Tour::mouvementValide(e,x,y))
      return true;
  return false;
}

bool
Roi::mouvementValide(Echiquier &e, int x,int y){
  int m_x=Piece::x(),m_y=Piece::y();
  if (abs(m_x-x)<2 && abs(m_y-y)<2) // la difference valeur de position 
  {                                 // du Roi et la nouvelle position est entre 0->1
    if (Dame::mouvementValide(e,x,y))
      {
        for (int i=1;i<8;i++)
          for (int j=1;j<8;j++)
            if (e.getPiece(i,j)!=NULL && 
                ((e.getPiece(m_x,m_y)->isWhite() && e.getPiece(i,j)->isBlack()) ||
                (e.getPiece(m_x,m_y)->isBlack() && e.getPiece(i,j)->isWhite())))
            {
              if (typeid(*e.getPiece(i,j))!=typeid(Pion) && typeid(*e.getPiece(i,j))!=typeid(Roi))
                { // verifier la nouvelle position si il y a autre(s) piece(s) 
                  // peut deplacer sur cette position, return false;
                  if (e.getPiece(i,j)->mouvementValide(e,x,y))
                    return false;
                }
              else {
                e.deplacer(e.getPiece(m_x,m_y),x,y); // deplacer le Roi sur la nouvelle position pour 
                                                    // verifier si il y a le Pion qui peut tuer le Roi ou pas
                for (int m=1;m<=8;m++)
                  for (int n=1;n<=8;n++)
                  {
                    if (e.getPiece(m,n)!=NULL && typeid(*e.getPiece(m,n))!=typeid(Roi) &&
                      ((e.getPiece(x,y)->isWhite() && e.getPiece(m,n)->isBlack()) ||
                      (e.getPiece(x,y)->isBlack() && e.getPiece(m,n)->isWhite())) && 
                      e.getPiece(m,n)->mouvementValide(e,x,y))
                      {
                        e.deplacer(e.getPiece(x,y),m_x,m_y); // Redeplacer le Roi a la courrant position.
                        return false;
                      }
                  }
                e.deplacer(e.getPiece(x,y),m_x,m_y); // Redeplacer le Roi a la courrant position.
                return true;
              }
            }
        return true;    
      }
  }
  return false;
}