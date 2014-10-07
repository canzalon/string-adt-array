/*****************************************************************************
Author: Christopher Anzalone
File: My_String.h
Description: This file contains the declaration of the My_String class. The 
implementation is located in the "My_String.cpp" file. The functions are in the 
following order, ctrl+f the tags (e.g. (#7) for the declaration of the Insert 
member function):
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

#ifndef MY_STRING
#define MY_STRING

class My_String
{
public:

//**********************************************************************************************
//NAME:  My_String (default constructor)    (#0)
//DESCRIPTION:  The default constructor will initialize the state of the object.
//PRECONDITION:  Declared in driver.		
//POSTCONDITION:  Object's state initialized. Dynamic memory allocated.
//**********************************************************************************************
	My_String();    //default

//**********************************************************************************************
//NAME:  My_String (explicit constructor)    (#1)
//DESCRIPTION:  Explicit-value constructor that initializes the state of the class with 
//              the specified value.
//PRECONDITION:  Char array parameter in variable declaration.	
//POSTCONDITION:  Object has been initialized with the specified value.
//**********************************************************************************************
	My_String(char*);	//explicit

//**********************************************************************************************
//NAME:  My_String (copy constructor)    (#2)
//DESCRIPTION:  This is the copy constructor, which makes a deep copy of itself for a
//              call-by-value, return, or intialization/declaration.
//PRECONDITION:  Current object exists and is initialized.		
//POSTCONDITION:  Deep copy of current object has been returned.
//**********************************************************************************************
	My_String(My_String &);	//copy

//**********************************************************************************************
//NAME:  ~My_String (destructor)    (#3)
//DESCRIPTION:  Deallocates dynamic memory and sets the state variables to null.
//PRECONDITION:  Object has been declared/initialized.				
//POSTCONDITION:  Object state has been nullified and deallocated.
//**********************************************************************************************
	~My_String();

//**********************************************************************************************
//NAME:  IsEmpty    (#4)
//DESCRIPTION:  Checks if object's state (string) is empty.
//PRECONDITION:  Object has been declared.				
//POSTCONDITION:  Boolean value returned; true if not empty, false if it is.
//**********************************************************************************************
	bool IsEmpty();

//**********************************************************************************************
//NAME:  IsFull    (#5)
//DESCRIPTION:  Checks if string is full
//PRECONDITION:  Object has been declared/initialized.			
//POSTCONDITION:  Value of true or false returned.
//**********************************************************************************************
	bool IsFull();

//**********************************************************************************************
//NAME:  Length    (#6)
//DESCRIPTION:  Returns length of string.
//PRECONDITION:  Object has been declared/initialized.			
//POSTCONDITION:  Number specifiying length of string returned.
//**********************************************************************************************
	int Length();

//**********************************************************************************************
//NAME:  Insert    (#7)
//DESCRIPTION:  Inserts substring into another string at position i.
//PRECONDITION:  Two objects has been declared/initialized; value for i has been established. 		
//POSTCONDITION:  Substring has been inserted at specified point in string.
//**********************************************************************************************
	void Insert(My_String &, int);

//**********************************************************************************************
//NAME:  AddStrings    (#8)
//DESCRIPTION:  Add two My_String object's strings together.
//PRECONDITION:  Two My_String objects have been declared/initialized.				
//POSTCONDITION:  Current object's string appended to explicit string.
//**********************************************************************************************
	void AddStrings(My_String &);

//**********************************************************************************************
//NAME:  Find    (#9)
//DESCRIPTION:  Finds index of string value inside string. Finds string a in string b
//              starting at position p.
//PRECONDITION:  Two string objects have been declared/initialized.
//				
//POSTCONDITION:  Index of string returned, or -1 if not found.
//**********************************************************************************************
	int Find(My_String &, int);

//**********************************************************************************************
//NAME:  FindLast    (#10)
//DESCRIPTION:  Finds last instance of a string.
//PRECONDITION:  Two string Objects have been declared/initialized.
//POSTCONDITION:  Index of last instance of sub string returned.
//**********************************************************************************************
	int FindLast(My_String &);

//**********************************************************************************************
//NAME:  Remove    (#11)
//DESCRIPTION:  Removes the first occurence of a substring from the string, if it exists.
//PRECONDITION:  Current My_String object holds values in char array, as well as the "substring"
//               My_String object.
//POSTCONDITION:  If it exists and current object's char array is not empty, then the substring 
//                has been removed.
//**********************************************************************************************
	void Remove(My_String &);

//**********************************************************************************************
//NAME:  Print    (#12)
//DESCRIPTION:  Prints current object's string.
//PRECONDITION:  Object has been declared/initialized. The string variable holds a value/values.			
//POSTCONDITION:  Object's string has been printed.
//**********************************************************************************************
	void Print();

//**********************************************************************************************
//NAME:  SetEqual    (#13)
//DESCRIPTION:  Sets a My_String object equal to another.
//PRECONDITION:  Two Objects have been declared/initialized.
//POSTCONDITION:  Explicit object's state has been set equal to current object's state.
//**********************************************************************************************
	void SetEqual(My_String &);

//**********************************************************************************************
//NAME:  IsEqual    (#14)
//DESCRIPTION:  Checks equality of two My_String objects.
//PRECONDITION:  Two My_String objects exist and hold char value(s). 
//POSTCONDITION:  A boolean value is returned; true if they are equal, false if they are not.
//**********************************************************************************************
	bool IsEqual(My_String &); 

//**********************************************************************************************
//NAME:  doubleCap    (#15)
//DESCRIPTION:  Doubles capacity of the dynamic array in the object's state.
//PRECONDITION:  Object has been declared/initialized.
//POSTCONDITION:  Capacity variable and dynamic memory have been doubled.
//**********************************************************************************************
	void doubleCap();

private:

	char * the_string;    //pointer for dynamic memory
	int CAPACITY;    //capacity tracked for expansion of the data structure
	int count;    //count keeps track of character count for the_string
};

#endif