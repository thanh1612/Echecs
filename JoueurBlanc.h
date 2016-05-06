#ifndef JOUEURBLANC_H
#define JOUEURBLANC_H
#include "Joueur.h"

class JoueurBlanc : public Joueur
{
public:
    JoueurBlanc();
    virtual void initialiserPieces();
    void jouer(Echiquier &e);
    void choisirPiece(Echiquier &e);
    void choisirPosition(Echiquier &e, Piece *p);
    bool EstFinJeu(Echiquier &e);
    bool Sacrifier(int x,int y,int x_roi,int y_roi,Echiquier &e);
    int Total_MouvementValide(int x,int y, Echiquier &e);
    bool EstEncoreEchecEtMat(Echiquier &e);
};
#endif