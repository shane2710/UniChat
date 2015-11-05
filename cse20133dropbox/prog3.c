/****************************************
 * Author: Shane Ryan, sryan8@nd.edu
 * Name: prog3.c
 * Purpose: Initialize two dimensional
 * array to zeroes, read a file into the
 * array, then sort by 3rd col value.
 ***************************************/


#include <stdio.h>
#include <stdlib.h>
#define ROW_SIZE 50
#define COL_SIZE 3
#define FILENAME "movie1.csv"
#define ROW_1 5
#define ROW_2 6


int main(void)
{
    float my_array[ROW_SIZE][COL_SIZE];
    int status_1, status_2, status_3, status_4;
    int init2DFloatArray(float array[ROW_SIZE][COL_SIZE]);
    int print2DFloatArray(float array[ROW_SIZE][COL_SIZE]);
    int readFileInto2DFloatArray(int m, int n, float array[m][n], char* file);
    int swapTwoRows(float array[ROW_SIZE][COL_SIZE], int row_1, int row_2);
    int sort2DFloatArray(float array[ROW_SIZE][COL_SIZE]);
    char *file = FILENAME; /* pointer to char for passing filename */


    status_1 = init2DFloatArray(my_array);
    status_3 = readFileInto2DFloatArray(ROW_SIZE, COL_SIZE, my_array, file);
    printf("\n\nOriginal Array: \n");
    status_2 = print2DFloatArray(my_array);
    status_4 = sort2DFloatArray(my_array);
    printf("\n\nNew Array: \n");
    status_2 = print2DFloatArray(my_array);

    if ((status_1 == 0) && (status_2 == 0) && (status_3 == 0) && (status_4 == 0)) {
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

    if ((ROW_SIZE < 1) || (COL_SIZE < 1)) {
        return EXIT_FAILURE;
    }
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
    input = fopen(file, "r");

    int i, j;
    j = 0;

    if (input == NULL) {
        return EXIT_FAILURE;
    }

    else {
        for (i = 0; i < m; i++) {
            fscanf(input, "%f,%f,%f", &array[i][j], &array[i][j+1], &array[i][j+2]);
        }

        fclose(input);

        return 0;
    }
}


/************************************
 * Name: swapTwoRows
 * Purpose: swap the data in two rows
 * of an array.
 * @input *array, row_1, row_2
 * @return int status
 * *********************************/

int swapTwoRows(float array[ROW_SIZE][COL_SIZE], int row_1, int row_2)
{
    int i;
    float tmp[COL_SIZE] = {0};

    for (i = 0; i < COL_SIZE; i++) {
        tmp[i] = array[row_1][i];
        array[row_1][i] = array[row_2][i];
        array[row_2][i] = tmp[i];
    }

    return 0;
}

/*************************************
 * Name: sort2DFloatArray
 * Purpose: sort an array by the third value
 * @input *array
 * @return int status
 * **********************************/

int sort2DFloatArray(float array[ROW_SIZE][COL_SIZE])
{
    int i, counter, state;
    state = 1;
    counter = 0;

    /* start a while loop that constantly compares one row's money value to the next rows */

    while (state == 1) {
        for (i = 0; i < (ROW_SIZE - 1); i++) {
            /* if the 1st is greater than the 2nd, swap */
            if (array[i][2] < array [i+1][2]) {
                swapTwoRows(array, i, i+1);
                counter++;
            }
        }
        /* if no rows have been swapped, we are successfully sorted */
        if (counter == 0) {
            state = 0;
        }
        counter = 0;
    }

    return 0;
}

