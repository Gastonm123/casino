# Roulette Challenge

Spin the roullete N times and record the winnings or losings of each players.

## Compile

To compile run

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Design

The design includes bets, players and annotations (aka. paper). Each player records his
loses and wins updating his balance and also his annotations. If the player is about to
bet an amount that is lower or higher than the minimum or maximum, respectively, then he
restarts his annotations. The implementation of the annotations may vary so we abstract
the details in an object.

Each player has a diferent strategy that we model as a function of bets with respect to
time. And a bet is nothing more than a subset of positions in the board. We chose to model
this with a selector function, which returns true in the positions of the subset. This is
a performance optimization because some subsets can be checked more efficiently with a
function than by iterating over a list.

## Challenge

### Roulette Rules

- In roulette there are 37 numbers, from 0 to 36.
- Within the possible bets, we are going to focus on the so-called simple bets (even and odd, red and black, high and low). In roulette there are 18 even and 18 odd numbers; 18 red and 18 black; 18 older and 18 younger. It is not necessary that I clarify which are even and odd. :-) The low ones go from 1 to 18 and the high ones from 19 to 36. You can see the red and black ones here: http://es.wikipedia.org/wiki/Ruleta#mediaviewer/Archivo:Roulette_frz.png
- 0 (zero) is a special number that is not even, odd, red, black, high or low. That is, if zero comes up and you bet on any of the simple bets: you lost!
- When hitting a simple bet, the bank pays double the amount bet.

For the simulation we will assume the following:
- The minimum bet of the table is 5.
- The maximum bet of the table is 4,000.

### Way to bet

Each player has a piece of paper where they write down their bets. When each player starts, their notebook says:

1 - 2 - 3 - 4

To bet add the numbers at the ends and bet (in this case bet 1 + 4 = 5). If you win, write down what you won at the end of the line (5), while if you lose, cross out the two numbers of the extremes (1 and 4). For the next bet, bet the sum of the extremes again. Note that what is recorded is the profit and not what the bank pays you (that is your bet plus the profit).

Then:
- If the player won, he would have: 1 - 2 - 3 - 4 - 5 (the next bet would be 1 + 5 = 6)
- If the player lost it would be: 2 - 3 (the next bet would be 2 + 3 = 5)

If at any time the player runs out of numbers in the queue, go back to the beginning and write down 1 - 2 - 3 - 4. And if it ever goes over the table max, same thing. In other words, if the sum gives you more than 4,000, you have to put 1 - 2 - 3 - 4 again and bet 5. The same if at any time you have a number less than the minimum. If you only have one number left, that is your bet (as long as it does not exceed the maximum allowed).

### Simulation

The idea is to make a program that simulates 6 people playing simultaneously at the same table, where each one always bets on the same thing (one on red, another on black, another on higher, etc.). You also have to simulate roulette using PC random (not ideal, but the simplest we have). That is, you would have to simulate the complete sequence:
- Player A bets on red.
- Player B bets on black.
- Player C bets higher.
- Player D bets to minor.
- Player E bets even.
- Player F bets on odd.
- Spin the wheel, a number comes out.
- Each player is paid accordingly.
- Return to the beginning with the new bets.
It must be taken into account that each of the players carries an individual piece of paper and their bets are independent of each other (when red wins, black loses and therefore the next bet will surely be different).

These 6 players are supposed to play as a team, therefore a simulation of 10,000 roulette spins would have to be done and at the end, make a balance by adding the wins and losses of the 6, to see if they ended up winning, losing or if they came out with the same money that came in

For practical purposes we are going to assume that the players have infinite money, that is, they will never stop betting because they ran out of money.