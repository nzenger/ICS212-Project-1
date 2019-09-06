h00444
s 00034/00000/00000
d D 1.1 19/03/10 20:08:49 nzenger 1 0
c date and time created 19/03/10 20:08:49 by nzenger
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
E 1
