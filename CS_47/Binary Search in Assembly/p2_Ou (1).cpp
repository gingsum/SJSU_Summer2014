/*
Steven Ou
CS 47
7 / 9 / 2014
Project 2
ID: 001876135
*/

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

int sorter(int* list, int count, int opcode)
{
	__asm
	{
		mov eax, 0;		 zero out the result
		mov ebx, opcode; move opcode to ebx for comparison

		mov eax, count; // array length
		mov ebx, list;  // array list
		mov esi, 1;		// inner loop counter
		mov edi, 0;	    // outter loop counter
		jmp sort0;		// jump to sort0

	sort0:							// setup values to be compare with and check for ascending or descending
		mov ecx, [ebx + edi * 4];	// put the initial value into ecx
		mov edx, [ebx + esi * 4];	// put the compare value into edx
		DEC eax;					// lower count by 1
		cmp opcode, 1;				// check if it should sort ascending or descending order
		je sortA;					// if ascending, jump to sortA
		jmp sortB;					// if decending, jump to sortB

	sortA:				// ascending comparison
		cmp ecx, edx;	// compare initial value with a value in the array
		jg swap0;		// if value in array is smaller, swap (ascending sort)
		jmp sort1;		// jump to sort1

	sortB:				// descending comparison
		cmp ecx, edx;	// compare initial value with a value in the array
		jl swap0;		// if value in array is bigger, swap (descending sort)
		jmp sort1;		// jump to sort1

	sort1:				// inner loop checker
		cmp eax, 1;		// checks to see if inner loop is at the end
		jle sort2;		// if count is less than or equal to 1, jump to sort2
		INC esi;		// compare the next value in the array by incrementing esi by 1
		jmp sort0;

	sort2:				// outter loop checker
		INC edi;		// use the next initial array value by increasing edi by 1
		mov esi, edi;	// put esi equal to edi to start the comparison at the same spot
		cmp edi, count; // check if outter loop is at the end
		jge done;		// if outter loop greater or equal to array size, jump to done
		mov eax, count;	// put array length into eax
		sub eax, edi;	// subtract array length by the starting initial array position
		add eax, 1;		// add one to offset for ascending sort, works for descending sort
		jmp sort0;		// jump to sort0

	swap0:							// swapping time
		mov[ebx + edi * 4], edx;	// puts comparison value from edx into initial position of array
		mov[ebx + esi * 4], ecx;	// puts initial position value into comparison position of array
		jmp sort1;					// jump to sort1
	done:				// sorting is complete
	}

}

int main(int argc, char** argv)
{
	int numlist[1000], asc;
	FILE *fptr;

	int i = 0;

	if (argc != 3)
	{
		printf("Usage: %s filename asc_des\n", argv[0]);
		return 1;
	}

	asc = atoi(argv[2]);
	asc = (asc == 1) ? 1 : 2;

	printf("\n");

	fptr = fopen((argv[1]), "rtc");
	if (fptr == NULL)
		printf("File %s was not opened\n", argv[1]);
	else
	{
		/* Set pointer to beginning of file: */
		fseek(fptr, 0L, SEEK_SET);

		/* Read data from file: */
		while (fscanf(fptr, "%d", &numlist[i]) != EOF)
		{
			printf("%d ", numlist[i]);
			i++;
		}

		printf("\n\nNumber of integer = %d\n", i);
		printf("Ascend_or_Descend = %d\n\n", asc);
		fclose(fptr);
	}

	sorter(numlist, i, asc);

	for (int j = 0; j < i; j++)
		printf("%d ", numlist[j]);

	printf("\n");

	return 0;
}