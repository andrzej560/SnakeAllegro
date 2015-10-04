#pragma once
#include "Ob_Statyczny.h"

class Reakcja: public Ob_Statyczny
{
public:
	Reakcja();
	~Reakcja();
	virtual void Rysuj(BITMAP *b)=0;
	virtual void Aktualizuj(BITMAP *b)=0;
	virtual int pobierzX()=0;
	virtual int pobierzY()=0;

};