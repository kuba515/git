// git.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <locale.h>
#include <iostream>
#include <conio.h>
using namespace std;



int** tab;
	int tabl[8][8];
	int tabs[16][16];
	int tabt[32][16];
	//ml-latwa tablica,ms-srednia tablica,mt-truDNA TABLICA
	void wypiszdanelt() {
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++) {
				tabl[i][j] = i * j;
			}
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cout << tabl[i][j] << "\t";
			}
			cout << endl;

		}
		

	}
	void wypiszdanest() {
		for (int h = 8; h < 16; h++) {

			for (int g = 0; g < 16; g++) {
				tabs[h][g] = h * g;

			}
		}
		for (int h = 0; h < 16;h++) {
			for (int g = 0; g < 16; g++) {
				cout << tabs[h][g] << "\t";
			}
			cout << endl;

		}

	}
	void wypiszdanett() {
		for (int a = 0; a < 32; a++) {
			for (int b = 0; b < 16; b++) {
				tabt[a][b] = a * b;
			}
		}
		for (int a = 0; a < 32; a++) {
			for (int b = 0; b < 16; b++) {
				cout << tabt[a][b] << "\t";
			}
			cout << endl;
		}
	}
	
	void losuj_pozycje()
	{
		time_t t;
		int poz_x, poz_y;
		int ilosc = 10;
		string plansza;
		string ustaw_mine;
		srand((unsigned)time(&t));

		while (ilosc > 0)
		{
			poz_x = rand() % 10;
			poz_y = rand() % 10;

			if ( plansza[poz_x][poz_y].wartosc != 9)
			{
				 ustaw_mine(poz_x, poz_y);
				ilosc--;
			}
		}
	}




 

	int main()
	{
		setlocale(LC_CTYPE, "Polish");

		





		int x = 0;
		while (x > 3 || x < 1)
		{
			cout << "*******************MENU SAPER********************" << endl;
			cout << "1.Łatwa plansza" << endl;
			cout << "2.Średnia plansza" << endl;
			cout << "3.Trudna plansza" << endl;
			cout << "Wybieram : ";
			cin >> x;
			system("cls");
		}

		switch (x)
		{
		case 1:
			wypiszdanelt();
			break;
		case 2:
			wypiszdanest();
			break;
		case 3:
			wypiszdanett();
			break;
		}
	}