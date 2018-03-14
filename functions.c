#include "functions.h"

struct product *init(void){
	struct product *new = (struct product*)malloc(sizeof(struct product));
	return new;
}

void insert(struct product *head, char *name, char *unit, int price, int quantity){
	//create new product
	struct product *new = (struct product*)malloc(sizeof(struct product));
	
	//add data
	new->name = name;
	new->unit = unit;
	new->price = price;
	new->quantity = quantity;
	
	//add to the end of the list
	while(head->next != NULL){
		head = head->next;
	}
	head->next = new;
}

void display(struct product *head){
	while(head->next != NULL){
		head = head->next;
		printf("Name: %s \t Unit: %s \t Price: $%d \t Quantity: %d\n", head->name,head->unit,head->price,head->quantity);
		fflush(stdout);
	}
}

void delete(struct product *head, char *name){
	while(head->next != NULL){
		
		if(strcmp(head->next->name,name) == 0){
			struct product *temp = head->next;
			head->next = head->next->next;
			free(temp);
		}
		
		head = head->next;
	}
}

void deleteAll(struct product *head){
	if(head->next != NULL){
		//recursive deletion
		deleteAll(head->next);
	}
	
	free(head);	
}

void save_to_file(struct product *head, const char *filename){
	FILE *out = fopen(filename, "w");
	printf("/nOPEN\n");
	while(list!=NULL){
		fprintf(out,"%s,%s,%d,%d\n",head->name,
									head->unit,
									head->price,
									head->quantity);
		
		head=head->next;
	}
	fclose(out);
}

void flush(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void search(struct product *head, char *name){
	while(head->next != NULL){
		
		if(strcmp(head->next->name,name) == 0){
			printf("Product %s found in list.\n", name);
		}
		
		head = head->next;
	}
}

void purchase(struct product *head, char *name){
	while(head->next != NULL){
		
		if(strcmp(head->next->name,name) == 0){
			head->next->quantity++;
		}
		
		head = head->next;
	}
}

void sell(struct product *head, char *name){
	while(head->next != NULL){
		
		if(strcmp(head->next->name,name) == 0){
			head->next->quantity--;
			
			if(head->next->quantity <= 0){
				struct product *temp = head->next;
				head->next = head->next->next;
				free(temp);
			}
		}
		
		head = head->next;
	}
}


/*
// Creates an empty list - only a head node
struct node *init(){
	struct node *this = (struct node*) malloc(sizeof(struct node));
	this->next = NULL;
	return this;
}

// Inserts a product into the list
void insert(struct node *head, char *name, char *unit, int price,
int quantity){
	struct node *new = (struct node*) malloc(sizeof(struct node));
	new->data = (struct product*) malloc(sizeof(struct product));
	new->data->name = name;
	new->data->unit = unit;
	new->data->price = price;
	new->data->quantity = quantity;
	while(head->next != NULL)
		head = head->next;
	head->next = new;
}

// Deletes a product from the list
void delete(struct node *head, char *name){
	int i = 0;
	while(head->next != NULL)
		if(strcmp(head->data->name, name) == 0){
			i++;
			head->prev->next = head->next;
			head->next->prev = head->prev;
			free(head->data);
			free(head);
		}
	if(i == 0)
		printf("Product %s was not found in the list.\n", name);
}

// Deletes all products in the list
void deleteAll(struct node *head){
	if(head->next != NULL)
		deleteAll(head->next);
	free(head->data);
	free(head);
}

// Searches for a product in the list
void search(struct node *head, char *name){
	int i = 0;
	while(head->next != NULL)
		if(strcmp(head->data->name, name) == 0)
			printf("Product %s found in list.\n", name);
	if(i == 0)
		printf("Product %s not found in list.\n", name);
}

// Displays all products in the list
void display(struct node *head){
	printf("Product \t Unit \t Price \t Quantity\n");
	while(head->next != NULL){
		head = head->next;
		printf("%s \t %s \t $%d \t %d\n", head->data->name, 
head->data->unit, head->data->price, head->data->quantity);
		//head = head->next;
	}
}

// Adds one to the quantity of the given product
void purchase(struct node *head, char *name){
	while(head->next != NULL)
		if(strcmp(head->data->name, name) == 0)
			head->data->quantity += 1;
}

// Removes one from the quantity of the given product
void sell(struct node *head, char *name){
	while(head->next != NULL)
		if(strcmp(head->data->name, name) == 0){
			head->data->quantity -= 1;
			if(head->data->quantity == 0){
				head->prev->next = head->next;
				head->next->prev = head->prev;
				free(head->data);
				free(head);
			}
		}
}
*/