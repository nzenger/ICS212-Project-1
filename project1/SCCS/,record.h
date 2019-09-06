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
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;
};

#endif
