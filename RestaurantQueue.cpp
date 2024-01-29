#include "RestaurantQueue.h"

// Default constructor
RestaurantQueue::RestaurantQueue() : rear(nullptr), size(0) {}

// Destructor
RestaurantQueue::~RestaurantQueue() {
  while (this->size) {
    this->dequeue();
  }
}

// Adds a group to the waiting list.
void RestaurantQueue::enqueue(const Group& group) {
  Node* newNode = new Node;
  newNode->data = group;
  newNode->next = nullptr;

  if (!this->rear) {
    // The list is empty
    newNode->next = newNode;
    this->rear = newNode;
  } else {
    newNode->next = this->rear->next;
    this->rear->next = newNode;
    this->rear = newNode;
  }

  this->size++;
}

// Removes the front group from the waiting list.
void RestaurantQueue::dequeue() {
  if (!this->rear) {
    // The list is empty
    return;
  }

  Node* front = this->rear->next;
  this->rear->next = front->next;
  delete front;

  this->size--;

  if (this->size == 0) {
    this->rear = nullptr;
  }
}

// Views the front group without removing it.
bool RestaurantQueue::peek(Group& aGroup) const {
  if (this->size == 0) {
    return false;
  }

  // There is always a next node even if the queue only has one group.
  aGroup = this->rear->next->data;

  return true;
}

// Displays the waiting list along with the number in line.
void RestaurantQueue::display() const {
  if (!rear) {
    cout << "Waiting list is empty!" << endl << endl;
    return;
  }

  Node* cur = rear->next;
  int position = 1;

  cout << "Displaying " << this->size << " group(s): " << endl << endl;

  while (position <= this->size) {
    cout << position << ". ";
    cur->data.printInformation(cout);
    cout << endl;

    cur = cur->next;
    position++;
  }

  cout << endl;
}

// Loads group data from a file into the queue. If there are any groups
// would like to receive coupons and other promotional materials, they are
// added to the stack.
int RestaurantQueue::loadData(const char fileName[], const Stack& stack) {
  ifstream inFile;
  inFile.open(fileName);

  if (!inFile) {
    return ERROR;
  }

  char groupName[STR_SIZE];
  int numPeople;
  bool isSpecialSeatingNeeded;
  char seatingInfo[STR_SIZE];
  bool isPromoAllowed;
  PersonalInfo personalInfo;
  char fullName[STR_SIZE];
  char email[STR_SIZE];

  inFile.ignore(numeric_limits<streamsize>::max(), '\n');

  inFile.getline(groupName, STR_SIZE, ';');

  while (!inFile.eof()) {
    inFile >> numPeople;
    inFile.ignore();

    inFile >> isSpecialSeatingNeeded;
    inFile.ignore();

    inFile.getline(seatingInfo, STR_SIZE, ';');

    inFile >> isPromoAllowed;
    inFile.ignore();

    inFile.getline(fullName, STR_SIZE, ';');

    inFile.getline(email, STR_SIZE, '\n');

    if (isPromoAllowed) {
      stack.push(PersonalInfo(fullName, email));
    }

    personalInfo = PersonalInfo(fullName, email);

    this->enqueue(Group(groupName, numPeople, isSpecialSeatingNeeded,
                        isSpecialSeatingNeeded ? seatingInfo : nullptr,
                        isPromoAllowed, personalInfo));

    inFile.getline(groupName, STR_SIZE, ';');
  }

  inFile.close();

  return this->size;
}

// Writes group data from the queue to a file.
bool RestaurantQueue::writeData(const char fileName[]) {
  ofstream outFile;
  outFile.open(fileName);

  if (!outFile) {
    return false;
  }

  outFile << "Group name;Number of people;Special seating needed;Special "
          << "seating info;Promotion allowed;Full name;Email" << endl;

  Node* cur = this->rear;

  for (int i = 0; i < this->size; i++) {
    cur = cur->next;

    cur->data.printInformation(outFile);
    outFile << endl;
  }

  outFile.close();

  return true;
}
