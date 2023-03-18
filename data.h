#ifndef _DATA_H_
#define _DATA_H_

#include "stdio.h"

// constant defnitions
#define MAX_STRING_LEN 128
#define MAX_LINE_LEN 512

// data definitions
struct footpath {
	int footpath_id;
	char *address;
	char *clue_sa;
    char *asset_type;
	double deltaz;
	double distance;
    double grade1in;
    int mcc_id;
    int mccid_int;
    double rlmax;
    double rlmin;
    char *segside;
    int statusid;
    int streetid;
    int street_group;
    double start_lat;
    double start_lon;
    double end_lat;
    double end_lon;
};

typedef struct footpath footpath_t;

// function definitions
void SkipHeaderLine(FILE *f);
footpath_t *read_data(FILE *f);

#endif
