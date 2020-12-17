#include "World.h"
#include <iostream>
#include <Windows.h>
using namespace world;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void World::setWorld()
{
	char b = 219;
	char p = 248;
	char P = 233;
	char temp[19][57] = {
		{ b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b },
		{ b,b,b,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,b,b,b,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,b,b,b },
		{ b,b,b,0,P,0,b,b,b,b,b,b,0,p,0,b,b,b,b,b,b,b,b,b,0,p,0,b,b,b,0,p,0,b,b,b,b,b,b,b,b,b,0,p,0,b,b,b,b,b,b,0,P,0,b,b,b },
		{ b,b,b,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,b,b,b },
		{ b,b,b,0,p,0,b,b,b,b,b,b,0,p,0,b,b,b,0,p,0,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,0,p,0,b,b,b,0,p,0,b,b,b,b,b,b,0,p,0,b,b,b },
		{ b,b,b,0,p,0,0,p,0,0,p,0,0,p,0,b,b,b,0,p,0,0,p,0,0,p,0,b,b,b,0,p,0,0,p,0,0,p,0,b,b,b,0,p,0,0,p,0,0,p,0,0,p,0,b,b,b },
		{ b,b,b,b,b,b,b,b,b,b,b,b,0,p,0,b,b,b,b,b,b,b,b,b,0,0,0,b,b,b,0,0,0,b,b,b,b,b,b,b,b,b,0,p,0,b,b,b,b,b,b,b,b,b,b,b,b },
		{ b,b,b,b,b,b,b,b,b,b,b,b,0,p,0,b,b,b,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,b,b,b,0,p,0,b,b,b,b,b,b,b,b,b,b,b,b },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,p,0,0,0,0,0,0,0,b,b,b,b,b,1,1,0,1,1,b,b,b,b,b,0,0,0,0,0,0,0,p,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ b,b,b,b,b,b,b,b,b,b,b,b,0,p,0,b,b,b,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,b,b,b,0,p,0,b,b,b,b,b,b,b,b,b,b,b,b },
		{ b,b,b,b,b,b,b,b,b,b,b,b,0,p,0,b,b,b,0,0,0,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,0,0,0,b,b,b,0,p,0,b,b,b,b,b,b,b,b,b,b,b,b },
		{ b,b,b,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,b,b,b,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,b,b,b },
		{ b,b,b,0,p,0,b,b,b,b,b,b,0,p,0,b,b,b,b,b,b,b,b,b,0,p,0,b,b,b,0,p,0,b,b,b,b,b,b,b,b,b,0,p,0,b,b,b,b,b,b,0,p,0,b,b,b },
		{ b,b,b,0,P,0,0,p,0,b,b,b,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,b,b,b,0,p,0,0,P,0,b,b,b },
		{ b,b,b,b,b,b,0,p,0,b,b,b,0,p,0,b,b,b,0,p,0,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,0,p,0,b,b,b,0,p,0,b,b,b,0,p,0,b,b,b,b,b,b },
		{ b,b,b,0,p,0,0,p,0,0,p,0,0,p,0,b,b,b,0,p,0,0,p,0,0,p,0,b,b,b,0,p,0,0,p,0,0,p,0,b,b,b,0,p,0,0,p,0,0,p,0,0,p,0,b,b,b },
		{ b,b,b,0,p,0,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,0,p,0,b,b,b,0,p,0,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,0,p,0,b,b,b },
		{ b,b,b,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,0,p,0,b,b,b },
		{ b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b }
	};
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 57; j++)
			m_world[i][j] = temp [i][j];
	}
}

void world::World::setPacPos(int xPos, int yPos)
{
	m_world[yPos][xPos] = 'O';
}

void world::World::setGhostPos(int xPos, int yPos, char color) {
	m_world[yPos][xPos] = color;
}

void world::World::setScore()
{
	m_score = 0;
}

char** world::World::getWorld()
{
	char** world = 0;
	world = new char* [19];
	for (int i = 0; i < 19; i++) {
		world[i] = new char[57];
		for (int j = 0; j < 57; j++) {
			world[i][j] = m_world[i][j];
		}
	}
	return world;
}

void World::drawWorld()
{
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 57; j++) {
			if (m_world[i][j] == 'O') {
				SetConsoleTextAttribute(hConsole, 14);
				std::cout << 'O';
			}
			else if (m_world[i][j] == 6) {
				SetConsoleTextAttribute(hConsole, 6);
				std::cout << 'M';
			}
			else if (m_world[i][j] == char(219)) {
				SetConsoleTextAttribute(hConsole, 1);
				std::cout << char(219);
			}
			else {
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << m_world[i][j];
			}
		}
		std::cout << std::endl;
	}
}

void world::World::setIntersections()
{
}

void world::World::getIntersections()
{
}

void world::World::collectPoint(int xPos, int yPos, char dir)
{
	if (dir == 'w' && m_world[yPos - 1][xPos] == char(248)) {
		m_score += 10;
	}
	if (dir == 'a' && m_world[yPos][xPos - 1] == char(248)) {
		m_score += 10;
	}
	if (dir == 's' && m_world[yPos + 1][xPos] == char(248)) {
		m_score += 10;
	}
	if (dir == 'd' && m_world[yPos][xPos + 1] == char(248)) {
		m_score += 10;
	}

	if (dir == 'w' && m_world[yPos - 1][xPos] == char(233)) {
		m_score += 50;
		b_Powerup = true;
	}
	if (dir == 'a' && m_world[yPos][xPos - 1] == char(233)) {
		m_score += 50;
		b_Powerup = true;
	}
	if (dir == 's' && m_world[yPos + 1][xPos] == char(233)) {
		m_score += 50;
		b_Powerup = true;
	}
	if (dir == 'd' && m_world[yPos][xPos + 1] == char(233)) {
		m_score += 50;
		b_Powerup = true;
	}
}

void world::World::deleteTile(int xPos, int yPos)
{
	m_world[yPos][xPos] = 0;
}

bool world::World::collision(char dir, int xPos, int yPos)
{
	if (dir == 'w' && m_world[yPos - 1][xPos] != char(219) && m_world[yPos - 1][xPos - 1] != char(219) && m_world[yPos - 1][xPos + 1] != char(219))
		return true;
	else if (dir == 'a' && m_world[yPos][xPos - 2] != char(219) || xPos == 2)
		return true;
	else if (dir == 's' && m_world[yPos + 1][xPos] != char(219) && m_world[yPos + 1][xPos - 1] != char(219) && m_world[yPos + 1][xPos + 1] != char(219))
		return true;
	else if (dir == 'd' && m_world[yPos][xPos + 2] != char(219) || xPos == 55)
		return true;
	else return false;
}

void World::drawKey()
{
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "SCORE: " << m_score;
}
