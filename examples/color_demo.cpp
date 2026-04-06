// color_demo.cpp - shows all the colours available
// Compile: g++ -std=c++17 color_demo.cpp ../concol.cpp -o color_demo

#include "../concol.hpp"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	concol con;
	con.setForeground(White);
	con.setBackground(Black);
	con.ClearScreen();

	con.goto_XY(25, 1);
	con.setForeground(Yellow);
	cout << "ConCol Colour Demo";

	// foreground colours
	const int fgCol[] = {Black, Blue, Red, Green, Cyan, Magenta, Orange, DkGray,
	                     LtGray, LtBlue, LtRed, LtGreen, LtCyan, LtMagenta, Yellow, White};

	const char* fgName[] = {"Black", "Blue", "Red", "Green", "Cyan", "Magenta", "Orange", "DkGray",
	                        "LtGray", "LtBlue", "LtRed", "LtGreen", "LtCyan", "LtMagenta", "Yellow", "White"};

	for (int i = 0; i < 16; i++) {
		con.setForeground(fgCol[i]);
		con.goto_XY(5, 3 + i);
		cout << fgName[i];
		con.goto_XY(18, 3 + i);
		cout << "The quick brown fox jumps over the lazy dog";
	}

	con.setForeground(White);
	con.goto_XY(5, 21);
	cout << "Press any key for background colours...";
	_getch();

	// background colours
	con.ClearScreen();
	con.setForeground(Yellow);
	con.goto_XY(25, 1);
	cout << "Background Colours";

	const int bgCol[] = {bBlue, bRed, bGreen, bCyan, bMagenta, bOrange, bDkGray,
	                     bLtGray, bLtBlue, bLtRed, bLtGreen, bLtCyan, bLtMagenta, bYellow, bWhite};

	const char* bgName[] = {"bBlue", "bRed", "bGreen", "bCyan", "bMagenta", "bOrange", "bDkGray",
	                        "bLtGray", "bLtBlue", "bLtRed", "bLtGreen", "bLtCyan", "bLtMagenta", "bYellow", "bWhite"};

	for (int i = 0; i < 15; i++) {
		con.setForeground(Black);
		con.setBackground(bgCol[i]);
		con.goto_XY(5, 3 + i);
		cout << " " << bgName[i] << " - background colour demo text         ";
	}

	con.setForeground(White);
	con.setBackground(Black);
	con.goto_XY(5, 20);
	cout << "Press any key to exit...";
	_getch();

	con.goto_XY(0, 23);
	return 0;
}
