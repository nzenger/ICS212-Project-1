h30874
s 00185/00000/00000
d D 1.1 19/04/14 20:16:22 nzenger 1 0
c date and time created 19/04/14 20:16:22 by nzenger
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
//  HOMEWORK:    project2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 14, 2019
//
//  FILE:        interface.c
//
//  DESCRIPTION:
//   User interface with menu for use to access and a databse and edit
//
//
****************************************************************/

#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include "llist.h"
using namespace std;

/*****************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION:   Retrieves a address from the user and the copies it to parameter
//
//  Parameters:    x (char*) : contains empty char to be copied to
				   y (int) : size of x
//
//  Return values:  void
//
****************************************************************/

void getaddress(char *x, int y) 
{
    #ifdef _DEBUG
	    cout << "DEBUGGER--> getaddress(char*,int) has been called and passed in char*: " << x << ", int: " << y << "\n";
    #endif
	
    char address[80];
    string line;
    cout << "Enter an address(type 'exit' followed by the enter key to end input):";
    cin.ignore();	
    while (getline(cin, line))
    {
        if (line == "exit")
        {
            break;
        }
        line.append("\n");
        strcat(x, line.c_str());
    }        

    
    /*address[i] = getchar();
    if (i > 0 && address[i] == '\n' && address[i - 1] == '\n') 
    {
        break;
    }
    }
    while ((getchar()) != '\n');
    address[i] = 0;
    strcpy(x, address);*/
}


/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Main of the program that runs the user interface
//                 This function runs a menu to edit and retireve info from database
//
//  Parameters:    **argv(char[]) commands turned into char arrays
//                 argc(int) count of the size of **argv
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char **argv) 
{
    llist record;
    int boul, option, db;
    boul = 1;
    option = -1;

    while (boul == 1) 
    {
	cout << "Option(0): Add a new record in the database\n";
	cout << "Option(1): Print information about a record using the accountno as the key\n";
	cout << "Option(2): Print all information in the database\n";
	cout << "Option(3): Find a record that is stored in the database\n";
	cout << "Option(4): Delete an existing record from the database using the accountno as a key\n";
	cout << "Option(5): Reverse the order of all the records in the list\n";
	cout << "Option(6): Quit the program\n";
	cout << "Enter option number:";
	cin >> option;
        cout << "\n";

	if (option == 0) 
	{
	    char name[25];
	    char address[80];
	    int number;
	    number = 0;

	    cout << "Enter a name:\n";
	    cin.ignore();
	    cin.getline(name, 25);

	    cout << "Enter a account number:\n";
	    cin >> number;

	    getaddress(address, 80);

	    record.addRecord(number, name, address);

	}

	if (option == 1) 
	{
	    int number;
	    number = 0;

	    cout << "Enter a account number:\n";
            cin.ignore();
	    cin >> number;

	    record.printRecord(number);
	}

	if (option == 2) 
	{
       	    record << cout;
	}

	if (option == 3) 
	{
	    char name[25];

	    cout << "Enter the first key characters of a name to search for:\n";
	    cin.ignore();
	    cin.getline(name, 25);
			
	    record.findRecords(name);
	}

	if (option == 4) 
	{
	    struct record record1[5];
	    int number;
	    number = 0;

	    cout <<"Enter a account number:\n";
	    cin.ignore();
	    cin >> number;
			
	    record.deleteRecord(number);
	}

	if (option == 5) 
	{
	    record.reverse();
	    cout << "List had been reversed...\n";
	}

	if (option == 6) 
	{
	    boul = 0;
	    cout << "Exiting Program...\n";
	}
    }
    return 0;
}


E 1
