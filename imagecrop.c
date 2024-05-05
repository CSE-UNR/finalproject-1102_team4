//Name: Vansh Sachdeva, Wiem Boubaker
//Due date: 05/07/2024
//Purpose: Image Cropping

#include <stdio.h>
#define NUM_ROWS 512 
#define NUM_COLS 384
#define FILENAME "Image.txt"

void displayImage(char image[][NUM_COLS], int rows, int cols);
void brightenImage(char (*currentImage)[NUM_COLS], int rows, int cols);
int displaySecondMenu();
void dimImage(char (*currentImage)[NUM_COLS], int rows, int cols);
void displayImageToCrop(char image[][NUM_COLS], int rows, int cols);
void cropImage(char (*currentImage)[NUM_COLS], int rows, int cols);
void saveImage(char image[][NUM_COLS], int rows, int cols);

int main(){
	int choice1, choice2 = 0;
	char originalImage[NUM_ROWS][NUM_COLS];
	FILE *fp;
	char row[NUM_COLS], choice3;
	int width = 0;
	int height = 0;
	char filename[100];
	
	do{
		printf("\nMain Menu:\n");
		printf("1. Load a new image\n");
		printf("2. Display the current image\n");
		printf("3. Edit the current image\n");
		printf("0. Exit\n");
		printf("\nEnter Your choice: ");
		scanf("%d", &choice1);
		
		switch(choice1){
			case 1:
				printf("Enter the name of the file: ");
				scanf("%s", filename);
				fp = fopen(filename, "r");
				if(fp == NULL){
					printf("Error opening file");
				}else{
					printf("\nImage loaded successfully!\n");
					fclose(fp);
				}
				break;
			case 2:
				fp = fopen(filename, "r");
				if(fp == NULL){
					printf("Error opening file");
				}else{
					while(fgets(row, sizeof(row), fp)){
					width = 0; // Reset width for each row
					for(int i = 0; row[i] != '\n' && row[i] != '\0'; i++){
						width++;
					}
					for(int i = 0; i < width; i++){
						originalImage[height][i] = row[i];
					}
					height++;
					}
					displayImage(originalImage, height, width);
					fclose(fp);
				}
				break;
			case 3:
				choice2 = displaySecondMenu();
				switch(choice2){
					case 1:
						displayImageToCrop(originalImage, height, width);
						break;
					case 2:
						dimImage(originalImage, height, width);
						displayImage(originalImage, height, width);
						saveImage(originalImage, height, width);
						break;
					case 3:
						brightenImage(originalImage, height, width);
						displayImage(originalImage, height, width);
						saveImage(originalImage, height, width);
						break;
					case 4:
						printf("Returning to main menu...\n");
						break;
					default:
						printf("Invalid choice! Please try again.\n");
				}
				break;
			case 0:
				printf("Exiting program...\n");
				break;
			default:
				printf("Invalid choice! Please try again.\n");
		}
	}while(choice1 != 0);
	
	return 0;
}

void displayImage(char image[][NUM_COLS], int rows, int cols){
	printf("Displaying image:\n");
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			switch(image[i][j]){
				case 0:
					printf(" ");
					break;
				case 1:
					printf(".");
					break;
				case 2:
					printf("o");
					break;
				case 3:
					printf("O");
					break;
				case 4:
					printf("0");
					break;
				default:
					printf(" ");
			}
		}
		printf("\n");
	}
}

int displaySecondMenu(){
	int choice;
	do{
		printf("\nEdit menu:\n");
		printf("1. Crop\n");
		printf("2. Dim\n");
		printf("3. Brighten\n");
		printf("4. Back to main menu\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
	}while(choice < 1 || choice > 4);
	return choice;
}

void brightenImage(char (*currentImage)[NUM_COLS], int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			int number = currentImage[i][j] - '0';
			if(currentImage[i][j] >= '0' && currentImage[i][j] < '4'){
				currentImage[i][j] = ++number + '0';
			}
		}
	}
	printf("Image brightned successfully.\n");
}

void dimImage(char (*currentImage)[NUM_COLS], int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			int number = currentImage[i][j] - '0';
			if(currentImage[i][j] >= '0' && currentImage[i][j] < '4'){
				currentImage[i][j] = --number + '0';
			}
		}
	}
	printf("Image dimmed successfully.\n");
}

void displayImageToCrop(char image[][NUM_COLS], int rows, int cols){
	for(int i = 0; i < rows; i++){
		if(i == 0 || i == cols){
			printf("%d", i + 1);
		}
		else{
			printf(" ");
		}
		for(int j = 0; j < cols; j++){
			if(j == 0 || j == cols - 1){
				printf("%d", j + 1);
			}
			else{
				printf(" ");
			}
			switch(image[i][j]){
				case '0':
					printf(" ");
					break;
				case '1':
					printf(".");
					break;
				case '2':
					printf("o");
					break;
				case '3':
					printf("O");
					break;
				case '4':
					printf("0");
					break;
				default:
					printf(" ");
			}
		}
		printf("\n");
	}
}

void cropImage(char (*currentImage)[NUM_COLS], int rows, int cols){
}

void saveImage(char image[][NUM_COLS], int rows, int cols){
	char choice3;
	char filename[100];
	
	printf("Do you want to save the edited image (Y/N): ");
	scanf(" %c", &choice3);
	
	if(choice3 == 'Y' || choice3 == 'y'){
		printf("Enter the name of the file to save the image: ");
		scanf("%s", filename);
		
		FILE *file = fopen(FILENAME, "w");
		if(file == NULL){
			printf("Error opening file.\n");
			return;
		}
		
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				fprintf(file, "%c", image [i][j]);
			}
			fprintf(file, "\n");
		}
		fclose(file);
	}
}
