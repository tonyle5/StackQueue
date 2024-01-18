// Name:   getNumber()
// Desc:   This function reads an input from the user and validates if the
//         number has type T and within a range.
// Input:  const char prompt[], const char errorMsg[], T from, T to,
//         T& num
// Output: Possibly error messages for data validation.
// Return: None
template <typename T>
void getNumber(const char prompt[], const char errorMsg[], T from, T to,
               T& num) {
  cout << prompt;

  cin >> num;

  while (!cin || num < from || num > to) {
    cout << errorMsg << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << prompt;
    cin >> num;
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Name:   freeDynamicArray()
// Desc:   This function frees the memory allocated for a dynamic array.
// Input:  T*& arr
// Output: None
// Return: None
template <typename T>
void freeDynamicArray(T*& arr) {
  if (arr) {
    delete[] arr;
    arr = nullptr;
  }
}
