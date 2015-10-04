#pragma once
#include "Ob_Dynamiczny.h"
#include <vector>

class Snake: public Ob_Dynamiczny{
public:
	
	int predkosc;
	static int kierunek;
	
	 static int dlugosc;
	
	 static std::vector < int > pozycjaX;
	 static std::vector < int > pozycjaY;
	 static std::vector < int > tmpX;
	 static std::vector < int > tmpY;


	 static std::vector < int >::iterator iter;


	Snake(int x, int y, BITMAP *b);
	~Snake();
	
	
	static void Aktualizuj();
	void Akcja();
	static bool Sprawdz();
	static void Rysuj(BITMAP *b);
	static void Wypisz();
	
};


