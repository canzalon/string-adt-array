/*****************************************************************************
Author: Christopher Anzalone
File: stringdriver.cpp
Description: This file contains the driver of my user-implemented My_String 
class. It tests each member function's operations of the abstract data type
that is linked here from the "My_String.h" file (and from there to the 
My_String.cpp file). 
*****************************************************************************/

#include <iostream>
#include "My_String.h"

using namespace std;

int main()
{	

//Default constructor test
	cout<<"-- DEFAULT CONSTRUCTOR TEST"<<endl;

	My_String A;

	cout<<"My_String A has been created using the default constructor."<<endl;
	cout<<"My_String A's length: "<<A.Length()<<endl;

	cout<<endl<<"------------------------------------------------"<<endl;
//*************************************************************************

//Explicit constructor test
	cout<<"-- EXPLICIT CONSTRUCTOR TEST"<<endl;

	char userInput[16];
	cout<<"Please enter a value for string B..."<<endl;
	cin.getline(userInput, 16);

	cout<<endl;

	My_String B(userInput);
	
	cout<<"String B has been created explicitly, its contents\n"
		<<" is printed below:"<<endl;

	B.Print();

	cout<<endl<<"------------------------------------------------"<<endl;
//*************************************************************************


//Copy constructor test
	cout<<"-- COPY CONSTRUCTOR TEST"<<endl;

	cout<<"The contents of string B will now be copied (assigned)\n"
		<<"  to string CC."<<endl;
	My_String CC = B;

	cout<<"Printing CC: "<<endl;
	CC.Print();

	cout<<endl<<"------------------------------------------------"<<endl;
//*************************************************************************


//IsEmpty test
	cout<<"-- IS-EMPTY TEST"<<endl;

	bool emptyTest = B.IsEmpty();
	cout<<"Is B empty?.."<<endl;
	if (emptyTest==1)
		cout<<"B is empty."<<endl;
	else
		cout<<"B is NOT empty."<<endl;

	cout<<endl<<"------------------------------------------------"<<endl;
//*************************************************************************


//Length test
	cout<<"-- LENGTH TEST"<<endl;

	cout<<"Testing Length with B... :"<<endl;
	cout<<"\t"<<B.Length();

	cout<<endl<<"------------------------------------------------"<<endl;
//*************************************************************************

//Insert
	cout<<"-- INSERT TEST"<<endl;

	char * anotherInput = new char[20];
	cout<<"Input value for MyString C"<<endl;
	cin>>anotherInput;
	My_String C(anotherInput);

	cout<<"Inserting C into index 2 of B"<<endl;
	B.Insert(C, 2);

	cout<<"Printing B.."<<endl;
	B.Print();

	delete [] anotherInput;
	anotherInput = 0;

	cout<<endl<<"------------------------------------------------"<<endl;
//*************************************************************************

//AddStrings
	cout<<"-- ADD-STRINGS TEST"<<endl;

	cout<<"Adding string E onto string D (adding 'le' "
		<<"on to 'alela'"<<endl;
	My_String D("alela");
	My_String E("le");
	D.AddStrings(E);
	cout<<"Printing D"<<endl;
	D.Print();
	
	cout<<endl<<"------------------------------------------------"<<endl;
//*************************************************************************

//Find
	cout<<"-- FIND TEST"<<endl;

	cout<<"Finding start index of E ('le') within D ('alelale')\n"
		<<"STARTING at index 2"<<endl;
	int findnum = D.Find(E,2);
	cout<<"Testing find:"<<findnum<<endl;
	
	cout<<endl<<"------------------------------------------------"<<endl;
//*************************************************************************

//FindLast
	cout<<"-- FIND-LAST TEST"<<endl;

	cout<<"Finding last instance (starting index) of 'an' inside\n"
		<<"of 'banana'"<<endl;
	My_String F("banana");
	My_String G("an");
	int findlastnum = F.FindLast(G);
	cout<<"findLastNum: "<<findlastnum<<endl;
	
	cout<<endl<<"------------------------------------------------"<<endl;
//*************************************************************************

//Remove
	cout<<"-- REMOVE TEST"<<endl;

	My_String AA("stogop");
	My_String BB("go");
	AA.Remove(BB);
	cout<<"Removing BB from AA, or 'go' from 'stogop'"<<endl;
	cout<<"AA printed below.."<<endl;
	AA.Print();
	
	cout<<endl<<"------------------------------------------------"<<endl;
//*************************************************************************

//setEqual
	cout<<"-- SET-EQUAL TEST"<<endl;

	My_String Z("Alpha");
	My_String Y("Beta");
	cout<<"Y before SetEqual function:"<<endl;
	Y.Print();
	cout<<endl;
	Z.SetEqual(Y);
	cout<<"Y after SetEqual function:"<<endl;
	Y.Print();
	
	cout<<endl<<"------------------------------------------------"<<endl;
//*************************************************************************

//IsEqual
	cout<<"-- IS-EQUAL TEST"<<endl;

	My_String ZX("hello");
	My_String YX("hello");
	bool isEq_test = ZX.IsEqual(YX);
	cout<<"Testing ZX with YX ('hello' with 'hello')"<<endl;
	cout<<"Value of isEqual test: "<<isEq_test<<endl;
	
	cout<<endl<<"------------------------------------------------"<<endl;
//*************************************************************************

//Print
	cout<<"-- PRINT TEST"<<endl;

	My_String lastStr("Sagan");
	cout<<"Printing lastStr: "<<endl;
	lastStr.Print();
	
	cout<<endl<<"------------------------------------------------"<<endl;
//*************************************************************************

	cout<<"All required member functions have been tested!"<<endl;

	return 0;
}