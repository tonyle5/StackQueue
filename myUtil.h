/* Name: Tony Le
 * Class: CS260 - 12720
 * Project: #1
 * Date: Jan 13, 2024
 * Description: This is the header file for a utility file, which contains
 * common functions, constants, and libraries.
 */

#ifndef _MYUTIL_
#define _MYUTIL_

#include <cfloat>
#include <climits>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

const int ERROR = -1;

const int STR_SIZE = 101;

const int INIT_CAP = 10;

const int GROWTH_FACTOR = 5;

// This function reads an input from the user and validates if the number is
// an integer and within a range.
template <typename T>
void getNumber(const char prompt[], const char errorMsg[], T from, T to,
               T& num);

// This function frees the memory allocated for a dynamic array.
template <typename T>
void freeDynamicArray(T*& arr);

// This function copy a dynamic array to a new array.
void setCharArr(const char*& srcArr, char*& destArr);

#include "myUtil.inl"

#endif

