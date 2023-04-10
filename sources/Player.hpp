#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stack>
#include <string>
#include "Card.hpp"

using namespace std;
using namespace ariel;

class Player
{
private:
    string name;
    string lastcard;
    stack<Card> cards;
    int wins;
    int taken;

public:
    Player();
    Player(string name);
    string getname();
    int getwins();
    void setwins();
    int gettaken();
    void settaken(int t);
    string getlastcard();
    void setlastcard(string cardd);
    void pushCard(int num, string kind);
    void PopLastCard();
    Card TopCards();
    int cardesTaken();
    int stacksize();
};
#endif