// git.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

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
	





 

int main()
{
	wypiszdanelt();
	wypiszdanest();
	wypiszdanett();


}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
