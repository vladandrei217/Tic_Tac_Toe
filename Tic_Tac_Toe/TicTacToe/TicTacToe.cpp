#include<iostream>
#include<conio.h>
#include<Windows.h>

#define X 3
#define Y 3

const char VERTICAL = 179;
const char HORIZONTAL = 196;

using namespace std;

void printTheboard(char board[X][Y], int& turn);
void gameBoard(char board[X][Y], char user[X][Y], int& turn);
void userInput(char input[X][Y], int& turn);
void centering();
bool winnerCheckX(char playerInput[X][Y]);
bool winnerCheckO(char playerInput[X][Y]);
bool tieCheck(char playerInput[X][Y]);

int main()
{
	int userRow, userColumn, playersTurn;
	char boardArray[X][Y];
	char playerInputArray[X][Y];
	char exitInput;
	do {
		gameBoard(boardArray, playerInputArray, playersTurn);
		cout << "Do you want to play again? Press 'y' for yes or 'n' for no!" << endl;
		exitInput = _getch();
		while (exitInput != 'y' && exitInput != 'n')
		{
			cout << "You can only select one of the options above, select yes or no!" << endl;
			exitInput = _getch();
		}
		system("cls");
	} while (exitInput != 'n');
	return 0;
}

void gameBoard(char board[X][Y], char user[X][Y], int& turn)
{
	turn = 1;

	for (int i = 0; i < X; i++)
		for (int j = 0; j < Y; j++)
			user[i][j] = 0;

	cout << "                                                Tic Tac Toe game: " << endl;
	cout << "\n\n\n\n\n";
	printTheboard(board, turn);

	do {
		userInput(user, turn);
		system("cls");
		cout << "                                                Tic Tac Toe game: " << endl;
		cout << "\n\n\n\n\n";
		for (int i = 0; i < X; i++)
		{
			centering();
			for (int j = 0; j < Y; j++)
			{
				if (user[i][j])
					board[i][j] = user[i][j];
				else
					board[i][j] = ' ';
				cout << board[i][j];
				if (j != Y - 1)
					cout << VERTICAL;
			}
			cout << endl;
			centering();
			if (i != X - 1)
				for (int k = 0; k < X + 2; k++)
					cout << HORIZONTAL;
			cout << endl;
		}



		if (winnerCheckX(user) == true)
		{
			cout << endl << "Player 'X' has won the game! Congratulations!\n" << endl;
			break;
		}
		if (winnerCheckO(user) == true)
		{
			cout << endl << "Player 'O' has won the game! Congratulations!\n" << endl;
			break;
		}

		if (tieCheck(user) == true)
		{
			cout << endl << "The game has ended with a tie!\n" << endl;
			break;
		}
		turn++;

	} while (true);
}
void userInput(char input[X][Y], int& turn)
{
	int x, y;

	cout << "\n\n\n\n";

	if (turn % 2 == 0)
		cout << "It's player 'O's turn!" << endl;
	else
		cout << "It's player 'X's turn!" << endl;

	do {
		cout << "Please enter the row and then the column (both 0-2): " << endl;
		cout << "Row: ";
		cin >> x;
		while (x > 2 || x < 0)
		{
			cout << "The command you have entered is invalid, enter a row between 0 and 2!" << endl;
			cout << "Row: ";
			cin >> x;
		}
		cout << "Column: ";
		cin >> y;
		while (y > 2 || y < 0)
		{
			cout << "The command you have entered is invalid, enter a column between 0 and 2!" << endl;
			cout << "Column: ";
			cin >> y;
		}

		if (input[x][y] == 'X' || input[x][y] == 'O')
			cout << "The position is already occupied, please try again!" << endl;
		else if (turn % 2 == 0)
		{
			input[x][y] = 'O';
			break;
		}
		else
		{
			input[x][y] = 'X';
			break;
		}

	} while (true);
}
void centering()
{
	cout << "                                                     ";
}
bool winnerCheckX(char playerInput[X][Y])
{
	if (playerInput[0][0] == playerInput[0][1] && playerInput[0][1] == playerInput[0][2] && playerInput[0][0] == 'X')
		return true;
	else if (playerInput[1][0] == playerInput[1][1] && playerInput[1][1] == playerInput[1][2] && playerInput[1][0] == 'X')
		return true;
	else if (playerInput[2][0] == playerInput[2][1] && playerInput[2][1] == playerInput[2][2] && playerInput[2][0] == 'X')
		return true;

	else if (playerInput[0][0] == playerInput[1][0] && playerInput[1][0] == playerInput[2][0] && playerInput[0][0] == 'X')
		return true;
	else if (playerInput[0][1] == playerInput[1][1] && playerInput[1][1] == playerInput[2][1] && playerInput[0][1] == 'X')
		return true;
	else if (playerInput[0][2] == playerInput[1][2] && playerInput[1][2] == playerInput[2][2] && playerInput[0][2] == 'X')
		return true;

	else if (playerInput[0][0] == playerInput[1][1] && playerInput[1][1] == playerInput[2][2] && playerInput[0][0] == 'X')
		return true;
	else if (playerInput[0][2] == playerInput[1][1] && playerInput[1][0] == playerInput[2][0] && playerInput[0][2] == 'X')
		return true;

	else
		return false;
}
bool winnerCheckO(char playerInput[X][Y])
{
	if (playerInput[0][0] == playerInput[0][1] && playerInput[0][1] == playerInput[0][2] && playerInput[0][0] == 'O')
		return true;
	else if (playerInput[1][0] == playerInput[1][1] && playerInput[1][1] == playerInput[1][2] && playerInput[1][0] == 'O')
		return true;
	else if (playerInput[2][0] == playerInput[2][1] && playerInput[2][1] == playerInput[2][2] && playerInput[2][0] == 'O')
		return true;

	else if (playerInput[0][0] == playerInput[1][0] && playerInput[1][0] == playerInput[2][0] && playerInput[0][0] == 'O')
		return true;
	else if (playerInput[0][1] == playerInput[1][1] && playerInput[1][1] == playerInput[2][1] && playerInput[0][1] == 'O')
		return true;
	else if (playerInput[0][2] == playerInput[1][2] && playerInput[1][2] == playerInput[2][2] && playerInput[0][2] == 'O')
		return true;

	else if (playerInput[0][0] == playerInput[1][1] && playerInput[1][1] == playerInput[2][2] && playerInput[0][0] == 'O')
		return true;
	else if (playerInput[0][2] == playerInput[1][1] && playerInput[1][0] == playerInput[2][0] && playerInput[0][2] == 'O')
		return true;

	else
		return false;
}
bool tieCheck(char playerInput[X][Y])
{
	bool ok = true;
	for (int i = 0; i < X; i++)
		for (int j = 0; j < Y; j++)
			if (playerInput[i][j] != 'X' && playerInput[i][j] != 'O')
			{
				ok = false;
				break;
			}

	return ok;
}
void printTheboard(char board[X][Y], int& turn)
{
	if (turn == 1)
	{
		for (int i = 0; i < X; i++)
		{
			centering();
			for (int j = 0; j < Y; j++)
			{
				cout << ' ';
				if (j != Y - 1)
					cout << VERTICAL;
			}
			cout << endl;
			centering();
			if (i != X - 1)
				for (int k = 0; k < X + 2; k++)
					cout << HORIZONTAL;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < X; i++)
		{
			centering();
			for (int j = 0; j < Y; j++)
			{
				if (board[i][j] != 'X' && board[i][j] != 'O')
					cout << ' ';
				else
					cout << board[i][j];
				if (j != Y - 1)
					cout << VERTICAL;
			}
			cout << endl;
			centering();
			if (i != X - 1)
				for (int k = 0; k < X + 2; k++)
					cout << HORIZONTAL;
			cout << endl;
		}
	}
}