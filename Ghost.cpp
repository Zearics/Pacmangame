#include "Ghost.h"


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
		if (m_Dir == 's' && collision && m_YPos != 8)
			m_YPos++;
		if (m_Dir == 'd' && collision)
			if (m_XPos == 55) m_XPos = 2;
			else m_XPos++;
	}
}

void ghost::Ghost::pathing(char** world)
{
	/*
	if (m_YPos < m_targetY) {
		char down = world[m_YPos + 1][m_XPos];
		char downright = world[m_YPos + 1][m_XPos + 1];
		char downleft = world[m_YPos + 1][m_XPos - 1];
		if (down != char(219)) {
			if (down == 0 && downleft == 0 && downright == 0 || down == char(248) && downleft == 0 && downright == 0 || down == 'O' && downleft == 0 && downright == 0) {
				m_Dir = 's';
				if (b_vulnerable) m_Dir = 'w';
			}
		}
	}
	if (m_YPos > m_targetY) {
		char up = world[m_YPos - 1][m_XPos];
		char upright = world[m_YPos - 1][m_XPos + 1];
		char upleft = world[m_YPos - 1][m_XPos - 1];
		if (up != char(219)) {
			if (up == 0 && upleft == 0 && upright == 0 || up == char(248) && upleft == 0 && upright == 0 || up == 'O' && upleft == 0 && upright == 0) {
				m_Dir = 'w';
				if (b_vulnerable) m_Dir = 's';
			}
		}
	}
	if (m_XPos < m_targetX) {
		char right = world[m_YPos][m_XPos + 1];
		char naught = 0;
		if (right == 0 || right == char(248) || right == 'O') {
			m_Dir = 'd';
			if (b_vulnerable) m_Dir = 'a';
		}
	}
	if (m_XPos > m_targetX) {
		char left = world[m_YPos][m_XPos - 1];
		if (left == 0 || left == char(248) || left == 'O') {
			m_Dir = 'a';
			if (b_vulnerable) m_Dir = 'd';
		}
	}
	*/

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
		for (int j = 1; j < 57; j++) {
			if (world[i][j] == 219) {
				m_board[i][j] = 100;
			}
			if (world[i][j] == 0) {
				char a = world[i][j + 1];
				char b = world[i][j - 1];
				if (a == 219 || b == 219) {
					m_board[i][j] = 100;
				}
			}
			if (world[i][j] == 1) m_board[i][j] = 100;
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



