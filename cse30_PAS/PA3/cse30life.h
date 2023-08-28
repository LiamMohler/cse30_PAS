//! CSE30-SP21
//! cse30life functions
//! functions to support life!

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdbool.h>

/**
 * time funcs
 */
//! start a time measurement
extern void startMeas();

//! stop a time measurement
extern void stopMeas();

//! get elapsed seconds
extern double getSecs();

/**
 *  predefined shapes
 */
//! create a glider
extern void glider(unsigned char *buf, size_t cols, size_t v, size_t h);   

//! create a toad
extern void toad(unsigned char *buf, size_t cols, size_t v, size_t h); 

//! create an acorn
extern void acorn(unsigned char *buf, size_t cols, size_t v, size_t h); 

//! create an oscillator horiz orient
extern void oscillator(unsigned char *buf, size_t cols, size_t v, size_t h);

//! create an oscillator vertical 
extern void oscillatorV(unsigned char *buf, size_t cols, size_t v, size_t h); 

/**
 * board printing
 */
//! print the board to the screen as ascii
extern void printAsciiBoard(unsigned char *buf, size_t rows, size_t cols, size_t gen);

//! dump board to a file
extern void dumpBoard(unsigned char *buf, size_t rows, size_t cols, const char *dumpFileName);