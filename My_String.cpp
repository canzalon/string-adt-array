/*****************************************************************************
Author: Christopher Anzalone
File: My_String.cpp
Description: This file contains the implementation of the My_String class. The 
declaration is located in the "My_String.h" file. The functions are in the 
following order (same order in header file), ctrl+f the tags (e.g. (#7) for
the implementation of the Insert member function):
    (#0) My_String [default]
    (#1) My_String [explicit]
    (#2) My_String [copy]
    (#3) ~My_String [destructor]
    (#4) IsEmpty
    (#5) IsFull
    (#6) Length
    (#7) Insert
    (#8) AddStrings
    (#9) Find
    (#10) FindLast
    (#11) Remove
    (#12) Print
    (#13) SetEqual
    (#14) IsEqual
    (#15) doubleCap
*****************************************************************************/

#include "My_String.h"

#include <iostream>

using namespace std;


//**********************************************************************************************
//NAME:  My_String (default constructor)    (#0)
//DESCRIPTION:  The default constructor will initialize the state of the object.
//PRECONDITION:  Declared in driver.		
//POSTCONDITION:  Object's state initialized. Dynamic memory allocated.
//**********************************************************************************************
My_String::My_String()
{
	CAPACITY = 20;
	count = 0;

	the_string = new char[CAPACITY];    //allocate memory for char array
}


//**********************************************************************************************
//NAME:  My_String (explicit constructor)    (#1)
//DESCRIPTION:  Explicit-value constructor that initializes the state of the class with 
//              the specified value.
//PRECONDITION:  Char array parameter in variable declaration.	
//POSTCONDITION:  Object has been initialized with the specified value.
//**********************************************************************************************
My_String::My_String(char * inString) 
{		

	CAPACITY = 20;
	count = 0;

	the_string = new char[CAPACITY];    //allocate memory for char array
	
	//assign each character from parameter to local data set 
	int x=0;
	while (inString[x]!='\0')
	{
		the_string[x] = inString[x];
		count++;
		x++;
	}  	
}


//**********************************************************************************************
//NAME:  My_String (copy constructor)    (#2)
//DESCRIPTION:  This is the copy constructor, which makes a deep copy of itself for a
//              call-by-value, return, or intialization/declaration.
//PRECONDITION:  Current object exists and is initialized.		
//POSTCONDITION:  Deep copy of current object has been returned.
//**********************************************************************************************
My_String::My_String(My_String & otherChar) 
{
	//copy state (CAPACITY and count) to current object
	CAPACITY = otherChar.CAPACITY;
	count = otherChar.count;

	//allocate memory for current object
	the_string = new char[CAPACITY];

	//copy contents of other dynamic array this object's dyn array
	for (int x=0; x<count; x++)
	{
		the_string[x] = otherChar.the_string[x];
	}

}


//**********************************************************************************************
//NAME:  ~My_String (destructor)    (#3)
//DESCRIPTION:  Deallocates dynamic memory and sets the state variables to null.
//PRECONDITION:  Object has been declared/initialized.				
//POSTCONDITION:  Object state has been nullified and deallocated.
//**********************************************************************************************
My_String::~My_String()
{   
	CAPACITY = 0;    //set state variables to null
	count = 0;

	delete [] the_string;   //deallocate memory used by object
	the_string = 0;    //point to null to avoid dangling pointer
}


//**********************************************************************************************
//NAME:  IsEmpty    (#4)
//DESCRIPTION:  Checks if object's state (string) is empty.
//PRECONDITION:  Object has been declared.				
//POSTCONDITION:  Boolean value returned; true if not empty, false if it is.
//**********************************************************************************************
bool My_String::IsEmpty() 
{
	if (count==0)
		return 1;
	else 
		return 0;
}


//**********************************************************************************************
//NAME:  IsFull    (#5)
//DESCRIPTION:  Checks if string is full
//PRECONDITION:  Object has been declared/initialized.			
//POSTCONDITION:  Value of true or false returned.
//**********************************************************************************************
bool My_String::IsFull() 
{
	if (count==CAPACITY)
		return 1;
	else
		return 0;
}


//**********************************************************************************************
//NAME:  Length    (#6)
//DESCRIPTION:  Returns length of string.
//PRECONDITION:  Object has been declared/initialized.			
//POSTCONDITION:  Number specifiying length of string returned.
//**********************************************************************************************
int My_String::Length() 
{
	return (count);
}


//**********************************************************************************************
//NAME:  Insert    (#7)
//DESCRIPTION:  Inserts substring into another string at position i.
//PRECONDITION:  Two objects has been declared/initialized; value for i has been established. 		
//POSTCONDITION:  Substring has been inserted at specified point in string.
//**********************************************************************************************
void My_String::Insert(My_String & subStr, int i)
{
	//Checks if combined count of strings will exceed capacity
	//if so, capacity of current objects dynamic array is doubled.
	if ((count + subStr.count) > CAPACITY)
	{
		doubleCap();
	}

	//if i is greater than count, append substr to end of current string
	if (i>count)
	{ 
		AddStrings(subStr);
	}
	else  //if index i exists, insert sub string
	{
		int num_elements /*z*/ = (count - i);   //Move "z" characters
		int shift /*x*/ = subStr.count;         //"x" times down.

		//This will shift the characters down to make room for the sub string
		//Outer loop controls how many chars are moved, and also controls..
		//..the amount of times each particular character is moved (inner loop)
		for (int z=0; z < num_elements; z++)
		{
			//Each chars loop will shift down depending on size of sub string..
			//..and current iteration. 
			for (int x=0; x < shift; x++)
			{
				 the_string[((count+x)-z)] = the_string[(((count-1)+x)-z)];
			}
			//Starting at the i position, "z" characters moved "x" amount of..
			//..times. (z=number of elements, x=number of times to shift).
		}

		//Inserts the substr into the empty elements of the current string
		for (int y=0; y < shift/*subStr count*/; y++)
		{   
			the_string[i+y] = subStr.the_string[y];
			count++;
		}
	}
}


//**********************************************************************************************
//NAME:  AddStrings    (#8)
//DESCRIPTION:  Add two My_String object's strings together.
//PRECONDITION:  Two My_String objects have been declared/initialized.				
//POSTCONDITION:  Current object's string appended to explicit string.
//**********************************************************************************************
void My_String::AddStrings(My_String & strB) 
{   
	//add states together for temp variable
	int tempCAP = CAPACITY + strB.CAPACITY;
	int tempCount = count + strB.count;

	//allocate memory with temp pointer
	char * tempStr = new char[tempCAP];

	//add this's contents to beginning of temp char array
	for (int x=0; (x < (*this).Length()); x++)
	{
		tempStr[x] = the_string[x];
	}

	int tempLength = strB.Length() + (*this).Length();
	//now add contents of subStr to end of temp char array
	for (int x=(*this).Length(), y=0; x<tempLength; x++, y++)
	{
		tempStr[x] = strB.the_string[y]; 
	}

	delete [] (*this).the_string;    //deallocate old memory of object's char array

	//point at new memory location, and update the rest of the state
	(*this).the_string = tempStr;   
	(*this).CAPACITY = tempCAP;
	(*this).count = tempCount;
}


//**********************************************************************************************
//NAME:  Find    (#9)
//DESCRIPTION:  Finds index of string value inside string. Finds string a in string b
//              starting at position p.
//PRECONDITION:  Two string objects have been declared/initialized.
//				
//POSTCONDITION:  Index of string returned, or -1 if not found.
//**********************************************************************************************
int My_String::Find(My_String & strB, int p) 
{   //find string a in string b starting at pos p
	int b_length = strB.Length();

	int tally=0;
	for (int x=0;p<=count;p++) //outer loop, x remains at 0 to keep testing B string against A
	{
		if (strB.the_string[x] == the_string[p]) //check if first char of B matches current element of A
		{
			//search for first-letter match
			for (int y=0; y<b_length; y++) //loop runs after a first-letter match, for as long as B's length
			{
				if (strB.the_string[y]==the_string[p+y])
				{
					tally++;  //add one to tally for element match
				}
			} //if complete match, ADD tally value to p counter

			if (tally==b_length)
			{
				return p;
			}
			else
			{
				p=p+tally;
				tally=0;
			}

		}

	}
	//if no matches found then return value of -1, instead of index
	return -1;

}


//**********************************************************************************************
//NAME:  FindLast    (#10)
//DESCRIPTION:  Finds last instance of a string.
//PRECONDITION:  Two string Objects have been declared/initialized.
//POSTCONDITION:  Index of last instance of sub string returned.
//**********************************************************************************************
int My_String::FindLast(My_String & strB) 
{
	int p = 0;
	int countCtrl = count;
	
	//if the substring is larger than the current string, a -1 is..
	//..returned as it would be impossible for you to find an instance..
	//..of it, in that case.
	if (count < strB.count)
	{
		return -1;
	}
	else   //the current string is equal or greater in size to the substring 
	{   //while x is less than "the number of times the substring can be divided..
		//..among the current string"
		for (int x=0; x < (count/strB.count); x++)
		{   //each possible length of the substring is tested throughout the..
			//..current string.
			p = Find(strB, countCtrl-strB.count);
			//if Find returns an actual index number, then it is returned right..
			//..away since we are searching from last to first.
			if (p != -1)
			{
				return p;
			}

			countCtrl--;
		}
	}
	//if the if/else structure is passed, then nothing was found and -1 is returned.
	return p;
}


//**********************************************************************************************
//NAME:  Remove    (#11)
//DESCRIPTION:  Removes the first occurence of a substring from the string, if it exists.
//PRECONDITION:  Current My_String object holds values in char array, as well as the "substring"
//               My_String object.
//POSTCONDITION:  If it exists and current object's char array is not empty, then the substring 
//                has been removed.
//**********************************************************************************************
void My_String::Remove(My_String & strB) 
{
	if (count == 0)	//Checks if object's char array is empty
	{
		cout<<"The array is empty; cannot remove."<<endl;
	}
	else
	{

		//Checks if the substring exists inside the object's string
		int position=Find(strB,0);

		if (position == -1)  //error if substring does not exist
		{
			cout <<" Substring does not exist in the string, unable "
				 <<"to remove it. "<<endl;
		}
		else  //shifts necessary chars to remove all of substring
		{ 
			int tally = 0;  //to control which chars get moved and when

			//loop as many times as there are chars AFTER the substring
			for (int z=0; z < (count-(position+strB.count)); z++)
			{   //chars shifted n* times to overwrite substring. *(n=substring count)
				for (int x=0, y=position; x < strB.count; x++, y--)
				{
					the_string[(y + strB.count)+tally-1] = the_string[(y+strB.count)+tally];
				}

				tally++;
			}
			count=count-strB.count;  //modify counter for removed chars

		}
	}
}


//**********************************************************************************************
//NAME:  Print    (#12)
//DESCRIPTION:  Prints current object's string.
//PRECONDITION:  Object has been declared/initialized. The string variable holds a value/values.			
//POSTCONDITION:  Object's string has been printed.
//**********************************************************************************************
void My_String::Print() 
{   //each char in array is printed individually
	for (int x=0; x<count; x++)
	{
		cout<<the_string[x];
	}
}


//**********************************************************************************************
//NAME:  SetEqual    (#13)
//DESCRIPTION:  Sets a My_String object equal to another.
//PRECONDITION:  Two Objects have been declared/initialized.
//POSTCONDITION:  Explicit object's state has been set equal to current object's state.
//**********************************************************************************************
void My_String::SetEqual(My_String & B) 
{
	//copy state (CAPACITY and count) to current object
	B.CAPACITY = CAPACITY;
	B.count = count;

	delete [] B.the_string;    //deallocate old memory of  

	//allocate memory for current object
	B.the_string = new char[B.CAPACITY];

	//copy contents of other dynamic array this object's dyn array
	for (int x=0; x<count; x++)
	{
		B.the_string[x] = the_string[x];
	}

}


//**********************************************************************************************
//NAME:  IsEqual    (#14)
//DESCRIPTION:  Checks equality of two My_String objects.
//PRECONDITION:  Two My_String objects exist and hold char value(s). 
//POSTCONDITION:  A boolean value is returned; true if they are equal, false if they are not.
//**********************************************************************************************
bool My_String::IsEqual(My_String & strB)
{   //sizes (count) of the strings must be equal if they are the same
	if (count==strB.count)
	{   //if same size, test each character in both arrays
		for (int x=0; x<count; x++)
		{   //if all of the corresponding x elements do not equal..
			//..each other, then the strings are different.
			if (the_string[x] != strB.the_string[x])
			{
				return 0;
			}
		}
		//if the loop is survived, the strings are equal (because..
		//..they have the same length and each char value is equal.
		return 1;
	}
	else
	{   //returns false if size (count) is different.
		return 0;
	}
}


//**********************************************************************************************
//NAME:  doubleCap    (#15)
//DESCRIPTION:  Doubles capacity of the dynamic array in the object's state.
//PRECONDITION:  Object has been declared/initialized.
//POSTCONDITION:  Capacity variable and dynamic memory have been doubled.
//**********************************************************************************************
void My_String::doubleCap() 
{
	char * temp_str;    //temp pointer for memory

	CAPACITY=CAPACITY*2;    //capacity is doubled

	temp_str = new char[CAPACITY];   //memory allocated for temp variable

	//current values in object's string are copied to temp memory
	for (int x=0; x<count; x++)
	{
		temp_str[x] = the_string[x];
	}

	delete [] the_string;    //object's old memory is deallocated; it is no longer in use
	the_string = temp_str;    //set address of temp memory equal to the object's pointer

}