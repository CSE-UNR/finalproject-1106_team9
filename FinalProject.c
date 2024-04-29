//Keilor Grossman and Jacob Bledsoe
//4-29-2024
//Final Project for image scalling

#include <stdio.h>

#define MAXSTRING_LENGTH 50

int main() {

	int menuoption;
	
	printf("***IMAGE MENU***\n");
	printf("(1): Import image file\n");
	printf("(2): Increase the image brightness\n");
	printf("(3): Decrease the image brightness\n");
	printf("(4): Crop current image\n");
	printf("(5): Save current image\n");
	printf("(0): Exit program\n");
	printf("Please enter the number of the option you would like to choose: ");
	scanf("%d", &menuoption);
	
	return 0;
}
