#pragma once
namespace pac {
	class Pac
	{
	public:
		void setPos();
		int getXPos();
		int getYPos();
		char getDir();
		void move(bool collision);
		void setDirection(char dir);
	private:
		int m_XPos;
		int m_YPos;
		char m_Dir;
		bool b_Powerup;
	};
}

