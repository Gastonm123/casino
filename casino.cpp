#include <iostream>
#include <list>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdlib>

/* Strategies used in the simulation. Each one of the players plays according
 * to one of these strategies. Since no order is given for the players we
 * choose the first player to always bet ODD, the second to always bet EVEN,
 * and so on following the enum order.
 */
enum {
  BET_ODD,
  BET_EVEN,
  BET_RED,
  BET_BLACK,
  BET_LOW,
  BET_HIGH,
};

using namespace std;

/* Player class manages the individual wins and losses of a player.
 * After a player wins a betting round the win method must be called.
 * Conversely when the players losses the lose method must be called.
 */
struct Player {
  int loss; // amount lost
  int gain; // amount gained
  list<int> annotations; // player annotations
  const int MIN_BET = 5; // minimum allowed bet
  const int MAX_BET = 4000; // maximum allowed bet

  Player() : loss(0), gain(0), annotations({1,2,3,4}) {};

  /* Returns the annotations' list back to its initial state.
   */
  void restart_annotations() {
    annotations.assign({1,2,3,4});
  }

  /* Returns the bet amount for this betting round. If the amount exceeds the
   * minimum or maximum the annotations are restarted.
   */
  int get_bet_amount() {
    // the player must have at least one annotation when calling this function
    assert(annotations.size() > 0);

    int bet_amount = annotations.front() + (annotations.size() > 1 ? annotations.back() : 0);

    if (bet_amount > MAX_BET || bet_amount < MIN_BET) {
      restart_annotations();
      return 5;
    }

    return bet_amount;
  }

  /* Manages a winning round. The gain is increased and the annotations are
   * updated with the amount gained.
   */
  void win() {
    int bet_amount = get_bet_amount();
    gain += bet_amount;
    annotations.push_back(bet_amount);
  }

  /* Manages a lossing round. The loss is increased and the first and last
   * annotations are erased or the annotations are restarted if there are at
   * most two.
   */
  void lose() {
    int bet_amount = get_bet_amount();
    loss += bet_amount;
    if (annotations.size() <= 2)
      restart_annotations();
    else {
      annotations.pop_front();
      annotations.pop_back();
    }
  }

  int get_balance() {
    return gain - loss;
  }
};

int main() {
  srand(time(0));

  const int NUMBER_PLAYERS = 6;
  const int NUMBER_ITERATIONS = 10000;
  Player players[NUMBER_PLAYERS];

  vector<int> red_numbers({1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27,
    30, 32, 34, 36});

  for (int iteration = 0; iteration < NUMBER_ITERATIONS; iteration++) {
    int roullete_number = rand() % 37;

    cout << "Iteration number: " << iteration << "\tRoullete number: " << roullete_number;
    cout << "\tBets: ";
    for (Player p : players)
      cout << p.get_bet_amount() << " ";
    cout << endl;

    if (roullete_number == 0) {
      for (Player p : players)
        p.lose();
    }
    else {
      if (roullete_number % 2 == 0) {
        players[BET_EVEN].win();
        players[BET_ODD].lose();
      }
      else {
        players[BET_EVEN].lose();
        players[BET_ODD].win();
      }

      if (find(red_numbers.begin(), red_numbers.end(), roullete_number) != red_numbers.end()) {
        players[BET_RED].win();
        players[BET_BLACK].lose();
      }
      else {
        players[BET_RED].lose();
        players[BET_BLACK].win();
      }

      if (roullete_number >= 1 && roullete_number <= 18) {
        players[BET_LOW].win();
        players[BET_HIGH].lose();
      }
      else {
        players[BET_LOW].lose();
        players[BET_HIGH].win();
      }
    }
  }

  // Print results

  cout << "Iterations finished..." << endl;
  cout << "#### Results ####" << endl;

  int general_balance = 0;

  for (int player_id = 0; player_id < NUMBER_PLAYERS; player_id++) {
    int balance = players[player_id].get_balance();
    cout << "Player " << player_id << " balance: " << balance << endl;
    general_balance += balance;
  }

  cout << "General balance: " << general_balance << endl;

  return 0;
}
