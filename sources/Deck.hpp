#ifndef Deck_hpp
#define Deck_hpp
#include "card.hpp"
#include <string>
#include <array>

using namespace std;

const int game_deck_size = 52;

class Deck {
    private:
        array <Card, game_deck_size> deck;

    public:
        Deck();
        Deck(array <Card, game_deck_size> deck);
        Deck(Deck &deck);
        ~Deck();
        array <Card, game_deck_size> getDeck();
        void setDeck(array <Card, game_deck_size> deck);
        void shuffle();
};

#endif