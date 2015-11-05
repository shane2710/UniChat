/****************************************
 * Author: Shane Ryan, sryan8@nd.edu
 * Name: prog1.c
 * Purpose: Initialize two dimensional
 * array to zeroes, read a file into the
 * array, and print it out.
 ***************************************/


#include <stdio.h>
#include <stdlib.h>
#define ROW_SIZE 50
#define COL_SIZE 3
#define FILENAME "movie1.csv"

int main(void)
{
    float my_array[ROW_SIZE][COL_SIZE];
    int status_1, status_2, status_3;
    int init2DFloatArray(float array[ROW_SIZE][COL_SIZE]);
    int print2DFloatArray(float array[ROW_SIZE][COL_SIZE]);
    int readFileInto2DFloatArray(int m, int n, float array[m][n], char* file);
    char *file = FILENAME; /* pointer to char for passing filename */


    status_1 = init2DFloatArray(my_array);
    status_2 = print2DFloatArray(my_array);
    status_3 = readFileInto2DFloatArray(ROW_SIZE, COL_SIZE, my_array, file);
    printf("\n\nNew Array: \n");
    status_2 = print2DFloatArray(my_array);

/* the following if statement ensures all functions executed without error */

    if ((status_1 == 0) && (status_2 == 0) && (status_3 == 0)) {
        return 0;
    }
    else {
        return EXIT_FAILURE;
    }
}


/***************************************
 * Name: init2DFloatArray
 * Purpose: Set a 2D array to zeros
 * @input *array
 * @return int status
 * ************************************/

int init2DFloatArray(float array[ROW_SIZE][COL_SIZE])
{
    int i, j;
    
    if ((ROW_SIZE < 1) || (COL_SIZE < 1)) {
        return EXIT_FAILURE;
    }

    /* loop through rows then columns to set to zero */

    else {
        for (i = 0; i < ROW_SIZE; i++) {
            for (j = 0; j < COL_SIZE; j++) {
                array[i][j] = 0.0;
            }
        }
        return EXIT_SUCCESS;
    }
}


/***************************************
 * Name: print2DFloatArray
 * Purpose: print out a 2D array
 * @input *array
 * @return int status
 * ************************************/

int print2DFloatArray(float array[ROW_SIZE][COL_SIZE])
{
    int k, l;

    /* check that it's a valid 2D array */

    if ((ROW_SIZE < 1) || (COL_SIZE < 1)) {
        return EXIT_FAILURE;
    }

    /* if so, print out a row with values separated by spaces, and then print out a newline character before proceeding to next row */

    else {
        for (k = 0; k < ROW_SIZE; k++) {
            for (l = 0; l < COL_SIZE; l++) {
                printf("\t%lf\t", array[k][l]);
            }
            printf("\n");
        }
        return 0;
    }
}

/**************************************
 * Name: readFileInto2DFloatArray
 * Purpose: read file into 2D array
 * @input *array, filename, row_size,
 * col_size
 * @return int status
 * ***********************************/

int readFileInto2DFloatArray(int m, int n, float array[m][n], char* file)
{
    FILE *input;
    /* open filename specified in main using pointer to char const */

    input = fopen(file, "r");

    int i, j;
    j = 0;

    /* error if file not found */

    if (input == NULL) {
        return EXIT_FAILURE;
    }

    /* if opened correctly, scan a row at a time into array */

    else {
        for (i = 0; i < m; i++) {
            fscanf(input, "%f,%f,%f", &array[i][j], &array[i][j+1], &array[i][j+2]);
        }

        fclose(input);

        return 0;
    }
}

