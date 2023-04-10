#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>

using namespace std;

namespace ariel{
class Card
{
private:
    int value;
    string kind;

public:
    Card(int value, string kind);
    Card();
    int getValue();
    string getKind();
    string details();
    int compare(Card another);
};
}
#endif