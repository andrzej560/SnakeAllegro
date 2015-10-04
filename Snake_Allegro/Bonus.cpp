#pragma once
#include "Bonus.h"



int _pozycjaX = 0;
int _pozycjaY = 0;

Bonus::Bonus(){
	 _pozycjaX = 0;
	 _pozycjaY = 0;
}

Bonus::Bonus(int X, int Y){
	_pozycjaX = X;
	_pozycjaY = Y;

}

Bonus::~Bonus(){}

void Bonus::Rysuj(BITMAP *b){
	rectfill( b, 20*_pozycjaX, 20*_pozycjaY, 20+20*_pozycjaX, 20+20*_pozycjaY, makecol( 255, 255, 0 ) ); 
}
int Bonus::pobierzX(){return _pozycjaX;}
int Bonus::pobierzY(){return _pozycjaY;}

void Bonus::Aktualizuj(BITMAP *b){
	
srand(time(NULL));

	_pozycjaX= (rand()%39)+1;
	_pozycjaY = (rand()%29)+1;
	rectfill( b, 20*_pozycjaX, 20*_pozycjaY, 20+20*_pozycjaX, 20+20*_pozycjaY, makecol( 0, 255, 0 ) ); 

}


void Bonus::ustawXY(int X, int Y){

	_pozycjaX = X;
	_pozycjaY = Y;

}