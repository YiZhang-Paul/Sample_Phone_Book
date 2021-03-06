#ifndef RECORD_H
#define RECORD_H

#include <stdio.h>
#include <stdlib.h>

#define FIELDS 3

struct record {

    char *firstName;
    char *lastName;
    char *phone;
};

struct record * createRecord(char *, char *, char *);
struct record * copyRecord(struct record *);
bool isSameRecord(struct record *, struct record *);
char * getRecordDetail(struct record *);
void printRecord(struct record *);
void saveRecord(struct record *, char *);
void freeRecord(void *);

#endif