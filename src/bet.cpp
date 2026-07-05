#include "bet.hpp"
#include <vector>
#include <algorithm>

const std::vector<int> red_positions = {
    1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21,
    23, 25, 27, 30, 32, 34, 36
};
const std::vector<int> black_positions = {
    2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22,
    24, 26, 28, 29, 31, 33, 35
};

Bet<unsigned> betOdd([](unsigned pos){ return pos%2==1; });
Bet<unsigned> betEven([](unsigned pos){ return pos%2==0; });
Bet<unsigned> betLow([](unsigned pos){ return pos>=1 && pos<=18; });
Bet<unsigned> betHigh([](unsigned pos){ return pos>=19 && pos<=36; });
Bet<unsigned> betBlack([](unsigned pos){
    return std::find(begin(black_positions), end(black_positions), pos) != end(black_positions);
});
Bet<unsigned> betRed([](unsigned pos){
    return std::find(begin(red_positions), end(red_positions), pos) != end(red_positions);
});