#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    class Card
    {
    public:
        string type; // {Hearts, Diamonds, ...}
        string rank; // {Ace, Two, ...}
        int value;
        Card(string rank, string type, int value);
        ~Card();
        string getRank();
        string getType();
        string toString();
        int getValue();
        bool operator<(const Card &other);
        bool operator>(const Card &other);
        bool operator==(const Card &other);
        bool operator!=(const Card &other);
        bool operator>=(const Card &other);
        bool operator<=(const Card &other);
    };

}

#endif