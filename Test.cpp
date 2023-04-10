#include "./sources/Player.hpp"
#include "./sources/Game.hpp"
#include "./sources/Card.hpp"
#include "doctest.h"

TEST_CASE("player mode")
{
    Player Alice("Alice");
    Player Bob("Bob");
    CHECK(Alice.cardesTaken() == 0);
    CHECK(Bob.cardesTaken() == 0);
    CHECK(Alice.stacksize() == 26);
    CHECK(Bob.stacksize() == 26);
    Game first(Alice, Bob);
    CHECK_THROWS(Player(NULL));
    first.playAll();
    CHECK(Alice.cardesTaken() != Bob.cardesTaken());
    CHECK(Alice.stacksize() == Bob.stacksize());
    bool ChangeCardesTaken = (Alice.cardesTaken() >= 2) || (Bob.cardesTaken() >= 2);
    bool ChangeStackSize = (Alice.stacksize() < 26) && (Bob.stacksize() < 26);
    CHECK(ChangeCardesTaken);
    CHECK(ChangeStackSize);
}

TEST_CASE("game on")
{
    Player p1("Alice");
    Player p2("Bob");
    Game first(p1, p2);
    CHECK_THROWS(Game(p1, p2));
    Player sameplayer("samesame");
    CHECK_THROWS(Game(sameplayer, sameplayer));
    CHECK_THROWS(first.printLastTurn());
    CHECK_THROWS(first.printLog());
    CHECK_THROWS(first.playAll());
    bool TotalCardesTaken = p1.cardesTaken() + p2.cardesTaken() == 52;
    bool EmptyStackSize = p1.stacksize() == 0 && p2.stacksize() == 0;
    CHECK(TotalCardesTaken);
    CHECK(EmptyStackSize);
    CHECK_THROWS(first.playTurn());
    CHECK_THROWS(first.playAll());
    // the end of the first game
    Player p3("adam");
    Player p4("david");
    CHECK_NOTHROW(Game(p1,p4));
    CHECK_NOTHROW(Game(p2,p3));
    }