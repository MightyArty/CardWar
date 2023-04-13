#include "card.hpp"
#include <string>

using namespace std;
using namespace ariel;

namespace ariel
{

    /**
     * @brief Main constructor of the Card
     */
    Card::Card(string rank, string type, int value)
    {
        this->rank = rank;
        this->type = type;
        this->value = value;
    }

    /**
     * @return the rank of the card
     */
    string Card::getRank()
    {
        return this->rank;
    }

    /**
     * @return the type of the card
     */
    string Card::getType()
    {
        return this->type;
    }

    /**
     * @return the card as a string (type and rank)
     */
    string Card::toString()
    {
        return this->rank + " of " + this->type;
    }

    /**
     * @return the value of the card
     */
    int Card::getValue()
    {
        return this->value;
    }

    /**
     * @brief Compare if the first card is smaller then the second
     * @return true if the first card is smaller
     * @param other the second card
     */
    bool Card::operator<(const Card &other)
    {
        if (this->rank == "2" && other.rank == "Ace")
        {
            return false;
        }
        else if (this->rank == "Ace" && other.rank == "2")
        {
            return true;
        }
        else if (this->rank == "Ace" && other.rank != "2")
        {
            return false;
        }
        else if (this->rank != "2" && other.rank == "Ace")
        {
            return true;
        }
        else
            return this->value < other.value;
    }

    /**
     * @brief Compare if the first card is greater then the second
     * @return true if the first card is greater
     * @param other the second card
     */
    bool Card::operator>(const Card &other)
    {
        if (this->rank == "Ace" && other.rank != "2")
        {
            return true;
        }
        else if (this->rank == "2" && other.rank == "Ace")
        {
            return true;
        }
        else if (this->rank == "Ace" && other.rank == "2")
        {
            return false;
        }
        else
            return value > other.value;
    }

    /**
     * @brief Compare if the first card is equal to the second
     * @return true if the first card is equal to the second
     * @param other the second card
     */
    bool Card::operator==(const Card &other)
    {
        return this->value == other.value;
    }

}