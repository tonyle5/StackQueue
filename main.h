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

/**
 * This function prints a welcome message.
 *
 * @return void
 */
void welcome();

/**
 * This function prints a goodbye message.
 *
 * @return void
 */
void goodbye();

/**
 * This function displays the menu to the user.
 *
 * @return void
 */
void displayMenu();

/**
 * This function prompts the user to enter the group information and adds it
 * to the restaurant queue.
 *
 * @param restaurantQueue The restaurant queue.
 * @param stack The stack.
 * @return void
 */
void addGroup(RestaurantQueue& restaurantQueue, Stack& stack);

/**
 * This function peeks at the first group that arrives in the queue.
 *
 * @param restaurantQueue The restaurant queue.
 * @return void
 */
void peekQueue(RestaurantQueue& restaurantQueue);

/**
 * This function removes the most recent (or top) customer in the stack.
 *
 * @param restaurantQueue The restaurant queue.
 * @return void
 */
void popCustomer(Stack& stack);

/**
 * This function peeks at the most recent (or top) customer in the stack.
 *
 * @param restaurantQueue The restaurant queue.
 * @return void
 */
void peekCustomer(Stack& stack);

/**
 * This function executes the option that the user chooses.
 *
 * @param option The option that the user chooses.
 * @param restaurantQueue The restaurant queue.
 * @param stack The stack.
 * @return void
 */
void exeOption(int option, RestaurantQueue& restaurantQueue, Stack& stack);

#endif
