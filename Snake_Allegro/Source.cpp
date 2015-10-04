#define USE_CONSOLE
#include <allegro.h>
#include <iostream>
#include "Owoc.h"
#include "Napis.h"
#include "Snake.h"
#include "Snake2.h"
#include "Bonus.h"

 int punkty = 0;
 int czas = 80;
 bool menu = true;
 int bonus_czas=15;
 int czas_gry=0;
using namespace std;
void PetlaGry(int ile_graczy);
Owoc *o = nullptr;

Bonus *b = nullptr;
void Rysuj_obiekt(Reakcja *r);
void Aktualizuj_obiekt(Reakcja *r);
void Statystyki();
BITMAP * bufor = NULL;
bool werdykt = true;
int wybor_gry=1;
int main()
{
	allegro_init();
	install_keyboard();
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0); //40x30
	set_window_title("Snake");
	
	
	bufor = create_bitmap( 800, 600 );
			if( !bufor )
			{
				set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
				allegro_message( "Nie moge zaladowac bufora" );
				allegro_exit();
				return 0;
			}
	
	

	while(!key[KEY_ESC]){
	blit( bufor, screen, 0, 0, 0, 0, 800, 600 );	
		
		
		if(menu==false){
			PetlaGry(wybor_gry);
		}else{
			
			Napis::Rysuj("SNAKE", 350,200, bufor);
			Napis::Rysuj("Kliknij 1 lub 2", 350,240, bufor);
			if (key[ KEY_1 ]) {
					o = new Owoc();
					b = new Bonus(1,1); 
					menu = false;
					Snake::Snake(15,15, bufor);
					wybor_gry=1;
					Aktualizuj_obiekt(o);
			}
			if (key[ KEY_2 ]) {
					o = new Owoc();
					menu = false;
					Snake::Snake(10 , 10, bufor);
						Snake::pozycjaX.push_back(0);
						Snake::pozycjaY.push_back(0);
						Snake::tmpX.push_back(0);
						Snake::tmpY.push_back(0);
						Snake::dlugosc++;
					Snake2::Snake2(20,20,bufor);
						Snake2::pozycjaX.push_back(0);
						Snake2::pozycjaY.push_back(0);
						Snake2::tmpX.push_back(0);
						Snake2::tmpY.push_back(0);
						Snake2::dlugosc++;
						Snake2::kierunek = 3;
					Aktualizuj_obiekt(o);
					wybor_gry=2;
			}
		}

	
	}
	
	destroy_bitmap( bufor );
	
	return 0;
}
END_OF_MAIN();



void PetlaGry(int ile_graczy){
	
		blit( bufor, screen, 0, 0, 0, 0, 800, 600 );
	if (ile_graczy==1){


		if (Snake::Sprawdz() == true){
		czas_gry++;
		
		clear_to_color( bufor, makecol( 0, 0, 0 ) );
		Napis::Rysuj("Punkty: ",punkty,10,10, bufor); 

	
		Snake::Rysuj(bufor);
		Rysuj_obiekt(b);
		Rysuj_obiekt(o); 

		bonus_czas--;
		if (bonus_czas<=0){		
			Aktualizuj_obiekt(b); bonus_czas=15;           
			}


			if ((Snake::pozycjaX[0]==o->pobierzX())&&(Snake::pozycjaY[0]==o->pobierzY()))
			{
				Aktualizuj_obiekt(o); //owoc w losowe miejsce
				Snake::pozycjaX.push_back(0);
				Snake::pozycjaY.push_back(0);
				Snake::tmpX.push_back(0);
				Snake::tmpY.push_back(0);
				Snake::dlugosc++;
				punkty++;

			}

			if ((Snake::pozycjaX[0]==b->pobierzX())&&(Snake::pozycjaY[0]==b->pobierzY()))
			{
				bonus_czas=3; 
				Aktualizuj_obiekt(b);
				punkty+=3;

			}

		Snake::Aktualizuj();
	
		Snake::Sprawdz();
		 if (punkty>=30) czas = 7;
		 else if(punkty>=20) czas=15;
		 else if(punkty>=15) czas=25;
		 else if(punkty>=10) czas=40;
		 else if(punkty>=5) czas=60;
		 else if(punkty>=3) czas=70;
		 

		 rest(czas);
	}else{
		
		Statystyki();
		Napis::Rysuj("Koniec gry",350,10, bufor); 
	}

	}else{ ////2 graczy
								if ((Snake::Sprawdz() == true) && (Snake2::Sprawdz() == true)){
								
		
											clear_to_color( bufor, makecol( 0, 0, 0 ) );
											Napis::Rysuj("Batalia",10,10, bufor); 

	
											Snake::Rysuj(bufor);
											Snake2::Rysuj(bufor);
								
											Rysuj_obiekt(o); 

							


								if ((Snake::pozycjaX[0]==o->pobierzX())&&(Snake::pozycjaY[0]==o->pobierzY()))
									{
										Aktualizuj_obiekt(o); //owoc w losowe miejsce
										Snake::pozycjaX.push_back(0);
										Snake::pozycjaY.push_back(0);
										Snake::tmpX.push_back(0);
										Snake::tmpY.push_back(0);
										Snake::dlugosc++;
										punkty++;

									} 
								///2 gracz
								if ((Snake2::pozycjaX[0]==o->pobierzX())&&(Snake2::pozycjaY[0]==o->pobierzY()))
									{
										Aktualizuj_obiekt(o); //owoc w losowe miejsce
										Snake2::pozycjaX.push_back(0);
										Snake2::pozycjaY.push_back(0);
										Snake2::tmpX.push_back(0);
										Snake2::tmpY.push_back(0);
										Snake2::dlugosc++;
										punkty++;

									} 

					

								Snake::Aktualizuj();
								Snake2::Aktualizuj();

								Snake::Sprawdz();
								Snake2::Sprawdz();

								 if (punkty>=30) czas = 7;
								 else if(punkty>=20) czas=15;
								 else if(punkty>=15) czas=25;
								 else if(punkty>=10) czas=40;
								 else if(punkty>=5) czas=60;
								 else if(punkty>=3) czas=70;
		 

								 rest(czas); ///czas
							}else{
								if (werdykt == true){

									if ((Snake::Sprawdz()==false) && (Snake2::Sprawdz()==false)){

										//Snake::Sprawdz() = true;
										Snake::pozycjaX[0] = 10;
										Snake::pozycjaY[0] = 10;

										//Snake2::Sprawdz()=true;

										Snake2::pozycjaX[0] = 20;
										Snake2::pozycjaY[0] = 20;

										Napis::Rysuj("Remis",350,30, bufor); 

									}else if ((Snake::Sprawdz()==false) && (Snake2::Sprawdz() == true)){      
										Napis::Rysuj("Drugi gracz wygrywa",350,30, bufor);       werdykt = false;       }
									else{
										Napis::Rysuj("Pierwszy gracz wygrywa",350,30, bufor);    werdykt = false;      }
									


									
								}
								
								Napis::Rysuj("Koniec gry",350,10, bufor); 
							}
	}

}



void Rysuj_obiekt(Reakcja *r){
	r->Rysuj (bufor);
}
void Aktualizuj_obiekt(Reakcja *r){
	r->Aktualizuj(bufor);
}

void Statystyki(){
if (czas_gry>0){
	
	cout << "STATYSTYKI: "<<'\n';
	cout << "Punkty: "<<punkty<<'\n';
	cout << "Zjedzonych bonusow: "<< (punkty - Snake::dlugosc)/3 << '\n';
	cout << "Czas gry: " << czas_gry << '\n';
	Snake::Wypisz();
	czas_gry = 0;
}
		
}