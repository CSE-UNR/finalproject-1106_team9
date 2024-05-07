//Keilor Grossman and Jacob Bledsoe
//4-29-2024
//Final Project for image scaling

#include <stdio.h>

#define MAXSTRING_LENGTH 50
#define MAXFILE_SIZE 500
#define MAX_COLUMNS 500
#define MAX_ROWS 500

int getMenu();
int editMenu();
void cropImage(char *File, char pictureData[][MAX_COLUMNS]);
void dimImage(char *File, char pictureData[][MAX_COLUMNS]);
void brightenImage(char *File, char pictureData[][MAX_COLUMNS]);

void getFile(char *File);

void displayImage(char *File, char pictureData[][MAX_COLUMNS]);


int main() {

	int menuChoice, editMenuOption;
	
	int columns;
	int rows;
	char mainPictureData[MAX_ROWS][MAX_COLUMNS];
	char File[MAXFILE_SIZE];
	char userSaveOption;
	
	
	do{
	
		menuChoice = getMenu();
	
			switch(menuChoice){
			case 1:
			
				getFile(File);
			
				break;
			case 2:
				displayImage(File, mainPictureData);
				break;
			case 3:
				editMenuOption = editMenu();
				switch(editMenuOption){
					case 1:
						cropImage(File, mainPictureData);
						return 0;
						break;
					case 2:
						brightenImage(File, mainPictureData);
						return 0;
						break;
					case 3:
						dimImage(File, mainPictureData);
						return 0;
						break;
					default:
						break;
				}
				break;
			case 0:
				printf("\nGoodbye!\n\n");
				return 0;
			default:
				printf("\nInvalid input\n\n");
				break;
		}
	} while(menuChoice != 0);
	return 0;
}

int getMenu(){

		int menuOption;	
		
		printf("\n***IMAGE MENU***\n");
		printf("(1): Load Image\n");
		printf("(2): Display Image\n");
		printf("(3): Edit Image\n");
		printf("(0): Exit program\n\n");
		printf("Choose from one of the options above: ");
		scanf("%d", &menuOption);
	
	
	return menuOption;
}

int editMenu(){
	int editMenuOption;
	
	printf("\n***EDIT IMAGE MENU***\n");
	printf("(1): Crop Image\n");
	printf("(2): Decrease Brightness\n");
	printf("(3): Increase Brightness\n");
	printf("(0): Go back to menu\n");
	printf("\nPlease enter the number for the operation you would like to perform: ");
	scanf("%d", &editMenuOption);
	
	return editMenuOption;
}


void getFile(char *File){

	
	char temp;
	printf("What is the name of the image file: ");
	scanf("%s", File);
	
	File[MAXFILE_SIZE] = '\0';
	
	FILE *readFilePointer;
	
	readFilePointer = fopen(File, "r");
	
	
	
	if(readFilePointer == NULL){
		printf("\nCould not find an image with that file name\n\n");
		return;

	}
	else{
		printf("\n\nImage successfully loaded!\n\n");
		fclose(readFilePointer);
		
	}
}

void displayImage(char *File, char pictureData[][MAX_COLUMNS]) {
	
	char temp;
	
	
	int pictureColumns = 0;
	int pictureRows = 0;
	
	File[MAXFILE_SIZE] = '\0';
	
	FILE *readFilePointer;
	
	readFilePointer = fopen(File, "r");
	
	while(fscanf(readFilePointer, "%c", &temp) == 1) {
		if(temp == '\n') {
			printf("\n");

			pictureColumns++;
			pictureRows = 0;
		}
		else{
			pictureData[pictureRows][pictureColumns] = temp - '0';
			
			switch(pictureData[pictureRows][pictureColumns]) {
				case 0:
					pictureData[pictureRows][pictureColumns] = ' ';
					break;
				case 1:
					pictureData[pictureRows][pictureColumns] = '.';
					break;
				case 2:
					pictureData[pictureRows][pictureColumns] = 'o';
					break;
				case 3: 
					pictureData[pictureRows][pictureColumns] = 'O';
					break;
				case 4:
					pictureData[pictureRows][pictureColumns] = '0';
					break;
				default:
					
					break;
			}
			printf("%c", pictureData[pictureRows][pictureColumns]);
			pictureRows++;
	
		} 
	}
}


void brightenImage(char *File, char pictureData[][MAX_COLUMNS]){
	
	char temp;
	
	
	int pictureColumns = 0;
	int pictureRows = 0;
	int picR = 0;
	
	File[MAXFILE_SIZE] = '\0';
	
	FILE *readFilePointer;
	
	readFilePointer = fopen(File, "r");
	
	while(fscanf(readFilePointer, "%c", &temp) == 1) {
		
		if(temp == '\n') {
			printf("\n");

			pictureColumns++;
			pictureRows = 0;
			
		}
		else{
			pictureData[pictureRows][pictureColumns] = temp - '0';
			
			switch(pictureData[pictureRows][pictureColumns]) {
				case 0:
					pictureData[pictureRows][pictureColumns] = '.';
					break;
				case 1:
					pictureData[pictureRows][pictureColumns] = 'o';
					break;
				case 2:
					pictureData[pictureRows][pictureColumns] = 'O';
					break;
				case 3: 
					pictureData[pictureRows][pictureColumns] = '0';
					break;
				case 4:
					pictureData[pictureRows][pictureColumns] = '0';
					break;
				default:
					
					break;
			}
			printf("%c", pictureData[pictureRows][pictureColumns]);
			pictureRows++;
			picR++;
		} 	
		
	}
	printf("\n");
	picR /= pictureColumns;
	
	int row, column, picC;
	picC = pictureColumns;
	char saveFile[MAXFILE_SIZE];
	char saveO;

	
	
	printf("Would you like to store image in a file?(y/n): ");
	scanf(" %c", &saveO);
	
	if(saveO == 'y'){
		printf("What do you want to name the image file? ");
		scanf("%s", saveFile);
		saveFile[MAXFILE_SIZE] = '\0';	
		FILE *savefptr;		
		savefptr = fopen(saveFile, "w");
		
		for(row = 0; row < picC; row++){
			for(column = 0; column < picR; column++){
				fprintf(savefptr, "%c", pictureData[column][row]);
				}
			fprintf(savefptr, "\n");
			}
	}
	return;
}

void dimImage(char *File, char pictureData[][MAX_COLUMNS]){
	
	char temp;
	
	
	
	int pictureColumns = 0;
	int pictureRows = 0;
	int picR = 0;
	
	File[MAXFILE_SIZE] = '\0';
	
	FILE *readFilePointer;
	
	readFilePointer = fopen(File, "r");
	
	
	while(fscanf(readFilePointer, "%c", &temp) == 1) {
		if(temp == '\n') {
			printf("\n");

			pictureColumns++;
			pictureRows = 0;
		}
		else{
			pictureData[pictureRows][pictureColumns] = temp - '0';
			
			switch(pictureData[pictureRows][pictureColumns]) {
				case 0:
					pictureData[pictureRows][pictureColumns] = ' ';
					break;
				case 1:
					pictureData[pictureRows][pictureColumns] = ' ';
					break;
				case 2:
					pictureData[pictureRows][pictureColumns] = '.';
					break;
				case 3: 
					pictureData[pictureRows][pictureColumns] = 'o';
					break;
				case 4:
					pictureData[pictureRows][pictureColumns] = 'O';
					break;
				default:
					
					break;
				
			}
			printf("%c", pictureData[pictureRows][pictureColumns]);
			pictureRows++;
			picR++;
			
		} 
		
	}
	printf("\n");
	picR /= pictureColumns;

	int row, column;
	char saveFile[MAXFILE_SIZE];
	char saveO;

	int picC = pictureColumns;
	
	
	printf("Would you like to store image in a file?(y/n): ");
	scanf(" %c", &saveO);
	
	if(saveO == 'y'){
		printf("What do you want to name the image file? ");
		scanf("%s", saveFile);
		saveFile[MAXFILE_SIZE] = '\0';	
		FILE *savefptr;		
		savefptr = fopen(saveFile, "w");
		
		for(row = 0; row < picC; row++){
			for(column = 0; column < picR; column++){
				fprintf(savefptr, "%c", pictureData[column][row]);
				}
			fprintf(savefptr, "\n");
			}
	}
		
	
	return;
}




void cropImage(char *File, char pictureData[][MAX_COLUMNS]){ 
	int leftBound, rightBound, topBound, bottomBound;
	
	printf("\n\nPlease enter your left boundry(value must be atleast 1): ");
	scanf("%d", &leftBound);
	printf("\nPlease enter your right boundry(value must be greater than value for your left boundy): ");
	scanf("%d", &rightBound);
	printf("\nPlease enter your upper boundry(value must be atleast 1): ");
	scanf("%d", &topBound);
	printf("\nPlease enter your lower boundry(value must be greater than your upper boundry): ");
	scanf("%d", &bottomBound);
	
	char temp;
	
	
	
	int pictureColumns = 0;
	int pictureRows = 0;
	
	File[MAXFILE_SIZE] = '\0';
	
	FILE *readFilePointer;
	
	readFilePointer = fopen(File, "r");
	
	while(fscanf(readFilePointer, "%c", &temp) == 1) {
		if(temp == '\n') {

			pictureColumns++;
			pictureRows = 0;
		}
		else{
			pictureData[pictureRows][pictureColumns] = temp - '0';
			
			switch(pictureData[pictureRows][pictureColumns]) {
				case 0:
					pictureData[pictureRows][pictureColumns] = ' ';
					break;
				case 1:
					pictureData[pictureRows][pictureColumns] = '.';
					break;
				case 2:
					pictureData[pictureRows][pictureColumns] = 'o';
					break;
				case 3: 
					pictureData[pictureRows][pictureColumns] = 'O';
					break;
				case 4:
					pictureData[pictureRows][pictureColumns] = '0';
					break;
				default:
					
					break;
			}
			pictureRows++;
	
		} 
	}
	for(int topI = topBound-1; topI < bottomBound; topI++){
		for(int leftI = leftBound-1; leftI < rightBound; leftI++){
			printf("%c", pictureData[leftI][topI]);
		}
		printf("\n");
	}
	
	char saveFile[MAXFILE_SIZE];
	char saveO;
	
	
	printf("Would you like to store image in a file?(y/n): ");
	scanf(" %c", &saveO);
	
	if(saveO == 'y'){
		printf("What do you want to name the image file? ");
		scanf("%s", saveFile);
		saveFile[MAXFILE_SIZE] = '\0';	
		FILE *savefptr;		
		savefptr = fopen(saveFile, "w");
		for(int topI = topBound-1; topI < bottomBound; topI++){
			for(int leftI = leftBound-1; leftI < rightBound; leftI++){
				fprintf(savefptr, "%c", pictureData[leftI][topI]);
				}
			fprintf(savefptr, "\n");
			}
	}
		
	return;	
}
	


