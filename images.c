
//Name: Vansh Sachdeva, Wiem Boubaker
//Due date: 05/07/2024
//Purpose: Image Processing


#include <stdio.h>

#define NUM_ROWS 30
#define NUM_COLS 30
#define FILENAME "image.txt"

// Function prototypes
void displayImage(char image[][NUM_COLS], int rows, int cols);
void brightenImage(char (*currentImage)[NUM_COLS], int rows, int cols);
int displaySecondMenu();
void dimImage(char (*currentImage)[NUM_COLS], int rows, int cols);
void displayImageToCrop(char image[][NUM_COLS], int rows, int cols);
void cropImage(char (*currentImage)[NUM_COLS], int rows, int cols);
void saveImage(char image[][NUM_COLS], int rows, int cols);

int main() {
    int choice1, choice2 = 0;
    char originalImage[NUM_ROWS][NUM_COLS];
    FILE *fp;
    char row[NUM_COLS], choice3;
    int width = 0;
    int height = 0;
    char filename[100]; 

    do {
        // Main menu
        printf("\nMain Menu:\n");
        printf("1. Load a new image\n");
        printf("2. Display the current image\n");
        printf("3. Edit the current image\n");
        printf("0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice1);

        switch (choice1) {
            case 1:
                // Load image from file
                printf("Enter the name of the file: ");
                scanf("%s", filename);
                fp = fopen(filename, "r");
                if (fp == NULL) {
                    printf("Error opening file.\n");
                } else {
                    printf("\nImage successfully loaded\n");
                    fclose(fp);
                }
                break;
            case 2:
                // Display current image
                fp = fopen(filename, "r");
                if (fp == NULL) {
                    printf("Error opening file.\n");
                } else {
                    while (fgets(row, NUM_ROWS, fp)) {
                        width = 0;
                        for (int i = 0; row[i] != '\n' && row[i] != '\0'; i++) {
                            width++;
                        }
                        for (int i = 0; i < width; i++) {
                            originalImage[height][i] = row[i];
                        }
                        height++;
                    }
                    displayImage(originalImage, height, width);
                    fclose(fp);
                }
                break;
            case 3:
                // Editing options
               choice2 = displaySecondMenu();
                switch (choice2) {
                    case 1:
                        // Crop image
                        displayImageToCrop(originalImage, height, width);
                        cropImage(originalImage, height, width);
                        displayImage(originalImage, height, width);
                        saveImage(originalImage, height, width);
                        break;
                    case 2:
                        // Dim image
                        dimImage(originalImage, height, width);
                        displayImage(originalImage, height, width);
                        saveImage(originalImage, height, width);
                        break;
                    case 3:
                        // Brighten image
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
    } while (choice1 != 0);

    return 0;
}

// Function to display the image
void displayImage(char image[][NUM_COLS], int rows, int cols) {
    printf("Displaying image:\n");
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           switch (image[i][j]) {
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

// Function to display the second menu for editing options
int displaySecondMenu() {
    int choice;
    do {
        printf("\nEdit Menu:\n");
        printf("1. Crop\n");
        printf("2. Dim\n");
        printf("3. Brighten\n");
        printf("4. Back to main menu\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 4);
    return choice;
}

// Function to brighten the image
void brightenImage(char (*currentImage)[NUM_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int number = currentImage[i][j] - '0';
            if (currentImage[i][j] >= '0' && currentImage[i][j] <'4') {
                currentImage[i][j] = ++number + '0'; 
            }
        }
    }
    printf("Image brightened successfully.\n");
}

// Function to dim the image
void dimImage(char (*currentImage)[NUM_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int number = currentImage[i][j] - '0';
            if (currentImage[i][j] >= '0' && currentImage[i][j] < '4') {
                currentImage[i][j] = --number + '0'; 
            }
        }
    }
    printf("Image dimmed successfully.\n");
}

// Function to display the image with indices to aid in cropping
void displayImageToCrop(char image[][NUM_COLS], int rows, int cols) {
    printf(" 1                    21\n");
    printf("1    00         00    \n");
    image[rows][cols];
    for (int i = 1; i < rows; i++) {
           if(rows < 21){
           printf(" ");
           }
        for (int j = 0; j < cols; j++) {
           if(cols < 12){
           printf(" ");
           }
           switch (image[i][j]) {
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
    printf("12\n");
}

// Function to crop the image
void cropImage(char (*currentImage)[NUM_COLS], int rows, int cols){
    int startRow, endRow, startCol, endCol = 0;
    
    printf("The image you want to crop is 12 x 21.\n");
    printf("The row and column values start in the upper lefthand corner.\n");
    printf("\n");
    printf("Which column do you want to be the new left side? ");
    scanf("%d", &startCol);
    if(startCol < cols){
        printf("Invalid column number. Choose a number between %d and %d: ", startCol + 1, cols - 1);
        scanf("%d", &startCol);
    }
    printf("\nWhich column do you want to be the right left side? ");
    scanf("%d", &endCol);
    if(endCol > cols){
        printf("Invalid column number. Choose a number between %d and %d: ", startCol, cols - 1);
        scanf("%d", &endCol);
    }
    printf("\nWhich row do you want to be the new top? ");
    scanf("%d", &startRow);
    if(startRow < rows){
        printf("Invalid row number. Choose a number between %d and %d: ", startRow + 1, rows - 1);
        scanf("%d", &startRow);
    }
    printf("\nWhich row do you want to be the new bottom? ");
    scanf("%d", &startRow);
    if(cols > startCol){
        printf("Invalid column number. Choose a number between %d and %d: ", startRow, rows - 1);
        scanf("%d", &endRow);
    }
}

// Function to save the edited image
void saveImage(char image[][NUM_COLS], int rows, int cols) {
    char choice3;
    char filename[100];

    printf("Do you want to save the edited image? (Y/N): ");
    scanf(" %c", &choice3);

    if (choice3 == 'Y' || choice3 == 'y') {
        printf("Enter the name of the file to save the image: ");
        scanf("%s", filename);

        FILE *file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error opening file.\n");
            return;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                fprintf(file, "%c", image[i][j]);
            }
            fprintf(file, "\n"); 
        }

        fclose(file);
    }
}

