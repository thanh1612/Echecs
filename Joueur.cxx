#include "Joueur.h"
#include <iostream>
#include <typeinfo>

using namespace std;

Joueur::Joueur()
{
	cout << "Joueur cree." << endl;
}

Joueur::~Joueur(){
	cout << "Joueur destruire." << endl;
}

void Joueur::affiche()
{
	for (int i=0;i<16;i++)
		p[i]->affiche();
}

void Joueur::placer(Echiquier &e)
{
    for(int i=0; i<16; i++)
        e.placer(p[i]);
}
