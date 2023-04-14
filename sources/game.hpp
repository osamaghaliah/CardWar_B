/**
 * This class represents a cards game which is called War.
 * @author Osama M. Ghaliah
*/

#ifndef GAME_HPP
#define GAME_HPP

#include "card.hpp"
#include "player.hpp"
#include "namespace.hpp"

using namespace std;

class Game {
    private:
        Player &firstPlayer;
        Player &secondPlayer;
        int rounds;
        string oneRoundIncident;
        string allRoundsIncidents;
        string gameWinner;
        vector <Card> gameDeck;
        vector <Card> gameWinningDeck;
        bool isDone;
        int drawsOccured;


    public:
        // Constructor.
        Game(Player &firstPlayer, Player &secondPlayer);
        // Getters.
        Player getFirstPlayer();
        Player getSecondPlayer();
        string getGameWinner();
        vector <Card> getGameDeck();
        vector <Card> getGameWinningDeck();
        // Printing methods for saving game's statistics, rounds details... etc.
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        // This method handles the cases where the two players are in a DRAW case.
        void GoToWarZone(Card FP_Card, Card SP_Card);
};

#endif
