#ifndef _GAMEOFLIFE_
#define _GAMEOFLIFE_
#define MAXLEGTH 100  		//max size of the map is 100*100
#define MINLEGTH 4  		//min size of the map is 4*4

enum status
{
	alive = 1,
	dead = 0
};

class GameMap
{
public:
	explicit GameMap();
	~GameMap(){};
	GameMap(int size);
	GameMap(const GameMap &);
	void addResident(int row, int col);
	status isAlive(int row, int col);
	void nextGeneration();
	int aliveNeighbour(int row, int col);

private:
	int MapSize=8;			//the default size is 8*8
	status Map[MAXLEGTH][MAXLEGTH];
};


#endif
