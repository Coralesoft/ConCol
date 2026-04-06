// bouncing_ball.cpp - simple animation test
// Compile: g++ -std=c++17 bouncing_ball.cpp ../concol.cpp -o bouncing_ball

#include "../concol.hpp"
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	concol con;
	con.ClearScreen();

	con.setForeground(Yellow);
	con.goto_XY(28, 1);
	cout << "Bouncing Ball";

	// draw the ground
	con.setForeground(Green);
	for (int x = 0; x < 78; x++) {
		con.goto_XY(x, 20);
		cout << "=";
	}

	int ballX = 0, ballY = 5;
	int vx = 1, vy = 1;
	int ground = 19;

	con.setForeground(LtCyan);
	for (int frame = 0; frame < 300; frame++)
	{
		// erase old pos
		con.goto_XY(ballX, ballY);
		cout << " ";

		ballX += vx;
		ballY += vy;

		// bounce off walls
		if (ballX <= 0 || ballX >= 77) {
			vx = -vx;
			ballX += vx;
		}
		// bounce off ground/ceiling
		if (ballY >= ground) {
			vy = -1;
			ballY = ground;
		}
		if (ballY <= 4) {
			vy = 1;
			ballY = 4;
		}

		// draw ball
		con.goto_XY(ballX, ballY);
		cout << "O";

		// gravity - speed up when falling
		if (ballY < ground && frame % 3 == 0 && vy < 2)
			vy++;

		Sleep(30);
	}

	con.setForeground(White);
	con.goto_XY(28, 22);
	cout << "Done!";
	con.goto_XY(0, 24);
	return 0;
}
