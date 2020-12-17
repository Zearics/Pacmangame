#include "Ghost.h"
#include <iostream>


void ghost::Ghost::setColor(int color)
{
	m_color = color;
	m_originalColor = color;
}

void ghost::Ghost::setPos(int xPos, int yPos)
{
	m_XPos = xPos;
	m_YPos = yPos;
}

void ghost::Ghost::setTarget(int xPos, int yPos)
{
	m_targetX = xPos;
	m_targetY = yPos;
}

void ghost::Ghost::setDirection(char dir)
{
	m_Dir = dir;
}

void ghost::Ghost::setVulnerable(bool powerup)
{
	b_vulnerable = powerup;
}

int ghost::Ghost::getColor()
{
	return m_color;
}

int ghost::Ghost::getXPos()
{
	return m_XPos;
}

int ghost::Ghost::getYPos()
{
	return m_YPos;
}

int ghost::Ghost::getWait()
{
	return m_wait;
}

char ghost::Ghost::getDirection()
{
	return m_Dir;
}

void ghost::Ghost::move(bool collision)
{
	m_wait = 0;
	if (m_wait == 0) {
		if (m_Dir == 'w' && collision)
			m_YPos--;
		if (m_Dir == 'a' && collision)
			if (m_XPos == 2) m_XPos = 55;
			else m_XPos--;
		if (m_Dir == 's' && collision)
			m_YPos++;
		if (m_Dir == 'd' && collision)
			if (m_XPos == 55) m_XPos = 2;
			else m_XPos++;
	}
}

void ghost::Ghost::pathing(char** world)
{
	m_board[m_targetY][m_targetX] = 0;
	int count = 1;
	for (int i = (m_targetX - 1); i >= 0; i--) {
		m_board[m_targetY][i] = count;
		count++;
	}
	count = 1;
	for (int i = (m_targetX + 1); i < 57; i++) {
		m_board[m_targetY][i] = count;
		count++;
	}
	for (int i = (m_targetY - 1); i >= 0; i--) {
		for (int j = 0; j < 57; j++) {
			m_board[i][j] = m_board[i + 1][j] + 1;
		}
	}
	for (int i = (m_targetY + 1); i < 19; i++) {
		for (int j = 0; j < 57; j++) {
			m_board[i][j] = m_board[i - 1][j] + 1;
		}
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 57; j++) {
			if (world[i][j] == char(219)) {
				m_board[i][j] = 100;
				m_board[i][j + 1] = 100;
				m_board[i][j - 1] = 100;
			}
			//if (world[i][j] == 0 && world[i][j - 1] || world[i][j] == 0 && world[i][j + 1] == 219) m_board[i][j] = 100;
		}
	}
	int a = m_board[m_YPos][m_XPos];
	int b = m_board[m_YPos - 1][m_XPos];
	int c = m_board[m_YPos + 1][m_XPos];
	int d = m_board[m_YPos][m_XPos - 1];
	int e = m_board[m_YPos][m_XPos + 1];
	if (m_board[m_YPos - 1][m_XPos] < m_board[m_YPos][m_XPos]) {
		if (b_vulnerable) m_Dir = 's';
		else m_Dir = 'w';
	}
	if (m_board[m_YPos + 1][m_XPos] < m_board[m_YPos][m_XPos]) {
		if (b_vulnerable) m_Dir = 'w';
		else m_Dir = 's';
	}
	if (m_board[m_YPos][m_XPos - 1] < m_board[m_YPos][m_XPos]) {
		if (b_vulnerable) m_Dir = 'd';
		else m_Dir = 'a';
	}
	if (m_board[m_YPos][m_XPos + 1] < m_board[m_YPos][m_XPos]) {
		if (b_vulnerable) m_Dir = 'a';
		else m_Dir = 'd';
	}
}

void ghost::Ghost::die()
{
}

void ghost::Ghost::draw(char** world)
{
	std::cout << std::endl;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 57; j++) {
			std::cout << m_board[i][j] << ",";
		}
		std::cout << std::endl;
	}
}



