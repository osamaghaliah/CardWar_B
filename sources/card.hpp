#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>

using namespace std;

enum Symbol {
    Clubs , Diamonds, Hearts, Spades
};

enum Rank {
    Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
};

class Card {
    private:
        Symbol symbol;
        Rank rank;  

    public:
        // Constructor.
        Card(Rank rank , Symbol symbol);
        // Getters.
        Symbol getSymbol();    
        Rank getRank();
        // Comparator for two cards ranks.
        int comp(Card other);
        // This method tells us what is the rank and the symbol of this card.
        string details();
};

#endif
