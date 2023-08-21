#include <stdlib.h>
#include <string.h>
#include "node.h"

node *insert_node(node *front, char* id, double x, double y) {
	// TODO: create a node, copy in the parameter fields
	// makesure that you do a deep copy
	node *new_n;
	new_n = malloc(sizeof(*new_n));
	if(new_n == NULL)
		return NULL;
	new_n->id = (char*) malloc(strlen(id)+1);
	strcpy(new_n->id, id);
	new_n->xcoord = x;
	new_n->ycoord = y;

	// TODO: link the new node into the chain 
	new_n->next = front;
	// TODO: return the new head of the chain if the function succeeded
	
	return new_n; // TODO: replace this once you implement
}


