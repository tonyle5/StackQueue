/******************************************************************************
# Author:           Tony Le
# Project:          Project 2
# Date:             Jan 18, 2024
# Description:      This program will help you keeping track of groups in
#                   line at the restaurant, and how long it will take before
#                   they get a table.
#                   It also helps reaching out to the customers who most
#                   recently frequented the restaurant to provide promotional
#                   materials so that they will return before forgetting about
#                   the restaurant.
# Sources:          Project 2 specifications
#*****************************************************************************/

#include "main.h"

int main() {
  RestaurantQueue restaurantQueue;
  Stack stack(INIT_CAP);
  int option = -1;
  int groupLoadResult = restaurantQueue.loadData(DATA_QUEUE, stack);
  int stackLoadResult = stack.loadData(DATA_STACK);

  welcome();

  if (groupLoadResult != ERROR && stackLoadResult != ERROR) {
    cout << groupLoadResult << " group(s) added to the queue." << endl;
    cout << stack.getSize() << " customer(s) added to the stack." << endl
         << endl;

    do {
      displayMenu();

      getNumber("", "Please choose the option from 1 to 10!", 1, 10, option);

      exeOption(option, restaurantQueue, stack);
    } while (option != 10);

    goodbye();
  }
}

// Name:   welcome()
// Desc:   This function prints a welcome message.
// Input:  None
// Output: Welcome message
// Return: None
void welcome() {
  cout << "Welcome to Line program!" << endl;
  cout << "This program will help you keeping track of restaurant wait list.";
  cout << endl << endl;
}

// Name:   goodbye()
// Desc:   This function prints a goodbye message.
// Input:  None
// Output: Goodbye message
// Return: None
void goodbye() {
  cout << endl;
  cout << "Thank you for using the program!!";
}

// Name:   displayMenu()
// Desc:   This function displays the menu to the user.
// Input:  None
// Output: The menu.
// Return: None
void displayMenu() {
  cout << "Pick an option from below: " << endl << endl;
  cout << "1. Add a new group to the queue" << endl;
  cout << "2. Remove the first group from the queue" << endl;
  cout << "3. Peek at the first group in queue" << endl;
  cout << "4. Display the wait list" << endl << endl;

  cout << "5. Pop the most recent customer from the stack" << endl;
  cout << "6. Peek at the most recent customer from the stack" << endl;
  cout << "7. Get the size of the customer stack" << endl;
  cout << "8. Check if the customer stack is empty" << endl;
  cout << "9. Display the customer stack" << endl << endl;

  cout << "10. Quit" << endl;
  cout << endl;
}

// Name:   addGroup()
// Desc:   This function prompts the user to enter the group information and
// adds it to
//         the restaurant queue.
// Input:  RestaurantQueue& restaurantQueue
// Output: Prompts the user to enter the group information
// Return: None
void addGroup(RestaurantQueue& restaurantQueue, Stack& stack) {
  char groupName[STR_SIZE];
  int numPeople;
  bool isSpecialSeatingNeeded;
  char seatingInfo[STR_SIZE];
  bool isPromoAllowed;
  PersonalInfo personalInfo;
  char fullName[STR_SIZE] = "";
  char email[STR_SIZE] = "";

  cout << "Enter the group name: ";
  cin.getline(groupName, STR_SIZE);

  getNumber<int>("Enter the number of people: ",
                 "Please enter a valid number!", 1, INT_MAX, numPeople);

  getNumber<bool>("Is anyone who needs special seating? (0: No, 1: Yes) ",
                  "Please enter 0 for No or 1 for Yes!", 0, 1,
                  isSpecialSeatingNeeded);

  if (isSpecialSeatingNeeded) {
    cout << "Enter the information about any requirements: ";
    cin.getline(seatingInfo, STR_SIZE);
  }

  getNumber<bool>(
    "Would the group like to receive coupons and other promotional "
    "materials? (0: No, 1: Yes) ",
    "Please enter 0 for No or 1 for Yes!", 0, 1, isPromoAllowed);

  if (isPromoAllowed) {
    cout << "Enter full name: ";
    cin.getline(fullName, STR_SIZE);

    cout << "Enter email: ";
    cin.getline(email, STR_SIZE);

    stack.push(PersonalInfo(fullName, email));
  }

  personalInfo = PersonalInfo(fullName, email);

  restaurantQueue.enqueue(
    Group(groupName, numPeople, isSpecialSeatingNeeded,
          isSpecialSeatingNeeded ? seatingInfo : nullptr, isPromoAllowed,
          personalInfo));

  cout << endl;
}

void peekQueue(RestaurantQueue& restaurantQueue) {
  Group group;

  if (restaurantQueue.peek(group)) {
    cout << "The first group in the queue: " << endl;
    group.printInformation(cout);
  } else {
    cout << "There is no group in the queue.";
  }

  cout << endl << endl;
}

void popCustomer(Stack& stack) {
  ofstream outFile;
  outFile.open(DATA_POPPED_CUSTOMER, std::ios_base::app);

  if (!outFile) {
    cout << "Error openning the file!!" << endl;
    return;
  }

  PersonalInfo personalInfo;

  if (stack.pop(personalInfo)) {
    cout << "This customer was removed from the stack: " << endl;
    cout << personalInfo << endl;

    outFile << personalInfo << endl;
    cout << "The customer information was written to file." << endl << endl;
  }

  outFile.close();
}

void peekCustomer(Stack& stack) {
  PersonalInfo personalInfo;

  if (stack.peek(personalInfo)) {
    cout << "Displaying the most recent customer: " << endl;
    cout << personalInfo;
  } else {
    cout << "There is no customer in the stack!";
  }

  cout << endl << endl;
}

// Name:   exeOption()
// Desc:   This function calls the different functions based on the input
//         option.
// Input:  char option, RestaurantQueue& restaurantQueue
// Output: None
// Return: None
void exeOption(int option, RestaurantQueue& restaurantQueue, Stack& stack) {
  switch (option) {
    case 1:
      addGroup(restaurantQueue, stack);
      restaurantQueue.display();
      break;
    case 2:
      restaurantQueue.dequeue();
      cout << endl;
      restaurantQueue.display();
      break;
    case 3:
      peekQueue(restaurantQueue);
      break;
    case 4:
      restaurantQueue.display();
      break;
    case 5:
      popCustomer(stack);
      break;
    case 6:
      peekCustomer(stack);
      break;
    case 7:
      cout << "The stack contains " << stack.getSize() << " customers."
           << endl
           << endl;
      break;
    case 8:
      cout << "The stack is " << (stack.isEmpty() ? "" : "not ") << "empty."
           << endl
           << endl;
      break;
    case 9:
      cout << stack << endl;
      break;
    case 10:
      if (!restaurantQueue.writeData(DATA_QUEUE)) {
        cout << "Error writing groups to the file!!" << endl;
      }

      if (!stack.writeData(DATA_STACK)) {
        cout << "Error writing customers to the file!!" << endl;
      }
      break;
    default:
      cout << "Invalid option!! Please try again!!!" << endl << endl;
  }
}
