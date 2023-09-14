/*	ENG175IN	Summer 2020
 *
 *	Inspiratrion from programmingsimplified.com. Helped to understand how bubble sorting worked.
 *
 *	Author:	Quynn Bell
 *
 *	Date Created:	25th of June 2020
 *
 *	Copyright @Qbell.	All Rights Reserved.
 *
 *	Program Function:	Bubble Method Integer Sorter
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>

char userRestart;

void Banner();
void SmallToLarge(int userNum);
void LargeToSmall(int userNum);

int main(void) {

	int userNum, userMenu;

	Banner();

	printf("Program: Bubble Method Integer Sorter\n\n");
	printf("This program will ask you how many numbers you would like to sort and then the program will also ask you how you would like the numbers sorted.\n");

	do {

		printf("\n");
		printf("How many numbers would you like sorted?\n");
		printf("Please enter a positive integer: ");
		scanf("%d", &userNum);

		while (userNum < 1) { printf("Invalid Entry. Please enter positive integer: "); scanf("%d", &userNum); }

		while (userNum > 100) { printf("Invalid Entry. Outside the range of this sorter! Please enter smaller value: "); scanf("%d", &userNum); }

		printf("Available Sorting Methods:\n\n1 - Small-to-Large     2 - Large-to-Small\n\n");
		printf("Please enter your choice: ");
		scanf("%d", &userMenu);

		while (userMenu < 1 || userMenu > 2) { printf("Invalid Entry. Please enter either (1 /2): "); scanf("%d", &userMenu); }

		switch (userMenu) {

		case 1:
			// Small-to-Large
			SmallToLarge(userNum);
			break;

		case 2:
			// Large-to-Small
			LargeToSmall(userNum);
			break;

		}

		// asking user if they want to restart program
		printf("Do you wish to restart the program? (Y / N) ");
		scanf(" %c", &userRestart);


		// checking and validating user's response is either Y or N
		while ((userRestart != 'N') && (userRestart != 'n') && (userRestart != 'Y') && (userRestart != 'y')) {
			printf("Invalid Entry. Please enter Yes or No (Y / N) ");
			scanf(" %c", &userRestart);
		}


		// if user wants to exit, break from loop an exit. else continue the loop.
		if ((userRestart == 'N') || (userRestart == 'n')) {
			printf("\nGoodbye.\n\n");
			break;
		}
		else {
			printf("\n------------------------------------------------------------------------------------------------------------------------\n");
			continue;
		}

	} while ((userRestart == 'Y') || (userRestart == 'y'));  // will restart loop if user entered Y.

	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	return 0;
}

void Banner() {
	/*
	

o.oOOOo.          o     o     o             .oOOOo.
 o     o         O     O     O              o     o
 O     O         O     O     o              O.                      O
 oOooOO.         o     o     O               `OOoo.                oOo
 o     `O O   o  OoOo. OoOo. o  .oOo.             `O .oOo. `OoOo.   o   .oOo. `OoOo.
 O      o o   O  O   o O   o O  OooO'              o O   o  o       O   OooO'  o
 o     .O O   o  o   O o   O o  O           O.    .O o   O  O       o   O      O
 `OooOO'  `OoO'o `OoO' `OoO' Oo `OoO'        `oooO'  `OoO'  o       `oO `OoO'  o

	
	*/
	printf("\033[0;34m");
	printf("\no.oOOOo.          o     o     o             .oOOOo.\n");
	printf(" o     o         O     O     O              o     o\n");
	printf(" O     O         O     O     o              O.                      O\n");
	printf(" oOooOO.         o     o     O               `OOoo.                oOo\n");
	printf(" o     `O O   o  OoOo. OoOo. o  .oOo.             `O .oOo. `OoOo.   o   .oOo. `OoOo.\n");
	printf(" O      o o   O  O   o O   o O  OooO'              o O   o  o       O   OooO'  o\n");
	printf(" o     .O O   o  o   O o   O o  O           O.    .O o   O  O       o   O      O\n");
	printf(" `OooOO'  `OoO'o `OoO' `OoO' Oo `OoO'        `oooO'  `OoO'  o       `oO `OoO'  o\n\n");
	printf("\033[0m");
	return;
}

void SmallToLarge(int userNum) {

	int i, j, k, swap;
	int userArray[100];

	printf("You chose to sort by Small-to-Large!\n\n");
	printf("Please enter %d integers\n", userNum);

	for (i = 0; i < userNum; i++) {
		printf("[%d]: ", i + 1);
		scanf("%d", &userArray[i]);
	}

	for (i = 0; i < userNum - 1; i++) {
		for (j = 0; j < userNum - i - 1; j++) {
			if (userArray[j] > userArray[j + 1]) {
				swap = userArray[j];
				userArray[j] = userArray[j + 1];
				userArray[j + 1] = swap;
			}
		}
	}

	printf("\nSmall-to-Large Sorted List:\n");

	for (i = 0; i < userNum; i++) {
		printf("[%d]: %d\n", i + 1, userArray[i]);
	}
	printf("\n");

	return;
}

void LargeToSmall(int userNum) {

	int i, j, k, swap;
	int userArray[100];

	printf("You chose to sort by Large-To-Small!\n\n");
	printf("Please enter %d integers\n", userNum);

	for (i = 0; i < userNum; i++) {
		printf("[%d]: ", i + 1);
		scanf("%d", &userArray[i]);
	}

	for (i = 0; i < userNum - 1; i++) {
		for (j = 0; j < userNum - i - 1; j++) {
			if (userArray[j] < userArray[j + 1]) {
				swap = userArray[j];
				userArray[j] = userArray[j + 1];
				userArray[j + 1] = swap;
			}
		}
	}

	printf("\nLarge-to-Small Sorted List:\n");

	for (i = 0; i < userNum; i++) {
		printf("[%d]: %d\n",i + 1, userArray[i]);
	}
	printf("\n");

	return;
}