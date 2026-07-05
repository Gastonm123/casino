#pragma once

/* Type of bet. A object encapsulating a selection of positions 
 */
template<class Position>
class Bet
{
private:
    bool (*m_select)(Position position);
public:
    Bet();
    Bet(bool (*select)(Position position));
    bool isSelected(Position position);
};

/* Templated empty selection. Used for default constructor
 */
template<class Position>
bool noPosition(Position position) {
    return false;
}

/* Default constructor. Uses empty selection
 */
template<class Position>
Bet<Position>::Bet():
    m_select(noPosition<Position>)
{}

/* Bet constructor. Takes a selection as a function
 */
template<class Position>
Bet<Position>::Bet(bool (*select)(Position position)):
    m_select(select)
{}

/* Checks if a position is included in the selection
 */
template<class Position>
bool Bet<Position>::isSelected(Position position) {
    return m_select(position);
}

/* Simple bets
 */
extern Bet<unsigned> \
    betOdd,
    betEven,
    betBlack,
    betRed,
    betLow,
    betHigh;