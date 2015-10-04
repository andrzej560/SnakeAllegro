#include "Snake.h"
#include "Snake2.h"
#include <iostream>
using namespace std;
int Snake::dlugosc = 0;
int Snake::kierunek = 1; //bool PRAWO   PRAWO/GÓRA/LEWO/DÓ£


vector < int > Snake::pozycjaX;
vector < int > Snake::pozycjaY;
vector < int > Snake::tmpX;
vector < int > Snake::tmpY;
vector < int >::iterator Snake::iter;

Snake::Snake(int x, int y, BITMAP *b){
	pozycjaX.push_back(x);
	pozycjaY.push_back(x);
	tmpX.push_back(x);
	tmpY.push_back(x);
	rectfill( b, 20*pozycjaX[0], 20*pozycjaY[0], 20+20*pozycjaX[0], 20+20*pozycjaY[0], makecol( 0, 0, 255 ) ); 
}

Snake::~Snake(){

}

void Snake::Rysuj(BITMAP *b){
	rectfill( b, 20*pozycjaX[0], 20*pozycjaY[0], 20+20*pozycjaX[0], 20+20*pozycjaY[0], makecol( 0, 255, 255 ) );

	for(int i=1;i<=dlugosc;i++){
	
		rectfill( b, 20*pozycjaX[i], 20*pozycjaY[i], 20+20*pozycjaX[i], 20+20*pozycjaY[i], makecol( 0, 0, 255 ) ); 
	}


}
bool Snake::Sprawdz(){
		
		for(int i = 1;i<=dlugosc;i++){
				if (( pozycjaX[0] == pozycjaX[i]) && (pozycjaY[0] == pozycjaY[i])){
					
					return false;	}
			}
	if (Snake2::dlugosc>0){
		for(int i = 0;i<=Snake2::dlugosc;i++){	
				if (( pozycjaX[0] == Snake2::pozycjaX[i]) && (pozycjaY[0] == Snake2::pozycjaY[i])){
				
					return false;}
			} 
	}


		if ((pozycjaX[0]<0) ||   (pozycjaX[0]>39) ||   (pozycjaY[0]<0)  ||   (pozycjaY[0]>29)           ){
			
					return false;
			}
	
			
			return true;

}

void Snake::Aktualizuj(){
	

		for(int i = 0;i<=dlugosc;i++){
			tmpX[i] = pozycjaX[i];
			tmpY[i] = pozycjaY[i];
		}

				if( (key[ KEY_LEFT ]) && (kierunek!=1) )kierunek=3;
				if( key[ KEY_RIGHT ] && (kierunek!=3)) kierunek=1;
				if( key[ KEY_UP ] && (kierunek!=4)) kierunek=2;
				if( key[ KEY_DOWN ] && (kierunek!=2)) kierunek=4;

				switch(kierunek)
				{
				case 1:  pozycjaX[0]++;  break;             
				case 2:  pozycjaY[0]--; break;
				case 3: pozycjaX[0]--;  break;
				case 4:	pozycjaY[0]++; break;
				}

		for(int i = 1;i<=dlugosc;i++){
			pozycjaX[i] = tmpX[i-1];
			pozycjaY[i] = tmpY[i-1];
		}

	

}

void Snake::Wypisz(){
	
		
		cout << "Dlugosc: "<< dlugosc<<'\n';
		cout << "Pozycje weza:"<<'\n';
		int i = 0;
		 for( iter=pozycjaX.begin(); iter!=pozycjaX.end(); ++iter )
		   {
			 cout<< *iter  << " - " << pozycjaY[i]<<'\n';
			 i++;
		   }

	}
	

