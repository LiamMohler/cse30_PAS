PA4 is a CSV file lookup. It will parse through a CSV file (id,xcoord,ycoord), store the data (hash table with separate chaining), then allow the user to query it through the id value in near constant time.

----------------
Example usage:
$ ./tree_lookup tiny.csv -s -t 10

BBBPIPO-1-2015
found tree id=BBBPIPO-1-2015, x=26.04204, y=79.45830
BBBPIPO-1-2010
could not find tree with id=BBBPIPO-1-2010
BBBPIPO-1-1954
found tree id=BBBPIPO-1-1954, x=9.33805, y=99.24527
2 successful queries
Table size: 10
Total entries: 5
Longest chain: 1
Shortest chain: 0
Empty buckets: 5



----------------
$ ./tree_lookup .... -> (how to use)

1) filename: Input the CSV file name (required)
2) -s: Prints descriptive metadata. (optional)
3) -t: An integer specifying the size to be used to create the hash table, if not input will use default. (optional)
