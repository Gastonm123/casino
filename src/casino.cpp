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

    std::vector<NormalPlayer> players = {
        NormalPlayer(alwaysRed, MIN_BET, MAX_BET),
        NormalPlayer(alwaysBlack, MIN_BET, MAX_BET),
        NormalPlayer(alwaysOdd, MIN_BET, MAX_BET),
        NormalPlayer(alwaysEven, MIN_BET, MAX_BET),
        NormalPlayer(alwaysHigh, MIN_BET, MAX_BET),
        NormalPlayer(alwaysLow, MIN_BET, MAX_BET),
    };

    std::vector<std::pair<NormalBet,int>> bets(players.size());

    for (int iteration = 0; iteration < NUMBER_ITERATIONS; iteration++)
    {
        std::cout << "Iteration: " << iteration+1 << "\n";

        // take the bets
        for (int playerI = 0; playerI < players.size(); ++playerI) {
            NormalBet bet;
            int betAmount;
            players[playerI].bet(&bet, &betAmount);
            bets[playerI] = std::make_pair(bet,betAmount);
        }
        std::cout << "Bets taken!\n";

        // spin the wheel
        unsigned spin = rand() % 37;
        std::cout << "Wheel landed on " << spin << "\n";

        std::cout << "Updating players\n";
        for (int playerI = 0; playerI < players.size(); ++playerI) {
            auto& [bet,betAmount] = bets[playerI];
            if (bet.isSelected(spin)) {
                players[playerI].win();
                // do something with the bet amount
            } else {
                players[playerI].lose();
                // do something with the bet amount
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
        std::cout << "Player " << playerI+1 << " balance: " << balance << std::endl;
        playerI += 1;
        total += balance;
    }

    std::cout << "General balance: " << total << std::endl;

    return 0;
}
