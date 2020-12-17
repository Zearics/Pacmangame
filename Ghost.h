#pragma once

namespace ghost {
	class Ghost
	{
	public:
		void setColor(int color);
		void setPos(int xPos, int yPos);
		void setTarget(int xPos, int yPos);
		void setDirection(char dir);
		void setVulnerable(bool powerup);
		int getColor();
		int getXPos();
		int getYPos();
		int getWait();
		char getDirection();
		void move(bool collision);
		void pathing(char** world);
		void die();
		void draw(char** world);
		

	private:
		int m_wait;
		int m_color;
		int m_originalColor;
		int m_XPos;
		int m_YPos;
		int m_targetX;
		int m_targetY;
		int m_board[19][57];
		char m_Dir;
		bool b_vulnerable;
	};
}

