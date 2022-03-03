/*
OUTLINE
1) create struct for FoodItem
2) create array of FoodItems
3) randomly pick from array
4) get user input for tax and tip (as percentages) using scanf
5) calculate costs
6) print out costs

*/

// BEGIN PROGRAM
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// struct for food item
struct FoodItem
{
  char name[10];
  float price;
};

// main function
int main()
{
  // array of FoodItems
  struct FoodItem menu[4];
  strcpy(menu[0].name, "Salad");
  menu[0].price = 9.95;
  strcpy(menu[1].name, "Soup");
  menu[1].price = 4.45;
  strcpy(menu[2].name, "Sandwhich");
  menu[2].price = 13.25;
  strcpy(menu[3].name, "Pizza");
  menu[3].price = 22.35;

  // randomly pick from array
  srand(time(0));
  struct FoodItem randomItem = menu[rand() % 4];

  // get user input for tax & tip
  float tip;
  float tax;
  printf("Please enter tip and tax as a percentage (i.e. \"15.43 12.25\" )");
  tip = scanf("%f %f", &tip, &tax);

  // calculate cost
  float tipCost = randomItem.price * tip / 100;
  float taxCost = randomItem.price * tax / 100;
  float totalCost = randomItem.price + tipCost + taxCost;

  // print out costs
  printf("%s($%.2f), tax: $%.2f, tip: $%.2f, total: $%.2f", randomItem.name, randomItem.price, taxCost, tipCost, totalCost);

  return 0;
}