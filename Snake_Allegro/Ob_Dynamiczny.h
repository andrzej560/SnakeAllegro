#pragma once
#include "Ob_Graficzny.h"

class Ob_Dynamiczny: public Ob_Graficzny
{
public:
	Ob_Dynamiczny();
	Ob_Dynamiczny(int xx, int yy);
	~Ob_Dynamiczny();
	bool Sprawdz();
	


};