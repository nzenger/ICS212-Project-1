h58785
s 00004/00004/00027
d D 1.2 19/04/14 20:21:33 nzenger 2 1
c no
e
s 00031/00000/00000
d D 1.1 19/03/10 20:08:44 nzenger 1 0
c date and time created 19/03/10 20:08:44 by nzenger
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
//  FILE:        record.h
//
//  DESCRIPTION:
//   header file containing the struct record object and its description
//
//
****************************************************************/

#ifndef RECORD_H
#define RECORD_H
struct record
{
D 2
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;
E 2
I 2
        int                accountno;
        char               name[25];
        char               address[80];
        struct record*     next;
E 2
};

#endif
E 1
