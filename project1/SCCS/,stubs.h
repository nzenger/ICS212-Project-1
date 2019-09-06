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
//   This file contains the headers for the stub.c file functions
//
//
****************************************************************/

#include "record.h"
#ifndef STUBS_H
#define STUBS_H

int addRecord (struct record **, int, char [ ],char [ ]);
int printRecord (struct record *, int);
void printAllRecords(struct record *);
int findRecords (struct record *, char [ ]);
int deleteRecord(struct record **, int);
int readfile(struct record **, char []);
int writefile(struct record *, char []);
void cleanup(struct record *);

#endif
