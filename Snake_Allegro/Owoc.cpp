#include "Owoc.h"




Owoc::Owoc(){
	srand(time(NULL));

	_pozycjaX= (rand()%39)+1;
	_pozycjaY = (rand()%29)+1;
}


void Owoc::ustawX(int val){
	_pozycjaX = val;
}
void Owoc::ustawY(int val){
	_pozycjaY = val;
}
int Owoc::pobierzX(){
	return _pozycjaX;
}
int Owoc::pobierzY(){
	return _pozycjaY;
}


void Owoc::Aktualizuj(BITMAP *b){
	srand(time(NULL));

	_pozycjaX= (rand()%39)+1;
	_pozycjaY = (rand()%29)+1;
	rectfill( b, 20*_pozycjaX, 20*_pozycjaY, 20+20*_pozycjaX, 20+20*_pozycjaY, makecol( 0, 255, 0 ) ); 

}


void Owoc::Rysuj(BITMAP *b){
	
	rectfill( b, 20*_pozycjaX, 20*_pozycjaY, 20+20*_pozycjaX, 20+20*_pozycjaY, makecol( 0, 255, 0 ) ); 

}