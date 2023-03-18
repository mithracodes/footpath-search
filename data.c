#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "data.h"
#include "list.h"

// Skips the header line of the given CSV file and points to the next line
void SkipHeaderLine(FILE *f) {
	while (fgetc(f) != '\n');
}

// Reads each line of the CSV file and stores the data in each field as a dynamic struct element 
footpath_t *read_data(FILE *f) {

	char line[MAX_LINE_LEN+1], temp[MAX_STRING_LEN+1];
	char *string;
	int str_len, column, x;

	footpath_t *a = NULL;

	// Define the type of each struct element
	int footpath_id;
	char address[MAX_STRING_LEN + 1]; 
	char clue_sa[MAX_STRING_LEN + 1];
	char asset_type[MAX_STRING_LEN + 1];
	double deltaz;
	double distance;
    double grade1in;
    int mcc_id;
    int mccid_int;
    double rlmax;
    double rlmin;
    char segside[MAX_STRING_LEN + 1];
    int statusid;
    int streetid;
    int street_group;
    double start_lat;
    double start_lon;
    double end_lat;
    double end_lon;

	// Scans through the input CSV file line by line
	while (fscanf(f, "%[^\n]", line)!=EOF) {

		fgetc(f);

		// allocates memory for struct a 
		a = malloc(sizeof(*a));     
		assert(a);

		// Converts the line into a single string and finds its length
		string = strdup(line);
		str_len = strlen(string);

		// Variable to check for quotation marks
		int found = 0;

		// Counts the number of fields already stored into the struct
		column=-1;

		// Character array to process each individual character in the line
		char curr_char[MAX_STRING_LEN+1];
		
		memset(temp,0,MAX_STRING_LEN);

		// Parses through each character in the line to add it to its appropriate struct element
		for(x=0;x<str_len;x++) {
						
			sscanf(&string[x],"%c",curr_char);
			
			// If double quotation marks are found within the fields
			if (strcmp(curr_char,"\"")==0) {

				found++;
				
			// If current character is a comma
			} else if (strcmp(curr_char,",")==0) {
			
				// If the comma is present before or after the quotation marks
				if (found==0 || found==2) {

					// Move to the next column
					column++;

					// Lines 86-179 convert the string to the appropriate type for that particular attribute by identifying the column   						number it is present in and stores it in the struct element
					if (column==0) {
						sscanf(temp,"%d",&footpath_id);
						a->footpath_id = footpath_id;	
					}

					if (column==1) {
						a->address = strdup(temp);  
						assert(a->address); 	
					}

					if (column==2) {	
						a->clue_sa = strdup(temp);						
						assert(a->clue_sa);
					}

					if (column==3) {
						a->asset_type = strdup(temp);
						assert(a->asset_type);
					}

					if (column==4) {
						sscanf(temp,"%lf",&deltaz);
						a->deltaz = deltaz;	
					}

					if (column==5) {
						sscanf(temp,"%lf",&distance);
						a->distance = distance;	
					}

					if (column==6) {
						sscanf(temp,"%lf",&grade1in);
						a->grade1in = grade1in;	
					}

					if (column==7) {
						sscanf(temp,"%d",&mcc_id);
						a->mcc_id = mcc_id;	
					}

					if (column==8) {
						sscanf(temp,"%d",&mccid_int);
						a->mccid_int = mccid_int;	
					}

					if (column==9) {
						sscanf(temp,"%lf",&rlmax);
						a->rlmax = rlmax;	
					}

					if (column==10) {
						sscanf(temp,"%lf",&rlmin);
						a->rlmin = rlmin;	
					}

					if (column==11) {
						a->segside = strdup(temp);
						assert(a->segside);
					}

					if (column==12) {
						sscanf(temp,"%d",&statusid);
						a->statusid = statusid;	
					}

					if (column==13) {
						sscanf(temp,"%d",&streetid);
						a->streetid = streetid;	
					}

					if (column==14) {
						sscanf(temp,"%d",&street_group);
						a->street_group = street_group;	
					}

					if (column==15) {
						sscanf(temp,"%lf",&start_lat);
						a->start_lat = start_lat;	
					}

					if (column==16) {
						sscanf(temp,"%lf",&start_lon);
						a->start_lon = start_lon;	
					}

					if (column==17) {
						sscanf(temp,"%lf",&end_lat);
						a->end_lat = end_lat;	
					}

					if (column==18) {
						sscanf(temp,"%lf",&end_lon);
						a->end_lon = end_lon;	
					}

					memset(temp,0,MAX_STRING_LEN);
					
				} else {
					// If comma is present within quotation marks
					// Adds the current character to the buffer array until another quote is found
					strcat(temp,curr_char);
					continue;
				}
								
			} else {
				// Adds the current character to the buffer array until another quote is found
				strcat(temp,curr_char);
			}

			// If the end of line is reached, convert the remaining string into appropriate type and store it in the last element of the 				struct
			if (x==str_len-1) {
				sscanf(temp,"%lf",&end_lon);
				a->end_lon = end_lon;	
			}

			if (found==2) {
				//If value within quotation marks is stored
				// Resets counter to 0
				found=0;
			}

		}
		
		
	}	
	
	// Returns the struct back to the node of the linked list
 	return a;
}
