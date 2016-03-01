/*
Steven Ou
7/23/2014
Summer CS 47
001876135
Project 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

int b_search(char list[100][20], int count, char* token)
{
	__asm
	{
		// Initialize register rows
		mov esi, 0;			// Tail array
		mov ebx, 0;			// ROW counter
		mov ecx, 0;			// COLUMN counter
		mov edi, count;		// Head array
		sub edi, 1;			// offset by 1, array notation

		// Special shifts and pre-setup
	evenShift:
		mov ebx, edi;		// set ebx to Head	
		sub ebx, esi;		// subtract Head by Tail
		cmp ebx, 0;				// check to see if the difference is 0
		je returnNull;			// go to returnNull if difference is 0
		shr ebx, 1;			// divide difference into half
		add ebx, esi;		// add tail to the half
		imul ebx, 20;		// multiply this index by 20
		jmp setUp;			// time to setup list and token
	oddShiftUp:
		mov ebx, edi;		// set ebx to Head
		add ebx, 1;			// add 1 to ebx
		sub ebx, esi;		// subtract Head by Tail
		cmp ebx, 0;				// check to see if the difference is 0
		je returnNull;			// go to returnNull if difference is 0
		shr ebx, 1;			// divide difference into half
		add ebx, esi;		// add tail to the half
		imul ebx, 20;		// multiply this index by 20
		jmp setUp;			// time to setup list and token
	oddShiftDown:
		mov ebx, edi;		// set ebx to Head
		sub ebx, 1;			// subtract 1 to ebx
		sub ebx, esi;		// find the difference between Head and Tail
		cmp ebx, 0;				// check to see if the difference is 0
		je returnNull;			// go to returnNull if difference is 0
		shr ebx, 1;			// divide difference by 2
		add ebx, esi;		// add Tail to difference to get the correct index
		imul ebx, 20;		// multiply index by 20 to get the correct row
		jmp setUp;			// go to setUp

		// Setting up the list and tokens to prepare for comparisons
	setUp:
		mov edx, token;						// put token into edx
		mov dl, byte ptr[edx + ecx];		// set dl as the char in token to be compare with
		add ecx, ebx;						// increase counter by row
		mov eax, list;						// put list into eax
		mov al, byte ptr[eax + ecx];		// set al as the char in list to be compare with
		sub ecx, ebx;						// revert counter back to original value
		cmp al, 0;							// check to see list char is null or not
		je compareNull;						// go to compareNull if list char is null
		cmp dl, 0;							// check to see token char is null or not
		je shiftDown;						// go to shiftDown if it's null
		jmp compare0;						// go to compare0 if token and list are not null

		// Final outputs
	compareNull:
		cmp dl, 0;							// check to see if token char is null
		je returnIndex;						// go to returnIndex if token char is null
		jmp shiftUp;						// go to shiftUp
	returnNull:
		cmp esi, 0;							// check to see if Tail is 0
		je compareSpecial;					// go to compareSpecial if it is
		mov eax, 0;							// output 0 or token not found
		jmp done;							// exit program
	absoluteNull:
		mov eax, 0;							// output 0 or token not found
		push 0;								// complete the same number of push and pop operation
		jmp done;							// exit program
	returnIndex:
		mov eax, ebx;		// set numerator ebx into eax
		mov ebx, 20;		// set denominator 20 to ebx
		mov edx, 0;			// set remainder holder to 0
		idiv ebx;			// divide numerator eax by denominator ebx
		add eax, 1;			// add 1 to the result of the division
		jmp done;			// exit program

		// Comparisons
	compare0:
		or al, 100000b;		// convert list to lowercase
		or dl, 100000b;		// convert token to uppercase
		cmp dl, al;			// compre token with list
		jg shiftUp;			// go to shift up if token is greater than list
		je increment;		// go to increment if token is equal to list
		jl shiftDown;		// go to shiftDown if token is less than list
	compareSpecial:
		mov ebx, 0;			// set Row to 0
		mov ecx, 0;			// set Counter to 0
		pop eax;			// pop the first value from stack into eax
		cmp eax, 100;		// check if the value poped is 100
		je absoluteNull;	// go to absoluteNull if it is
		push 100;			// otherwise push 100 onto stack
		jmp setUp;			// go to setUp

		// Binary shifting: up, down, or stay
	shiftUp:
		mov ecx, 0;			// reset counter to 0
		mov eax, ebx;		// setup the index*20 into eax as numerator
		mov ebx, 20;		// set denominator as 20
		mov edx, 0;			// make sure remainder register is free
		idiv ebx;			// divide numerator by denominator
		mov ebx, eax;		// put the truncated value into ebx, this will be the correct index
		mov esi, ebx;		// put the index value into Tail
		mov ebx, edi;		// put Head into ebx
		sub ebx, esi;		// find the difference between Head and Tail
		cmp ebx, 0;				// check to see if the difference is 0
		je returnNull;			// go to returnNull if difference is 0
		and ebx, 1;			// find the parity of the difference
		cmp ebx, 1;			// check to see if it's odd or not
		je oddShiftUp;		// go to oddShift if it's odd
		jmp evenShift;		// go to evenShift if it's even	
	increment:
		INC ecx;			// increase counter by 1
		jmp setUp;			// time to setup the new list and new token
	shiftDown:
		mov ecx, 0;			// reset Column counter to 0
		mov eax, ebx;		// setup the index*20 into eax as numerator
		mov ebx, 20;		// set denominator as 20
		mov edx, 0;			// make sure remainder register is free
		idiv ebx;			// divide numerator by denominator
		mov ebx, eax;		// put the truncated value into ebx, this will be the correct index
		mov edi, ebx;		// set Head to index, because we are shifting down
		mov ebx, edi;		// put Head into ebx
		sub ebx, esi;		// find the difference between Head and Tail
		cmp ebx, 0;				// check to see if the difference is 0
		je returnNull;			// go to returnNull if difference is 0
		and ebx, 1;			// mod difference by 2 to see if it's even or odd
		cmp ebx, 1;			// compare difference to 1 to check for parity
		je oddShiftDown;	// go to evenShift if it's even	
		jmp evenShift;		// go to evenShift, since shiftDown doesn't care for parity
	done:
	}
}

int main(int argc, char** argv)
{
	char list[100][20], *token;
	FILE *fptr;
	int id = 0;
	int i = 0;

	if (argc != 3)
	{
		printf("Usage: %s filename token\n", argv[0]);
		return 1;
	}

	token = argv[2];

	printf("\n");

	fptr = fopen((argv[1]), "rtc");
	if (fptr == NULL)
		printf("File %s was not opened\n", argv[1]);
	else
	{
		/* Set pointer to beginning of file: */
		fseek(fptr, 0L, SEEK_SET);

		/* Read data from file: */
		while (fscanf(fptr, "%s", &list[i]) != EOF)
		{
			printf("%s ", list[i]);
			i++;
		}

		printf("\n\nNumber of names = %d\n", i);
		printf("Search Token = %s\n", token);
		fclose(fptr);
	}

	id = b_search(list, i, token);

	if (id)
		printf("Search token is in the number %d position.\n", id);
	else
		printf("Search token is not found.\n");

	return 0;
}
