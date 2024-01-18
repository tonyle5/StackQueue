/* Name: Tony Le
 * Class: CS260 - 12720
 * Project: #2
 * Date: Jan 18, 2024
 * Description: This is the header file for the main program.
 */

#ifndef MAIN_H
#define MAIN_H

#include "RestaurantQueue.h"
#include "Stack.h"
#include "myUtil.h"

const char* DATA_QUEUE = "groups.txt";
const char* DATA_STACK = "stacks.txt";
const char* DATA_POPPED_CUSTOMER = "popped-customers.txt";

// Function prototypes

// This function prints a welcome message.
void welcome();

// This function prints a goodbye message.
void goodbye();

// This function displays the menu to the user.
void displayMenu();

// This function prompts the user to enter the group information and adds it to
// the restaurant queue.
void addGroup(RestaurantQueue& restaurantQueue, Stack& stack);

void peekQueue(RestaurantQueue& restaurantQueue);

void popCustomer(Stack& stack);

void peekCustomer(Stack& stack);

// This function calls the different functions such as view, add, remove, and
// search for doughnuts.
void exeOption(int option, RestaurantQueue& restaurantQueue, Stack& stack);

#endif
