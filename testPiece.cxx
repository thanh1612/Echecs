/** 
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"
#include <cstdlib>

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;


/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  // instancie un objet p1 de type Piece
  //  Piece p1,p2(4,4,false);
  // p1 est une piece blanche de coordonnees (3,3)
  //p1.init( 3, 3, true );
 // p2.init( 5, 5, false);

  /*Piece * tab[4];
  tab[0] = new Piece (1,2,true);
  tab[1] = new Piece (2,3,false);
  tab[2]= new Piece(3,2,true);
  tab[3]= new Piece(6,2,false);
  for (int i =0; i<4;i++)
    tab[i]->affiche();

  // On l'affiche
   cout << "Piece: x=" << p1.x() << " y=" << p1.y() << " "
       << ( p1.isWhite() ? "blanche" : "noire" ) << endl;

  cout << "Piece: x=" << p2.x() << " y=" << p2.y() << " "
       << ( p2.isWhite() ? "blanche" : "noire" ) << endl;*/

  Echiquier e;
  JoueurBlanc j_white;
  j_white.placer(e);
  JoueurNoir j_black;
  j_black.placer(e);
  system("clear");
  bool finJeux = false;
  bool TourdeJoueur = true;
  int k=0;
  while (!finJeux)
    {
      if (TourdeJoueur)
      {
        j_white.jouer(e);
        if (j_white.EstEncoreEchecEtMat(e))
          break;
        TourdeJoueur = false;
        finJeux=j_black.EstFinJeu(e);
      }
      else
      {
        j_black.jouer(e);
        if (j_black.EstEncoreEchecEtMat(e))
          break;
        TourdeJoueur = true;
        finJeux=j_white.EstFinJeu(e);        
      }
    }
    e.affiche();
    cout << "\t\t\t\tFIN" << endl;
    if (TourdeJoueur)
      cout << "\t\t\tJoueurNoir gagne!" << endl;
    else cout << "\t\t\tJoueurBlanc gagne!" << endl;

  // les objets definis dans cette fonction sont automatiquement détruits.
  // Ex : p1
}
