#include "GameOfLife.h"
#include "CppUTest/TestHarness.h"


TEST_GROUP(GameOfLife)
{
    GameMap * hhg;

    void setup()
    {
        hhg = new GameMap();
    }
    void teardown()
    {
        delete hhg;
    }
};

TEST(GameOfLife, AliveCell_2AliveNeighbours_ShouldBeAlive)
{
    hhg->addResident(3,3);
    hhg->addResident(2,2);
    hhg->addResident(2,3);
    hhg->nextGeneration();
    CHECK_EQUAL(1,hhg->getStatus(3,3));
}

TEST(GameOfLife, AliveCell_3AliveNeighbours_ShouldBeAlive)
{
    // a simple example to start you off
    hhg->addResident(3,3);
    hhg->addResident(2,2);
    hhg->addResident(2,3);
    hhg->addResident(2,4);
    hhg->nextGeneration();
    CHECK_EQUAL(1,hhg->getStatus(3,3));
    //LONGS_EQUAL(42, hhg->answer());
    //CHECK(1);
    //CHECK_TRUE(1);
    //CHECK_FALSE(0);
    //STRCMP_EQUAL("hey", "hey");
    //FAIL("Start here");
}

TEST(GameOfLife, AliveCell_LessThan2AliveNeighbours_ShouldBeDead)
{
    hhg->addResident(3,3);
    hhg->nextGeneration();
    CHECK_EQUAL(0,hhg->getStatus(3,3));
}

TEST(GameOfLife, AliveCell_MoreThan3AliveNeighbours_ShouldBeDead)
{
    hhg->addResident(3,3);
    hhg->addResident(2,2);
    hhg->addResident(2,3);
    hhg->addResident(2,4);
    hhg->addResident(3,4);
    hhg->nextGeneration();
    CHECK_EQUAL(0,hhg->getStatus(3,3));
}

TEST(GameOfLife, DeadCell_3AliveNeighbours_ShouldBeAlive)
{
    hhg->addResident(2,2);
    hhg->addResident(2,3);
    hhg->addResident(2,4);
    hhg->nextGeneration();
    CHECK_EQUAL(1,hhg->getStatus(3,3));
}