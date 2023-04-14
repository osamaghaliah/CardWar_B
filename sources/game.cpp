#include <random>
#include <algorithm>
#include "player.hpp"
#include "card.hpp"
#include "game.hpp"
#include "namespace.hpp"

using namespace std;

Game::Game(Player& firstPlayer, Player& secondPlayer): firstPlayer(firstPlayer), secondPlayer(secondPlayer) {
    this->isDone = false;
    this->oneRoundIncident = "";
    this->allRoundsIncidents = "";
    this->gameWinner = "";
    this->rounds = 0;
    this->drawsOccured = 0;
    
    // Setting up a full deck consisting of 52 cards.
    this->gameDeck = ariel::DECK;

    // Shuffling the deck.
    shuffle(this->gameDeck.begin(), this->gameDeck.end(), default_random_engine());
    
    // Distributing the deck between the two opponents.
    size_t index = 0;

    while (index < 26) {
        this->firstPlayer.putOnPlayerDeck(this->gameDeck[index]);
        index++;
    }

    while (index >= 26 && index < 52) {
        this->secondPlayer.putOnPlayerDeck(this->gameDeck[index]);
        index++;
    }
}

Player Game::getFirstPlayer() {
    return this->firstPlayer;
}

Player Game::getSecondPlayer() {
    return this->secondPlayer;
}

string Game::getGameWinner() {
    return this->gameWinner;
}

vector <Card> Game::getGameDeck() {
    return this->gameDeck;
}

vector <Card> Game::getGameWinningDeck() {
    return this->gameWinningDeck;
}

void Game::playTurn() {
    if(this->isDone) {
        throw logic_error("The game has finished.");
    }
    else if (this->firstPlayer.getName() == this->secondPlayer.getName()) {
        throw logic_error("A player CANNOT compete with himself.");
    }
    else if (this->firstPlayer.getPlayerDeck().size() == 0 || this->secondPlayer.getPlayerDeck().size() == 0) {
        throw logic_error("One of the opponenets has NO cards left in his stack.");
    }
    else {
        Card FP_FacedUpCard = this->firstPlayer.pullFromTopOfDeck();
        Card SP_FacedUpCard = this->secondPlayer.pullFromTopOfDeck();
        
        this->oneRoundIncident = this->firstPlayer.getName() + " pulled " + FP_FacedUpCard.details() + " --- " 
                                    + this->secondPlayer.getName() + " pulled " + SP_FacedUpCard.details();
        
        int compResult = FP_FacedUpCard.comp(SP_FacedUpCard);

        if (compResult == 0) {
            this->oneRoundIncident += " --- Draw.";
            this->allRoundsIncidents += oneRoundIncident +"\n";
            this->gameWinningDeck.push_back(FP_FacedUpCard);
            this->gameWinningDeck.push_back(SP_FacedUpCard);

            GoToWarZone(FP_FacedUpCard,SP_FacedUpCard);
        }
        else if (compResult == 1) {
            this->secondPlayer.putOnPlayerWinningDeck(SP_FacedUpCard);
            this->secondPlayer.putOnPlayerWinningDeck(FP_FacedUpCard);
            this->oneRoundIncident += " --- "+ this->secondPlayer.getName() + " wins.";
            this->allRoundsIncidents += this->oneRoundIncident +"\n";
            this->secondPlayer.setRoundsWon(this->secondPlayer.getRoundsWon() + 1);
        }
        else {
            this->firstPlayer.putOnPlayerWinningDeck(FP_FacedUpCard);
            this->firstPlayer.putOnPlayerWinningDeck(SP_FacedUpCard);
            this->oneRoundIncident += " --- "+ this->firstPlayer.getName() + " wins.";
            this->allRoundsIncidents += oneRoundIncident +"\n";
            this->firstPlayer.setRoundsWon(this->firstPlayer.getRoundsWon() + 1);
        }

        // Moving on to the next round.
        this->rounds++;
    }
}

void Game::printLastTurn() {
    string lastTurnDetails = "Round " + to_string(this->rounds) + ": ";
    lastTurnDetails += this->oneRoundIncident;

    cout << lastTurnDetails << endl; 
}

void Game::playAll() {
    while (this->firstPlayer.stacksize() != 0 || this->secondPlayer.stacksize() != 0)
        this->playTurn();
    
    this->isDone = true;
}

void Game::printWiner() {
    if (!(this->isDone)) {
        cout << "The game has NOT finished yet. \n";
    }
    else if (this->firstPlayer.cardesTaken() == this->secondPlayer.cardesTaken()) {
        cout << "DRAW! There is NO winner." << endl;
    }
    else if (this->firstPlayer.cardesTaken() > this->secondPlayer.cardesTaken()) {
        this->gameWinner = "WINNER: " + this->firstPlayer.getName();
        cout << this->gameWinner << endl;
    }
    else {
        this->gameWinner = "WINNER: " + this->secondPlayer.getName();
        cout << this->gameWinner << endl;
    }
}

void Game::printLog() {
    cout << this->allRoundsIncidents << endl; 
}

void Game::printStats() {
    cout << " ------------------------------" << endl;
    cout << "|      Game's Statistics       |" << endl;
    cout << " ------------------------------";
    cout << "\n";

    cout << "|      " + this->firstPlayer.getName() + "'s Peformance      |" << endl;
    cout << "| ---------------------------  |" << endl;
    double FP_DrawRatio = this->drawsOccured / this->rounds;
    cout << "|        Draw rate: " + to_string(FP_DrawRatio) << "%" << "  |" << endl;
    double FP_WinRatio = 100.0 * this->firstPlayer.getRoundsWon() / this->rounds;
    cout << "|        Win rate: " << FP_WinRatio << "%" << "         |" << endl;
    cout << "|        Rounds played: " << this->rounds << "      |" << endl;
    cout << "|        Rounds won: " << this->firstPlayer.getRoundsWon() << "         |" << endl;

    cout << "|                              |" << endl;
    cout << "|                              |" << endl;

    cout << "|      " + this->secondPlayer.getName() + "'s Peformance        |" << endl;
    cout << "| ---------------------------  |" << endl;
    double SP_DrawRatio = this->drawsOccured / this->rounds;
    cout << "|        Draw rate: " + to_string(SP_DrawRatio) << "%" << "  |" << endl;
    double SP_WinRatio = 100.0 * this->secondPlayer.getRoundsWon() / this->rounds;
    cout << "|        Win rate: " << SP_WinRatio << "%" << "         |" << endl;
    cout << "|        Rounds played: " << this->rounds << "      |" << endl;
    cout << "|        Rounds won: " << this->secondPlayer.getRoundsWon() << "         |" << endl;

    cout << "| ____________________________ |" << endl;
    cout << "\n";
}

void Game::GoToWarZone(Card FP_Card, Card SP_Card) {
    this->drawsOccured++;
    Card FP_FacedDownCard = this->firstPlayer.pullFromTopOfDeck();
    Card SP_FacedDownCard = this->secondPlayer.pullFromTopOfDeck();
    Card FP_FacedUpCard = this->firstPlayer.pullFromTopOfDeck();
    Card SP_FacedUpCard = this->secondPlayer.pullFromTopOfDeck();

    this->oneRoundIncident = this->firstPlayer.getName() + " pulled " + FP_FacedUpCard.details() + " " 
                                + this->secondPlayer.getName() + " pulled " + SP_FacedUpCard.details();
    
    this->gameWinningDeck.push_back(FP_FacedDownCard);
    this->gameWinningDeck.push_back(SP_FacedDownCard);
    this->gameWinningDeck.push_back(FP_FacedUpCard);
    this->gameWinningDeck.push_back(SP_FacedUpCard);
    
    int compResult = FP_FacedUpCard.comp(SP_FacedUpCard);

    if (compResult == 0) {
        this->oneRoundIncident += ". Draw.";
        this->allRoundsIncidents += oneRoundIncident +"\n";
        GoToWarZone(FP_FacedUpCard, SP_FacedUpCard);
    }
    else if (compResult == 1) {
        size_t index = 0;
        
        while (index < this->gameWinningDeck.size()) {
            this->secondPlayer.putOnPlayerWinningDeck(this->gameWinningDeck[index]);
            index++;
        }

        this->gameWinningDeck.clear();
        
        this->oneRoundIncident += ". "+ this->secondPlayer.getName() + " wins.";
        this->allRoundsIncidents += oneRoundIncident +"\n";
        
    }   
    else {
        size_t index = 0;
        
        while (index < this->gameWinningDeck.size()) {
            this->firstPlayer.putOnPlayerWinningDeck(this->gameWinningDeck[index]);
            index++;
        }

        this->gameWinningDeck.clear();

        this->oneRoundIncident += ". "+ this->firstPlayer.getName() + " wins.";
        this->allRoundsIncidents += oneRoundIncident +"\n";
    }

    if (this->firstPlayer.stacksize() == 1 && this->secondPlayer.stacksize() == 1) {
        this->firstPlayer.putOnPlayerWinningDeck(this->firstPlayer.getPlayerDeck().front());
        this->secondPlayer.putOnPlayerWinningDeck(this->secondPlayer.getPlayerDeck().front());
    }
}