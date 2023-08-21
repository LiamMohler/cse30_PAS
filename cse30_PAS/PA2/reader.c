#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 256
int main(int argc, char **argv)
{

    int in_cols = 0; 
    int out_cols = 0; 

    
    char *readbuffer = NULL; 

    char **buf = NULL; 
    int *obuf = NULL;  

    unsigned int linecnt = 0;   
    unsigned int lngst_fld = 0; 

    int stats_flag = 0; 

    
    int c;
   	while ((c = getopt(argc, argv, "sc:")) != -1)
        switch (c)
	{
	case 'c':
		if(optarg == NULL){
			break;
		}
		in_cols = atoi(optarg);
        	break;
	case 's':
		stats_flag = 1;
	      	break;	
        default:
            abort();
        }
    

  
	out_cols = argc - 3 - stats_flag;
	// this will set outcols, however need to figure out how to use optind, use optind to skip lines
	obuf = (int*)malloc(out_cols*sizeof(int));
	// this will create the obuf array size, however still need to set the value of it.
	
	int curO = 0;
	while(argv[optind] != NULL){
		*(obuf+curO) = atoi(argv[optind]);
		curO++;
		optind++;
	}
	buf = (char**)malloc(in_cols*sizeof(char *));
	unsigned int len = 0;
	int after_char = 0;
	int curBuf = 0;
	unsigned int curLong = 0;
	while(getline(&readbuffer, &len, stdin) != -1){
		after_char = 0;
		while(*readbuffer != '\0'){
			if(*readbuffer == '\n'){
				if(after_char == 1){
					linecnt++;
					*readbuffer = '\0';
					curBuf = 0;
					//will print 
					for(int i = 0; i < out_cols;i++){
						if(i < out_cols-1){
							//print with space
							printf("%s ", *(buf+(*(obuf+i))));
						}
						else{
							//print w/o space
							printf("%s", *(buf+(*(obuf+i))));
						}
					}
					printf("\n");
					after_char = -1;
					break;
				}
				else{
					linecnt++;
                                        curBuf = 0;
					//will print
					for(int i = 0; i < out_cols;i++){
                                                if(i < out_cols-1){
                                                        //print with space
                                                        printf("%s ", *(buf+(*(obuf+i))));
                                                }
                                                else{
                                                        //print w/o space
                                                        printf("%s", *(buf+(*(obuf+i))));
                                                }
                                        }
                                        printf("\n");
					after_char = -1;
					break;
				}
			}
			else if((after_char == 1) && (*readbuffer == '\t' || *readbuffer == ' ')){
				*readbuffer = '\0';
				after_char = 0;
				curLong = 0;
			}
			else if(after_char == 0 && !(*readbuffer == '\t' || *readbuffer == ' ')){
				*(buf+curBuf) = &(*readbuffer);
				curBuf++; 
				after_char = 1;
				curLong = 0;
			}
			readbuffer++;
			curLong++;
			if(curLong > lngst_fld){
				lngst_fld = curLong;
			}
		}
	}


	if(after_char != -1)
	{
		linecnt++;
		for(int i = 0; i < out_cols;i++){
                                                if(i < out_cols-1){
                                                        //print with space
                                                        printf("%s ", *(buf+(*(obuf+i))));
                                                }
                                                else{
                                                        //print w/o space
                                                        printf("%s", *(buf+(*(obuf+i))));
                                                }
                                        }
                                        printf("\n");
	}
	


    /* use this line to print out the statistics when -s flag is set */
    if(stats_flag == 1){
	printf("Number of lines: %d\nLongest field: %d characters\n", linecnt, lngst_fld);
    }
    free(obuf);
    free(buf);
}
