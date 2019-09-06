/*****************************************************************
//
//  NAME:        Nathan Zenger
//
//  HOMEWORK:    project1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Feburary 7, 2019
//
//  FILE:        menu.c
//
//  DESCRIPTION:
//   User interface with menu for use to access and a databse and edit
//
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include "stubs.h"
#include "record.h"

void getaddress (char [], int);

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

int main(int argc, char **argv[]){
    
    if(argc == 2){
        if(strcmp(argv[1],"debug") == 0){
            argc = -1;
            printf("Debug Mode On...\n");
        }else{
            printf("db: Incorrect debug command\n");
            printf("Try './file.c debug' on command line\n");
            exit(0);
        }
    }else if(argc > 2){
        printf("db: Incorrect debug command\n");
        printf("Try './file.c debug' on command line\n");
        exit(0);
    }
    
    
    struct record *start;
    start = NULL;
    int bool,option,db;
    bool = 1;
    option = -1;

    char filename[50];
    printf("Enter a file name to read into database:\n");
    scanf("%s", filename);
    while ((getchar()) != '\n');
    readfile(&start, filename);
        
    if(argc == -1){
        printf("----Debugger----\n");
        printf("findRecords called\n");
        printf("parameter 1: start\n");
        printf("parameter 2: %s\n",filename);        
        printf("----------------\n");
    }

    while(bool == 1){
        printf("Option(0): Add a new record in the database\n");
        printf("Option(1): Print information about a record using the accountno as the key\n");
        printf("Option(2): Print all information in the database\n");
        printf("Option(3): Find a record that is stored in the database\n");
        printf("Option(4): Delete an existing record from the database using the accountno as a key\n");
        printf("Option(5): Read a file and store the records into database\n");
        printf("Option(6): Write the database of records to a file\n");
        printf("Option(7): Cleanup the database by wiping it\n");
        printf("Option(8): Quit the program\n");
        printf("Enter option number:");
        scanf("%d", &option);
        while((getchar()) != '\n');
        printf("\n");
        
        if(option == 0){
            char name[25];
            char address[80];
            int number;
            number = 0;
            
            printf("Enter a name:\n");
			fgets(name, 25, stdin);
			
			if ((strlen(name) > 0) && (name[strlen(name) - 1] == '\n'))
				name[strlen(name) - 1] = '\0';

            printf("Enter a account number:\n");
            scanf("%d",&number);
            while((getchar()) != '\n');

            if(argc == -1){
                printf("----Debugger----\n");
                printf("getaddress called\n");
                printf("parameter 1: %s\n",address);
                printf("parameter 2: %d\n",sizeof(address));
                printf("----------------\n");
            }
            
            getaddress(address,80);                 
          
            addRecord(&start,number,name,address);
            
            if(argc == -1){
                printf("----Debugger----\n");
                printf("addRecord called\n");
                printf("parameters 1: start\n");
                printf("parameter 2: %d\n",number);
                printf("parameter 3: %s\n",name);
                printf("parameter 4: %s\n",address);
                printf("----------------\n");
            }
            
        }            
        
        if(option == 1){
            int number;
            number = 0;

            printf("Enter a account number:\n");
            scanf("%d",&number);
            while((getchar()) != '\n');

            

            printRecord(start, number);          
              
            if(argc == -1){
                printf("----Debugger----\n");
                printf("printRecord called\n");
                printf("parameters 1: start\n");     
                printf("parameter 2: %d\n",number);
                printf("----------------\n");
            }

        }

        if(option == 2){  
            
            printAllRecords(start);
            
            if(argc == -1){
                printf("----Debugger----\n");
                printf("printAllRecords called\n");
                printf("parameters 1: start\n");     
                printf("----------------\n");
            }
        }
        
        if(option == 3){
	    char name[25];
          
            printf("Enter the first key characters of a name to search for:\n");
	    scanf("%s", name);
	    while ((getchar()) != '\n');

            findRecords(start, name);
            
            if(argc == -1){
                printf("----Debugger----\n");
                printf("findRecords called\n");
                printf("parameters 1: start\n");     
                printf("parameter 2: %s\n",name);
                printf("----------------\n");
            }  
        }
           
        if(option == 4){
            struct record record1[5];
            int number;
            number = 0;
            
            printf("Enter a account number:\n");
            scanf("%d",&number);
            while((getchar()) != '\n');

            deleteRecord(start, number);

            
            if(argc == -1){
                printf("----Debugger----\n");
                printf("deleteRecord called\n");
                printf("parameters 1: start\n");     
                printf("parameter 2: %d\n",number);
                printf("----------------\n");
            }
        }

		if (option == 5) {
			char filename[50];
			printf("Enter a file name to read:\n");
			scanf("%s", filename);
			while ((getchar()) != '\n');
			readfile(&start, filename);

                        if(argc == -1){
                	    printf("----Debugger----\n");
                	    printf("readfile called\n");
                	    printf("parameters 1: start\n");     
                            printf("parameter 2: %s\n",filename);
                	    printf("----------------\n");
            		}

		}

		if (option == 6) {
			char filename[50];
			printf("Enter a file name to write:\n");
			scanf("%s", filename);
			while ((getchar()) != '\n');
			writefile(start, filename);
                        if(argc == -1){
                            printf("----Debugger----\n");
                            printf("writefile called\n");
                            printf("parameters 1: start\n");     
                            printf("parameter 2: %s\n",filename);
                            printf("----------------\n");
                       }

		}

		if (option == 7) {
			printf("Clearing Database...\n");
			cleanup(start);
			if(argc == -1){
                           printf("----Debugger----\n");
                           printf("cleanup called\n");
                           printf("parameters 1: start\n");     
                           printf("----------------\n");
                        }
                        start = NULL;

		}
        
		if(option == 8){
            bool = 0;
            printf("Exiting Program...\n");
        }
    }

	char writename[50];
	printf("Enter a file name to write to before quitting:\n");
	scanf("%s", filename);
	while ((getchar()) != '\n');
	writefile(start, filename);
        
        if(argc == -1){
            printf("----Debugger----\n");
            printf("writefile called\n"); 
            printf("parameters 1: start\n");
            printf("parameter 2: %s\n",filename);
            printf("----------------\n");
        }         

	cleanup(start);

        if(argc == -1){
            printf("----Debugger----\n");
            printf("cleanup called\n");  
            printf("parameters 1: start\n"); 
            printf("----------------\n");
        }
    return 0;
}

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

void getaddress(char *x, int y){
    int i;
    char address[80];
    
    printf("Enter an address(press 'Enter' key 2x to end input):");
    for(i = 0; i >= 0; ++i){
        address[i] = getchar();
        if (i > 0 && address[i] == '\n' && address[i-1] == '\n'){
             break;                
        }
    }
    while((getchar()) != '\n');
    address[i] = 0;
    strcpy(x,address);
}

