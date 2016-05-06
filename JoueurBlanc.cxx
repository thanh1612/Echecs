#include "JoueurBlanc.h"
#include <string>
#include <iostream>
#include <typeinfo>
#include "Piece.h"
#include <cstdlib>

using namespace std;

JoueurBlanc::JoueurBlanc()
{
	initialiserPieces();
}

void JoueurBlanc::initialiserPieces() // creer piece
{
	for (int i = 0; i < 16 ; i++)
		{
			if (((i%8)+1==3 || (i%8)+1==6) && i<8)
				p[i] = new Fou((i%8)+1, 1,true);
			else if (((i%8)+1==2 || (i%8)+1==7) && i<8)
				p[i] = new Cavalier((i%8)+1, 1,true);
			else if (((i%8)+1==1 || (i%8)+1==8) && i<8)
				p[i] = new Tour((i%8)+1, 1,true);
			else if ((i%8)+1==4 &&  i<8)
				p[i] = new Dame ((i%8)+1, 1,true);
			else if ((i%8)+1==5 &&  i<8)
				p[i] = new Roi ((i%8)+1, 1,true);
			else if (i>=8)
				p[i] = new Pion ((i%8)+1, 2,true);
		}
}

void JoueurBlanc::jouer(Echiquier &e)
{
	choisirPiece(e);
}

void JoueurBlanc::choisirPiece(Echiquier &e) // choisir Piece pour deplacer
{
	int x,y;
	string position="";
	cout << endl;
	e.affiche();
	cout << "\n\t\t\t Au BLANC de joueur.\n" << endl;
	cout << "Choisir la position du piece(ex: a2): ";
	cin >> position;
	if (position[2]!='\0' && position[2]!=' ')  // verifier si il y a un erreur d'entrer la position
	{
		system("clear"); 
		cout << "\033[1;31m\t\t\t  Erreur! Reessayer!\033[0m" ; 
		choisirPiece(e); 
		return;
	}
	switch (position[0])
	{
		case 'a': case 'A': x=1; break;
		case 'b': case 'B': x=2; break;
		case 'c': case 'C': x=3; break;
		case 'd': case 'D': x=4; break;
		case 'e': case 'E': x=5; break;
		case 'f': case 'F': x=6; break;
		case 'g': case 'G': x=7; break;
		case 'h': case 'H': x=8; break;
		default: system("clear"); 
				cout << "\033[1;31m\t\t   La position du piece n'existe pas!\033[0m\n"; 
				choisirPiece(e);
				return;
	}

	switch (position[1])
	{
		case '1': y=1; break;
		case '2': y=2; break;
		case '3': y=3; break;
		case '4': y=4; break;
		case '5': y=5; break;
		case '6': y=6; break;
		case '7': y=7; break;
		case '8': y=8; break;
		default: system("clear"); 
				cout << "\033[1;31m\t\t   La position du piece n'existe pas!\033[0m";
				choisirPiece(e); 
				return;
	}
	Piece* p = e.getPiece(x,y);
	if ( p == 0 )
	{
		system("clear");
		cout << "\033[1;31m\t\t     La position n'a pas de Piece!\033[0m"; 
		choisirPiece(e);
	}
	else
		if (p->isWhite())
		{
			system("clear"); cout << endl;
			e.affiche();
			cout << "\n\t\t\t Au BLANC de joueur.\n" << endl;
			cout << "Choisir la position du piece: " << position;
	    	if (typeid(*p) == typeid(Fou)) cout << " (Fou)" << endl;
	    	if (typeid(*p) == typeid(Tour)) cout << " (Tour)" << endl;
	    	if (typeid(*p) == typeid(Cavalier)) cout << " (Cavalier)" << endl;
			if (typeid(*p) == typeid(Dame)) cout << " (Dame)" << endl;
			if (typeid(*p) == typeid(Roi)) cout << " (Roi)" << endl;
			if (typeid(*p) == typeid(Pion)) cout << " (Pion)" << endl;
			choisirPosition(e,p);
		}
		else 
		{
			system("clear");
			cout << "\033[1;31m\t\t Erreur! Le piece est de JoueurNoir!\033[0m";
			choisirPiece(e);
		}
	return;
}

void JoueurBlanc::choisirPosition(Echiquier &e, Piece *p) // choisir la position pour deplacer
{
	string mouvement="";
	int x,y;
	cout << "Choisir la position pour mouvement(ex: a3): ";
	cin >> mouvement;
	if (mouvement[2]!='\0' && mouvement[2]!=' ')  // verifier si il y a un erreur d'entrer la position
	{
		system("clear"); 
		cout << "\033[1;31m\t\t\t  Erreur! Reessayer!\033[0m" << endl;
		choisirPosition(e,p);
		return;
	}
	switch (mouvement[0])
	{
		case 'a': case 'A': x=1; break;
		case 'b': case 'B': x=2; break;
		case 'c': case 'C': x=3; break;
		case 'd': case 'D': x=4; break;
		case 'e': case 'E': x=5; break;
		case 'f': case 'F': x=6; break;
		case 'g': case 'G': x=7; break;
		case 'h': case 'H': x=8; break;
		default:	system("clear");
					cout << endl;
					e.affiche(); 
					cout << "\033[1;31m\n\t\tLa position pour deplacer est erreur!\033[0m\n\n";
					choisirPosition(e,p); 
					break;
	}

	switch (mouvement[1])
	{
		case '1': y=1; break;
		case '2': y=2; break;
		case '3': y=3; break;
		case '4': y=4; break;
		case '5': y=5; break;
		case '6': y=6; break;
		case '7': y=7; break;
		case '8': y=8; break;
		default: 	system("clear");
					cout << endl;
					e.affiche(); 
					cout << "\033[1;31m\n\t\tLa position pour deplacer est erreur!\033[0m\n\n";
					choisirPosition(e,p); 
					break;
	}
	
	if (p->mouvementValide(e,x,y)) // si la position x,y est valide, afficher le succes de deplacer
	{
		system("clear");
		if (typeid(*p) == typeid(Fou)) cout << "\t\t\tFou: ";
	    if (typeid(*p) == typeid(Tour)) cout << "\t\t\tTour: ";
    	if (typeid(*p) == typeid(Cavalier)) cout << "\t\t\tCavalier: ";
		if (typeid(*p) == typeid(Dame)) cout << "\t\t\tDame: ";
		if (typeid(*p) == typeid(Roi)) cout << "\t\t\tRoi: ";
		if (typeid(*p) == typeid(Pion)) cout << "\t\t\tPion: ";
		switch(p->x())
		{
			case 1: cout << "a"; break;
			case 2: cout << "b"; break;
			case 3: cout << "c"; break;
			case 4: cout << "d"; break;
			case 5: cout << "e"; break;
			case 6: cout << "f"; break;
			case 7: cout << "g"; break;
			case 8: cout << "h"; break;
		}
		cout << p->y() << " to ";
		switch(x)
		{
			case 1: cout << "a"; break;
			case 2: cout << "b"; break;
			case 3: cout << "c"; break;
			case 4: cout << "d"; break;
			case 5: cout << "e"; break;
			case 6: cout << "f"; break;
			case 7: cout << "g"; break;
			case 8: cout << "h"; break;
		}
		cout << y;
		e.deplacer(p,x,y);
		cout << " Successly!";
	}
	else {
		system("clear");
		cout << "\033[1;31m\t\t\t  Mouvement invalide...\033[0m";
		choisirPiece(e);
	}
	return;
}

bool JoueurBlanc::EstFinJeu(Echiquier &e){  // verifier le Roi etait echec et mat ou pas
	int x_roi,y_roi;
	for (int i = 0; i < 16 ; i++)
	{
		if (p[i]!=NULL && typeid(*p[i]) == typeid(Roi))
		{
			x_roi=p[i]->x();
			y_roi=p[i]->y();
			break;
		}
	}
	for (int x=1;x<=8;x++)
		for (int y=1;y<=8;y++)
			if (e.getPiece(x,y)!=NULL && e.getPiece(x,y)->isBlack())
			{
				if (e.getPiece(x,y)->mouvementValide(e,x_roi,y_roi)) // le Roi est echec et mat 
					{												// par un piece noir.
						cout << "\033[1;31mSystem: JoueurBlanc est pres de perdre. Faire plus attention!!!\033[0m"<< endl;
						if (Total_MouvementValide(x_roi,y_roi,e)==0)  // si le Roi n'a pas de position pour deplacer 
							{
								if (Sacrifier(x,y,x_roi,y_roi,e)) // if quelque(s) piece(s) peuvent 
									return false;					// etre sacrifie pour le Roi, return false
								else return true;     			// sinon, fin du jeu
							}
						else return false;  
					}
			}
	if (Total_MouvementValide(x_roi,y_roi,e)==0) // si le Roi ne peut pas deplacer sur aucune position
		{										// et tous les autres pieces aussi, fin du jeu
			for (int x=1;x<=8;x++)				
				for (int y=1;y<=8;y++)
					if (e.getPiece(x,y)!=NULL && e.getPiece(x,y)->isWhite())
						if (Total_MouvementValide(x,y,e)!=0)
								return false;
		}
	else return false;
	return true;				
}

bool JoueurBlanc::Sacrifier(int x,int y,int x_roi,int y_roi,Echiquier &e) 
{ // verifier si il y a au moins d'un piece peut sacrifie pour le Roi, return true, false sinon.
	for (int m=1;m<=8;m++)
		for (int n=1;n<=8;n++)
			if (e.getPiece(m,n)!=NULL && e.getPiece(m,n)->isWhite()) 
			{
				Piece *p=e.getPiece(m,n);
				if (p->mouvementValide(e,x,y))
					return true;
				if (x==x_roi && y>y_roi)
					for (int k=y-1;k>y_roi;k--)
						if (p->mouvementValide(e,x,k))
							return true;
				if (x==x_roi && y<y_roi)
					for (int k=y+1;k<y_roi;k++)
						if (p->mouvementValide(e,x,k))
							return true;
				if (x>x_roi && y==y_roi)
					for (int k=x-1;k>x_roi;k--)
						if (p->mouvementValide(e,k,y))
							return true;
				if (x<x_roi && y==y_roi)
					for (int k=x+1;k<x_roi;k++)
						if (p->mouvementValide(e,k,y))
							return true;
				if (x<x_roi && y>y_roi)
				{
					int l=x+1;
					for (int k=y-1;k>y_roi;k--)
						{
							if (p->mouvementValide(e,l,k))
								return true;
							l+=1;
						}
				}
				if (x<x_roi && y<y_roi)
				{
					int l=x+1;
					for (int k=y+1;k<y_roi;k++)
						{
							if (p->mouvementValide(e,l,k))
								return true;
							l+=1;
						}
				}
				if (x>x_roi && y<y_roi)
				{
					int l=x-1;
					for (int k=y+1;k<y_roi;k++)
						{
							if (p->mouvementValide(e,l,k))
								return true;
							l-=1;
						}
				}
				if (x>x_roi && y>y_roi)
				{
					int l=x-1;
					for (int k=y-1;k>y_roi;k--)
						{
							if (p->mouvementValide(e,l,k))
								return true;
							l-=1;
						}
				}												
			}
	return false;	
}

int JoueurBlanc::Total_MouvementValide(int x,int y, Echiquier &e)
{ // Compte le nombre total de mouvement valide de piece.
	int nb=0;
	Piece *p=e.getPiece(x,y);
	for (int i=1; i<=8; i++)
		for (int j=1; j<=8; j++)
			if (p->mouvementValide(e,i,j))
				nb+=1;
	return nb;
}

bool JoueurBlanc::EstEncoreEchecEtMat(Echiquier &e){ // verifier si le Roi est echec et mat ou pas
	int x_roi,y_roi;
	for (int i = 0; i < 16 ; i++)
	{
		if (p[i]!=NULL && typeid(*p[i]) == typeid(Roi))
		{
			x_roi=p[i]->x();
			y_roi=p[i]->y();
			break;
		}
	}
	for (int x=1;x<=8;x++)
		for (int y=1;y<=8;y++)
			if (e.getPiece(x,y)!=NULL && e.getPiece(x,y)->isBlack())
				if (e.getPiece(x,y)->mouvementValide(e,x_roi,y_roi))
					return true;
	return false;
}