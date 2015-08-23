#include "GameOfLife.h"

//initialize the cells with default value 8*8
GameMap::GameMap()
{
	int row,col;
	for(row=0; row<this->MapSize; ++row)
		for(col=0; col<this->MapSize; ++col)
			this->Map[row][col] = dead;
}

//initialize the cells with given value
GameMap::GameMap(int size)
{
	if(size < MINLEGTH)
		size = MINLEGTH;
	int row = 0;
	int col = 0;
	this->MapSize = size;
	for( ; row<size; ++row)
		for(  ; col<size; ++col)
			this->Map[row][col] = dead;
}

//add residents to the map
void GameMap::addResident(int row, int col)
{
    if( row<1 || col>(this->MapSize-1) )
            return;
	this->Map[row][col] = alive;
      
}

//get the status of the given cell
status GameMap::getStatus(int row, int col)
{
	return this->Map[row][col];
}
//generate next generation
void GameMap::nextGeneration()
{
	int row;
	int col;
    status tempMap[MAXLEGTH][MAXLEGTH];
    //set up a temp map
    for( row=0 ; row<this->MapSize; ++row)
		for( col=0  ; col<this->MapSize; ++col)
			tempMap[row][col] = dead;

	//no consideration of cells on the sides 
	for( row=1; row<(this->MapSize-1); ++row)
		for( col=1; col<(this->MapSize-1); ++col)
		{
			if( this->Map[row][col] && (this->aliveNeighbour(row,col)==2) )
				tempMap[row][col] = alive;
			else if( this->aliveNeighbour(row,col)==3 )
				tempMap[row][col] = alive;
			else
				tempMap[row][col] = dead;
		}

	//copy to the current map
    for( row=1 ; row<(this->MapSize-1); ++row)
		for( col=1  ; col<(this->MapSize-1); ++col)
			this->Map[row][col] = tempMap[row][col];

}

//count alive neighbours
int GameMap::aliveNeighbour(int row, int col)
{
	//no need to care about the edges here
	int count = 0;
	count = this->Map[row-1][col-1] + this->Map[row-1][col] + this->Map[row-1][col+1] \
			+this->Map[row][col-1]+ this->Map[row][col+1] \
			+this->Map[row+1][col-1] + this->Map[row+1][col] + this->Map[row+1][col+1];
	return count;
}