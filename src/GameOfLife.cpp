#include "GameOfLife.h"

//initialize the cells with default value 8*8
GameOfLife::GameOfLife()
{
    int row,col;
    for ( row = 0; row < this->m_MapSize; ++row)
    {
        for (col = 0; col < this->m_MapSize; ++col)
        {
            this->m_Map[row][col] = dead;
        }
    }
}

//initialize the cells with given value
GameOfLife::GameOfLife(int size)
{
    if( size < MINLEGTH)
    {
        size = MINLEGTH;
    }
    int row = 0;
    int col = 0;
    this->m_MapSize = size;
    for ( ; row < size; ++row)
    {
        for (  ; col < size; ++col)
        {
            this->m_Map[row][col] = dead;
        }
    }
}


void GameOfLife::addResident(int row, int col)
{
    if ( row<1 || col>(this->m_MapSize-1) )
    {
        return;
    }
    this->m_Map[row][col] = alive;

}


status GameOfLife::isAlive(int row, int col)
{
    return this->m_Map[row][col];
}

void GameOfLife::nextGeneration()
{
    int row;
    int col;
    status nextMap[MAXLEGTH][MAXLEGTH];
    //set up a temp map
    for ( row = 0 ; row < this->m_MapSize; ++row)
    {
        for ( col = 0  ; col < this->m_MapSize; ++col)
        {
            nextMap[row][col] = dead;
        }
    }

    //no consideration of cells on the sides 
    for ( row = 1; row < (this->m_MapSize - 1); ++row)
    {
        for ( col = 1; col < (this->m_MapSize - 1); ++col)
        {
            if ( this->m_Map[row][col] && (this->aliveNeighbour(row,col) == 2) )
            {
                nextMap[row][col] = alive;
            }
            else if ( this->aliveNeighbour(row,col) == 3 )
            {
                nextMap[row][col] = alive;
            }
            else
            {
                nextMap[row][col] = dead;
            }
        }
    }
    //copy to the current map
    for ( row = 1 ; row < (this->m_MapSize - 1); ++row)
    {
        for ( col = 1  ; col < (this->m_MapSize - 1); ++col)
        {
            this->m_Map[row][col] = nextMap[row][col];
        }
    }

}


int GameOfLife::aliveNeighbour(int row, int col)
{
    //no need to care about the edges here
    int count = 0;
    count = this->m_Map[row-1][col-1] + this->m_Map[row-1][col] + this->m_Map[row-1][col+1] \
        +this->m_Map[row][col-1]+ this->m_Map[row][col+1] \
        +this->m_Map[row+1][col-1] + this->m_Map[row+1][col] + this->m_Map[row+1][col+1];
    return count;
}
