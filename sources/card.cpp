#include "card.hpp"

using namespace std;

Card::Card(Rank rank, Symbol symbol) {
    this->rank = rank;
    this->symbol = symbol;
}

Rank Card::getRank() {
    return this->rank;
}

Symbol Card::getSymbol() {
    return this->symbol;
}

int Card::comp(Card other) {
    // Two vs. Ace - Two wins.
    if (this->rank == Two && other.rank == Ace) {
        return 1;
    }
    // Ace vs. Two - Ace loses. 
    else if (this->rank == Ace && other.rank == Two) {
        return -1;
    }
    else if (this->rank > other.rank) {
        return 1;
    }
    else if (this->rank < other.rank) {
        return -1;
    }
    // Occurrence of draw.
    else {
        return 0;
    }
}

string Card::details() {
    string symbol;
    string rank;

    // Converting Symbol ENUMS into strings.
    switch (this->symbol) {
        case Symbol::Clubs:
            symbol = "Clubs";
            break;
        case Symbol::Diamonds:
            symbol = "Diamonds";
            break;
        case Symbol::Hearts:
            symbol = "Hearts";
            break;
        case Symbol::Spades:
            symbol = "Spades";
            break;            
    }

    // Converting Rank ENUMS into strings.
    switch (this->rank) {
        case Rank::Two:
            rank = "2";
            break;
        case Rank::Three:
            rank = "3";
            break;    
        case Rank::Four:
            rank = "4";
            break;
        case Rank::Five:
            rank = "5";
            break;
        case Rank::Six:
            rank = "6";
            break; 
        case Rank::Seven:
            rank = "7";
            break;
        case Rank::Eight:
            rank = "8";
            break;
        case Rank::Nine:
            rank = "9";
            break;   
        case Rank::Ten:
            rank = "10";
            break;
        case Rank::Jack:
            rank = "Jack";
            break;
        case Rank::Queen:
            rank = "Queen";
            break;  
        case Rank::King:
            rank = "King";
            break;
        case Rank::Ace:
            rank = "Ace";
            break;
    }

    string details = "[" + rank + ", " + symbol + "]";

    return details;
}
