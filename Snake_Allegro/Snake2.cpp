#include "Snake.h"
#include "Snake2.h"
#include <iostream>
using namespace std;
int Snake2::dlugosc = 0;
int Snake2::kierunek = 1; //bool PRAWO   PRAWO/GÓRA/LEWO/DÓ£


vector < int > Snake2::pozycjaX;
vector < int > Snake2::pozycjaY;
vector < int > Snake2::tmpX;
vector < int > Snake2::tmpY;
vector < int >::iterator Snake2::iter;

Snake2::Snake2(int x, int y, BITMAP *b){
	pozycjaX.push_back(x);
	pozycjaY.push_back(x);
	tmpX.push_back(x);
	tmpY.push_back(x);
	rectfill( b, 20*pozycjaX[0], 20*pozycjaY[0], 20+20*pozycjaX[0], 20+20*pozycjaY[0], makecol( 0, 0, 255 ) ); 
}

Snake2::~Snake2(){

}

void Snake2::Rysuj(BITMAP *b){
	rectfill( b, 20*pozycjaX[0], 20*pozycjaY[0], 20+20*pozycjaX[0], 20+20*pozycjaY[0], makecol( 255, 100, 255 ) );

	for(int i=1;i<=dlugosc;i++){
	
		rectfill( b, 20*pozycjaX[i], 20*pozycjaY[i], 20+20*pozycjaX[i], 20+20*pozycjaY[i], makecol( 255, 150, 150 ) ); 
	}


}
bool Snake2::Sprawdz(){
		
		for(int i = 1;i<=dlugosc;i++){
				if (( pozycjaX[0] == pozycjaX[i]) && (pozycjaY[0] == pozycjaY[i])){
					
					return false;}
			}

		for(int i = 0;i<=Snake::dlugosc;i++){	
				if (( pozycjaX[0] == Snake::pozycjaX[i]) && (pozycjaY[0] == Snake::pozycjaY[i])){
					
					return false;}
						} 


			if ((pozycjaX[0]<0) ||   (pozycjaX[0]>39) ||   (pozycjaY[0]<0)  ||   (pozycjaY[0]>29)           ){
				
					return false;
			}

	return true;

}

void Snake2::Aktualizuj(){
	

		for(int i = 0;i<=dlugosc;i++){
			tmpX[i] = pozycjaX[i];
			tmpY[i] = pozycjaY[i];
		}

				if( (key[ KEY_A]) && (kierunek!=1) )kierunek=3;
				if( key[ KEY_D ] && (kierunek!=3)) kierunek=1;
				if( key[ KEY_W ] && (kierunek!=4)) kierunek=2;
				if( key[ KEY_S ] && (kierunek!=2)) kierunek=4;

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

void Snake2::Wypisz(){
	
		
		cout << "Dlugosc: "<< dlugosc<<'\n';
		cout << "Pozycje weza nr 2:"<<'\n';
		int i = 0;
		 for( iter=pozycjaX.begin(); iter!=pozycjaX.end(); ++iter )
		   {
			 cout<< *iter  << " - " << pozycjaY[i]<<'\n';
			 i++;
		   }

	}
	

