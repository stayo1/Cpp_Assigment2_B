#include "Game.hpp"
#include <string.h>
#include <random>
#include <algorithm>
#include <iostream>

using namespace std;
using namespace ariel;

#define Hearts 1
#define Diamonds 2
#define Clubs 3
#define Spades 4

Game ::Game(Player a, Player b)
{
    this->a = a;
    this->b = b;
    this->rounds = 0;
    this->counter = 0;
    this->draw = 0;
    this->lasturnwin = "";
    this->turnstats = new string[26];
    int kindCards[4] = {Hearts, Diamonds, Clubs, Spades};
    int AllCards[13][4] = {{Hearts, Diamonds, Clubs, Spades},
                           {Hearts, Diamonds, Clubs, Spades},
                           {Hearts, Diamonds, Clubs, Spades},
                           {Hearts, Diamonds, Clubs, Spades},
                           {Hearts, Diamonds, Clubs, Spades},
                           {Hearts, Diamonds, Clubs, Spades},
                           {Hearts, Diamonds, Clubs, Spades},
                           {Hearts, Diamonds, Clubs, Spades},
                           {Hearts, Diamonds, Clubs, Spades},
                           {Hearts, Diamonds, Clubs, Spades},
                           {Hearts, Diamonds, Clubs, Spades},
                           {Hearts, Diamonds, Clubs, Spades},
                           {Hearts, Diamonds, Clubs, Spades}};
    for (int i = 0; i < 26; i++)
    {
        DealCards(this->a, this->AllCards);
        DealCards(this->b, this->AllCards);
    }
}

void Game ::playTurn()
{
    if (&this->a == &this->b)
    {
        cout << "c'ant play with same player" << endl;
        return;
    }

    if (a.stacksize() || rounds < 26)
    {
        if (counter == 0)
        {
            counter = 2;
        }

        if ((a.TopCards().compare(b.TopCards())) < 0)
        {
            b.setwins();
            b.settaken(counter);
            a.setlastcard(a.TopCards().details());
            b.setlastcard(b.TopCards().details());
            a.PopLastCard();
            b.PopLastCard();
            counter = 0;
            lasturnwin = "Bob win";
            turnstats[rounds] = "Alice played" + a.getlastcard() + "Bob played" + b.getlastcard() + ". " + lasturnwin;
            rounds++;
        }

        else if ((a.TopCards().compare(b.TopCards())) > 0)
        {
            a.setwins();
            a.settaken(counter);
            a.setlastcard(a.TopCards().details());
            b.setlastcard(b.TopCards().details());
            a.PopLastCard();
            b.PopLastCard();
            counter = 0;
            lasturnwin = "Alice win";
            turnstats[rounds] += "Alice played" + a.getlastcard() + "Bob played" + b.getlastcard() + ". " + lasturnwin + ",";
            rounds++;
        }

        else
        {
            draw++;
            if (!a.stacksize() && !b.stacksize())
            {
                a.settaken(counter / 2);
                b.settaken(counter / 2);
                return;
            }
            a.PopLastCard();
            b.PopLastCard();
            a.setlastcard(a.TopCards().details());
            b.setlastcard(b.TopCards().details());
            counter += 4;
            lasturnwin = "draw";
            turnstats[rounds] += "Alice played" + a.getlastcard() + "Bob played" + b.getlastcard() + ". " + lasturnwin + ",";
            playTurn();
        }
    }

    else
    {
        cout << "the game its over or the card are done" << endl;
    }
}

void Game ::printLastTurn()
{
    if (!rounds)
    {
        cout << "The game hasn't started yet" << endl;
        return;
    }
    cout << turnstats[rounds - 1] << endl;
}

void Game ::playAll()
{
    while (a.stacksize() && rounds < 26)
    {
        playTurn();
    }
}

void Game ::printWiner()
{
    string winame;
    if (rounds > 0)
    {
        if (a.getwins() > b.getwins())
            winame = "Alice";
        else
        {
            winame = "Bob";
        }
        cout << "the winner of the all game is" + winame << endl;
    }
}

void Game ::printLog()
{
    for (int i = 0; i < 26; i++)
    {
        cout << turnstats[i] << endl;
    }
}

void Game ::printStats()
{
    cout << "Alice's number of wins is :" + to_string(a.getwins()) + "Alice's number of wins is :" + to_string(a.gettaken());
    cout << "Bob's number of wins is :" + to_string(b.getwins()), +"Bob's number of wins is :" + to_string(b.gettaken());
    cout << "The draw number is :" + to_string(draw);
}

void Game ::DealCards(Player p, int AllCards[13][4])
{
    bool getcard = false;
    int numcard = random() % 13;
    int kindcard = random() % 4;
    while (getcard)
    {
        if (AllCards[numcard][kindcard] != 0)
        {
            if (kindcard == Hearts)
            {
                p.pushCard(numcard, "Hearts");
                cout << "11111111" << endl;
            }
            else if (kindcard == Diamonds)
            {
                p.pushCard(numcard, "Diamonds");
                cout << "22222222" << endl;
            }
            else if (kindcard == Clubs)
            {
                p.pushCard(numcard, "Clubs");
                cout << "33333333333" << endl;
            }
            else if (kindcard == Spades)
            {
                p.pushCard(numcard, "Spades");
                cout << "44444444444" << endl;
            }
            getcard = true;
            AllCards[numcard][kindcard]--;
            cout << "ifffff" << endl;
        }
        else
        {
            int numcard = 1 + random() % 13;
            int kindcard = 1 + random() % 4;
            cout << "elseeeeee" << endl;
        }
    }
}