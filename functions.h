#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct product{
	char name[256];
	char unit[256];
	int price;
	int quantity;
	struct product *next;
};

struct product *init(void);

void insert(struct product *head, char *name, char *unit, int price,
int quantity);

void display(struct product *head);

void delete(struct product *head, char *name);

void deleteAll(struct product *head);

int search(struct product *head, char *name);

void purchase(struct product *head, char *name);

void sell(struct product *head, char *name);

void save_to_file(struct product *head, const char *filename);

void flush(void);

#endif
