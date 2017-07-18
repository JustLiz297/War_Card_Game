#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


class Card {
private:
	string _suit;
	string _rank;
	int _value;

public:
	Card();
	Card(string suit, string rank, int value);
	string GetSuit() const;
	string GetRank() const;
	int GetValue() const;

	void SetSuit(string suit);
	void SetRank(string rank);
	void SetValue(int value);
	void ConvertValuetoRank();
};

class Player {
private:
    int _score;
public:
    Player();

    vector <Card> _hand;
    Player(vector <Card> a, int score);
    void SetHand(Card c, int i);
    //Card GetHand(int r);
    Card DrawCard();
    void AddCard(Card c);
    void RemoveCard();
    void UpdateScore();
    int GetScore();
};

class Game {
private:
	vector <Card> _deck;
	//Player _computer;
	//Player _player;
	void CreateDeck();
	void ShuffleDeck();
	void Introduction();
    void SplitDeck(Player &player, Player &computer);
    Card MoveCard();
    int _war;
    int _round;
    int _score;

public:
    Game();
	//void War(Player &player, Player &computer);
    void TestDeck();
    void TestSplit(Player &player, Player &computer);
    void Compare(Player &player, Player &computer,Card plCard, Card coCard);
    void UpdateScores(Player &player, Player &computer);
    int GetScore();
    int GetRounds();

};
int War(Player &player, Player &computer);
