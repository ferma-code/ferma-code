#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numb;

    srand(time(NULL));
    printf("Game: Guess the number\n");

    printf("Enter number: ");
    scanf("%d", &numb);

    int secret = rand() % numb + 1;
    int guess;
    int count = 0;

    system("clear");

    while (1) {
        printf("Enter number: ");
        scanf("%d", &guess);

        count++;

        if (guess < secret) {
            printf("More\n");
        } else if (guess > secret) {
            printf("Less\n");
        } else {
            printf("You guessed!\n");
            printf("Attempts: %d\n", count);
            break;
        }
    }
    return 0;
}
