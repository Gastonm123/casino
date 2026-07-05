#include <iostream>
#include <list>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "player.hpp"
#include "bet.hpp"

using NormalPlayer = Player<int, unsigned>;
using NormalBet = Bet<unsigned>;

const int NUMBER_ITERATIONS = 10000;
const int MAX_BET = 4000;
const int MIN_BET = 5;

int main()
{
    srand(time(0));

    const std::vector<NormalPlayer> players = {
        NormalPlayer(alwaysRed, MIN_BET, MAX_BET),
        NormalPlayer(alwaysBlack, MIN_BET, MAX_BET),
        NormalPlayer(alwaysOdd, MIN_BET, MAX_BET),
        NormalPlayer(alwaysEven, MIN_BET, MAX_BET),
        NormalPlayer(alwaysHigh, MIN_BET, MAX_BET),
        NormalPlayer(alwaysLow, MIN_BET, MAX_BET),
    };


    for (int iteration = 0; iteration < NUMBER_ITERATIONS; iteration++)
    {
        unsigned spin = rand() % 37;

        std::cout << "Iteration number: " << iteration << "\tRoullete number: " << spin;
        std::cout << "\tBets: ";
        for (NormalPlayer p : players) {
            NormalBet bet;
            int betAmount;
            p.bet(&bet, &betAmount);

            if (bet.isSelected(spin)) {
                p.win();
            } else {
                p.lose();
            }
        }
    }

    // Print results

    std::cout << "Iterations finished..." << std::endl;
    std::cout << "#### Results ####" << std::endl;

    int total = 0;
    int playerI = 0;

    for (NormalPlayer p : players)
    {
        int balance = p.balance();
        std::cout << "Player " << playerI << " balance: " << balance << std::endl;
        playerI += 1;
        total += balance;
    }

    std::cout << "General balance: " << total << std::endl;

    return 0;
}
