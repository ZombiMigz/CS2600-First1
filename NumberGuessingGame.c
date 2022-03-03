/*
OUTLINE
1) create max number variable
2) create function to generate random number based on max number
3) create function to play game (ask user and return correct or wrong)
4) create struct for game results
5) add store game results in game function
6) add q(quit) option in game function
7) create setMaxValue function (print max settable value and read input)
8) add error checking on setMaxValue function
9) create main function with while loop checking inputs
10) add option 3 to inputs (thanks user, prints results, return 0)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// max number variable
int maxNumber = 10;

// generate a random number
int generateRandomNumber()
{
  srand(time(0));
  return rand() % maxNumber + 1;
}

// game result storage
struct GameResult
{
  bool win;
  int attempts;
};

int currGame;
struct GameResult gameResults[999];

void printGameResults()
{
  printf("GAME RESULTS\n");
  for (int i = 0; i < currGame; i++)
  {
    printf("Game %d) result: %s | attempts: %d\n", i + 1, gameResults[i].win == true ? "WIN" : "LOSS", gameResults[i].attempts);
  }
  printf("**********\n");
}

// play game function
void playGame()
{
  printf("It's time to start playing the game!\n");
  int randomNumber = generateRandomNumber();
  while (true)
  {
    printf("Enter a number between 1 and %d or enter q to quit: ", maxNumber);
    gameResults[currGame].attempts++;
    char result;
    scanf(" %c", &result);
    if (result == 'q')
    {
      printf("Quitting game. Loss recorded\n");
      gameResults[currGame].attempts--;
      gameResults[currGame].win = false;
      break;
    }
    if (result - '0' == randomNumber)
    {
      printf("Congradulations! You guessed the correct number!\n");
      gameResults[currGame].win = true;
      break;
    }
    else
    {
      printf("Oops, wrong number! Try again.\n");
    }
  }
  currGame++;
}

// set max value
void setMaxValue()
{
  while (true)
  {
    printf("Enter a maximum value greater than 0 and less or equal to than 10:");
    int val;
    scanf("%d", &val);
    if (val > 0 && val <= 10)
    {
      printf("The new max value will be: %d\n", val);
      maxNumber = val;
      break;
    }
    printf("Sorry, that is an invalid maximum value\n");
  }
}

int main()
{
  while (true)
  {
    printf("Please select an option:\n");
    printf("Press 1 to play a game\n");
    printf("Press 2 to change the max number\n");
    printf("Press 3 to quit\n");

    int input;
    scanf("%d", &input);
    if (input == 1)
      playGame();
    if (input == 2)
      setMaxValue();
    if (input == 3)
      break;
  }
  printf("Thank you for playing!\n");
  printGameResults();
  return 0;
}
