#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "data.h"
#include "list.h"

int main(int argc, char *argv[]){

    char path[128]="tests/";
    char inputfile[128];
    char query[MAX_STRING_LEN+1];

    // Checks if three command line arguments are present 
    if (argc < 3) {
		fprintf(stderr, "Usage: %s input_file_name output_file_name\n", argv[0]);
		exit(EXIT_FAILURE);
	}

    // Converts the second command line argument into a string and concatenates the path name of the input file to it

    strcpy(inputfile,(strcat(path,argv[2])));

    // Allocates a file pointer to open the input file and output file
	FILE *inFile = fopen(inputfile, "r"); 
    FILE *outFile = fopen(argv[3], "w");
    assert(inFile);
    assert(outFile);

    // Gets the query from user input
    fgets(query,MAX_STRING_LEN,stdin);

    // Creates an empty linked list to store attributes from the dataset
    list_t *list = make_empty_list();

    // Ignores the header line of the dataset and reads from the next line
    SkipHeaderLine(inFile);

    // Creates a struct to represent individual records from the dataset containing all attributes
    footpath_t *a;

    // Reads each line of the csv file and dynamically stores it into a dynamic struct whose pointer is contained in a linked list
    while ((a=read_data(inFile))) {
        insert_at_foot(list, a);
        printf("end_lat is %lf",a->end_lat);
        free(a);
    }

    // Searches the dictionary for a specific attribute matching the query and prints out the entire record of data
    //search(list,query);

    free_list(list);
    fclose(inFile);
    free(outFile);


    return 0;
}
