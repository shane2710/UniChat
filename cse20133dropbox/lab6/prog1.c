#########################
# Author: Shane Ryan
# Name: prog1.c
# Purpose: Read file line
# by line, encrypt.
#########################

#include <stdio.h>
#include <stdlib.h>
#define FILENAME "hello.txt"

int main()
{
    FILE *inputtext;
    int expected = 1;
    char letter[200];

    inputtext = fopen(FILENAME, "r");

    if (inputtext == NULL) {
        printf("ERROR: Could not find file.  Exiting...")
        return(EXIT_FAILURE); 
    }

    while ((!feof(inputtext)) && (expected == 1)) {
        expected = fscanf(inputtext, "%c", &letter);
    
    }

    printCharacterArray(letter, 200);    

    return 0;
}


void printCharacterArray(char input[200], int length)
{
    int i;
    
    for (i=0; i < length; i++) {
        printf("%c\n", input[i]);
    }

    return EXIT_SUCCESS;
}
