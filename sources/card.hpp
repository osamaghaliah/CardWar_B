/**
 * This class represents a single card that will be existed in a player's stack.
 * 
 * @author Osama M. Ghaliah
*/

#ifndef card_hpp
#define card_hpp

#include <iostream>
#include <string>

using namespace std;

class Card {
    private:
        string rank;
        string symbol;
        bool revealed;

    public:
        // Non-default constructor.
        Card(string rank, string symbol);
        // Default constructor.
        Card();
        // Copy constructor.
        Card(Card &card);
        ~Card();
        // Getters for this card's attributes.
        string getRank();
        string getSymbol();
        bool getRevealed();
        // Setters for this card's attributes.
        void setRank(string new_rank);
        void setSymbol(string new_symbol);
        void setRevealed(bool revealed);
        // This method represents a description for this card's rank and symbol.
        string description();
};

#endif