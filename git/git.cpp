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
}
void printBoard(char myBoard[][MAXSIDE])
{
	int i, j;

	cout << (" ");

	for (i = 0; i < SIDE; i++)
		cout << "\t" << i;

	cout << ("\n");

	for (i = 0; i < SIDE; i++)
	{
		cout << i << "\t";

		for (j = 0; j < SIDE; j++)
			if (flag[i][j] == true) {
				cout << "X\t";
			}
			else {
				cout << myBoard[i][j] << "\t";
			}

		cout << ("\n");
	}
}


int countAdjacentMines(int row, int col, int mines[][2],
	char realBoard[][MAXSIDE])
{

	int i;
	int count = 0;



	if (isValid(row - 1, col) == true)
	{
		if (isMine(row - 1, col, realBoard) == true)
			count++;
	}

	if (isValid(row + 1, col) == true)
	{
		if (isMine(row + 1, col, realBoard) == true)
			count++;
	}

	if (isValid(row, col + 1) == true)
	{
		if (isMine(row, col + 1, realBoard) == true)
			count++;
	}

	if (isValid(row, col - 1) == true)
	{
		if (isMine(row, col - 1, realBoard) == true)
			count++;
	}

	if (isValid(row - 1, col + 1) == true)
	{
		if (isMine(row - 1, col + 1, realBoard) == true)
			count++;
	}

	if (isValid(row - 1, col - 1) == true)
	{
		if (isMine(row - 1, col - 1, realBoard) == true)
			count++;
	}

	if (isValid(row + 1, col + 1) == true)
	{
		if (isMine(row + 1, col + 1, realBoard) == true)
			count++;
	}

	if (isValid(row + 1, col - 1) == true)
	{
		if (isMine(row + 1, col - 1, realBoard) == true)
			count++;
	}

	return (count);
}


bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE],
	int mines[][2], int row, int col, int* movesLeft)
{

	if (myBoard[row][col] != '-')
		return (false);

	int i, j;


	if (realBoard[row][col] == '*')
	{
		myBoard[row][col] = '*';

		for (i = 0; i < MINES; i++)
			myBoard[mines[i][0]][mines[i][1]] = '*';

		printBoard(myBoard);
		cout << ("\nYou lost!\n");
		return (true);
	}

	else
	{
		int count = countAdjacentMines(row, col, mines, realBoard);
		(*movesLeft)--;

		myBoard[row][col] = count + '0';

		if (!count)
		{
			if (isValid(row - 1, col) == true)
			{
				if (isMine(row - 1, col, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row - 1, col, movesLeft);
			}

			if (isValid(row + 1, col) == true)
			{
				if (isMine(row + 1, col, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row + 1, col, movesLeft);
			}

			if (isValid(row, col + 1) == true)
			{
				if (isMine(row, col + 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row, col + 1, movesLeft);
			}

			if (isValid(row, col - 1) == true)
			{
				if (isMine(row, col - 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row, col - 1, movesLeft);
			}

			if (isValid(row - 1, col + 1) == true)
			{
				if (isMine(row - 1, col + 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row - 1, col + 1, movesLeft);
			}

			if (isValid(row - 1, col - 1) == true)
			{
				if (isMine(row - 1, col - 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row - 1, col - 1, movesLeft);
			}

			if (isValid(row + 1, col + 1) == true)
			{
				if (isMine(row + 1, col + 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row + 1, col + 1, movesLeft);
			}

			if (isValid(row + 1, col - 1) == true)
			{
				if (isMine(row + 1, col - 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row + 1, col - 1, movesLeft);
			}
		}

		return (false);
	}
}

