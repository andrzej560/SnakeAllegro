#include "Napis.h"

void Napis::Rysuj(char wyraz[20], int punktyP, int xx, int yy, BITMAP*b){

	 textprintf_ex(b, font, xx, yy, makecol(255, 100, 200),
                    -1, "%s %d",wyraz, punktyP);
}

void Napis::Rysuj(char wyraz[20],  int xx, int yy, BITMAP *b){
	
	 textprintf_ex(b, font, xx, yy, makecol(255, 100, 200),
                    -1, "%s",wyraz);
}