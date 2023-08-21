#include <stdio.h>
#include <limits.h>
#include "node.h"

#define TABSZ_MSG "Table size: %lu\n"
#define TOTAL_ENTRIES_MSG "Total entries: %lu\n"
#define LONGEST_MSG "Longest chain: %lu\n"
#define SHORTEST_MSG "Shortest chain: %lu\n"
#define EMPTY_MSG "Empty buckets: %lu\n"
#define TREES_WITHIN_REGION_MSG "Total trees within given region: %lu\n"


void print_info(node **htable, unsigned long tabsz) {
	// TODO: walk down the indices of the htable
	// iterate through each chain and update statistics
	// print out statistics at end
	//
	// NOTE: all your statistics variables should be of type
	// unsigned long
	//
	// NOTE: you may use ULONG_MAX if you want
	// (maximum value for unsigned long int)
	unsigned long total_ent = 0;
	unsigned long long_chain = 0;	
	unsigned long short_chain = ULONG_MAX;
	unsigned long empty_buckets = 0;
	for(int i = 0; i < (int) tabsz;i++){
		node *t_list = htable[i];
		unsigned long cur_chain = 0;
		while(t_list != NULL){
			total_ent++;
			cur_chain ++;
			t_list = t_list->next;
		}
		if(cur_chain < short_chain){
			short_chain = cur_chain;
		}
		if(cur_chain > long_chain){
			long_chain = cur_chain;
		}
		if(cur_chain == 0){
			empty_buckets ++;
		}
	}
	printf(TABSZ_MSG,tabsz);
	printf(TOTAL_ENTRIES_MSG, total_ent);
	printf(LONGEST_MSG, long_chain);
	printf(SHORTEST_MSG, short_chain);
	printf(EMPTY_MSG, empty_buckets);

}
