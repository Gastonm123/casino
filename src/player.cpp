#include "player.hpp"
#include <ctime>


Bet<unsigned> alwaysBlack(int time) {
    return betBlack;
}
Bet<unsigned> alwaysRed(int time) {
    return betRed;
}
Bet<unsigned> alwaysOdd(int time){
    return betOdd;
}
Bet<unsigned> alwaysEven(int time){
    return betEven;
}
Bet<unsigned> alwaysLow(int time){
    return betLow;
}
Bet<unsigned> alwaysHigh(int time){
    return betHigh;
}