//file header
    .arch armv6     //armv6 architecture
    .arm            //arm 32-bit IS
    .fpu vfp        //floating point co-processor
    .syntax unified //modern syntax

//definitions applying to the entire source file
    //.equ EXAMPLE_DEF, 0xff

    //.data         //uncomment if needed

    .text           //start of text segment

    .global fpconvert               //make fpconvert global for linking to
    .type   fpconvert, %function    //define fpconvert to be a function
    .equ 	FP_OFF, 32 	            //fp offset distance from sp (# of saved regs - 1) * 4

fpconvert:
// function prologue - do not edit this part
    push    {r4-r10, fp, lr}    // save registers to stack
    add     fp, sp, FP_OFF      // set frame pointer to frame base

// you can use any of r0-r10 inclusive
// R0 is the parameter to the function
// the last value of R0 is the value
// returned from the function
// ==========================================================================
// YOUR CODE GOES IN THE SECTION BELOW
// ==========================================================================
	AND R10,R0,0x00000800 //this will give the MSB and store in R10 (need to LSL)
	LSL R10, 20 //move it to the far left



	AND R8,R0,0x0000003F //this will give the mantissa and store in R8 (nee$



	AND R9,R0,0x000007C0 //this will give the exponent part and store in R9
	LSR R9,6 // move to right

	MOV R0, 0x00000000 // reset R0

	CMP R9,0x0000001F // check if its all 1's
	BNE .Lnum1//if its not then we want to skip this portion


	//add code to call infinity fucntion
	MOV R2, R8
	BL convert_infinity 

//need to pass in the mantissa, then add in implied 1's for exp and move mantissa, return, then will send to end to add on MSB


	B .Lskip2
	.Lnum1:

	CMP R9, 0x00000000 //check if all 0's
	BNE .Lnum2

	CMP R8, 0x00000000 //check if mantissa all 0
	BEQ .Lskip

	.LWhileL:
	AND R5, R8, 0x00000020
	CMP R5, 0x00000020
	BEQ .Lin
	
	LSL R8, 1
	SUB R9, R9, 1
	B .LWhileL


	.Lin: 
	LSL R8, 1
	SUB R9, R9, 1	
	//add code for when its all 0
	//check for if mantissa next is 1. if it is then add one to offset
	//while (R9 AND 00000020 != 0)
	//add and shift mantissa one to left.
	//then at the end add one



	.Lnum2:

	ADD R9, R9, 112 // add the offset

	//this needs to be moved for all of them
	LSL R9, 23 // Move it to where EXP should be
	LSL R8, 17 // move left
	MOV R0, R8
	.Lskip: // skip to end so only combine MSB and EXP
	ADD R0, R0, R9
	.Lskip2:
	ADD R0, R0, R10

// ==========================================================================
// function epilogue - do not edit
    sub	sp, fp, FP_OFF
    pop     {r4-r10, fp, lr}     // MUST MATCH LIST IN PROLOG'S PUSH
    bx      lr                   // return

// function footer
    .size fpconvert, (. - fpconvert) // set size for function

// ==========================================================================

    .global convert_infinity
    .type   convert_infinity, %function
    .equ    FP_OFF, 32
// make a 32-bit IEEE +Inf or -Inf
convert_infinity:	
// function prologue (do not edit)
    push    {r4-r10, fp, lr}    // save regs
    add     fp, sp, FP_OFF
// you can use any of r0-r10 inclusive
// R0 is the parameter to the function
// the last value of R0 is the value
// returned from the function
// r4-r10 are local to this function
// changes to these values will not be reflected
// in the main function.

// ==========================================================================
// YOUR CODE GOES IN THE SECTION BELOW
// ==========================================================================

	//idk why this is even needed
	LSL R2, 17
	ORR R0,R0,R2
	ORR R0, R0, 0x7F000000
	ORR R0,R0,0x00800000
	BX LR


// ==========================================================================
// function epilogue (do not edit)
    sub	sp, fp, FP_OFF
    pop     {r4-r10, fp, lr}    // restore regs
    bx      lr                  // return
// function footer
    .size convert_infinity, (. - convert_infinity)

//file footer
    .section .note.GNU-stack,"",%progbits // stack/data non-exec (linker)
.end
