/* Name: Tony Le
 * Class: CS260 - 12720
 * Project: #1
 * Date: Jan 13, 2024
 * Description: This is the implementation file for a utility file.
 */

#include "myUtil.h"

// Name:   setCharArr()
// Desc:   This function copy a dynamic array to a new array.
// Input:  const char* srcArr, char*& destArr
// Output: None
// Return: None
void setCharArr(const char*& srcArr, char*& destArr) {
  if (srcArr) {
    freeDynamicArray<char>(destArr);

    int size = strlen(srcArr);
    destArr = new char[size + 1];

    strcpy(destArr, srcArr);
  }
}
