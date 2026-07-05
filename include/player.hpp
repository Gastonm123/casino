#pragma once
#include "paper.hpp"
#include "bet.hpp"

/* Player class manages the individual wins and losses of a player.
 * After a player wins a betting round the win method must be called.
 * Conversely when the players losses the lose method must be called.
 */
template<class Money, class Position>
class Player {
private:
    Money m_loss; // amount lost
    Money m_gain; // amount gained
    Paper<Money> m_paper; // player annotations
    Bet<Position> (*m_strategy)(int time); // betting strategy
    const Money m_minBet;
    const Money m_maxBet;
public:
    Player();
    Player(
        Bet<Position> (*strategy)(int time),
        const Money minBet,
        const Money maxBet
    );
    void bet(Bet<Position> *playerBet, Money *betAmount);
    void win();
    void lose();
    Money balance();
};

/* Default constructor for a player
 */
template<class Money, class Position>
Player<Money,Position>::Player():
    m_loss(Money()),
    m_gain(Money()),
    m_paper(),
    m_minBet(Money()),
    m_maxBet(Money())
{}

/* Player constructor
 */
template<class Money, class Position>
Player<Money,Position>::Player(
    Bet<Position> (*strategy)(int), 
    const Money minBet,
    const Money maxBet
):
    m_loss(Money()),
    m_gain(Money()),
    m_strategy(strategy),
    m_paper(),
    m_minBet(minBet),
    m_maxBet(maxBet)
{}

/* Returns player bet and bet amount
 */
template<class Money, class Position>
void Player<Money,Position>::bet(Bet<Position> *playerBet, Money *betAmount) {
    // get the time right now
    std::time_t now = time(nullptr);
    *playerBet = m_strategy(now);

    Money nextBet = m_paper.betAmount();
    if (nextBet > m_maxBet || nextBet < m_minBet) {
        m_paper.restart();
        nextBet = m_paper.betAmount();
    }

    *betAmount = nextBet;
}

/* Records a win
 */
template<class Money,class Position>
void Player<Money,Position>::win() {
    m_gain += m_paper.betAmount();
    m_paper.win();
}

/* Records a lose
 */
template<class Money,class Position>
void Player<Money,Position>::lose() {
    m_loss += m_paper.betAmount();
    m_paper.lose();
}

/* Returns player balance
 */
template<class Money,class Position>
Money Player<Money,Position>::balance() {
    return m_gain - m_loss;
}


/* Strategies used in the simulation. Each one of the players plays according
 * to one of these strategies. Since no order is given for the players we
 * choose the first player to always bet ODD, the second to always bet EVEN,
 * and so on following the enum order.
 */
Bet<unsigned> alwaysRed(int time);
Bet<unsigned> alwaysBlack(int time);
Bet<unsigned> alwaysOdd(int time);
Bet<unsigned> alwaysEven(int time);
Bet<unsigned> alwaysLow(int time);
Bet<unsigned> alwaysHigh(int time);