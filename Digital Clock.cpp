#include "stdafx.h"
#include "iostream"

using namespace System::Threading;
using namespace System;
using namespace std;

int i, j, k;

void zero(int x);
void one(int x);
void two(int x);
void three(int x);
void four(int x);
void five(int x);
void six(int x);
void seven(int x);
void eight(int x);
void nine(int x);

void swich (int d1,int d2)
{
	switch (d1)
	{
	case 0:
		zero(d2);
		break;
	case 1:
		one(d2);
		break;
	case 2:
		two(d2);
		break;
	case 3:
		three(d2);
		break;
	case 4:
		four(d2);
		break;
	case 5:
		five(d2);
		break;
	case 6:
		six(d2);
		break;
	case 7:
		seven(d2);
		break;
	case 8:
		eight(d2);
		break;
	case 9:
		nine(d2);
		break;
	}
}

void clock(int a, int b, int c)
{
	int x = 9, y = 5;

	if (a < 10)
	{
		zero(y);
		swich(a , x + y);
	}
	else
	{
		swich((a - a % 10)/10, y);
		swich(a % 10, x + y);
	}

	for (i = 23; i < 28; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ((i != 25) && (j == 2 || j == 3 || j == 6 || j == 7))
			{
				Console::SetCursorPosition(i, j + k);
				putchar('*');
			}
			else
			{
				Console::SetCursorPosition(i, j + k);
				putchar(' ');
			}
		}
	}

	if (b < 10)
	{
		zero(2*x + 2*y + 2);
		swich(b, 3*x + 2*y + 2);
	}
	else
	{
		swich((b - b % 10) / 10, 2*x + 2*y + 2);
		swich(b % 10, 3*x + 2*y + 2);
	}

	for (i = 48; i < 53; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ((i != 50) && (j == 2 || j == 3 || j == 6 || j == 7))
			{
				Console::SetCursorPosition(i, j + k);
				putchar('*');
			}
			else
			{
				Console::SetCursorPosition(i, j + k);
				putchar(' ');
			}
		}
	}

	if (c < 10)
	{
		zero(4 * x + 3 * y + 4);
		swich(c, 5 * x + 3 * y + 4);
	}
	else
	{
		swich((c - c % 10) / 10, 4 * x + 3 * y + 4);
		swich(c % 10, 5 * x + 3 * y + 4);
	}
}

void main()
{
	int l,m,n;


	while (l >= 0)
	{
		l = DateTime::Now.Hour;
		m = DateTime::Now.Minute;
		n = DateTime::Now.Second;

		Console::Clear();
		k = 2;
		clock(l, m, n);
		if (l > 12)
		{
			l -= 12;
		}
		k = 14;
		clock(l, m, n);
		Thread::Sleep(1000);
	}


	Console::Read();
}

void zero(int x)
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ((i>1 && i<5) && (j>1 && j<8))
			{
				Console::SetCursorPosition(i+x, j + k);
				putchar(' ');
			}
			else
			{
				Console::SetCursorPosition(i+x, j + k);
				putchar('*');
			}
		}
	}
}
void one(int x)
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (i<5)
			{
				Console::SetCursorPosition(i+x, j + k);
				putchar(' ');
			}
			else
			{
				Console::SetCursorPosition(i+x, j + k);
				putchar('*');
			}
		}
	}
}
void two(int x)
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (((j>1 && j<4) && i<5) || ((j>5 && j<8) && i>1))
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar(' ');
			}
			else
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar('*');
			}
		}
	}
}
void three(int x)
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (((j>1 && j<4) && i<5) || ((j>5 && j<8) && i<5))
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar(' ');
			}
			else
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar('*');
			}
		}
	}
}
void four(int x)
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ((j<4 && (i>1 && i<5)) || (j>5 && i<5))
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar(' ');
			}
			else
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar('*');
			}
		}
	}
}
void five(int x)
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ((i>1 && (j>1 && j<4)) || (i<5 && (j>5 && j<8)))
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar(' ');
			}
			else
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar('*');
			}
		}
	}
}
void six(int x)
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ((i>1 && (j>1 && j<4)) || ((i<5 && i>1) && (j>5 && j<8)))
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar(' ');
			}
			else
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar('*');
			}
		}
	}
}
void seven(int x)
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (i<5 && j>1)
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar(' ');
			}
			else
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar('*');
			}
		}
	}
}
void eight(int x)
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ((i > 1 && i < 5) && (j == 2 || j == 3 || j == 6 || j == 7))
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar(' ');
			}
			else
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar('*');
			}
		}
	}
}
void nine(int x)
{
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (((i>1 && i<5) && (j>1 && j<4)) || (i<5 && j>5))
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar(' ');
			}
			else
			{
				Console::SetCursorPosition(i + x, j + k);
				putchar('*');
			}
		}
	}
}

VISUAL CLOCK PROJECT
int i, j, r=1, k=0;

void clock(int hours)
{
	Console::SetCursorPosition(50, 5);
	putchar('1');
	Console::SetCursorPosition(51, 5);
	putchar('2');
	Console::SetCursorPosition(54, 6);
	putchar('1');
	Console::SetCursorPosition(58, 8);
	putchar('2');
	Console::SetCursorPosition(62, 10);
	putchar('3');
	Console::SetCursorPosition(58, 12);
	putchar('4');
	Console::SetCursorPosition(54, 14);
	putchar('5');
	Console::SetCursorPosition(50, 15);
	putchar('6');
	Console::SetCursorPosition(46, 6);
	putchar('1');
	Console::SetCursorPosition(47, 6);
	putchar('1');
	Console::SetCursorPosition(42, 8);
	putchar('1');
	Console::SetCursorPosition(43, 8);
	putchar('0');
	Console::SetCursorPosition(39, 10);
	putchar('9');
	Console::SetCursorPosition(42, 12);
	putchar('8');
	Console::SetCursorPosition(46, 14);
	putchar('7');

	if (hours > 12)
		hours - 12;

	Console::ForegroundColor = ConsoleColor::Blue;
	switch (hours)
	{
	case 1: Console::SetCursorPosition(54, 6); putchar('1'); break;
	case 2: Console::SetCursorPosition(58, 8); putchar('2'); break;
	case 3: Console::SetCursorPosition(62, 10); putchar('3'); break;
	case 4: Console::SetCursorPosition(62, 10); putchar('3'); break;
	case 5: Console::SetCursorPosition(54, 14); putchar('5'); break;
	case 6: Console::SetCursorPosition(50, 15); putchar('6'); break;
	case 7: Console::SetCursorPosition(46, 14); putchar('7'); break;
	case 8: Console::SetCursorPosition(42, 12); putchar('8'); break;
	case 9: Console::SetCursorPosition(39, 10); putchar('9'); break;
	case 10: Console::SetCursorPosition(42, 8); putchar('1'); Console::SetCursorPosition(43, 8); putchar('0'); break;
	case 11: Console::SetCursorPosition(46, 6); putchar('1'); Console::SetCursorPosition(47, 6); putchar('1'); break;
	case 12: Console::SetCursorPosition(50, 5); putchar('1'); Console::SetCursorPosition(51, 5); putchar('2'); break;
	}

	Console::ForegroundColor = ConsoleColor::White;
}
void min(int mint)
{
	for (i = 1; i <= 18; i+=3)
	{
		for (j = 1; j <= 10; j++)
		{
			Console::SetCursorPosition(16+i, 4+j);
			if (k == mint)
			{
				Console::ForegroundColor = ConsoleColor::DarkGreen;
				cout << k;
				Console::ForegroundColor = ConsoleColor::White;
			}
			else
			{
				cout << k;
			}

			k++;
			if (k == 60)
				k = 0;
		}
	}

}
void sec(int seco)
{
	for (i = 1; i <= 18; i += 3)
	{
		for (j = 1; j <= 10; j++)
		{
			Console::SetCursorPosition(66 + i, 4 + j);
			if (k == seco)
			{
				Console::ForegroundColor = ConsoleColor::DarkGreen;
				cout << k;
				Console::ForegroundColor = ConsoleColor::White;
			}
			else
			{
				cout << k;
			}

			k++;
			if (k == 60)
				k = 0;
		}
	}

}
void hand(int minhand)
{
	Console::ForegroundColor = ConsoleColor::Red;

	Console::SetCursorPosition(50, 10);
	putchar('*');

	if (minhand >= 5)
		minhand = (minhand - minhand % 5) / 5;
	else
		minhand = 12;

	switch (minhand)
	{
	case 1:
	{
		for (i = 1; i < 4; i++)
		{
			Console::SetCursorPosition(50 + i, 10 - i);
			putchar('*');
		}
		break;
	}
	case 2:
	{
		Console::SetCursorPosition(51, 10);
		putchar('*');
		Console::SetCursorPosition(52, 10);
		putchar('*');
		Console::SetCursorPosition(53, 10);
		putchar('*');
		Console::SetCursorPosition(53, 9);
		putchar('*');
		Console::SetCursorPosition(54, 9);
		putchar('*');
		Console::SetCursorPosition(55, 9);
		putchar('*');
		Console::SetCursorPosition(55, 8);
		putchar('*');
		Console::SetCursorPosition(56, 8);
		putchar('*');
		Console::SetCursorPosition(57, 8);
		putchar('*');
		break;
	}
	case 3:
	{
		for (i = 1; i < 12; i++)
		{
			Console::SetCursorPosition(50 + i, 10);
			putchar('*');
		}
		break;
	}
	case 4:
	{
		Console::SetCursorPosition(49, 10);
		putchar('*');
		Console::SetCursorPosition(48, 10);
		putchar('*');
		Console::SetCursorPosition(47, 10);
		putchar('*');
		Console::SetCursorPosition(47, 11);
		putchar('*');
		Console::SetCursorPosition(46, 11);
		putchar('*');
		Console::SetCursorPosition(45, 11);
		putchar('*');
		Console::SetCursorPosition(45, 12);
		putchar('*');
		Console::SetCursorPosition(44, 12);
		putchar('*');
		Console::SetCursorPosition(43, 12);
		putchar('*');
		break;
	}
	case 5:
	{
		for (i = 1; i < 4; i++)
		{
			Console::SetCursorPosition(50 + i, 10 + i);
			putchar('*');
		}
		break;
	}
	case 6:
	{
		for (i = 1; i<5; i++)
		{
			Console::SetCursorPosition(50, 10 + i);
			putchar('*');
		}
		break;
	}
	case 7:
	{
		for (i = 1; i < 4; i++)
		{
			Console::SetCursorPosition(50 - i, 10 + i);
			putchar('*');
		}
		break;
	}
	case 8:
	{
		Console::SetCursorPosition(51, 10);
		putchar('*');
		Console::SetCursorPosition(52, 10);
		putchar('*');
		Console::SetCursorPosition(53, 10);
		putchar('*');
		Console::SetCursorPosition(53, 11);
		putchar('*');
		Console::SetCursorPosition(54, 11);
		putchar('*');
		Console::SetCursorPosition(55, 11);
		putchar('*');
		Console::SetCursorPosition(55, 12);
		putchar('*');
		Console::SetCursorPosition(56, 12);
		putchar('*');
		Console::SetCursorPosition(57, 12);
		putchar('*');

		break;
	}
	case 9:
	{
		for (i = 1; i < 11; i++)
		{
			Console::SetCursorPosition(50 - i, 10);
			putchar('*');
		}
		break;
	}
	case 10:
	{
		Console::SetCursorPosition(49, 10);
		putchar('*');
		Console::SetCursorPosition(48, 10);
		putchar('*');
		Console::SetCursorPosition(47, 10);
		putchar('*');
		Console::SetCursorPosition(47, 9);
		putchar('*');
		Console::SetCursorPosition(46, 9);
		putchar('*');
		Console::SetCursorPosition(45, 9);
		putchar('*');
		Console::SetCursorPosition(45, 8);
		putchar('*');
		Console::SetCursorPosition(44, 8);
		putchar('*');
		break;
	}
	case 11:
	{
		for (i = 1; i < 4; i++)
		{
			Console::SetCursorPosition(50 - i, 10 - i);
			putchar('*');
		}
		break;
	}
	case 12:
	{
		for (i = 1; i<5; i++)
		{
			Console::SetCursorPosition(50, 10 - i);
			putchar('*');
		}
		break;
	}
	}

	Console::ForegroundColor = ConsoleColor::White;
}

void main()
{
	while (r == 1)
	{
		Console::Clear();

		clock(DateTime::Now.Hour);
		min(DateTime::Now.Minute);
		sec(DateTime::Now.Second);
		hand(DateTime::Now.Minute);

		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(47, 17);
		cout << DateTime::Now.Hour <<":"<< DateTime::Now.Minute <<":"<< DateTime::Now.Second;
		Console::ForegroundColor = ConsoleColor::White;

		Thread::Sleep(1000);
	}

	Console::Read();
}
