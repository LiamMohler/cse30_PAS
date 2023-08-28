/**
 * Assignment: life
 * Name:TODO
 * PID :TODO
 * Class: UCSD CSE30-SP21
 *
 */
#ifndef _BOARD_H
#define _BOARD_H
#include "cse30life.h"

// we can change the board type to different sizes to see how this affects the speed.
// DO NOT CHANGE - libcse30life library assumes unsigned char
typedef unsigned char belem;


typedef struct boards boards_t;
struct boards {
	belem *bufferA;			// pointer to first life board buffer
	belem *bufferB;			// pointer to second life board buffer
	size_t numRows;		// number of rows in the life board
	size_t numCols;		// number of cols in the life board
	belem *currentBuffer;	// pointer to the current life board's buffer 
	belem *nextBuffer;		// pointer to the next iteration's board buffer
	unsigned int gen;			// generation number   
};

extern boards_t *createBoard(char *filename);		// create a board structure
extern void deleteBoard(boards_t **);				// delete a board structure
extern void clearBoards(boards_t *self);			// clear the boards (current and next)
extern void swapBuffers(boards_t *self);			// swap the board current and next
extern void simStep(boards_t *self, unsigned int steps);		// simulate one step


extern void setSim(boards_t *self, void (*sim)(boards_t *self, unsigned int steps));
//extern void setSim(boards_t *self, void (*sim)(belem *, belem *, unsigned int, unsigned int, unsigned int));

extern size_t getIndex(size_t numCols, size_t row, size_t col);	// get index of (row,col) in 1D buffer

#endif // _BOARD_H
