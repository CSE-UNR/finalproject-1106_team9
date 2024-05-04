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
int cropImage();
int dimImage();
int brightenImage();

void getFile(int *pictureColumns, int *pictureRows, char pictureData[][MAX_COLUMNS]);

void displayImage(int maxColSize, int *pictureColumns, int maxRowSize, int *pictureRows, char pictureData[][MAX_COLUMNS]);

int main() {

	int menuChoice, editMenuOption;

	
	int columns;
	int rows;

	char mainPictureData[MAX_ROWS][MAX_COLUMNS];
	

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
				editMenuOption = editMenu();
				switch(editMenuOption){
					case 1:
						cropImage();
						break;
					case 2:
						brightenImage();
						break;
					case 3:
						dimImage();
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
	}while(menuChoice != 0);
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
	printf("(2): Increase Brightness\n");
	printf("(3): Decrease Brightness\n");
	printf("(0): Go back to menu\n");
	printf("Please enter the number for the operation you would like to perform: ");
	scanf("%d", &editMenuOption);
	
	return editMenuOption;
}



void getFile(int maxColSize, int *pictureColumns, int maxRowSize, int *pictureRows, char pictureData[][MAX_COLUMNS]){

	
	char File[MAXFILE_SIZE], temp;


void getFile(int maxColSize,int *pictureColumns, int maxRowSize, int *pictureRows, int pictureData[][MAX_ROWS]){

	
	char File[MAXFILE_SIZE];
	int* columnnum = 0, rownum = 0;

	
	*pictureColumns = 0;
	*pictureRows = 0;
	

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
	}


	


	char temp;

	
	while(fscanf(readFilePointer, "%c", &temp) == 1) {
		if(temp == '\n') {
			printf("\n");

			*pictureColumns++;
			*pictureRows = 0;
		}
		else{
			pictureData[*pictureRows][*pictureColumns] = temp - '0';
			
			switch(pictureData[*pictureRows][*pictureColumns]) {
				case 0:
					pictureData[*pictureRows][*pictureColumns] = ' ';
					break;
				case 1:
					pictureData[*pictureRows][*pictureColumns] = '.';
					break;
				case 2:
					pictureData[*pictureRows][*pictureColumns] = 'o';
					break;
				case 3: 

					pictureData[*pictureRows][*pictureColumns] = 'O';
					break;
				case 4:
					pictureData[*pictureRows][*pictureColumns] = '0';

					pictureData[*pictureColumns][*pictureRows] = 'O';
					break;
				case 4:
					pictureData[*pictureColumns][*pictureRows] = '0';

					break;
				default:
					
					break;
			}

			

			printf("%c", pictureData[*pictureRows][*pictureColumns]);

			printf("%c", pictureData[*pictureColumns][*pictureRows]);


			*pictureRows++;
		}
	}
	
	fclose(readFilePointer);

}

void displayImage(int maxColSize, int *pictureColumns, int maxRowSize, int *pictureRows, char pictureData[][MAX_COLUMNS]) {

	
	for(int rowI= 0; rowI < *pictureRows; rowI++) {
		for(int columnI = 0; pictureData[*pictureRows][columnI] != '\n'; columnI++){
			printf("%c", pictureData[*pictureRows][columnI]);
		}
		printf("\n");
		


	return;



}



void displayImage(int maxColSize, int *pictureColumns, int maxRowSize, int *pictureRows, int pictureData[][MAX_ROWS]) {

	
	int currentRow;
	int currentColumn;
		

	for(int currentColumn = 0; currentColumn < *pictureColumns; currentColumn++) {
		for(int currentRow = 0; currentRow < *pictureRows; currentRow++){

			printf("%c", pictureData[*pictureColumns][*pictureRows]);
		}

			
			if(pictureData[currentColumn][currentRow] == '0'){
				printf(" ");
			}
			else if (pictureData[currentColumn][currentRow] == '1'){
				printf(".");
			}
			else if (pictureData[currentColumn][currentRow] == '2'){
				printf("o");
			}
			else if (pictureData[currentColumn][currentRow] == '3') {
				printf("O");
			}
			else{
				printf("0");
			}
		}

	printf("%c", pictureData[*pictureColumns][*pictureRows]);
	printf("\n");



	}
	
} 


int brightenImage(){
	return 0;
}



int dimImage(){
	return 0;
}




int cropImage(){ 
	int leftBound, rightBound, topBound, bottomBound;
	
	printf("\n\nPlease enter how much you would like to remove from the left side of the image: ");
	scanf("%d", &leftBound);
	printf("\nPlease enter how much you would like to remove from the right side of the image: ");
	scanf("%d", &rightBound);
	printf("\nPlease enter how much you would like to remove from the top of the image: ");
	scanf("%d", &topBound);
	printf("\nPlease enter how much you would like to remove from the bottom of the image: ");
	scanf("%d", &bottomBound);
	printf("\nYou have chosen to remove %d from the left side, %d from the right side, %d from the top, and %d from the bottom.\nHere is your croped image:\n", leftBound, rightBound, topBound, bottomBound);
	
	return 0;	
}

