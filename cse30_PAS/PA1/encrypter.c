#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]) {
  unsigned int n = atoi(argv[2]);
  FILE* fin = fopen(argv[1],"r");
  if(argc != 3){
	fprintf(stderr,"Error, expected two arguments\n");
	return EXIT_FAILURE;
  }
  if(fin == NULL) {
    perror("Could not open input file.");
    return 1;
  }
  int c;
  while((c = fgetc(fin)) != EOF){
	//printf("%c",c);
	if(c >= 'A' && c <= 'Z'){
		//printf("%c",c);
		c = c + n;
		if(c > 'Z'){
			c = c - 26;
		}
	}
	else if(c >= 'a' && c <= 'z'){
		c = c + n;
		if(c > 'z'){
			c = c - 26;
		}
	}
	printf("%c",c);
  }
 
  fclose(fin);

  return 0;
}
