//Keilor Grossman and Jacob Bledsoe
//4-29-2024
//Final Project for image scalling

#include <stdio.h>

#define MAXSTRING_LENGTH 50
#define MAXFILE_SIZE 500
#define MAX_COLUMNS 500
#define MAX_ROWS 500

int getMenu();


void getFile(int pictureColumns, int pictureRows, int pictureData[][MAX_ROWS]);


void displayImage(int *pictureColumns, int *pictureRows, int pictureData[][pictureRows]);

int main() {

	int menuChoice;
	
	int columns = 0;
	int rows = 0;
	int mainPictureData[MAX_COLUMNS][MAX_ROWS] = {0};

	do{
	
		menuChoice = getMenu();
	
			switch(menuChoice){
			case 1:
			
				getFile(columns, rows, mainPictureData);
			
				break;
			case 2:
				displayImage(&columns, &rows, mainPictureData);
				break;
			case 3:
				break;

			case 0:
				return 0;
			default:
				printf("invalid input, goodbye");
				break;
		}
	} while(menuChoice != 0);
	return 0;
}

int getMenu(){

		int menuOption;	
		
		printf("***IMAGE MENU***\n");
		printf("(1): Load Image\n");
		printf("(2): Display Image\n");
		printf("(3): Edit Image\n");
		printf("(0): Exit program\n\n");
		printf("Choose from one of the options above: ");
		scanf("%d", &menuOption);
	
	
	return menuOption;
}

void getFile(int pictureColumns, int pictureRows, int pictureData[][MAX_ROWS]){
	
	char File[MAXFILE_SIZE];
	

	printf("What is the name of the image file: ");
	scanf("%s", File);
	
	File[MAXFILE_SIZE] = '\0';
	
	FILE* readFilePointer;
	
	readFilePointer = fopen(File, "r");
	
	if(readFilePointer == NULL){
		printf("\nCould not find an image with that file name\n\n");
		return;
	}
	else{
		printf("\n\nImage successfully loaded!\n\n");
	}
	
	
	for(int currentColumn = 0; currentColumn < MAX_COLUMNS; currentColumn++) {
		for(int currentRow = 0; currentRow < MAX_ROWS; currentRow++){
			fscanf(readFilePointer, "%d", &pictureData[currentColumn][currentRow]);
		}
	}
	
	return;
	
	fclose(readFilePointer);

	

}

void displayImage(int *pictureColumns, int *pictureRows, int pictureData[][MAX_ROWS]) {
	

		//for(int currentColumn = 0; currentColumn < pictureColumns; currentColumn++) {
		//	for(int currentRow = 0; currentRow < pictureRows; currentRow++) {
		//		printf("%d ", pictureData[currentColumn][currentRow]);
		
		
	for(int currentColumn = 0; currentColumn < *pictureColumns; currentColumn++) {
		for(int currentRow = 0; currentRow < *pictureRows; currentRow++){
			if(pictureData[currentColumn][currentRow] == 0){
				printf(" ");
			}
			else if (pictureData[currentColumn][currentRow] == 1){
				printf(".");
			}
			else if (pictureData[currentColumn][currentRow] == 2){
				printf("o");
			}
			else if (pictureData[currentColumn][currentRow] == 3) {
				printf("O");
			}
			else{
				printf("0");
			}
		}
	}
	return;
} 

	



