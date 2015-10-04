#pragma once
#include "Ob_Statyczny.h"



class Napis: public Ob_Statyczny{
public:
Napis();
~Napis();
 static void Rysuj(char wyraz[20],int punktyP, int xx, int yy, BITMAP *b);
 static void Rysuj(char wyraz[20], int xx, int yy, BITMAP *b);
};