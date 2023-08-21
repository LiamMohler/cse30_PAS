#include <stdlib.h>
#include "node.h"

void delete_table(node **htable, unsigned long tabsz) {
	// TODO: walk through the chains in table
	//
	// TODO: free all the memory associated to each node in each chain
	//
	// TODO: free the entire table

	(void) htable; // suppress unused variable warnings
	(void) tabsz; // TODO: delete these once you start implementation
	for(int i = 0;i<(int) tabsz;i++){
		node *t_list = htable[i];
		while(t_list!=NULL)
		{
			free(t_list->id);
			t_list = t_list->next; 
		}
	}
	free(htable);
}
