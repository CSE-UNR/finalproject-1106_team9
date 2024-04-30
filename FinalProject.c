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

	int menuoption;
	
	printf("***IMAGE MENU***\n");
	printf("(1): Import image file\n");
	printf("(2): Increase the image brightness\n");
	printf("(3): Decrease the image brightness\n");
	printf("(4): Crop current image\n");
	printf("(5): Save current image to file\n");
	printf("(6): Display current image\n");
	printf("(0): Exit program\n");
	printf("Please enter the number of the option you would like to choose: ");
	scanf("%d", &menuoption);
	
	switch(menuoption){
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
			printf("invalid imput, good bye");
			break;
	}
	return;
}

void getFile(){
	
	char File[MAXFILE_SIZE];
	
	printf("Please enter the name of the file you would like to edit: ");
	fgets(File, MAXFILE_SIZE, stdin);
	
}

	



