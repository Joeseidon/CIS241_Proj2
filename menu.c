#include <stdio.h>
#include <stdlib.h>
//#include <ctypes.h>
#include <string.h>
#include "functions.h"

#define NUM_CMDS 10
/*
typedef struct command command{
	int cmd_num;
	char *prompt;
};

//commands
command commands[10] = {
	{0, ""},
	{1, ""},
	{2, ""},
	{3, ""},
	{4, ""},
	{5, ""},
	{6, ""},
	{7, ""},
	{8, ""},
	{9, ""}
};*/
const char *OUT_FILE = "list.txt";
const char *command_prompt[6] ={"1: Create and empty list \t 2: Insert a product",
						  "\n3: Delete a product	   \t 4: Delete the entire list",
						  "\n5: Search a product	   \t 6: Display products in the list",
						  "\n7: Purchase a product    \t 8: Sell a product",
						  "\n9: Save to file     	   \t 0: Exit",
						  "\n\nEnter a command: "};

struct node *list = NULL;

int FIRST_CMD = 1;
int remain_active = 1;

int performAction(int command);
void save_to_file(struct node *list, const char *filename);

int main(int argc, char *argv[]){

	int command =0;

	while(remain_active){
		//print intro prompt
		int i;
		
		do{
			for(i = 0; i<6; i++)
			printf("%s",command_prompt[i]);
		
			//monitor for user input 
			fflush(stdin);
			scanf("%d",&command);
			if(FIRST_CMD && command != 1){
				printf("\nMust create a list first.\n\n");
			}
		}while((FIRST_CMD == 1 && command != 1) || (!FIRST_CMD && (command < 0 || command > 9)));//first command must be to create list //after, it must just be a valid command
		
		if(FIRST_CMD == 1){
			FIRST_CMD = 0;
		}
		 
		//act on valid input
		if(!performAction(command)){
			printf("Action Error!\n");
		}

	}

	return 0;
}

int performAction(int command){
	//temp values
	char name[256],units[256];
	int price=0,quantity=0;
	
	switch(command){
		case 0:
			exit(0);
			break;
		case 1:
			if(list != NULL){
				//delete current list
				deleteAll(list);
			}
			//make new list
			list = init();
			break;
		case 2:
			//fflush(stdin);
			printf("\nEnter product info. (name,unit,price,quantity)\n");
			fflush(stdin);
			scanf("%s,%s,%d,%d",name,units,&price,&quantity);

			//insert item in list
			printf("Recieved: %s,   %s,   %d,   %d\n",name,units,price,quantity);
			insert(list,name,units,price,quantity);
			break;
		case 3:
			printf("\nEnter product name:\n");
			fflush(stdin);
			scanf("%s",name);
			
			//remove from lit
			
			delete(list, name);
			break;
		case 4:
			printf("\nAll nodes will be deleted!\n");
			
			deleteAll(list);
			break;
		case 5:
			printf("\nEnter the name to search for:\n");
			fflush(stdin);
			
			scanf("%s",name);
			printf("Name Recieved\n");
			search(list, name);
			break;
		case 6:
			printf("\nThe list contains the following:\n"); 
			
			display(list);
			break;
		case 7:
			printf("\nEnter the name to purchase:\n");
			fflush(stdin);
			
			scanf("%s",name);
			
			purchase(list, name);
			break;
		case 8:
			printf("\nEnter the name to sell:\n");
			fflush(stdin);
			
			scanf("%s",name);
			
			sell(list, name);
			break;
		case 9:
			save_to_file(list,OUT_FILE);
			break;
			
		default:
			return 0;
			
	}
	
	return 1;
}

void save_to_file(struct node *list, const char *filename){
	FILE *out = fopen(filename, "w");
	while(list!=NULL){
		fprintf(out,"%s,%s,%d,%d\n",list->data->name,
									list->data->unit,
									list->data->price,
									list->data->quantity);
		
		list=list->next;
	}
	fclose(out);
}
