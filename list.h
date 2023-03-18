#ifndef _LIST_H_
#define _LIST_H_
#include "stdio.h"
#include "data.h"

// data definitions

typedef struct node node_t;

typedef struct {
	node_t *head;
	node_t *foot;
} list_t; 

// function definitions

list_t *make_empty_list();
void insert_at_foot(list_t *list, footpath_t *value);
void free_list(list_t *list);
void search(list_t *list, char *query);
#endif
