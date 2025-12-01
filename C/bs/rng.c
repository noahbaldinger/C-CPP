/* Includes */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNum;

int guess;

int main() {
  srand(time(NULL));
  randomNum = rand() % 101;

  printf("How are you?\n");
  printf("This is a number guessing game. I've already got a number in my "
         "memory.\n");
  printf("Now you must guess the correct number!\n\r");

  while (guess != randomNum) {
    scanf("%d", &guess);
    if (guess < randomNum)
      printf("Your guess is too low.");
    else {
      printf("Your guess is too high.");
    }
  }
  printf("Congrats you guessed right!\n\r");
};
