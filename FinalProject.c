//Keilor Grossman and Jacob Bledsoe
//4-29-2024
//Final Project for image scalling

#include <stdio.h>

#define MAXSTRING_LENGTH 50
#define MAXFILE_SIZE 500

void getFile();
void getMenu();

int main() {

	getMenu();
	
	return 0;
}

void getMenu(){

	int menuOption;
	
	do{
	
	
		printf("***IMAGE MENU***\n");
		printf("(1): Load Image\n");
		printf("(2): Display Image\n");
		printf("(3): Edit Image\n");
		printf("(0): Exit program\n\n");
		printf("Choose from one of the options above: ");
		scanf("%d", &menuOption);
	
		switch(menuOption){
			case 1:
			
				getFile();
			
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
			case 0:
				return;
			default:
				printf("invalid input, goodbye");
				break;
		}
	
	
	
		}while(menuOption > 0);
	
	return;
}

void getFile(){
	
	char File[MAXFILE_SIZE];
	

	printf("What is the name of the image file: ");
	scanf("%s", File);
	
	File[MAXFILE_SIZE] = '\0';
	
	FILE* readFilePointer;
	
	readFilePointer = fopen(File, "r");
	
	if(readFilePointer == NULL){
		printf("Could not find an image with that file name\n");
		return;
	}
	else{
		printf("\nImage successfully loaded!\n\n");
	}
	
	return;

	printf("Please enter the name of the file you would like to edit: \n");
	fgets(File, MAXFILE_SIZE, stdin);
	

	
}

	



