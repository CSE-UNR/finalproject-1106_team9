int cropImage(){ 
	int leftBound, rightBound, topBound, bottomBound;
	
	printf("Please enter how much you would like to remove from the left side of the image: ");
	scanf("%d", &leftBound);
	printf("\nPlease enter how much you would like to remove from the right side of the image: ");
	scanf("%d", &rightBound);
	printf("\nPlease enter how much you would like to remove from the top of the image: ");
	scanf("%d", &topBound);
	printf("\nPlease enter how much you would like to remove from the bottom of the image: ");
	scanf("%d", &bottomBound);
	printf("\nYou have chosen to remove %d from the left side, %d from the right side, %d from the top, and %d from the bottom.\nHere is your croped image:\n", leftBound, rightBound, topBound, bottomBound);
	
	
