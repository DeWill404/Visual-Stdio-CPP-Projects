#include "stdafx.h"
#include "iostream"

using namespace System::Threading;
using namespace System;
using namespace std;

TIC-TAC-TOE PROJECT
int i, j;             // Iteration Variable
int turns = 1;        // Change turn Variable
char winner = '-';         // Win checking Variable
int win_counter = 0;  // To check is game over
int lp;               // To enter the location of X & O  
int x, y;             // To consider Co-ordinates
char store[10] = { '-','-','-','-','-','-','-','-','-','-' };   // To store X & O

// To get detail of players................
struct player
{
	char name[10];
}  p[2];
void get_detail()
{
	Console::SetCursorPosition(0, 5);
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Enter the name of X-player : ";
	cin >> p[0].name;

	Console::ForegroundColor = ConsoleColor::Red;
	cout << "Enter the name of O-player : ";
	cin >> p[1].name;

	Console::ForegroundColor = ConsoleColor::White;
}

// To check winner...............
int win();

// To create a blank board..............
void blank_board();

// To check the availblity of space............
void check_lp(int lp);

// To get X & O on their co-ordinates.............. 
void get_input();

//To create gaming board................
void board();

void main()
{
	blank_board();
	get_detail();

	while ((win_counter < 9) && (winner == '-'))
	{
		get_input();
	}
	
	if (win() == 1)
	{
		Console::SetCursorPosition(20, 25);
		Console::ForegroundColor = ConsoleColor::Yellow;
		if (winner == 'X')
		{
			cout << "The Winner is ";
			Console::ForegroundColor = ConsoleColor::Blue;
			cout << p[0].name;
			Console::ForegroundColor = ConsoleColor::Yellow;
			cout << "......";
		}
		else
		{
			cout << "The Winner is ";
			Console::ForegroundColor = ConsoleColor::Red;
			cout << p[1].name;
			Console::ForegroundColor = ConsoleColor::Yellow;
			cout << "......";
		}
	}
	if (win_counter == 9)
	{
		Console::SetCursorPosition(20, 25);
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << "The Match is Draw......";
	}
	Console::Read();
}

int win()
{
	if ((store[1] == store[5]) && (store[1] == store[9]))           //Diagonal
	{
		winner = store[1];
		return 1;
	}
	else if ((store[3] == store[5]) && (store[3] == store[7]))       //Diagonal
	{
		winner = store[3];
		return 1;
	}
	else if ((store[1] == store[4]) && (store[1] == store[7]))        //Vertical
	{
		winner = store[1];
		return 1;
	}
	else if ((store[2] == store[5]) && (store[2] == store[8]))        //Vertical
	{
		winner = store[2];
		return 1;
	}
	else if ((store[3] == store[6]) && (store[3] == store[9]))        //Vertical
	{
		winner = store[3];
		return 1;
	}
	else if ((store[1] == store[2]) && (store[1] == store[3]))        //Horizntal
	{
		winner = store[1];
		return 1;
	}
	else if ((store[4] == store[5]) && (store[4] == store[6]))        //Horizntal
	{
		winner = store[14];
		return 1;
	}
	else if ((store[7] == store[9]) && (store[7] == store[8]))        //Horizntal
	{
		winner = store[7];
		return 1;
	}
	else
		return 0;
}

void board()
{
	if (turns % 2 == 1)
	{
		Console::ForegroundColor = ConsoleColor::Blue;
		Console::SetCursorPosition(x, y);
		putchar('X');
		Console::ForegroundColor = ConsoleColor::White;
		store[lp] = 'X';
	}
	else
	{
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y);
		putchar('O');
		Console::ForegroundColor = ConsoleColor::White;
		store[lp] = 'O';
	}
	win();
}

void check_lp(int lp)
{
	if (store[lp] == '-')
	{
		switch (lp)
		{
		case 1: x = 5, y = 10; break;
		case 2: x = 7, y = 10; break;
		case 3: x = 9, y = 10; break;
		case 4: x = 5, y = 12; break;
		case 5: x = 7, y = 12; break;
		case 6: x = 9, y = 12; break;
		case 7: x = 5, y = 14; break;
		case 8: x = 7, y = 14; break;
		case 9: x = 9, y = 14; break;
		}
		win_counter++;
		board();
		turns++;
	}
	else
	{
		get_input();
	}
	
}

void get_input()
{
	// To clear previous line
	for (i = 0; i < 40; i++)
	{
		Console::SetCursorPosition(i, 6);
		putchar(' ');
	}

	// To clear previously entered lp
	Console::SetCursorPosition(36, 5);
	putchar(' ');

	// To reset Cursor position
	Console::SetCursorPosition(0, 5);
	if (turns % 2 == 1)
	{
		Console::ForegroundColor = ConsoleColor::Blue;
		cout << "Enter location point for X-" << p[0].name<<" : ";
		cin >> lp;
	}
	else
	{
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "Enter location point for O-" << p[1].name << " : ";
		cin >> lp;
	}

	check_lp(lp);
}

void blank_board()
{
	cout << "\t\t\t\t<-Tic Tac Toe ->";
	cout << "\n\n\n\n\n\n\n\n     BOARD";
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << " \t Location point";
	Console::ForegroundColor = ConsoleColor::White;
	char t = '1';

	for (j = 0; j < 5; j += 2)
	{
		for (i = 0; i < 5; i += 2)
		{
			Console::SetCursorPosition(5 + i, 10 + j);
			putchar('-');

			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::SetCursorPosition(20 + i, 10 + j);
			putchar(t);
			Console::ForegroundColor = ConsoleColor::White;

			t++;
		}
	}
}