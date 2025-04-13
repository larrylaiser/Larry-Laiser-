#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
 {
    int maxLevel = 4;
    char *levelNames[] = {"Easy", "Medium", "Hard", "Impossible"};
    int maxNumbers[] = {10, 50, 100, 1000};
    char input[20];
    
   
    srand(time(0));
    
    int level = 1;
    
    while (1) {
        int lives = 5;
        int target, guess;
        int range = maxNumbers[level - 1];
        
        
        target = rand() % range + 1;
        
        printf("\nLevel %d - %s (Guess a number between 1 and %d)\n", level, levelNames[level - 1], range);
        printf("You have %d lives. Type 'q' to quit at any time.\n", lives);
        
        int won = 0;
        while (lives > 0) {
            printf("Enter your guess: ");
            scanf("%s", input);
            
           
            if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
                printf("Quitting the game.\n");
                return 0;
            }
            
            guess = atoi(input);
            lives--;
            
            if (guess > target) {
                printf("Too high! You have %d lives left.\n", lives);
            } else if (guess < target) {
                printf("Too low! You have %d lives left.\n", lives);
            } else {
                printf("Congratulations! You guessed the number correctly!\n");
                won = 1;
                break;
            }
        }
        
        if (won) {
            if (level < maxLevel) {
                printf("Level %d completed. Go to next level (n) or quit (q)? ", level);
                scanf("%s", input);
                if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
                    printf("Quitting the game.\n");
                    return 0;
                } else {
                    level++;
                    continue;
                }
            } else {
                printf("Congratulations! You've completed the Impossible level and won the game!\n");
                printf("Play again? (y to restart / q to quit): ");
                scanf("%s", input);
                if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
                    printf("Quitting the game.\n");
                    return 0;
                } else {
                    level = 1;
                    continue;
                }
            }
        } else {
            
            printf("Game over! You ran out of lives.\n");
            printf("Do you want to try again? (y to restart / q to quit): ");
            scanf("%s", input);
            if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
                printf("Quitting the game.\n");
                return 0;
            }
           
            level = 1;
        }
    }
    return 0;
}