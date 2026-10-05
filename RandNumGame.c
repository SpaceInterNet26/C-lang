
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void game();
int main() {
	int n;
		printf(" NUMBER GUESSING GAME \n");
		printf(" 1. Play the game\n 2. Exit\n Your choice: ");
		scanf("%d", &n);
		do{
		switch (n)
		{
		case 1:
			game();
			printf("\nDo you want to play again? 1 - Yes, 2- No\n");
			scanf("%d", &n);
			break;
		default:
			exit(0);
		}
		} while (n == 1);

	
	return 0;
}

void game() {

	srand(time(NULL));
	int random = rand() % 100 + 1;
	int input, counter = 0;
	do {
		printf("Guess a number: ");
		scanf("%d", &input);
		if (input < random) {
			printf("number is higher.\n");
		}
		else if (input > random) {
			printf("number is lower.\n");
		}
		counter++;
	} while (input != random);

	printf("You guessed it in %d tries\n", counter);


}
