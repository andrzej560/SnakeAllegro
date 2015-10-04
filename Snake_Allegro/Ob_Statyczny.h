#pragma once

#include "Ob_Graficzny.h"

class Ob_Statyczny: public Ob_Graficzny{
public:
	Ob_Statyczny();
	Ob_Statyczny(int x, int y);
	static void Rysuj();

};