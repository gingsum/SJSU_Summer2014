/*
Steven Ou
7/31/2014
Summer CS 47
001876135
Project 4

encrypt.cpp - This file contains the code to encrypt and decrypt an input string
and output the modified string.
*/

#include "key.h"	/* Okay to use the 3 symbolic names inside key.h */
#include <string.h>

__declspec(dllexport) int s_encrypt(char *src, char* dest, int en_flag);


__declspec(dllexport) int s_encrypt(char *src, char* dest, int en_flag)
{
	/* !! Put your __asm code here !! */
	// direction, shiftcount, invertcase

	__asm
	{
		// setup registers for source, destination, converted char counter, and string char counter
		mov esi, src;			// move the source string pointer to esi
		mov edi, dest;			// move the destination string pointer to edi
		mov eax, 0;				// converted char counter
		mov ecx, 0;				// String char counter
	
		// setup encryption, direction, and shiftcount before starting String comparison
		cmp en_flag, 1;			// check to see if it's encryption or decryption
		je reverseDest;			// if decryption than jump to reverseDest
		jmp setShift;			// else jump to setShift
	reverseDest:
		xor direction, 1;		// decreyption mode by reversing directions
	setShift:
		cmp shiftcount, 26;		// check if shiftcount is over 26
		jge mod26;				// go to mod26 if shiftcount is over 26
		mov edx, shiftcount;	// put shiftcount into edx (later on truncate edx to dl since shiftcount is small)
		jmp checkNull;			// jump to checkNull
	mod26:
		sub shiftcount, 26;		// subtract shiftcount by 26 and jump
		jmp setShift;			// to setShift to see if it's still 26
	
		// this part checks to see if it's the end of the String, exit function if it is
	checkNull:
		mov bl, [esi + ecx];	// put src char in ecx index into bl register
		cmp bl, 0;				// see if the char is null
		jg checkBigA;			// if it's not null than jump to checkBigA
		jmp returnNull;			// go to returnNull if bl equals null
	returnNull:
		mov[edi + ecx], 0;		// set the rest of dest String to null to get rid of trash data
		jmp done;				// exit function
		
		// this part compares bl to the upper and lower case alphabets and determine it's case
	checkBigA:
		cmp bl, 65;				// compare bl to 'A'
		jl copyDest;			// if bl is less than 'A', ignore the rest and go to copyDest
		jge checkBigZ;			// otherwise go to checkBigZ
	checkBigZ:
		cmp bl, 90;				// compare bl to 'Z'
		jle checkDirectionUpper;// if bl is less than or equal to 'Z' go to checkDirectionUpper
		jg checkSmallA;			// otherwise go to checkSmallA
	checkSmallA:
		cmp bl, 97;				// compare bl to 'a'
		jl copyDest;			// if it's less than 'a', go directly to copyDest
		jge checkSmallZ;		// otherwise go to checkSmallZ
	checkSmallZ:
		cmp bl, 122;			// compare bl to 'z'
		jle checkDirectionLower;// if bl is less than or equal to 'z', go to checkDirectionLower
		jg copyDest;			// otherwise go to copyDest

		// after determining case, we check which direction we should shift bl
	checkDirectionUpper:
		add eax, 1;				// increment eax by 1
		cmp direction, 0;		// check if direction is forward
		je forwardUpper;		// if it is go to forwardUpper
		jg backwardUpper;		// otherwise go to backwardUpper
		mov eax, 404;		// error check in case direction is neither forward or backward
		jmp done;			// exit program if there's an error
	checkDirectionLower:
		add eax, 1;				// increment eax by 1
		cmp direction, 0;		// check if direction is forward 
		je forwardLower;		// if it is go to forwardLower
		jg backwardLower;		// otherwise go to backwardLower
		mov eax, 404;		// error check in case direction is neither forward or backward
		jmp done;			// exit program if there's an error
		
		// this part shifts bl by adding or subtracting dl
	forwardUpper:
		add bl, dl;				// add bl to dl which contains shiftcount
		cmp bl, 90;				// check to see if the shifted value is greater than 'Z'
		jg loopCeiling;			// go to loopCeiling if it is greater
		jle checkInvert;		// otherwise go to checkInvert
	backwardUpper:
		sub bl, dl;				// subtract bl by dl which contains shiftcount
		cmp bl, 65;				// check to see if the shifted value is smaller than 'A'
		jl loopFloor;			// if it is jump to loopFloor
		jge checkInvert;		// else go to checkInvert
	forwardLower:
		add bl, dl;				// add bl to dl which contains shiftcount
		cmp bl, 122;			// check to see if the shifted value is greater than 'z'
		jg loopCeiling;			// go to loopCeiling if it is greater
		jle checkInvert;		// otherwise go to checkInvert
	backwardLower:
		sub bl, dl;				// subtract bl by dl which contains shiftcount
		cmp bl, 97;				// check to see if the shifted value is smaller than 'a'
		jl loopFloor;			// if it is, go to loopFloor
		jge checkInvert;		// else go to checkInvert

		// this part loops to the beginning or the end of the alphabet depending on direction
	loopCeiling:
		sub bl, 26;				// looping to the beginning by subtracting bl by 26
		jmp checkInvert;		// go to checkInvert
	loopFloor:
		add bl, 26;				// looping to the end by adding bl by 26
		jmp checkInvert;		// go to checkInvert

		// this part check if bl needs to be inverted or not
	checkInvert:
		cmp invertcase, 0;		// compare invertcase to see if it's regular
		je copyDest;			// go to copyDest if it is
		xor bl, 100000b;		// otherwise invert bl by xor bl to 100000b
		jmp copyDest;			// go to copyDest

		// this part copy the result of bl into the converted String
	copyDest:
		mov [edi + ecx], bl;	// mov the converted bl into dest denoted by ecx places
		INC ecx;				// increment the ecx counter by 1
		jmp checkNull;			// jump to checkNull to begin checking the next char
	done:					// exit program
	}
}