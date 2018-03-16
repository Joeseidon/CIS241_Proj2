#include "functions.h"

struct product *init(void){
	struct product *new = (struct product*)malloc(sizeof(struct product));
	new->next = NULL;
	return new;
}

void insert(struct product *head, char *name, char *unit, int price, int quantity){
	//create new product
	struct product *new = (struct product*)malloc(sizeof(struct product));

	//add data
	strcpy(new->name,name);
	strcpy(new->unit,unit);
	new->price = price;
	new->quantity = quantity;
	new->next = NULL;
	
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
		
		if(head->next == NULL)
			break;
		
		head = head->next;
	}
}

void deleteAll(struct product *head){
	if(head != NULL){
		//recursive deletion
		deleteAll(head->next);
	}
	
	free(head);	
}

int search(struct product *head, char *name){
	while(head->next != NULL){
		head = head->next;
		if(strcmp(head->name,name) == 0){
			return 1;
		}
	}
	return 0;
}

void purchase(struct product *head, char *name){
	while(head->next != NULL){
		
		if(strcmp(head->next->name,name) == 0){
			head->next->quantity++;
			return;
		}
		
		head = head->next;
		
	}
	printf("Product, %s, not found.\n",name);
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
			
			return;
		}
		if(head->next == NULL)
			break;
		
		head = head->next;
	}
	printf("Product, %s, not found.\n",name);
}

void save_to_file(struct product *head, const char *filename){
	FILE *out = fopen(filename, "w");
	int i = 0;
	while(head->next != NULL){
		head=head->next;
		
		fprintf(out,"%s,%s,%d,%d\n",head->name,
									head->unit,
									head->price,
									head->quantity);
		
		
		i++;
	}
	printf("\n%d Product(s) Written to File: %s\n",i,filename);
	fclose(out);
}

void flush(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}