#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "card.hpp"

using namespace std;

class Player {
    private:
        string name;
        vector <Card> playerDeck;
        vector <Card> playerWinningDeck;
        int roundsWon;
        int cardsWon;
        
    public:
        // Constructor.
        Player(string name);    
        vector <Card> getPlayerDeck();  
        vector <Card> getPlayerWinningDeck();
        int getRoundsWon();
        void setRoundsWon(int roundsWon);
        string getName();
        int stacksize();
        int cardesTaken();
        // For reading convenience.
        void putOnPlayerDeck(Card card);
        void putOnPlayerWinningDeck(Card card);
        Card pullFromTopOfDeck();
};

#endif
