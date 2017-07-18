
#include "Classes.h"
using namespace std;


Card::Card() {
    _suit = "Hearts";
    _rank = "Queen";
    _value = 12;
}
Card::Card(string suit, string rank, int value) {
    _suit = suit;
    _rank = rank;
    _value = value;
}
void Card::ConvertValuetoRank() {
    if (_value == 1) {
        SetRank("2");
    }
    else if (_value == 2) {
        SetRank("3");
    }
    else if (_value == 3) {
        SetRank("4");
    }
    else if (_value == 4) {
        SetRank("5");
    }
    else if (_value == 5) {
        SetRank("6");
    }
    else if (_value == 6) {
        SetRank("7");
    }
    else if (_value == 7) {
        SetRank("8");
    }
    else if (_value == 8) {
        SetRank("9");
    }
    else if (_value == 9) {
        SetRank("10");
    }
    else if (_value == 10) {
        SetRank("Jack");
    }
    else if (_value == 11) {
        SetRank("Queen");
    }
    else if (_value == 12) {
        SetRank("King");
    }
    else if (_value == 13) {
        SetRank("Ace");
    }
}

void Card::SetRank(string rank) {
    _rank = rank;
}
void Card::SetSuit(string suit) {
    _suit = suit;
}
void Card::SetValue(int value) {
    _value = value;
}

string Card::GetRank() const {
    return _rank;
}
string Card::GetSuit() const {
    return _suit;
}
int Card::GetValue() const {
    return _value;
}


//////////////////////////////////
Game::Game() {
    _round = 0;
    _score = 0;
    Player player;
    Player computer;
    string entry = "0";
    //player._hand.clear();
    //computer._hand.clear();
    CreateDeck();
    Introduction();
    ShuffleDeck();
    //TestDeck();
    SplitDeck(player, computer);
    //TestSplit(player, computer);
    //UpdateScores(player, computer);
    do {
        _round++;
        if (player._hand.size() != 0 || computer._hand.size() != 0) {
            Compare(player, computer, player.DrawCard(), computer.DrawCard());
            //TestSplit(player, computer);
            UpdateScores(player, computer);

        }
        do {
            cout << "Enter D to draw or Q to quit: ";
            cin >> entry;
        } while (entry != "D" && entry != "Q" && entry != "d" && entry != "q");

    } while (player._hand.size() != 0 && computer._hand.size() != 0 && ((entry != "Q" ||entry != "q") && (entry == "D" || entry == "d")));
    if (player.GetScore() == 52) {
        cout << "Congrats! You win!! You won in " << _round << "rounds." << endl;
    }
    else if (player.GetScore() > computer.GetScore()) {
        cout << "Congrats you had a higher score than the computer! You win!" << endl;
    }
    else {
        cout << "Sorry, the computer beat you :(" << endl;
    }


}

void Game::Introduction() {
    cout << "Welcome to WAR!." << endl;
    cout << "You will be playing against the computer." << endl;
    cout << "Each of you have will start with half of the deck (26 cards)." << endl;
    cout << "The goal is to get the whole deck (52 cards)\nor have a higher amount of cards than the computer." << endl;
    cout << "(Because, yes, to get 52 cards will take a long time,\nbut hey, good thing to procrastinate with)" << endl;
    cout << "To do this, you will draw one card at a time, then compare the scores." << endl;
    cout << "Whichever drew the higher valued card gets to put those two cards back into their hand." << endl;
    cout << "Aces beat all. If the two cards drawn have the same value, then a WAR starts."<< endl;
    cout << "During WAR, each player draws three more cards, but does not look at the first two,\nthe third cards drawn then are compared just like normal." << endl;
    cout << "The winner of the WAR get to keep all the cards played in that round." << endl;
    system("pause");
}
void Game::CreateDeck() {
    for (int i = 0; i < 13; i++) {
        Card card;
        card.SetValue(i + 1);
        card.SetSuit("Hearts");
        _deck.push_back(card);
    }
    for (int i = 0; i < 13; i++) {
        Card card;
        card.SetValue(i + 1);
        card.SetSuit("Spades");
        _deck.push_back(card);
    }
    for (int i = 0; i < 13; i++) {
        Card card;
        card.SetValue(i + 1);
        card.SetSuit("Diamonds");
        _deck.push_back(card);
    }
    for (int i = 0; i < 13; i++) {
        Card card;
        card.SetValue(i + 1);
        card.SetSuit("Clubs");
        _deck.push_back(card);
    }
    for (int i = 0; i < 52; i++) {
        _deck.at(i).ConvertValuetoRank();
    }
    ShuffleDeck();
}
void Game::ShuffleDeck() {
    for (int i = 0; i < 52; i++) {
        Card holder;
        int pos1 = (rand() % 52);
        int pos2 = (rand() % 52);
        holder = _deck.at(pos1);
        _deck.at(pos1) = _deck.at(pos2);
        _deck.at(pos2) = holder;
    }
}
void Game::SplitDeck(Player &player, Player &computer) {
    for (int i = 0; i < 26; i++) {
        player.SetHand(_deck.at(i), i);
        computer.SetHand(_deck.at(i + 26), i);
    }
}
Card Game::MoveCard() {
    Card a = _deck.at(_deck.size());
    _deck.pop_back();
    return a;
}

void Game::TestDeck() {
    for (int i = 0; i < 52; i++) {
        cout << _deck.at(i).GetRank() << " " << _deck.at(i).GetSuit() << " " << _deck.at(i).GetValue() << endl;
    };
    ShuffleDeck();
    for (int i = 0; i < 52; i++) {
        cout << _deck.at(i).GetRank() << " " << _deck.at(i).GetSuit() << " " << _deck.at(i).GetValue() << endl;
    };
}
void Game::TestSplit(Player &player, Player &computer) {
    cout << "Player:" << endl;
    int pLength = player._hand.size();

    for (int i = 0; i < pLength; i++) {
        cout << i << "#" <<player._hand.at(i).GetRank() << " " << player._hand.at(i).GetSuit() << endl;
    }
    cout << "--------------------" << endl;
    int cLength = computer._hand.size();
    cout << "Computer:" << endl;
    for (int i = 0; i < cLength; i++) {
        cout << i << "#" << computer._hand.at(i).GetRank() << " " << computer._hand.at(i).GetSuit() << endl;
    }

}

void Game::Compare(Player &player, Player &computer, Card plCard, Card coCard) {
    _war = 0;
    //computer.RemoveCard();
    //player.RemoveCard();
    int p = plCard.GetValue();
    int c = coCard.GetValue();
    cout << "Computer Drew: " << coCard.GetRank() << " of " << coCard.GetSuit() << endl;
    cout << "Player Drew: " << plCard.GetRank() << " of " << plCard.GetSuit() << endl;
    if (p == c) {
        int w = War(player, computer);
        if (w == 1) {
            player.AddCard(coCard);
            player.AddCard(plCard);
        }
        else if (w == 2) {
            computer.AddCard(plCard);
            computer.AddCard(coCard);
        }
    }
    if (p > c) {
        cout << "Player's is higher." << endl;
        player.AddCard(coCard);
        player.AddCard(plCard);
        
    }
    else if (c > p) {
        cout << "Computer's is higher." << endl;
        computer.AddCard(plCard);
        computer.AddCard(coCard);
    }
}
void Game::UpdateScores(Player &player, Player &computer) {
    computer.UpdateScore();
    player.UpdateScore();
    _score = player.GetScore();
    cout << "-----------------------" << endl;
    cout << "Current Score: " << player.GetScore() << "/52" << endl;
    cout << "-----------------------" << endl;
}
int Game::GetScore() {
    return _score;
}
int Game::GetRounds() {
    return _round;
}
int War(Player &player, Player &computer) {
    int _war = 0;
    cout << "-----WAR!-----" << endl;
    Card pl4;
    Card co4 = computer.DrawCard();
    Card pl2;
    Card pl1;
    Card co1;
    Card co2;
    if (player._hand.size() != 0 && computer._hand.size() != 0) {
        pl4 = player.DrawCard();
        co4 = computer.DrawCard();

        int p4 = pl4.GetValue();
        int c4 = co4.GetValue();
        if (player._hand.size() != 0) {
            pl2 = player.DrawCard();
        }
        if (player._hand.size() != 0) {
            pl1 = player.DrawCard();
        }
        if (computer._hand.size() != 0) {
            co2 = computer.DrawCard();
        }
        if (computer._hand.size() != 0) {
            co1 = computer.DrawCard();
        }

        cout << "Computer Drew: " << co4.GetRank() << " of " << co4.GetSuit() << endl;
        cout << "Player Drew: " << pl4.GetRank() << " of " << pl4.GetSuit() << endl;
        if (p4 == c4) {
            int w = War(player, computer);
            if (w == 1) {
                player.AddCard(co4);
                player.AddCard(pl4);
                player.AddCard(co2);
                player.AddCard(pl2);
                player.AddCard(co1);
                player.AddCard(pl1);
                return 1;
            }
            else if (w == 2) {
                computer.AddCard(pl4);
                computer.AddCard(co4);
                computer.AddCard(pl2);
                computer.AddCard(co2);
                computer.AddCard(pl1);
                computer.AddCard(co1);
                return 2;
            }
        }
        if (p4 > c4) {
            cout << "Player's is higher." << endl;
            player.AddCard(co4);
            player.AddCard(pl4);
            player.AddCard(co2);
            player.AddCard(pl2);
            player.AddCard(co1);
            player.AddCard(pl1);
            return 1;

        }
        else if (c4 > p4) {
            cout << "Computer's is higher." << endl;
            computer.AddCard(pl4);
            computer.AddCard(co4);
            computer.AddCard(pl2);
            computer.AddCard(co2);
            computer.AddCard(pl1);
            computer.AddCard(co1);
            return 2;
        }
    }
}

//////////////////////////////////
Player::Player() {
    _score = 0;
    _hand.resize(26);
}
Player::Player(vector <Card> a, int score) {
    _hand = a;
    _score = 0;
}

void Player::SetHand(Card c, int i) {
    _hand.at(i).SetRank(c.GetRank());
    _hand.at(i).SetSuit(c.GetSuit());
    _hand.at(i).SetValue(c.GetValue());
}
//Card Player::GetHand(int r) {
//    return _hand.at(r);
//}
Card Player::DrawCard() {
    int length = _hand.size();
    Card c = _hand.at(0);
    for (int i = 1; i < length; i++) {
        _hand.at(i-1) = _hand.at(i);
    }
    _hand.pop_back();
    return c;
}
void Player::AddCard(Card c) {
    _hand.push_back(c);
}
//void Player::RemoveCard() {
//    _hand.pop_back();
//}
void Player::UpdateScore() {
    _score = _hand.size();
}
int Player::GetScore() {
    return _score;
}