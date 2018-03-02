#include <stdio.h>
#include <stdlib.h>
#include <ctypes.h>
#include <string.h>
#include <functions.h>

#define NUM_CMDS 10
 
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
};

struct node *list = NULL;

int main(int argc, char *argv[]){

	//print intro prompt

	while(remain_active){
		 //monitor for user input 
		 do{
		 
		 }while();//first command must be to create list //after, it must just be a vlid command
		 
		 //act on valid input
		 performAction(input_command);

	}

	return 0;
}

int performAction(int command){
	int i;
	for(i=0; i<NUM_CMDS; i++){
		if commands[i].cmd_num == command){
			printf("%s",commands[i].prompt);
			break;
		}
	}
	switch(i){
		case 0:
			if(list != NULL){
				//delete current list
				deleteAll(list);
			}
			//make new list
			list = init();
			break;
		case 1:
			
			break;
		case 2:
		
			break;
		case 3:
		
			break;
		case 4:
		
			break;
		case 5:
		
			break;
		case 6:
		
			break;
		case 7:
		
			break;
		case 8:
		
			break;
		case 9:
		
			break;
}
