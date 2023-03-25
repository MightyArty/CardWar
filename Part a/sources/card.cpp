#include "card.hpp"
#include <string>

using namespace std;
using namespace ariel;

namespace ariel
{

    Card::Card(string rank, string type, int value)
    {
        this->rank = rank;
        this->type = type;
        this->value = value;
    }

    Card::~Card(){

    };

    string Card::getRank()
    {
        return this->rank;
    }

    string Card::getType()
    {
        return this->type;
    }

    string Card::toString()
    {
        return this->rank + " of " + this->type;
    }

    int Card::getValue()
    {
        return this->value;
    }

    bool Card::operator<(const Card &other)
    {
        return this->value < other.value;
    }
    bool Card::operator>(const Card &other)
    {
        return this->value > other.value;
    }
    bool Card::operator==(const Card &other)
    {
        return this->value == other.value;
    }
    bool Card::operator!=(const Card &other)
    {
        return this->value != other.value;
    }
    bool Card::operator>=(const Card &other)
    {
        return this->value >= other.value;
    }
    bool Card::operator<=(const Card &other)
    {
        return this->value <= other.value;
    }

}