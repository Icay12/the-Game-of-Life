#ifndef _GAMEOFLIFE_
#define _GAMEOFLIFE_
#define MAXLEGTH 100  		//max size of the map is 100*100
#define MINLEGTH 4  		//min size of the map is 4*4

enum status
{
    alive = 1,
    dead = 0
};

class GameOfLife
{
public:
    explicit GameOfLife();
    ~GameOfLife(){}
    GameOfLife(int size);
    GameOfLife(const GameOfLife &);
    void addResident(int row, int col);
    status isAlive(int row, int col);
    void nextGeneration();
    int aliveNeighbour(int row, int col);

private:
    int m_MapSize;
    status m_Map[MAXLEGTH][MAXLEGTH];
};


#endif
