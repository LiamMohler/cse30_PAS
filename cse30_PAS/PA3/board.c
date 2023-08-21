/**
 * Assignment: life
 * Name :Liam Mohler
 * PID: A17432488
 * Class: UCSD CSE30-SP21
 *
 */
#include "cse30life.h"
#include "board.h"


/**
 * create a new board
 *
 * - malloc a boards structure
 * - set the generation to 0
 * - open the file (if it doesn't exist, return a NULL pointer
 * - read the first line which is the number of rows
 * - read the second line which is the number of cols
 * - set the # of rows and # of cols in the boards structure
 * - malloc bufferA and bufferB 
 * - Set currentBuffer and nextBuffer
 * - clear both board buffers
 * - read the file until done.  each row contains a row and a columns separted by
 *   white space
 *     for each line, set the cell in the current buffer
 * - close the file
 * - return the boards pointer if successfull or NULL ptr otherwise
 */
boards_t * createBoard(char *initFileName){
  // TODO:
	FILE *fp;
	if((fp = fopen(initFileName, "r")) == NULL){
		return NULL;
	}
	boards_t *new_b;
       	new_b = malloc(sizeof(boards_t));
	
	if(new_b == NULL) return NULL;
	int numR;
	int numC;
	
	//maybe make it count errors
	fscanf(fp, "%d", &numR);
	fscanf(fp, "%d", &numC);
	new_b->numRows = numR;
	new_b->numCols = numC;
	new_b->bufferA = malloc(numR*numC*sizeof(unsigned char));
	new_b->bufferB = malloc(numR*numC*sizeof(unsigned char));
	new_b->currentBuffer = new_b->bufferA;
	new_b->nextBuffer = new_b->bufferB;	
	clearBoards(new_b);
	//edit numR and numC
	//malloc the space
	//then below here we can actually set the correct indicies
	int numOne;
	int numTwo;
	while(fscanf(fp, "%d %d", &numOne, &numTwo) > 0){
		//edit it board at these places
		int idx = getIndex(numC,numOne,numTwo);
		*(new_b->bufferA+idx) = 1;
	}
 	fclose(fp); 
	return new_b;
}



/**
 * delete a board
 */
void deleteBoard(boards_t **bptrPtr){
  // TODO:
  	free((*bptrPtr)->bufferA);
	free((*bptrPtr)->bufferB);

	free(*bptrPtr);
	*bptrPtr = NULL;
}

/**
 * set all the belems in both buffers to 0
 */
void clearBoards(boards_t *self){
  // TODO:
  // loop through, maybe better to free then calloc
  	size_t size = (self->numRows)*(self->numCols);
	for(size_t i = 0; i<size; i++){
		self->bufferA[i] = 0;
		self->bufferB[i] = 0;
	}
}

/**
 * swap the current and next buffers
 */
void swapBuffers(boards_t *self){
  // TODO:
	belem *tmp1 = self->currentBuffer;
	belem *tmp2 = self->nextBuffer;

	self->nextBuffer = tmp1;
	self->currentBuffer = tmp2;
}


/**
 * get a cell index
 */
size_t getIndex(size_t numCols, size_t row, size_t col){
  // TODO:
	return row * numCols + col;
}
  
