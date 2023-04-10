#include "Player.hpp"
#include "Card.hpp"

using namespace std;
using namespace ariel;

Player ::Player()
{
    this->name = "";
    this->wins = 0;
    this->taken = 0;
    this->lastcard = "";
    this->cards = stack<Card>();
}

Player ::Player(string name)
{
    this->name = name;
    this->wins = 0;
    this->taken = 0;
    this->lastcard = "";
    this->cards = stack<Card>();
}

string Player ::getname() 
{
    return this->name;
}

void Player ::pushCard(int num, string kind)
{
    this->cards.push(Card(num, kind));
}

void Player ::PopLastCard()
{
    this->cards.pop();
}

Card Player ::TopCards()
{
    return this->cards.top();
}

int Player ::getwins()
{
    return this->wins;
}

void Player ::setwins()
{
    this->wins++;
}

int Player ::gettaken()
{
    return this->taken;
}

void Player ::settaken(int t)
{
    this->taken += t;
}

string Player ::getlastcard()
{
    return this->lastcard;
}

void Player ::setlastcard(string cardd)
{
    this->lastcard = cardd;
}

int Player ::cardesTaken() 
{
    return this->taken;
}

int Player ::stacksize() 
{
    return cards.size();
}