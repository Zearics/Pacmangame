#include "Pac.h"
#include "World.h"

void pac::Pac::move(bool collision)
{	
	if (m_Dir == 'w' && collision)
		m_YPos--;
	if (m_Dir == 'a' && collision)
		if (m_XPos == 2) m_XPos = 57;
		else m_XPos--;
	if (m_Dir == 's' && collision)
		m_YPos++;
	if (m_Dir == 'd' && collision) {
		if (m_XPos == 55) m_XPos = 0;
		else m_XPos++;
	}
}

void pac::Pac::setDirection(char dir)
{
	m_Dir = dir;
}

void pac::Pac::setPos()
{
	m_YPos = 13;
	m_XPos = 28;
}

int pac::Pac::getXPos()
{
	return m_XPos;
}

int pac::Pac::getYPos()
{
	return m_YPos;
}

char pac::Pac::getDir()
{
	return m_Dir;
}
