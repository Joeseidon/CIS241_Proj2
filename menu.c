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

struct product *list = NULL;

int FIRST_CMD = 1;
int remain_active = 1;

int performAction(int command);


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
	char *name=" ",*units=" ";
	int price=0,quantity=0;
	char text[256];
	char *ptr;
	
	
	int i = 0;
	
	switch(command){
		case 0:
			deleteAll(list);
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

			fprintf(stdout,"\nEnter product info. (name,unit,price,quantity)\n");

			flush();
			fgets(text,256,stdin);

			char *token = strtok(text, ",");
			while(token != NULL && i < 4){
				if(i==0){
					//printf("token: %s",token);
					name=token;

				}else if(i==1){
					//printf("token: %s",token);
					units=token;

				}else if(i==2){
					//printf("token: %s",token);
					price = atoi(token);

				}else{
					//printf("token: %s",token);
					quantity = atoi(token);
					
				}
				token=strtok(NULL, ",");
				i++;
			}		
			
			insert(list,name,units,price,quantity);
			break;
		case 3:
			printf("\nEnter product name:\n");
			flush();
			fgets(text,256,stdin);
			
			//remove from lit
			
			delete(list, text);
			break;
		case 4:
			printf("\nAll nodes will be deleted!\n");
			
			deleteAll(list);
			
			FIRST_CMD = 1;
			break;
		case 5:
			printf("\nEnter the name to search for:\n");
			flush();
			fgets(text,256,stdin);

			search(list, text);
			break;
		case 6:
			printf("\nThe list contains the following:\n"); 
			
			display(list);
			break;
		case 7:
			printf("\nEnter the name to purchase:\n");
			flush();
			fgets(text,256,stdin);
			
			purchase(list, text);
			break;
		case 8:
			printf("\nEnter the name to sell:\n");
			flush();
			fgets(text,256,stdin);
			
			sell(list, text);
			break;
		case 9:
			save_to_file(list,OUT_FILE);
			break;
			
		default:
			return 0;
			
	}
	
	return 1;
}
