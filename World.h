#pragma once
namespace world {
	class World
	{
	public:
		void setWorld();
		void setPacPos(int xPos, int yPos);
		void setGhostPos(int xPos, int yPos, char color);
		void setScore();
		char** getWorld();
		void drawWorld();
		void setIntersections();
		void getIntersections();
		void collectPoint(int xPos, int yPos, char dir);
		void deleteTile(int xPos, int yPos);

		bool collision(char dir, int xPos, int yPos);
		void drawKey();

	private:
		char m_world[19][57];
		int m_score;
		int m_lives;
		bool b_Powerup;
		//int intersections[][];
	};
}
