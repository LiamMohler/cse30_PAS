#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "node.h"

#define MIN_TAB_SZ 3
#define DEFAULT_TAB_SZ 1873
#define QUERY_SUCCESS_FORMAT "found tree id=%s, x=%.5f, y=%.5f\n" 
#define QUERY_FAILURE_FORMAT "could not find tree with id=%s\n"

int main(int argc, char **argv) {
	int s_flag;
	unsigned long tabsz = DEFAULT_TAB_SZ;
	// TODO: parse opts with getopt and initialize these variables
	int c;
	char *tmp;
	char *filename = argv[1];
	while ((c = getopt(argc,argv,"st:")) != -1){
		switch (c)
		{
			case 's':
				s_flag = 1;
				break;
			case 't':
				if(strtoul(optarg, &tmp, 10) >= MIN_TAB_SZ){
					tabsz = strtoul(optarg, &tmp, 0);
				}
		}
	}
	
	
	// TODO: initialze htable
	// using calloc so all buckets are initialized to NULL
	node **htable = calloc(tabsz, sizeof(node));
	if (htable == NULL) {
		return EXIT_FAILURE;
	}
	
	// TODO: get filename and call load_table;
	

	if (load_table(htable, tabsz, filename) == -1 /* TODO: call load_table and check if it succeeded */) {
		fprintf(stderr, "error in load_table\n");
		free(htable);
		return EXIT_FAILURE;
	}
	
	size_t bufsz = 0;
	char *buf = NULL; 
	int num = 0;
	// read one line at a time from stdin, do a lookup for that id
	// 
	ssize_t bytes;
	while ((bytes = getline(&buf, &bufsz, stdin)) > 0) {
		// replace the \n, if it exists (for hashing)
		if (buf[bytes - 1] == '\n') buf[bytes - 1] = '\0';
		char *id = buf;
		unsigned long cur_bin = (hash(id)) % tabsz;
		// TODO: read a line from stdin and perform a lookup
		// if the tree is found, print its x and y to stdout
		// using QUERY_SUCCESS_FORMAT
		
		node *n_tmp = node_lookup(htable[cur_bin],id);
		if(n_tmp == NULL){
			printf(QUERY_FAILURE_FORMAT,id);
		}
		else{
			printf(QUERY_SUCCESS_FORMAT,n_tmp->id,n_tmp->xcoord,n_tmp->ycoord);
			num++;
		}
		// if the tree is not found, print a message to **stdout**
		// using QUERY_FAILURE_FORMAT
		//
		// keep track of the number of successful queries
	}
	printf("%d successful queries\n", num /* TODO: fill in */);

	// if -s called then print stats
	if (s_flag == 1) {
		// TODO: output the stats 
		print_info(htable, tabsz);	
	}

	// TODO: free all allocated memory associated with the table 
	// using delete_table()
	
	delete_table(htable,tabsz);
	free(buf);  // free the buffer allocated by getline()

	return EXIT_SUCCESS;
}



