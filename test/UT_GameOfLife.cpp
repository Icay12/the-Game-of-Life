#include "GameOfLife.h"
#include "CppUTest/TestHarness.h"


TEST_GROUP(TheGameOfLife)
{
    GameOfLife * game;

    void setup()
    {
        game = new GameOfLife();
    }
    void teardown()
    {
        delete game;
    }
};

TEST(TheGameOfLife, AliveCell_2AliveNeighbours_ShouldBeAlive)
{
    game->addResident(3,3);
    game->addResident(2,2);
    game->addResident(2,3);
    game->nextGeneration();
    CHECK_EQUAL(alive,game->isAlive(3,3));
}

TEST(TheGameOfLife, AliveCell_3AliveNeighbours_ShouldBeAlive)
{
    game->addResident(3,3);
    game->addResident(2,2);
    game->addResident(2,3);
    game->addResident(2,4);
    game->nextGeneration();
    CHECK_EQUAL(alive,game->isAlive(3,3));
}

TEST(TheGameOfLife, AliveCell_LessThan2AliveNeighbours_ShouldBeDead)
{
    game->addResident(3,3);
    game->nextGeneration();
    CHECK_EQUAL(dead,game->isAlive(3,3));
}

TEST(TheGameOfLife, AliveCell_MoreThan3AliveNeighbours_ShouldBeDead)
{
    game->addResident(3,3);
    game->addResident(2,2);
    game->addResident(2,3);
    game->addResident(2,4);
    game->addResident(3,4);
    game->nextGeneration();
    CHECK_EQUAL(dead,game->isAlive(3,3));
}

TEST(TheGameOfLife, DeadCell_3AliveNeighbours_ShouldBeAlive)
{
    game->addResident(2,2);
    game->addResident(2,3);
    game->addResident(2,4);
    game->nextGeneration();
    CHECK_EQUAL(alive,game->isAlive(3,3));
}
