// File: SuperArray
// Created by Hugo Valle on 10/31/2017.
// Copyright (c) 2017 WSU
//

#include "SuperArray.h"
/*!
 * Constructor
 * @param begIndex User's low index
 * @param capacity Maximum array capacity
 */
SuperArray::SuperArray(const int begIndex, const unsigned int capacity)
{
	/* This is declaring a local variable, if you have data member
	 * called int* arr, the code on line ## will NOT refer to the data
	 * member, instead you created a second arr pointer, and this
	 * second pointer dies and is lost forever when the constructor ends
	 */
	arr = new int[capacity];
    SuperArray::capacity = capacity;
	// Other info below
    lowIndex = begIndex;
    highIndex = begIndex + capacity - 1; 
}

/*!
 * Class Destructor
 */
SuperArray::~SuperArray()
{
	delete[] arr;
}
/*!Convert array content to string
 * @param: obj SuperArray class
 * @return: String version of the array
 */

string arrayToString(const SuperArray& s)
{
    stringstream ss;
    //TODO: change 5 for s.length()
    for(int i=0; i < 5; i++)
    {
       // cout << s.arr[i] <<  " i " << i << endl;
        ss << s.arr[i] << " ";
    }
    string s1 = ss.str(); //build a string from the stream of chars
   // cout << s1 << endl;
   
    size_t found;
    found = s1.find_last_not_of(" ");
    if (found != string::npos)
    {
        s1.erase(found + 1);
    }
    else
    {
        s1.clear(); //whitespace
    }
    return s1;
}

/*!
 * overload [] operator. translates user's index to the real index
 * @param: index User's index
 * @return: the real index
 */

 int &SuperArray::operator[](const int index)
{
   int realIndex;
   if(SuperArray::lowIndex == 0)
   {
       realIndex = index;
   }
   else
   {
       realIndex = index - lowIndex;
   }
   return arr[realIndex];
}

