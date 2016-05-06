/** 
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cxx
 */

#include <iostream>
// A besoin de la declaration de la classe
#include "Echiquier.h"
#include <typeinfo>
using namespace std;

/**
 * Constructeur par défaut.
 * Initialise à vide l'echiquier.
 */
Echiquier::Echiquier()
{
	for (int i=0; i<64; i++)
        m_cases[i] = NULL;
}


/**
 * Recupere la piece situee sur une case.
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
Piece* Echiquier::getPiece( int x, int y )
{
    int n = (x-1)+(y-1)*8;
        return (n < 64) ? m_cases[n] : NULL;
}

  
/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool Echiquier::placer( Piece* p )
{
	int n = (p->x()-1)+(p->y()-1)*8;
	    if (m_cases[n] == NULL && n < 64)
		{
			m_cases[n] = p;
			return true;
		}
		else
	        return false;
}


/**
 * Deplace une piece sur l'echiquier, des coordonnees specifiees
 * dans la piece aux coordonnees x,y. 
 *
 * @param p un pointeur vers une piece
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide, piece pas
 * presente au bon endroit sur l'echiquier)
 */
bool Echiquier::deplacer( Piece* p, int x, int y )
{
	int n = (x-1)+(y-1)*8;
	if(p!=NULL && m_cases[n]==NULL && n <64) // case n'a pas piece
	{
		enleverPiece(p->x(),p->y()); // enlever la position courrant de piece p dans la liste de cases
		p->move(x,y);                // deplacer sur la nouvelle position       
		m_cases[n] = p;				 // sauvegarder la nouvelle position
		return true;
	}
	else
	{
		if ((m_cases[n]!=NULL)  && // case a une piece
			 ((p->isWhite() && m_cases[n]->isBlack()) || (p->isBlack() && m_cases[n]->isWhite())))
			{
				enleverPiece(p->x(),p->y());
				p->move(x,y);
				m_cases[n]=p;
				return true;
			}
    }
	return false;
}


/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
Piece* Echiquier::enleverPiece( int x, int y )
{
	int n = (x-1)+(y-1)*8;
	if ((x>=1) && (x<=8) && (y>=1) && (y<=8) && getPiece(x,y)!=NULL){
		Piece * tmp=m_cases[n];
		m_cases[n]=NULL;
		return tmp;
	}	
	return NULL;
}


/**
 * Affiche l'echiquier avec des - pour les cases noires et + pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */
void Echiquier::affiche() // Il y a quelque complement dans l'affiche pour ajouter le couleur.
{
  cout << "\n";
  cout << "\t\t\t  "<<"\033[1;31m*\033[0m"<<"\033[1;32m----------------\033[0m"<<"\033[1;31m*\033[0m" << endl;
  for ( int y = 8; y >= 1; y-- )
    {
      cout <<"\t\t\t\033[1;36m"<< y << " \033[1;32m|\033[0m";
      for ( int x = 1; x <= 8; x++ )
	{
	  string s;
	  Piece* p = getPiece( x, y );
	  if ( p == 0 ) 
		s = ( ( x + y ) % 2 ) == 0 ? "\033[1;36m+\033[0m" : "\033[1;33m+\033[0m";
	  else
	    {
	    	if (p->isWhite())
	    	{
		    	if (typeid(*p) == typeid(Fou)) s = "\033[1;37mF\033[0m";
		    	if (typeid(*p) == typeid(Tour)) s = "\033[1;37mT\033[0m";
		    	if (typeid(*p) == typeid(Cavalier)) s = "\033[1;37mC\033[0m";
				if (typeid(*p) == typeid(Dame)) s = "\033[1;37mD\033[0m";
				if (typeid(*p) == typeid(Roi)) s = "\033[1;37mR\033[0m";
				if (typeid(*p) == typeid(Pion)) s = "\033[1;37mP\033[0m";
			}
			else 
			{
				if (typeid(*p) == typeid(Fou)) s = "\033[1;30mF\033[0m";
		    	if (typeid(*p) == typeid(Tour)) s = "\033[1;30mT\033[0m";
		    	if (typeid(*p) == typeid(Cavalier)) s = "\033[1;30mC\033[0m";
				if (typeid(*p) == typeid(Dame)) s = "\033[1;30mD\033[0m";
				if (typeid(*p) == typeid(Roi)) s = "\033[1;30mR\033[0m";
				if (typeid(*p) == typeid(Pion)) s = "\033[1;30mP\033[0m";
			}
	    }
	  cout << s <<" ";
	}	
      cout << "\033[1;32m|\033[0m " << endl;
    }
    cout << "\t\t\t  "<<"\033[1;31m*\033[0m"<<"\033[1;32m----------------\033[0m"<<"\033[1;31m*\033[0m" << endl;
  cout << "\t\t\t   \033[1;33ma b c d e f g h\033[0m" << endl;
}

