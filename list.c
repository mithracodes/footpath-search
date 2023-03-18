#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <assert.h>
#include "list.h"
#include "data.h"

// Define a node for the linked list
struct node {
	footpath_t *data;
	node_t *next;
};

//Code used for free_list, make_empty_list, insert_at_foot is partially taken from: https://people.eng.unimelb.edu.au/ammoffat/ppsaa/c/listops.c


// Creates an empty linked list
list_t
*make_empty_list() {

	list_t *list;

	// Allocates space for the list
	list = (list_t*)malloc(sizeof(*list));
	assert(list!=NULL);

	// Initialises head and foot of the list as NULL
	list->head = list->foot = NULL;
	return list;
}

// Inserts a pointer to the struct as the last node of the linked list
void
insert_at_foot(list_t *list, footpath_t *value) {

	// Creates a new node and allocates space for it 
	node_t *new;
	new = (node_t*)malloc(sizeof(*new));
	assert(list!=NULL && new!=NULL);

	// Assigns the pointer to a struct as value for the node
	new->data = value;
	new->next = NULL;


	if (list->foot==NULL) {

		// this is the first insertion into the list
		list->head = list->foot = new;

	} else {

		// Adds the new node to the foot of the list
		list->foot->next = new;
		list->foot = new;
	}

}

void
free_list(list_t *list) {
	node_t *curr, *prev;
	assert(list!=NULL);
	curr = list->head;
	while (curr) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	free(list);
}

// Searches through the linked list for a node having a struct element matching the query and prints out the entire record of attributes 
void
search(list_t *list, char* query) {

	// If the record matching the query is not found 
	if (list->head==NULL) {
		printf("NOTFOUND");
		exit(0);
	}
	
	// If the record matching the query is not found 
	if (strcmp(list->head->data->address,query)==0) {
		
		// Print out all other attributes of the record
		printf("--> ");
		printf("footpath_id: %d ||",list->head->data->footpath_id);
		printf("address: %s ||",list->head->data->address);
		printf("clue_sa: %s ||",list->head->data->clue_sa);
		printf("asset_type: %s ||",list->head->data->asset_type);
		printf("deltaz: %lf ||",list->head->data->deltaz);
		printf("distance: %lf ||",list->head->data->distance);
		printf("grade1in: %lf ||",list->head->data->grade1in);
		printf("mcc_id: %d ||",list->head->data->mcc_id);
		printf("mccid_int: %d ||",list->head->data->mccid_int);
		printf("rlmax: %lf ||",list->head->data->rlmax);
		printf("rlmin: %lf ||",list->head->data->rlmin);
		printf("segside: %s ||",list->head->data->segside);
		printf("statusid: %d ||",list->head->data->statusid);
		printf("street_group: %d ||",list->head->data->street_group);
		printf("start_lat: %lf ||",list->head->data->start_lat);
		printf("start_lon: %lf ||",list->head->data->start_lon);
		printf("end_lat: %lf ||",list->head->data->end_lat);
		printf("end_lon: %lf ||",list->head->data->end_lon);
				
	}
	
	// Search the next node of the linked list
	list->head = list->head->next;

}

