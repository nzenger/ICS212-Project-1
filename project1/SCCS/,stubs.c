/*****************************************************************
//
//  NAME:        Nathan Zenger
//
//  HOMEWORK:    3b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        February 7, 2019
//
//  FILE:        stubs.c
//
//  DESCRIPTION:
//   This file contains stub functions used by menu.c
//
//
****************************************************************/

#include "stubs.h"
#include "record.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int addRecord(struct record** start, int accountno, char *name, char *address) {
	int bool = 0;
	if (*start == NULL)
	{
		struct record *temp;
		temp = malloc(sizeof(struct record));
		*start = temp;
		temp->accountno = accountno;
		strcpy(temp->name, name);
		strcpy(temp->address, address);
		temp->next = NULL;
		bool = 1;
	}
	if (*start != NULL && bool == 0) {
        struct record *ptr;
	    ptr = *start;
	    while ((ptr) != NULL) {
		    if (ptr->accountno == accountno) {
			    bool = -1;
				printf("Cannot accept duplicate account number in database...\n");
		    }
		    ptr = ptr->next;
	    }
    }
	if(*start != NULL && bool == 0){
        struct record *newrec  = malloc(sizeof(struct record));
		struct record *ptr; 
		ptr = *start;
        while((ptr->next) != NULL){
        ptr = ptr->next;
        }
        ptr->next = newrec;
        newrec->accountno = accountno;
        strcpy(newrec->name,name);
        strcpy(newrec->address,address);
		newrec->next = NULL;
		bool = 1;
	}
	else {
		bool = -1;
	}
    return bool;
}

int printRecord (struct record* start, int accountno){
	struct record *ptr;
	ptr = start;
	printf("Database record:\n");
	while ((ptr) != NULL) {
		if (accountno == ptr->accountno) {
			printf("Name:\n%s\n", ptr->name);
			printf("Account Number:\n%d\n", ptr->accountno);
			printf("Address:\n%s\n", ptr->address);
		}
		ptr = ptr->next;
	}
	return 0;
}

void printAllRecords(struct record* start){
	if (start == NULL) {
		printf("Database is empty...\n");
	}
	else if (start != NULL) {
		struct record *ptr;
		ptr = start;
		printf("All of Database:\n");
		while ((ptr) != NULL) {
			printf("Name:\n%s\n", ptr->name);
			printf("Account Number:\n%d\n", ptr->accountno);
			printf("Address:\n%s\n", ptr->address);
			ptr = ptr->next;
		}
	}
}

int findRecords (struct record* start, char *key){
	struct record *ptr;
	ptr = start;
	printf("Found Records:\n");
	while ((ptr) != NULL) {
		if(strstr(ptr->name,key)){
			printf("    Name:%s\n", ptr->name);
			printf("    Account Number:%d\n", ptr->accountno);
			printf("    Address:%s\n", ptr->address);
	    }
			ptr = ptr->next;
	}
	return 0;
}

int deleteRecord(struct record** start, int accountno){
	int bool = 0;
	if (*start == NULL)
	{
		bool = -1;
	}
	else if (*start != NULL) {
		struct record *curr = NULL;
		struct record *prev = NULL;
		curr = start;
		prev = start;
		if (accountno == curr->accountno) {
			*start = curr->next;
			curr->next = NULL;
			free(curr);
			bool = 1;
		}
		if (curr->accountno != accountno) {
			while ((curr) != NULL) {
				curr = curr->next;
				if (curr->accountno == accountno) {
					prev->next = curr->next;
					free(curr);
                                        curr = NULL;
					bool = 1;
					
				}
                                else if (curr->accountno != accountno) {
				    prev = prev->next;
			
			        }

			}
		
		}
	}
	return bool;
}

int readfile(struct record** start, char* filename) {
	char temp[1000] = "";
    char buf[80]= "";
	FILE *file;
	file = fopen(filename, "r");
	while (fgets(buf, sizeof(buf), file) != NULL) {
		strcat(temp, buf);
	}
    fclose(file);
	int x;
	x = 0;
	char name[25];
	char address[80];
	int number = 0;

	char delim[] = "+";

	char *pt = strtok(temp, delim);

	while (pt != NULL){
		
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
			addRecord(start,number,name,address);
			x = 0;
		}
			
	}
       
    return 0;
}

int writefile(struct record* start, char* filename) {
	struct record *ptr;
	ptr = start;
	int x, y;
	x = 0;
	y = 0; 

	FILE *file;
	file = fopen(filename, "w");
	while (ptr != NULL) {
		if (x == 0)
		{
			fprintf(file, "%d+", ptr->accountno);
		}
		if (x == 1)
		{
			fprintf(file, "%s+", ptr->name);
		}
		if (x == 2 && ptr->next == NULL)
		{
			fprintf(file, "%s", ptr->address);
			y++;
			x = -1;
			fclose(file);
			ptr = ptr->next;
		}
		else if (x == 2)
		{
			fprintf(file, "%s+", ptr->address);
			y++;
			x = -1;
			ptr = ptr->next;
		}
		x++;
	}
	return 0;
}

void cleanup(struct record* start) {
	struct record *next;
	struct record *ptr;
	next = start;
	ptr = start;
	start = NULL;
	while ((ptr) != NULL) {
		next = ptr->next;
		free(ptr);
		ptr = NULL;
		ptr = next;
	}
	
}
