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
        int rank;
        string type; // Hearts, Diamonds, Clubs or Spadec

    public:
        Card(int rank, string type);
        int getRank() const;
        string getType() const;
        bool operator<(const Card &other) const;
        bool operator>(const Card &other) const;
        bool operator==(const Card &other) const;
        bool operator!=(const Card &other) const;
        friend std::ostream &operator<<(std::ostream &os, const Card &c);
    };

}

#endif