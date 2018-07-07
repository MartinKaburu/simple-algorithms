/***********************************
*Rot-13 password encryption
*Source code by Martin Muguna
*Email: martinkaburu.m@gmail.com
*30-03-2018  01.07 AM
*********************************/
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

#define ENTER 13
#define BACKSPACE 8
char* _password();

int main(){
	FILE *fptr;
	if((fptr = fopen("passwords.txt", "a")) == NULL)
		fptr = fopen("passwords.txt", "w");
	printf("Enter password\n");
	char* password = _password();
	printf("\n%s\n", password);
	fprintf(fptr, "%s", password);
	return 0;
}

char* _password(){
	int i = 0;
	char* single_letter;
	single_letter = malloc(sizeof(char)*20);
	for(i = 0; i <= 20; i++){
		fflush(stdin);
		single_letter[i] = getch();
		if(single_letter[i] == ENTER)
			break;
		else if(single_letter[i] == BACKSPACE){
			printf("\b %c", BACKSPACE);
		}
		else
			printf("*");
	}
	single_letter[i] = '\0';
	printf("\n");
	return single_letter;
}
/*
*Work on the back-space 
*do a logic check for the length
*store encrypted passwords and read them from a file
*/