/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"


// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;


/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  // instancie un objet p1 de type Piece
    Piece p1,p2(4,4,false);
  // p1 est une piece blanche de coordonnees (3,3)
  p1.init( 3, 3, true );


  // On l'affiche

    cout << "Piece: x=" << p1.x() << " y=" << p1.y() << " "
       << ( p1.isWhite() ? "blanche" : "noire" ) << endl;

  cout << "Piece: x=" << p2.x() << " y=" << p2.y() << " "
       << ( p2.isWhite() ? "blanche" : "noire" ) << endl;

  // les objets definis dans cette fonction sont automatiquement détruits.
  // Ex : p1
}

