#include "Card.hpp"

using namespace ariel;

Card::Card(int value, string kind)
{
    this->value = value;
    this->kind = kind;
}

Card::Card()
{
    this->value = 0;
    this->kind = "";
}

int Card::getValue()
{
    return this->value;
}

string Card::getKind()
{
    return this->kind;
}

string Card::details()
{
    string info = "";
    int num = this->value;
    switch (num)
    {
    case 1:
        info += "Ace of " + this->kind;
        break;
    case 11:
        info += "Jack of " + this->kind;
        break;
    case 12:
        info += "Queen of " + this->kind;
        break;
    case 13:
        info += "King of " + this->kind;
        break;
    default:
        info += to_string(this->value) + " of " + this->kind;
        break;
    }
    return info;
}

int Card::compare(Card another)
{
    if (this->value > another.value)
    {
        return 1;
    }
    else if (this->value < another.value)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
