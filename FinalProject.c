//Keilor Grossman and Jacob Bledsoe
//4-29-2024
//Final Project for image scalling

#include <stdio.h>

#define MAXSTRING_LENGTH 50
#define MAXFILE_SIZE 500
#define MAX_COLUMNS 500
#define MAX_ROWS 500

int getMenu();
int editMenu();

void getFile(int maxColSize,int *pictureColumns, int maxRowSize, int *pictureRows, int pictureData[][MAX_ROWS]);


void displayImage(int maxColSize, int *pictureColumns, int maxRowSize, int *pictureRows, int pictureData[][MAX_ROWS]);

int main() {

	int menuChoice;
	
	int columns;
	int rows;
	int mainPictureData[MAX_COLUMNS][MAX_ROWS];
	
	do{
	
		menuChoice = getMenu();
	
			switch(menuChoice){
			case 1:
			
				getFile(MAX_COLUMNS, &columns, MAX_ROWS, &rows, mainPictureData);
			
				break;
			case 2:
				displayImage(MAX_COLUMNS, &columns, MAX_ROWS, &rows, mainPictureData);
				break;
			case 3:
				editMenu();
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
		
		printf("***IMAGE MENU***\n");
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
	
	printf("***EDIT IMAGE MENU***\n");
	printf("(1): Crop Image\n");
	printf("(2): Increase Brightness\n");
	printf("(3): Decrease Brightness\n");
	printf("(0): Go back to menu\n");
	printf("Please enter the number for the operation you would like to perform: ");
	scanf("%d", &editMenuOption);
	
	return editMenuOption;
}

<<<<<<< HEAD
int getFile(int pictureColumns, int pictureRows, int pictureData[MAX_COLUMNS][MAX_ROWS]){
=======
void getFile(int maxColSize,int *pictureColumns, int maxRowSize, int *pictureRows, int pictureData[][MAX_ROWS]){
>>>>>>> 03307edd607624f4284284d385c28851f303757d
	
	char File[MAXFILE_SIZE];
	//int currentColumn = 0
	//int currentRow = 0;
	
	 *pictureColumns = 0;
	 *pictureRows = 0;
	

	printf("What is the name of the image file: ");
	scanf("%s", File);
	
	File[MAXFILE_SIZE] = '\0';
	
	FILE *readFilePointer;
	
	readFilePointer = fopen(File, "r");
	
	
	
	if(readFilePointer == NULL){
		printf("\nCould not find an image with that file name\n\n");
<<<<<<< HEAD
		return 1;
=======
		return;
>>>>>>> 03307edd607624f4284284d385c28851f303757d
	}
	else{
		printf("\n\nImage successfully loaded!\n\n");

	}
	for(currentColumn = 0; currentColumn < pictureColumns; currentColumn++) {
		for(currentRow = 0; currentRow = '\0'; currentRow++){
			fscanf(readFilePointer, "%d", &pictureData[currentColumn][currentRow]);
		}
		pictureData[currentColumn][MAX_ROWS] = '\0';
	}
	
	
<<<<<<< HEAD
	//while(fscanf(readFilePointer, "%d%d", &pictureData[index][MAX_COLUMNS], &pictureData[index][MAX_ROWS]) == 1){
	//	index++;
	//}
=======
	char temp;

	
	while(fscanf(readFilePointer, "%c", &temp) == 1) {
		if(temp == '\n') {
			*pictureRows++;
			*pictureColumns = 0;
		}
		else{
			pictureData[*pictureColumns][*pictureRows] = temp;
			printf("%d", pictureData[*pictureColumns][*pictureRows]);
			printf("\n");
		
			*pictureColumns++;
		}
	}
>>>>>>> 03307edd607624f4284284d385c28851f303757d
	
	//*pictureColumns = currentColumn;
	//*pictureRows = currentRow;
	
	
	
	
	
	


}

void displayImage(int maxColSize, int *pictureColumns, int maxRowSize, int *pictureRows, int pictureData[][MAX_ROWS]) {
	
<<<<<<< HEAD
	int currentRow, currentColumn;
=======
	int currentRow;
	int currentColumn;
		
		
>>>>>>> 03307edd607624f4284284d385c28851f303757d
		
	for(currentColumn = 0; currentColumn < *pictureColumns; currentColumn++) {
		for(currentRow = 0; currentRow < *pictureRows; currentRow++){
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

	



