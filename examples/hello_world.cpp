// hello_world.cpp - basic concol test
// Compile: g++ -std=c++17 hello_world.cpp ../concol.cpp -o hello_world

#include "../concol.hpp"
#include <iostream>
using namespace std;

int main()
{
	concol con;

	con.setForeground(LtGreen);
	con.setBackground(bBlue);
	con.ClearScreen();

	con.goto_XY(28, 10);
	cout << "Hello, Colourful World!";

	con.setForeground(Yellow);
	con.goto_XY(24, 12);
	cout << "Welcome to ConCol Library!";

	con.setForeground(White);
	con.setBackground(Black);
	con.goto_XY(0, 20);

	return 0;
}
