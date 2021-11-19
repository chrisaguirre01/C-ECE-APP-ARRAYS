/* Christopher Aguirre
* EECE 2160 Program 4: Guessing Game
* October 24th, 2021
* Professor Michael Geiger
*/

#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio, not zyBooks
#include <stdio.h>
#include <stdlib.h>                 // Necessary for rand(), srand() functions
#include <stdbool.h>

int main() {
	//Some variables are already declarized so that their respective loops will run no matter what
	//Ex: seed is -1 so that its while-loop will always execute at least once
	int seed = -1;	// RNG seed
	int nVals; //scanf return value (for format checking)
	char junk; //for line clearing
	int min = -1; //range minimum
	int max = -1; //range maximum
	int guesses = 1; //user-input # of guesses
	int rds = 0; //user-input # of rounds
	int ans; //seeded rand() number
	int guess = -1; //user guess
	bool correct; //bool representing if user was correct
	int wins = 0; //# of user wins
	int losses = 0; //# of user losses

   //GET SEED
	while (!(seed > 0)) {
		do {
			printf("Enter seed for random number generator: ");
			nVals = scanf("%d", &seed);
			if (nVals < 1) {
				printf("ERROR: Incorrectly formatted input\n");
				do {
					scanf("%c", &junk);
				} while (junk != '\n');
			}
			if (nVals == 1 && seed < 1) {
				printf("ERROR: Seed value should be > 0\n");
				nVals = 0;
			}
		} while (nVals < 1);
	}
	printf("\nSeed: %d\n", seed);

	//GET RANGE
	while (!(min > 0) && !(max > 0)) {
		do {
			printf("\nEnter range endpoints: ");
			nVals = scanf("%d%d", &min, &max);

			if (nVals < 2) {
				printf("ERROR: Incorrectly formatted input\n");
				do {
					scanf("%c", &junk);
				} while (junk != '\n');
			}

			if (nVals == 2) {
				if (!(max >= min + 4)) {
					printf("ERROR: Max value should be at least 4 more than min value\n");
					nVals = 0; //nVals = 0 statement is used a lot
				}
				if (max < 0) {
					printf("ERROR: Max value should be positive\n");
					nVals = 0; // Makes sure that in the event of a formatting error, nVals is not mistakenly
								//taking input we don't want (negative ints in this case)
				}
				if (min < 0) {
					printf("ERROR: Min value should be positive\n");
					nVals = 0;
				}
			}
		} while (nVals < 2);
	}
	printf("\nRange endpoints: %d %d", min, max);

	//GET GUESSES
	while (!(guesses >= 2)) {
		do {
			printf("\n\nEnter number of guesses per round: \n");
			nVals = scanf("%d", &guesses);

			if (nVals < 1) {
				printf("ERROR: Incorrectly formatted input\n");
				do {
					scanf("%c", &junk);
				} while (junk != '\n');
			}

			if (nVals == 1 && guesses < 2) {
				printf("ERROR: Must allow at least 2 guesses\n");
				nVals = 0;
			}
		} while (nVals < 1);
	}
	printf("Number of guesses: %d", guesses);

	//GET ROUNDS
	while (!(rds >= 1)) {
		do {
			printf("\n\nEnter number of rounds for game: ");
			nVals = scanf("%d", &rds);

			if (nVals < 1) {
				printf("ERROR: Incorrectly formatted input\n");
				do {
					scanf("%c", &junk);
				} while (junk != '\n');
			}

			if (nVals == 1 && rds < 1) {
				printf("ERROR: Must allow at least 1 round\n");
			}

		} while (nVals < 1);
	}
	printf("\nNumber of rounds: %d\n", rds);

	srand(seed);

	//THE GAME
	//ROUNDS FOR-LOOP
	for (int i = 1; i <= rds; i++) {
		nVals = 0;
		correct = false;
		printf("\nROUND %d\n", i);
		ans = rand() % (max - min + 1) + min;

		//GUESSES FOR-LOOP
		for (int j = 1; j <= guesses; j++) {

			while (!(nVals == 1)) {
				do {
					printf("Enter guess #%d: ", j);
					nVals = scanf("%d", &guess);

					if (nVals < 1) {
						printf("ERROR: Incorrectly formatted input\n");
						do {
							scanf("%c", &junk);
						} while (junk != '\n');
					}
				} while (nVals < 1);
			}

			if (guess == ans) {
				correct = true;
				printf("Correct guess!\n");
				wins++;
				break;
			}
			else {
				if (guess > ans) {
					printf("%d is too high!\n", guess);
					nVals = 0;
				}
				else {
					printf("%d is too low!\n", guess);
					nVals = 0;
				}
			}

		}
		//win/loss stats and results kept outside of guesses for-loop, and inside rounds for-loop
		//boolean says if user is not correct by end of round, loss is added and round loop repeated
		if (!(correct)) {
			printf("No more guesses--the correct answer was %d\n", ans);
			losses++;
		}
		printf("\nCurrent wins: %d\n", wins);
		printf("Current losses: %d\n", losses);
	}
	//final stats outside of both for-loops to represent end of program/game
	printf("\nFINAL STATS\n");
	printf("Wins: %d\n", wins);
	printf("Losses : %d\n", losses);
	printf("Winning percentage : %0.2lf%%\n", ((double)wins / (wins + losses)) * 100);

	return 0;
}