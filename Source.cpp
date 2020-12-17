#include "World.h"
#include "Pac.h"
#include "Functions.h"
#include "Ghost.h"
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <string>
using namespace std;
using namespace world;
using namespace pac;
using namespace ghost;

int main()
{
	World world_1;
	Pac pacman;
	Ghost ghost_1;
	pacman.setPos();
	ghost_1.setPos(28, 8);
	ghost_1.setColor(6);
	char key = NULL;
	char** board = nullptr;
	int framecount = 0;
	world_1.setScore();
	world_1.setWorld();
	ghost_1.setDirection('w');
	ghost_1.setVulnerable(false);
	while (true) {
		char pacXPos = pacman.getXPos();
		char pacYPos = pacman.getYPos();

		if (_kbhit()) {
			key = _getch();
			if (key == 'x') return 0;
			pacman.setDirection(key);
		}

		world_1.collectPoint(pacXPos, pacYPos, key);
		world_1.deleteTile(pacXPos, pacYPos);
		bool collision = world_1.collision(key, pacXPos, pacYPos);
		pacman.move(collision);

		if (board)
			delete board;
		board = world_1.getWorld();
		ghost_1.setTarget(pacXPos, pacYPos);
		ghost_1.pathing(board);
		if (framecount < 10) {
			world_1.deleteTile(ghost_1.getXPos(), ghost_1.getYPos());
			ghost_1.move(world_1.collision(ghost_1.getDirection(), ghost_1.getXPos(), ghost_1.getYPos()));
			world_1.setGhostPos(ghost_1.getXPos(), ghost_1.getYPos(), 6);
			framecount++;
		}
		else
			framecount = 0;


		world_1.setPacPos(pacman.getXPos(), pacman.getYPos());
		world_1.drawWorld();
		world_1.drawKey();

		this_thread::sleep_for(chrono::milliseconds(100));
		ClearScreen();
	}
	
}