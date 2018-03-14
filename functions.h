#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef functions_h
#define functions_h

/*struct product{
	char *name;
	char *unit;
	int price;
	int quantity;
};
*/
struct product{
	char *name;
	char *unit;
	int price;
	int quantity;
	struct product next;
};


/*struct node{
	struct product *data;
	struct node *next;
	struct node *prev;
};
*/

struct product init(void);

void insert(struct product *head, char *name, char *unit, int price,
int quantity);

void display(struct product *head);
/*
// Creates an empty list - only a head node
struct node *init();

// Inserts a product into the list
void insert(struct node *head, char *name, char *unit, int price,
int quantity);

// Deletes a product from the list
void delete(struct node *head, char *name);

// Deletes all products in the list
void deleteAll(struct node *head);

// Searches for a product in the list
void search(struct node *head, char *name);

// Displays all products in the list
void display(struct node *head);

// Adds one to the quantity of the given product
void purchase(struct node *head, char *name);

// Removes one from the quantity of the given product
void sell(struct node *head, char *name);
*/
#endif