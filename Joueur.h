#ifndef JOUEUR_H
#define JOUEUR_H

#include "Piece.h"
#include "Echiquier.h"

class Joueur: public Piece
{
protected:
	Piece * p[16];
	bool m_white;
	virtual void initialiserPieces() = 0;
public:
	Joueur();
	virtual ~Joueur();
	void affiche();
	void placer(Echiquier &e);

};

#endif