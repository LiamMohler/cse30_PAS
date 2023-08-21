#include <stdio.h>
#include <stdlib.h>
const char* USAGE_ERROR = "Usage %s starting_number\n";
const char* OUT_OF_BOUNDS_ERRORS ="argument %lld must be > 0 and less than or equal to 2,147,483,647\n";
const char* STOP_TIME = "n = %lld has a stopping time of %d\n";

unsigned int
compute(unsigned long long num){
  //TODO: Implement the recursive Collatz
 	unsigned int count = 0;
	while(num!=1){
		if(num%2 == 0){
			num/=2;
		}
		else{
			num*=3;
			num+=1;
		}
		count++;
	}
	return count;
}

int
main(int argc, char **argv){
  //TODO: Implement input processing
	if(argc != 2){
		fprintf(stderr, USAGE_ERROR, argv[0]);
		return EXIT_FAILURE;
	}
	unsigned long long n = atoll(argv[1]);
	if(n <=0 || n>2147483647ll){
		fprintf(stderr, OUT_OF_BOUNDS_ERRORS, n);
		return EXIT_FAILURE;
	}
  //TODO: Get stopping time
  unsigned int stopping = compute(n);
  printf(STOP_TIME, n, stopping);
}
