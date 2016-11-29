#ifndef HEARTS_GAME_HPP
#define HEARTS_GAME_HPP

#include "Player.hpp"
#include "Game.hpp"
#include <boost/asio.hpp>
#include <random>

class HeartsGame : public Game
{
public://10 functions
  HeartsGame(std::vector<Player>& netPlayers);
  ~HeartsGame();
  void play_Hearts();
  // looks through each hand to find the 2 of clubs
  int findTwoOfClubs();
  // function for passing cards at beginging of round
  void passCards(int round);
  int endTurn(int currentPlayer);
  void endRound();
  bool setPassCards(std::vector<Card> cards, std::string name);
  int playCard(Card card, std::string name);
  std::vector<Player> getPlayers() { return players; }
  std::vector<Card> getCenterPile() { return centerPile; }
private: //6 functions
  std::vector<Card> initializeDeck();
  void dealCards(std::vector<Card>& Deck);

  // checks to see if a players hand is all hearts.
  bool allhearts(std::vector<Card> h);
  // compares hand against the lead suit
  bool noLeadSuit(Suit s, std::vector<Card> h);
  bool validateMove(int index, Card move);
  std::vector<Card> centerPile;

  bool brokenHearts = false;
  bool validatePass(std::vector<Card> cards, std::string name);
  int turn = 0;
  int numTrick = 0;
  std::vector<std::vector<Card>> cardsToPass;
  void passCard(Card tmp, int i);
  bool gameOver = false;
  bool roundOver = false;
};

#endif // HEARTS_GAME_HPP