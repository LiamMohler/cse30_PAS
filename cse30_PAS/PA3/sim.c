/**
 * Assignment: life
 * Name: Liam Mohler
 * PID: A17432488
 * Class: UCSD CSE30-SP21
 *
 */
#include "sim.h"

#define CIMP
extern void asm_doRow(belem *, belem *, size_t, size_t, size_t);

/**
 * gets x mod N (works for negative numbers as well! Use this instead of %)
 */
size_t getModVal(int x, size_t N){
     size_t adj = x/N;

     return((x+adj*N)%N);
}

/**
 * process one row of the board
 */
static void doRow(belem *dest, belem *src, size_t row, size_t rows, size_t cols){
  // TODO:
	for(size_t i = 0; i < cols; i++){
		unsigned int N = 0, S = 0, E = 0, W = 0, NE = 0, NW = 0, SE = 0, SW = 0;
		E = src[ ((getModVal(row, rows) * cols) + (getModVal(i+1,cols))) ];
		W = src[ ((getModVal(row, rows) * cols) + (getModVal(i-1,cols))) ];
		N = src[ ((getModVal(row-1, rows) * cols) + (getModVal(i,cols))) ];
		S = src[ ((getModVal(row+1, rows) * cols) + (getModVal(i,cols))) ];
		NE = src[ ((getModVal(row-1, rows) * cols) + (getModVal(i+1,cols))) ];
		SE = src[ ((getModVal(row+1, rows) * cols) + (getModVal(i+1,cols))) ];
		NW = src[ ((getModVal(row-1, rows) * cols) + (getModVal(i-1,cols))) ];
		SW = src[ ((getModVal(row+1, rows) * cols) + (getModVal(i-1,cols))) ];
		unsigned int numAlive = (unsigned int) N +(unsigned int) S +(unsigned int) E +(unsigned int) W +(unsigned int) SE +(unsigned int) SW +(unsigned int) NW + (unsigned int)NE;
		if(src[row*cols + i] == 1){
			if (numAlive < 2){
				dest[row*cols + i] = 0;
			}
			else if (numAlive < 4){
				dest[row*cols + i] = 1;
			}
			else{
				dest[row*cols + i] = 0;
			}
		}
		else if (src[row*cols + i] == 0){
			if (numAlive == 3){
				dest[row*cols + i] = 1;
			}
			else{
				dest[row*cols + i] = 0;
			}
		}
	}
}


/**
 * perform a simulation for "steps" generations
 *
 * for steps
 *   calculate the next board
 *   swap current and next
 */
void simLoop(boards_t *self, unsigned int steps){
  // TODO:
	for(unsigned int i = 0; i < steps ; i++){
		int numR = self->numRows;
		int numC = self->numCols;
		for(int j = 0; j < numR; j++){
			doRow(self->nextBuffer, self->currentBuffer, j, numR, numC);	
		}
		swapBuffers(self);
		(self->gen)++;
	}

}
