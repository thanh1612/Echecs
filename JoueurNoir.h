#ifndef JOUEURNOIR_H
#define JOUEURNOIR_H
#include "Joueur.h"

class JoueurNoir : public Joueur
{
public:
    JoueurNoir();
    virtual void initialiserPieces();
    void jouer(Echiquier &e);
    void choisirPiece(Echiquier &e);
    void choisirPosition(Echiquier &e, Piece *p);
    bool EstFinJeu(Echiquier &e);
    bool Sacrifier(int x,int y,int x_roi,int y_roi,Echiquier &e);
    int Total_MouvementValide(int x_roi,int y_roi, Echiquier &e);
    bool EstEncoreEchecEtMat(Echiquier &e);
};
#endif