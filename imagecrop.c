//Name: Vansh Sachdeva, Wiem Boubaker
//Due date: 05/07/2024
//Purpose: Image Cropping
#include <stdio.h>

#define NUM_ROW 512 
#define NUM_COLS 384
#define FILENAME "Image.txt"

void loadImage( int image [] [cols], int row, int cols, FILE *fp);
void displayImage( int image [] [cols], int row, int cols, char image2[] [cols]);
int cropImage (int image [] [cols], int startRow, int startCols, int endRow, int endCols);
int dimImage (int image [] [cols], int row, int cols);
int brightenImage (int image [] [cols], int row, int cols);
int rotateImage (int image [] [cols], int row, int cols);


int main(){

	int choice;
	int choice2;
	int choice3;
	int rows;
	int cols;
	int startRow, endRow;
	int startCols, endCols;
	int image[NUM_ROW][NUM_COLS];
	char image2;

	printf("1:load an image\n");
	printf("2:Display  \n");
	printf("3:Edit \n");
	printf("4:Exit \n");
	scanf(" %d", &choice);
	
	FILE *fp;
	fp = fopen(FILENAME, "r");
	if(fp == NULL){
		printf("Cannot load image, goodbye\n");
		return 0;
	}
	
	switch(choice){
		case '1':
			loadImage(rows, cols, fp);
			break;
		case '2':
			displayImage(rows, cols, fp);
			break:
		



	return 0;
}
