#include "stdafx.h"
#include "iostream"

using namespace System::Threading;
using namespace System;
using namespace std;

enum Direction   // To define direction
{
	WEST = 'a', SOUTH = 's', NORTH = 'w',
	EAST = 'd', QUIT = 'q'
};

enum BOUNDS { LEFT = 0, RIGHT = 49, TOP = 0, BOTTOM = 19 };    // To bond cursor

Direction read();    // To intake direction

int i, j;            //Iteration variable 
char wall[20][50];   // To store location of maze wall

// Maze Map
void map()
{
	Console::BackgroundColor = ConsoleColor::White;
	Console::ForegroundColor = ConsoleColor::Black;


	for (j = 0; j < 20; j++)
	{
		for (i = 0; i < 50; i++)
		{
			if (j == 0)
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j==1 && (i==5 || i==11 || i==15 || i==20 || i==28 || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j==2 && (i<4 || i==5 || (i>8 && i<14) || (i>14 && i<18) || i==20 || i==23 || i==26 || i==28 || i==34 ||(i>36 && i<46) || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j==3 && (i==0 || i==5 || i==9 || i==7 || i==19 || i==20 || (i>21 && i<30) || (i>31 && i<35) || i==37 || i==43 || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j==4 && (i==0 || (i>1 && i<6) || i==7 || i==9 || i==11 || (i>12 && i<18) || i==19 || i==24 || i==26 || i==29 || i==32 || i==34 || i==37 || i==40 || i==43 || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j==5 && (i==0 || i==5 || i==9 || i==11 || i==13 || i==16 || i==19 || (i>21 && i<25) || (i>28 && i<33) || i==34 || (i>35 && i<39) || i==40 || i==43 || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j==6 && (i<4 || i==5 || i==7 || i==11 || i==13 || i==16 || (i>17 && i<21) || i==22 || i==27 || i==29 || i==38 || i==40 || (i>41 && i<45) || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j==7 && (i==0 || i==7 || i==9 || i==13 || i==18 || (i>21 && i<28) || (i>28 && i<39) || (i>39 && i<43) || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j==8 && (i==0 || (i>1 && i<8) || (i>8 && i<15) || (i>15 && i<21) || i==22 || i==27 || i==29 || i==33 || i==42 || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j==9 && (i==0 || i==22 || i==24 || i==27 || i==31 || i==33 || (i>34 && i<41) || i==42 || (i>43 && i<48) || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j == 10 && (i<6 || i==7 || i==8 || (i>9 && i<16) || i==17 || (i>18 && i<23) || i==24 || i==26 || i==27 || i==29 || i==31 || i==35 || i==38 || i==42 || i==47 || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j == 11 && (i==0 || i==7 || i==15 || (i>16 && i<20) || (i>21 && i<25) || i==27 || i==29 || (i>30 && i<37) || (i>37 && i<41) || (i>41 && i<46) || i>46))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j == 12 && (i==0 || (i>1 && i<8) || i==9 || i==10 || i==12 || i==15 || i==17 || i==23 || (i>25 && i<30) || i==31 || i==40 || i==45 || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j == 13 && (i==0 || i==2 || i==9 || (i>11 && i<16) || (i>16 && i<22) || i==23 || i==25 || i==26 || i==31 || (i>32 && i<36) || i==37 || (i>39 && i<44) || i==46 || i==45 || i==47 || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j == 14 && (i<6 || i==7 || i==9 || i==11 || i==12 || i==15 || i==21 || i==26 || (i>27 && i<32) || i==37 || i==43 || i==45 || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j == 15 && (i==0 || i==7 || (i>8 && i<12) || (i>13 && i<20) || (i>20 && i<24) || i==25 || i==26 || i==28 || i==34 || i==36 || i==37 || (i>38 && i<42) || i==43 || i==45 || i==47 || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j == 16 && (i==0 || (i>2 && i<8) || i==13 || i==14 || i==19 || i==28 || (i>31 && i<35) || i==39 || i==41 || i==45 || i==47 || i==49))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j == 17 && (i==0 || i==3 || i==2 || (i>6 && i<11) || i==12 || i==13 || i==16 || i==17 || (i>18 && i<24) || (i>24 && i<31) || (i>33 && i<40) || (i>40 && i<44) || i==45 || i>46))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j == 18 && (i==0 || i==17 || i==32 || i==43))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
			if (j == 19)
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
				wall[j][i] = '1';
			}
		}
	}

	Console::BackgroundColor = ConsoleColor::Black;
	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(51, 18);
	cout << "Exit";
}

void main()
{
	Console::Clear();

	map();  // Print map

	// Initial position of cursor
	int x = 0;
	int y = 1;
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::BackgroundColor = ConsoleColor::Black;
	Console::SetCursorPosition(x, y);
	putchar('#');

	Direction d;   // Declaring Enum direction
	while ((d = read()) != QUIT)
	{
		map();
		Console::ForegroundColor = ConsoleColor::Black;
		Console::BackgroundColor = ConsoleColor::Black;
		Console::SetCursorPosition(x, y);
		putchar(' ');

		switch (d)
		{
		case WEST:
		{
			if (x > LEFT) 
			{
				if (wall[y][x - 1] != '1')
				{
					x = x - 1;
				}
			}
			break;
		}
		case NORTH:
		{
			if (y > TOP)
			{
				if (wall[y - 1][x] != '1')
				{
					y = y - 1;
				}
			}
			break;
		}
		case EAST: 
		{
			if (x < RIGHT)  
			{
				if (wall[y][x + 1] != '1')
				{
					x = x + 1;
				}
			}
			break;
		}
		case SOUTH: 
		{
			if (y < BOTTOM)
			{
				if (wall[y + 1][x] != '1')
				{
					y = y + 1;
				}
			}
			break;
		}
		}

		// To check win or loss
		if (x == 49 && y == 18)
		{
			Console::BackgroundColor = ConsoleColor::DarkRed;
			Console::ForegroundColor = ConsoleColor::Black;
			Console::SetCursorPosition(10, 10);
			cout << "You won the game.....";
			Console::Read();
			exit(-1);
		}

		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::BackgroundColor = ConsoleColor::Black;
		Console::SetCursorPosition(x, y);
		putchar('#');
	}// end while loop

	Console::Read();
}

Direction read()
{
	Boolean flag = true;
	char direction;
	while (flag) {
		direction = Console::ReadKey(true).KeyChar;
		switch (direction)
		{
		case 'A':
		case 'a': return WEST; break;
		case 'W':
		case 'w': return NORTH; break;
		case 'D':
		case 'd': return EAST; break;
		case 'S':
		case 's': return SOUTH; break;
		case 'Q':
		case 'q': return QUIT; break;
		}// end switch case
	}// end while loop
}
