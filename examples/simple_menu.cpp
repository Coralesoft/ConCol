// simple_menu.cpp - menu system demo
// Compile: g++ -std=c++17 simple_menu.cpp ../concol.cpp -o simple_menu

#include "../concol.hpp"
#include <iostream>
using namespace std;

void drawMenu(concol &con)
{
	con.ClearScreen();

	// title bar
	con.setForeground(Yellow);
	con.setBackground(bBlue);
	con.goto_XY(0, 0);
	cout << "                                                                                ";
	con.goto_XY(28, 0);
	cout << " MAIN MENU ";
	con.setBackground(Black);

	// border and options
	con.setForeground(LtGreen);
	con.goto_XY(23, 6);
	cout << "+-------------------------+";
	for (int y = 7; y <= 12; y++) {
		con.goto_XY(23, y);
		cout << "|";
		con.goto_XY(49, y);
		cout << "|";
	}
	con.goto_XY(23, 13);
	cout << "+-------------------------+";

	con.setForeground(White);
	con.goto_XY(25, 7);
	cout << "1. Start New Game";
	con.goto_XY(25, 8);
	cout << "2. Load Game";
	con.goto_XY(25, 9);
	cout << "3. Options";
	con.goto_XY(25, 10);
	cout << "4. Help";
	con.goto_XY(25, 11);
	cout << "5. Exit";

	con.setForeground(LtGray);
	con.goto_XY(22, 16);
	cout << "Enter your choice (1-5): ";
}

int main()
{
	concol con;
	int choice = 0;

	do {
		drawMenu(con);
		cin >> choice;

		con.ClearSect(0, 18);
		con.goto_XY(25, 19);

		switch(choice) {
		case 1:
			con.setForeground(LtCyan);
			cout << "Starting new game...";
			break;
		case 2:
			con.setForeground(LtCyan);
			cout << "Loading saved game...";
			break;
		case 3:
			con.setForeground(LtCyan);
			cout << "Opening options...";
			break;
		case 4:
			con.setForeground(LtCyan);
			cout << "Help screen goes here...";
			break;
		case 5:
			con.setForeground(LtCyan);
			cout << "Goodbye!";
			break;
		default:
			con.setForeground(LtRed);
			cout << "Invalid choice!";
		}

		if (choice != 5) {
			con.setForeground(LtGray);
			con.goto_XY(22, 21);
			cout << "Press Enter to continue...";
			cin.ignore();
			cin.get();
		}
	} while (choice != 5);

	con.setForeground(White);
	con.goto_XY(0, 23);
	return 0;
}
