h22265
s 00604/00000/00000
d D 1.1 19/04/14 20:16:38 nzenger 1 0
c date and time created 19/04/14 20:16:38 by nzenger
e
u
U
f e 0
t
T
I 1
/*****************************************************************
//
//  NAME:        Nathan Zenger
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 14, 2019
//
//  FILE:        llist.c
//
//  DESCRIPTION:
//   This file contains llist functions of the llist class
//
//
****************************************************************/

#include "llist.h"
#include "record.h"
#include <stdlib.h> 
#include <string.h>
#include <sstream>
#include<fstream>
#include <iostream>
using namespace std;

/*****************************************************************
//
//  Function name: llist()
//
//  DESCRIPTION:   A llist class function
//                 This function is a constructor for the llist class
//
//  Parameters:    N/A
//
//  Return values:  N/A
//
****************************************************************/

llist::llist()
{
    #ifdef _DEBUG
	cout << "DEBUGGER--> llist::llist() has been called with no parameters passed in\n";
    #endif
	
    start = NULL;
    strcpy(filename, "read.txt");
    readfile();
}

/*****************************************************************
//
//  Function name: llist(char[})
//
//  DESCRIPTION:   A llist class function
//                 This function is a constructor for the llist class
//
//  Parameters:    file (char[]) : contains name of file to read
//
//  Return values:  N/A
//
****************************************************************/

llist::llist(char file[]) 
{
    #ifdef _DEBUG
        cout << "DEBUGGER--> llist::llist(char[]) has been called and passed in char[]: " << file <<"\n";
    #endif
	
    start = NULL;
    strcpy(filename, file);
    readfile();

}

/*****************************************************************
//
//  Function name: ~llist()
//
//  DESCRIPTION:   A llist class function
//                 This function is a destructor for the llist class
//
//  Parameters:    N/A
//
//  Return values:  N/A
//
****************************************************************/

llist::~llist()
{
    #ifdef _DEBUG
        cout << "DEBUGGER--> llist::~llist() has been called with no parameters passed in\n";
    #endif
    writefile();
    cleanup();
    start = NULL;
}

/*****************************************************************
//
//  Function name: reverse()
//
//  DESCRIPTION:   A llist class function
//                 This function reverses the list of records
//
//  Parameters:    N/A
//
//  Return values: N/A
//
****************************************************************/

void llist::reverse()
{
    #ifdef _DEBUG
	cout << "DEBUGGER--> llist:reverse() has been called with no parameters passed in\n";
    #endif

    llist::reverse(start);
}

/*****************************************************************
//
//  Function name: reverse(struct record*)
//
//  DESCRIPTION:   A llist class function
//                 This function is a helper methof for the reverse() function
//
//  Parameters:    curr (struct record*) : contains a pointer to current struct record
//                               which will be reveresed
//
//  Return values:  *struct record: points to starting struct record of new reversed list
//
****************************************************************/

record* llist::reverse(struct record* curr)
{
    #ifdef _DEBUG
        cout << "DEBUGGER--> llist:reverse(struct record*) has been called and passed in struct record*\n";
    #endif

    if (curr == NULL) 
    {
        return NULL;
    }
    if (curr->next == NULL) 
    {
        start = curr;
        return curr;
    }
    struct record* curr2 = reverse(curr->next);
    curr2->next = curr;
    curr->next = NULL;
    return curr;
}

/*****************************************************************
//
//  Function name: operator<<(ostream)
//
//  DESCRIPTION:   A llist class function
//                 This function overloads the << operator to print the list of records
//
//  Parameters:    &out (ostream) : contains the ostream passed in as a parameter
//                               required to overload the operator
//
//  Return values:  ostream : the output of printing the list
//
****************************************************************/

std::ostream & llist::operator<<(std::ostream &out)
{
    #ifdef _DEBUG
        cout << "DEBUGGER--> std::ostream & llist::operator<<(std::ostream & out) has been called and passed in std::ostream\n";
    #endif
	
    if (start == NULL) 
    {
        cout << "Database is empty...\n";
    }
    else if (start != NULL) 
    {
        struct record *ptr;
	ptr = start;
	cout << "All of Database:\n";
	while ((ptr) != NULL) 
        {
	    cout << "Name:\n" << ptr->name << "\n";
	    cout << "Account Number:\n" << ptr->accountno << "\n";
	    cout << "Address:\n" << ptr->address << "\n";
	    ptr = ptr->next;
	}
    }
    return out;
}

/*****************************************************************
//
//  Function name: addRecord(int,char*,char*)
//
//  DESCRIPTION:   A list class function
//                 This function adds a record to the list
//
//  Parameters:    accountno (int) : contains the account number of the record
//                               which will be added
//                 name (char*) : contains the name of the record
//                               which will be added 
//				   address (char*) : contains the address of the record
//				                 which will be added
//
//  Return values:  0 : success
//                 -1 : the record was not added
//
****************************************************************/

int llist::addRecord(int accountno, char *name, char *address) 
{
    #ifdef _DEBUG
        cout << "DEBUGGER--> addRecord(int,char*,char*) has been called and passed in int: " << accountno <<", char*: " << name << ", char*:" << address << "\n";
    #endif

    int boul = 0;
    if (start == NULL)
    {
        struct record *temp;
	temp = new struct record();
	start = temp;
	temp->accountno = accountno;
	strcpy(temp->name, name);
	strcpy(temp->address, address);
	temp->next = NULL;
	boul = 1;
    }
    if (start != NULL && boul == 0) 
    {
	struct record *ptr;
	ptr = start;
	while ((ptr) != NULL) 
	{
	    if (ptr->accountno == accountno) 
	    {
	        boul = -1;
		cout << "Cannot accept duplicate account number in database...\n";
	    }
	    ptr = ptr->next;
	}
    }
    if (start != NULL && boul == 0) 
    {
	struct record *newrec = new struct record();
	struct record *ptr;
	ptr = start;
	while ((ptr->next) != NULL) 
	{
	    ptr = ptr->next;
	}
	ptr->next = newrec;
	newrec->accountno = accountno;
	strcpy(newrec->name, name);
	strcpy(newrec->address, address);
	newrec->next = NULL;
	boul = 1;
    }
    else 
    {
        boul = -1;
    }
    return boul;
}

/*****************************************************************
//
//  Function name: printRecord(int)
//
//  DESCRIPTION:   A llist class function
//                 This function pritns a specific record ith matching account no
//
//  Parameters:    accountno (int) : contains the account number to search for
//                               which will be printed
//
//  Return values:  0 : success
//                 -1 : the record was not found
//
****************************************************************/

int llist::printRecord(int accountno) 
{
    #ifdef _DEBUG
        cout << "DEBUGGER--> llist::printRecord(int) has been called and passed in int: " << accountno << "\n";
    #endif
	
    struct record *ptr;
    ptr = start;
    cout << "Database record:\n";
    while ((ptr) != NULL) 
    {
        if (accountno == ptr->accountno) 
	{
	    cout << "Name:\n" << ptr->name << "\n";
	    cout << "Account Number:\n" << ptr->accountno << "\n";
	    cout << "Address:\n" << ptr->address << "\n";
	}
	ptr = ptr->next;
    }
    return 0;
}

/*****************************************************************
//
//  Function name: printAllRecords(struct record*)
//
//  DESCRIPTION:   A helper method for operator<<(ostream)
//                 This function prints all records in list in order
//
//  Parameters:    start (struct record*) : contains paonter to first record in list
//                               which will be traversed and printed
//
//  Return values:  N/A
//
****************************************************************/

void printAllRecords(struct record* start) 
{
    #ifdef _DEBUG
        cout << "DEBUGGER--> printAllRecords(struct record*) has been called and passed in struct record*\n";
    #endif

    if (start == NULL) 
    {
	cout << "Database is empty...\n";
    }
    else if (start != NULL) 
    {
        struct record *ptr;
	ptr = start;
	cout << "All of Database:\n";
	while ((ptr) != NULL) 
	{
	    cout << "Name:\n" << ptr->name << "\n";
	    cout << "Account Number:\n" << ptr->accountno << "\n";
	    cout << "Address:\n" << ptr->address << "\n";
	    ptr = ptr->next;
        }
    }
}

/*****************************************************************
//
//  Function name: findRecords(char*)
//
//  DESCRIPTION:   A llist class function
//                 This function searchs for a record and prints it
//
//  Parameters:    name (char*) : contains a set of characters 
//                               which will searched for in records names
//
//  Return values:  0 : success
//                 -1 : the value was not found
//
****************************************************************/

int llist::findRecords(char *key) 
{
    #ifdef _DEBUG
        cout << "DEBUGGER--> llist::findRecords(char*) has been called and passed in char*: " << key << "\n";
    #endif
	
    struct record *ptr;
    ptr = start;
    cout << "Found Records:\n";
    while ((ptr) != NULL) 
    {
        if (strstr(ptr->name, key)) 
	{
	    cout << "    Name: " << ptr->name << "\n";
	    cout << "    Account Number: " << ptr->accountno << "\n";
	    cout << "    Address: " << ptr->address << "\n";
	}
	ptr = ptr->next;
    }
    return 0;
}

/*****************************************************************
//
//  Function name: deleteRecord(int)
//
//  DESCRIPTION:   A llist class function
//                 This function finds a record and removes it
//
//  Parameters:    accountno (int) : contains the account number to delete
//                               which will be removed
//
//  Return values:  0 : success
//                 -1 : the value was not found
//
****************************************************************/

int llist::deleteRecord(int accountno) 
{
    #ifdef _DEBUG
        cout << "DEBUGGER--> llist::deleteRecord(int) has been called and passed in int: " << accountno << "\n";
    #endif

    int boul = 0;
    if (start == NULL)
    {
	boul = -1;
    }
    else if (start != NULL) 
    {
	struct record *curr = NULL;
	struct record *prev = NULL;
	curr = start;
	prev = start;
	if (accountno == curr->accountno) 
	{
	    start = curr->next;
	    curr->next = NULL;
	    free(curr);
	    boul = 1;
	}
	else if (curr->accountno != accountno) 
	{
	    while ((curr) != NULL) 
	    {
		curr = curr->next;
		if (curr->accountno == accountno) 
		{
		    prev->next = curr->next;
		    free(curr);
		    curr = NULL;
		    boul = 1;

	        }
		else if (curr->accountno != accountno) 
		{
		    prev = prev->next;

		}

	    }

	}
    }
    return boul;
}

/*****************************************************************
//
//  Function name: readfile()
//
//  DESCRIPTION:   A llist class function
//                 This function reads a file and adds record to a list
//
//  Parameters:    N/A
//
//  Return values:  0 : success
//                 -1 : the value was not found
//
****************************************************************/

int llist::readfile() 
{
    #ifdef _DEBUG
       cout << "DEBUGGER--> llist::readfile() has been called with no parameters passed\n";
    #endif
	
    char temp[1000] = "";
    char buf[80] = "";
   
    ifstream in(filename);

    stringstream buffer;
    buffer << in.rdbuf();

    string sub(buffer.str());
    strcpy(temp, sub.c_str());
	
    int x;
    x = 0;
    char name[25];
    char address[80];
    int number = 0;

    char delim[] = "+";

    char *pt = strtok(temp, delim);

    while (pt != NULL) 
    {
        if (x == 0)
        {
	    number = atoi(pt);
	    pt = strtok(NULL, delim);
	    x++;
	}
	else if (x == 1)
	{
	    strcpy(name, pt);
	    pt = strtok(NULL, delim);
	    x++;
        }
	else if (x == 2)
	{
            strcpy(address, pt);
	    pt = strtok(NULL, delim);
	    llist::addRecord(number, name, address);
	    x = 0;
	}

    }
    return 0;
}

/*****************************************************************
//
//  Function name: writefile()
//
//  DESCRIPTION:   A llist class function
//                 This function writes a list of records to a file
//
//  Parameters:    N/A
//
//  Return values:  N/A
//
****************************************************************/

void llist::writefile() 
{
    #ifdef _DEBUG
        cout << "DEBUGGER--> llist::writefile() has been called with no parameters passed\n";
    #endif
	
    struct record *ptr;
    ptr = start;
    int x, y;
    x = 0;
    y = 0;
    ofstream file;
    file.open(filename);
    while (ptr != NULL) {
	if (x == 0)
	{
	    file << ptr->accountno << "+";
	}
	if (x == 1)
	{
	    file << ptr->name << "+";
	}
	if (x == 2 && ptr->next == NULL)
	{
	    file << ptr->address;
            y++;
	    x = -1;
	    file.close();
	    ptr = ptr->next;
	}
	else if (x == 2)
	{
	    file << ptr->address << "+";
	    y++;
	    x = -1;
	    ptr = ptr->next;
	}
	x++;
    }
}

/*****************************************************************
//
//  Function name: cleanup()
//
//  DESCRIPTION:   A llist class function
//                 This function reoves all records from the heap
//
//  Parameters:    N/A
//
//  Return values:  N/A
//
****************************************************************/

void llist::cleanup() 
{
    #ifdef _DEBUG
	cout << "DEBUGGER--> llist::cleanup() has been called with no parameters passed\n";
    #endif

    struct record *next;
    struct record *ptr;
    next = start;
    ptr = start;
    start = NULL;
    while ((ptr) != NULL) 
    {
	next = ptr->next;
	free(ptr);
	ptr = NULL;
	ptr = next;
    }

}
E 1
