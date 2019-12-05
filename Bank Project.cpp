#include "stdafx.h"
#include "iostream"

using namespace System::Threading;
using namespace System;
using namespace std;

void show_bal();      // To show Banker Balance on every screen

ConsoleKey key;      // To take case input of switch-case
bool validkey(ConsoleKey key)             // To limit inputs within case of switch-case range
{
	switch (key)
	{
	case ConsoleKey::D1: return true; break;
	case ConsoleKey::D2: return true; break;
	case ConsoleKey::D3: return true; break;
	case ConsoleKey::D4: return true; break;
	case ConsoleKey::D5: return true; break;
	case ConsoleKey::D6: return true; break;
	case ConsoleKey::NumPad1: return true; break;
	case ConsoleKey::NumPad2: return true; break;
	case ConsoleKey::NumPad3: return true; break;
	case ConsoleKey::NumPad4: return true; break;
	case ConsoleKey::NumPad5: return true; break;
	case ConsoleKey::NumPad6: return true; break;
	default:return false;
	}
}       
ConsoleKey menu()       // To print display menu
{
	Console::Clear();
	show_bal();
	Console::SetCursorPosition(0, 2);
	cout << "\tEnter";
	cout << "\n\t\t'1' to add benifeciary.....";
	cout << "\n\t\t'2' to Show benifeciary List........";
	cout << "\n\t\t'3' to transfer amount from your account......";
	cout << "\n\t\t'4' to withdraw amount from your account.......";
	cout << "\n\t\t'5' to deposit amount in your account........";
	cout << "\n\t\t'6' to EXIT.....";

	key = Console::ReadKey(true).Key;
	while (!validkey(key))                               //
	{                                                   //
		Console::SetCursorPosition(10, 10);             // To run validity wile loop
		cout << "Please enter a valid key..........";   //
		key = Console::ReadKey(true).Key;               //
	}                                                   //

	return key;
}

int temp, temp1, temp2;   // Temporary Variable
int i, j;                 // Iteration Variable
int password;             // Password Variable
int incorrect = 3;        // Security Variable
int benif = -1;           // Benifeciary Record Variable

int ac_no = 0;            // Main A/C no.
char name[10];            // Main A/C name
char dob[8];              // Main A/C Date Of Birth
int balance;              // Main A/C Balance

struct benifeciary       // To keep benifeciary Data
{
	int ac_b;
	char name_b[10];
	char dob_b[8];
	int bal;
} b[5];               // Array handle of take multiple benifeciary

void welcome();      // Welcome Display
void pass();         // Password Display
void check();        // To make account Secure

void benifeciary();       // To take benifeciary detail
void show_bef();          // To show list of benifeciary
void transfer();          // To transfer amount from yur A/C to benifeciary
void withdrawl();         // To withdrawl money
void deposit();           // To depoosit money

class ac_detail        //     Input display
{
public:
	void input()
	{
		Console::Clear();
		Console::SetCursorPosition(10, 10);
		cout << "Account no.     : " << ac_no;
		Console::SetCursorPosition(10, 11);
		cout << "Name            : ";
		cin >> name;
		Console::SetCursorPosition(10, 12);
		cout << "Date Of Birth  (DD-MM-YY) : ";
		cin >> dob;
		Console::SetCursorPosition(10, 13);
		cout << "Balance         : ";
		cin >> balance;
		check();
	}
};

void main()
{
	ConsoleKey key;

	welcome();
	Thread::Sleep(2000);

	pass();
	ac_detail ac;
	ac.input();
	Console::BackgroundColor = ConsoleColor::Black;
	while (((key = menu()) != ConsoleKey::D6) || ((key = menu()) != ConsoleKey::NumPad6))
	{
		Console::Clear();
		switch (key)
		{
		case ConsoleKey::D1:
		case ConsoleKey::NumPad1: benifeciary(); break;
		case ConsoleKey::D2:
		case ConsoleKey::NumPad2: show_bef(); break;
		case ConsoleKey::D3:
		case ConsoleKey::NumPad3: transfer(); break;
		case ConsoleKey::D4:
		case ConsoleKey::NumPad4: withdrawl(); break;
		case ConsoleKey::D5:
		case ConsoleKey::NumPad5: deposit(); break;
		default: exit(-1); break;
		}
	}
	Console::Read();
}

void benifeciary()
{
	if (benif > 4)
	{
		Console::SetCursorPosition(10, 10);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "You can only add 5 benifeciary.....";
		Console::ForegroundColor = ConsoleColor::Yellow;
	}
	else
	{
		Console::Clear();
		show_bal();
		benif += 1;
		b[benif].ac_b = benif + 1;
		Console::SetCursorPosition(10, 5);
		Console::ForegroundColor = ConsoleColor::Yellow;

		cout << "Account no.     : ";
		Console::ForegroundColor = ConsoleColor::White;
		cout << b[benif].ac_b;
		Console::SetCursorPosition(10, 6);
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << "Name            : ";
		Console::ForegroundColor = ConsoleColor::White;
		cin >> b[benif].name_b;
		Console::SetCursorPosition(10, 7);
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << "Date Of Birth  (DD-MM-YY) : ";
		Console::ForegroundColor = ConsoleColor::White;
		cin >> b[benif].dob_b;
		Console::SetCursorPosition(10, 8);
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << "Balance         : ";
		Console::ForegroundColor = ConsoleColor::White;
		cin >> b[benif].bal;
	}
}
void show_bef()
{
	Console::Clear();
	show_bal();
	for (i = 0; i <= benif; i++)
	{
		if (i % 2 == 0)
			Console::ForegroundColor = ConsoleColor::DarkCyan;
		else
			Console::ForegroundColor = ConsoleColor::DarkMagenta;

		cout << "\t" << i + 1 << endl;
		cout << "\t" << b[i].name_b << endl;
		cout << "\t" << b[i].dob_b << endl;
		cout << "\t" << b[i].bal << endl << endl;
	}
	Console::Read();
}
void transfer()
{
	Console::Clear();
	show_bal();

	Console::SetCursorPosition(5, 5);
	Console::ForegroundColor = ConsoleColor::Magenta;
	cout << "Enter the A/C no. of the benifeciary : ";
	Console::ForegroundColor = ConsoleColor::Blue;
	cin >> temp;
	temp1 = temp - 1;

	if (temp - 1 <= benif)
	{
		Console::ForegroundColor = ConsoleColor::Magenta;
		Console::SetCursorPosition(5, 7);
		cout << "Enter the amount to be transfer : ";
		Console::ForegroundColor = ConsoleColor::Red;
		cin >> temp2;
		check();
		if (balance < temp2)
			cout << "Insufficient Balance......";
		else
		{
			balance = balance - temp2;
			b[temp1].bal = b[temp1].bal + temp2;
			cout << "Transection Sucessfull.......";
		}
		Console::Read();
	}
	else
	{
		Console::ForegroundColor = ConsoleColor::DarkRed;
		cout << "Invalid A/C no.......";
		Console::Read();
	}
}
void withdrawl()
{
	Console::Clear();
	show_bal();
	Console::SetCursorPosition(5, 5);
	Console::ForegroundColor = ConsoleColor::DarkGreen;
	cout << "Enter the amount to be withdrawl : ";
	cin >> temp;
	check;
	if (balance < temp)
		cout << "Insufficient Balance......";
	else
	{
		balance = balance - temp;
		cout << "Amount is Withdrawled.......";
	}
	Console::Read();	
}
void deposit()
{
	Console::Clear();
	show_bal();
	Console::SetCursorPosition(5, 5);
	Console::ForegroundColor = ConsoleColor::DarkBlue;
	cout << "Enter the amount to deposit : ";
	cin >> temp;
	balance += temp;
	cout << "Amount Deposited......";
	Console::Read();
}

void show_bal()
{
	if (balance >= 3000)
	{
		Console::ForegroundColor = ConsoleColor::Blue;
		cout << "A/C balance : " << balance;
		Console::ForegroundColor = ConsoleColor::Yellow;
	}
	else
	{
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "A/C balance : " << balance;
		Console::ForegroundColor = ConsoleColor::Yellow;
	}
}
void check()
{
	a:
	Console::SetCursorPosition(10, 20);
	cout << "Enter the password : ";
	cin >> temp;
	if (temp == password)
	{
		incorrect = 3;
	}
	else
	{
		if (incorrect == 0)
		{
			cout << "\n\n\t\tyou damm hacker.....";
			Thread::Sleep(2000);
			exit(-1);
		}
		else
		{
			Console::SetCursorPosition(5, 18);
			cout << "Incorrect password  try  again(" << incorrect << ")";
			for (i = 0; i < 4; i++)
			{
				Console::SetCursorPosition(31+i, 20);
				putchar(' ');
			}
			incorrect--;
			goto a;
		}
	}
}
void pass()
{
	Console::Clear();
	Console::BackgroundColor = ConsoleColor::White;
	Console::ForegroundColor = ConsoleColor::Black;
	Console::SetCursorPosition(33, 12);
	cout << "Enter a 4-digit no. password for security purpose : ";
	cin >> password;
}
void welcome()
{
	Console::ForegroundColor = ConsoleColor::DarkMagenta;
	Console::SetCursorPosition(51, 11);
	cout << "WELCOME";
	Console::ForegroundColor = ConsoleColor::DarkGreen;
	Console::SetCursorPosition(53, 12);
	cout << "To";
	Console::ForegroundColor = ConsoleColor::Cyan;
	Console::SetCursorPosition(50, 13);
	cout << "C++ BANK";

	Console::BackgroundColor = ConsoleColor::White;
	Console::ForegroundColor = ConsoleColor::DarkBlue;
	for (j = 9; j < 16; j++)
	{
		for (i = 47; i < 62; i++)
		{
			if ((i < 50 || i>58) || (j < 11 || j>13))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
			}
		}
	}
	Console::ForegroundColor = ConsoleColor::Red;
	for (j = 8; j < 17; j++)
	{
		for (i = 44; i < 65; i++)
		{
			if ((i < 47 || i > 61) || (j < 9 || j > 15))
			{
				Console::SetCursorPosition(i, j);
				putchar('*');
			}
		}
	}
	Console::ForegroundColor = ConsoleColor::Black;
	for (j = 7; j < 18; j++)
	{
		for (i = 43; i < 66; i++)
		{
			if ((i == 43 || i == 65) || (j == 7 || j ==17))
			{
				Console::SetCursorPosition(i, j);
				putchar(' ');
			}
		}
	}
}