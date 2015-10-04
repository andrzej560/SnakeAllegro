#pragma once
#include "Reakcja.h"

class Bonus: public Reakcja{
private:
	int _pozycjaX;
	int _pozycjaY;

public:
	Bonus();
	Bonus(int X, int Y);
	~Bonus();
	void Rysuj(BITMAP *b);
	void Aktualizuj(BITMAP *b);
	void ustawXY(int X, int Y);
	int pobierzX();
	int pobierzY();

};