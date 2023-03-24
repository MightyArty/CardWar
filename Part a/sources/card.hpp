#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    class Card
    {

    private:
        string rank; // {ace,two,three,...,king}
        string type; // {hearts, clubs, diamonds, spades}
        bool faceUp; // card face up or down

    public:
        Card(string rank, string type, int value);
        const string getRank() const;
        const string getType() const;
        string toString() const;
        int getValue() const;
        bool operator<(const Card &other) const;
        bool operator>(const Card &other) const;
        bool operator==(const Card &other) const;
        bool operator!=(const Card &other) const;
        bool operator>=(const Card &other) const;
        bool operator<=(const Card &other) const;
    };

}

#endif