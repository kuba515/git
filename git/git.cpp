// git.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

#define BEGINNER 0
#define INTERMEDIATE 1
#define ADVANCED 2
#define MAXSIDE 25
#define MAXMINES 99
#define MOVESIZE 526 // (25 * 25 - 99)

int SIDE;
int MINES;
bool flag[24][24];

using namespace std;


void clearFLags() {
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 24; j++) {
			flag[i][j] = false;
		}
	}
}

bool isValid(int row, int col)
{

	return (row >= 0) && (row < SIDE) &&
		(col >= 0) && (col < SIDE);
}


bool isMine(int row, int col, char board[][MAXSIDE])
{
	if (board[row][col] == '*')
		return (true);
	else
		return (false);
}


void makeMove(int* x, int* y)
{
	int a, b;
	cout << "Wpisz x i y nastepnego ruchu -> " << endl;
	cin >> a;
	cin >> b;
	*x = a;
	*y = b;
}

void makeFlag(int* x, int* y)
{
	int fx, fb;
	cout << "Wpisz x i y flagi -> " << endl;
	cin >> fx;
	cin >> fb;
	*x = fx;
	*y = fb - 1;
	if (flag[fx][fb] == true) {
		flag[fx][fb] = false;
	}
	else {
		flag[fx][fb] = true;
	}

