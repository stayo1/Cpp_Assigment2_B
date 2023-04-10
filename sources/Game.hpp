#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Card.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace ariel;

class Game
{
private:
    Player a;
    Player b;
    int rounds;
    int counter;
    int draw;
    int KindCards[4];
    int AllCards[13][4];
    string lasturnwin;
    string* turnstats;

public:
    Game(Player a, Player b);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printLog();
    void printWiner();
    void printStats();
    void DealCards(Player p, int kindofcards[13][4]);
};
#endif