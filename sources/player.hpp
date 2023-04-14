/**
 * This class represents a player who is willing to be apart of a cards game.
 * @author Osama M. Ghaliah
*/

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
        //int roundsDrawn;
        int cardsWon;
        
    public:
        // Constructor.
        Player(string name);    
        vector <Card> getPlayerDeck();  
        vector <Card> getPlayerWinningDeck();
        int getRoundsWon();
        //int getRoundsDrawn();
        string getName();
        void setRoundsWon(int roundsWon);
        //void setRoundsDrawn();
        int stacksize();
        int cardesTaken();
        // For reading convenience.
        void putOnPlayerDeck(Card card);
        void putOnPlayerWinningDeck(Card card);
        Card pullFromTopOfDeck();
};

#endif
