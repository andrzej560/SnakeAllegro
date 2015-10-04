#pragma once
#include "Reakcja.h"

class Owoc: public Reakcja{
private:
 int _pozycjaX;
 int _pozycjaY;
 

public:
	Owoc();
	~Owoc();
	void Aktualizuj(BITMAP *b);
	void Rysuj(BITMAP *b);
	void ustawX(int val);
	void ustawY(int val);

	int pobierzX();
	int pobierzY();
};