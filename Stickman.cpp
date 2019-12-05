#include "stdafx.h"
#include "iostream"

using namespace System::Threading;
using namespace System;
using namespace std;

// Iteration Variable
int i, j;

void Show_Obstacle(int p,int q)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			Console::SetCursorPosition(p+j, q-i);
			putchar('*');
		}
	}
}
void Hide_Obstacle(int p, int q)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			Console::SetCursorPosition(p + j, q - i);
			putchar(' ');
		}
	}
}
void Obstacle_Animation(int p,int q)
{
	int i;
	for (i = 0; i < 50; i++)
	{
		Show_Obstacle(p - i, q);
		Thread::Sleep(50);
		Hide_Obstacle(p - i, q);
	}
}
void Road(int j)
{
	for (int i = 0; i < 120; i++)
	{
		Console::SetCursorPosition(i, j);
		putchar('*');
	}
}
void Show_Stickman(int p, int q)
{
	Console::SetCursorPosition(p, q);
	putchar('*');
	Console::SetCursorPosition(p+1, q);
	putchar('*');
	Console::SetCursorPosition(p-1, q);
	putchar('*');
	Console::SetCursorPosition(p+2, q+1);
	putchar('*');
	Console::SetCursorPosition(p-2, q+1);
	putchar('*');
	Console::SetCursorPosition(p, q-1);
	putchar('*');
	Console::SetCursorPosition(p, q-2);
	putchar('*');
	Console::SetCursorPosition(p+2, q-2);
	putchar('*');
	Console::SetCursorPosition(p-2, q-2);
	putchar('*');
	Console::SetCursorPosition(p+1, q-3);
	putchar('*');
	Console::SetCursorPosition(p, q-3);
	putchar('*');
	Console::SetCursorPosition(p-1, q-3);
	putchar('*');
	Console::SetCursorPosition(p, q-4);
	putchar('*');
	Console::SetCursorPosition(p+1, q-5);
	putchar('*');
	Console::SetCursorPosition(p, q-5);
	putchar('*');
	Console::SetCursorPosition(p-1, q-5);
	putchar('*');
	Console::SetCursorPosition(p+1, q-6);
	putchar('*');
	Console::SetCursorPosition(p-1, q-6);
	putchar('*');
	Console::SetCursorPosition(p+1, q-7);
	putchar('*');
	Console::SetCursorPosition(p, q-7);
	putchar('*');
	Console::SetCursorPosition(p-1, q-7);
	putchar('*');
}
void Hide_Stickman(int p, int q)
{
	Console::SetCursorPosition(p, q);
	putchar(' ');
	Console::SetCursorPosition(p + 1, q);
	putchar(' ');
	Console::SetCursorPosition(p - 1, q);
	putchar(' ');
	Console::SetCursorPosition(p + 2, q + 1);
	putchar(' ');
	Console::SetCursorPosition(p - 2, q + 1);
	putchar(' ');
	Console::SetCursorPosition(p, q - 1);
	putchar(' ');
	Console::SetCursorPosition(p, q - 2);
	putchar(' ');
	Console::SetCursorPosition(p + 2, q - 2);
	putchar(' ');
	Console::SetCursorPosition(p - 2, q - 2);
	putchar(' ');
	Console::SetCursorPosition(p + 1, q - 3);
	putchar(' ');
	Console::SetCursorPosition(p, q - 3);
	putchar(' ');
	Console::SetCursorPosition(p - 1, q - 3);
	putchar(' ');
	Console::SetCursorPosition(p, q - 4);
	putchar(' ');
	Console::SetCursorPosition(p + 1, q - 5);
	putchar(' ');
	Console::SetCursorPosition(p, q - 5);
	putchar(' ');
	Console::SetCursorPosition(p - 1, q - 5);
	putchar(' ');
	Console::SetCursorPosition(p + 1, q - 6);
	putchar(' ');
	Console::SetCursorPosition(p - 1, q - 6);
	putchar(' ');
	Console::SetCursorPosition(p + 1, q - 7);
	putchar(' ');
	Console::SetCursorPosition(p, q - 7);
	putchar(' ');
	Console::SetCursorPosition(p - 1, q - 7);
	putchar(' ');
}
void Stickman_Animation(int p,int q)
{
	int i;
	for (i = 0; i <= 5; i++)
	{
		Show_Stickman(p, q-i);
		Thread::Sleep(50);
		Hide_Stickman(p, q-i);
	}
	q -= 5;
	for (i = 0; i <= 13; i++)
	{
		Show_Stickman(p+i, q);
		Thread::Sleep(50);
		Hide_Stickman(p+i, q);
	}
	p +=13;
	for (i = 0; i <= 5; i++)
	{
		Show_Stickman(p, q + i);
		Thread::Sleep(50);
		Hide_Stickman(p, q + i);
	}
	q += 5;
	Show_Stickman(p, q);
}
void hack(int p, int q)
{
	int i;
	for (i = 0; i <= 13; i++)
	{
		Show_Stickman(p - i, q);
		Thread::Sleep(50);
		Hide_Stickman(p - i, q);
	}
}

void main()
{
	int r = 1, *p;
	p = &r;
	do
	{
		Console::Clear();
		Road(5);
		Road(20);
		Show_Stickman(45, 18);
		Obstacle_Animation(100,19);
		Console::Clear();
		Road(5);
		Road(20);
		Show_Obstacle(50,19);
		Stickman_Animation(45, 18);
		Obstacle_Animation(50,19);
		hack(58, 18);
		Show_Stickman(45, 18);
		Obstacle_Animation(100, 10);
		Obstacle_Animation(50, 10);
	} while (*p==1);
	Console::Read();
}
