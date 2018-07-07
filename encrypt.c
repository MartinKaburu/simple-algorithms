/***********************************
*Rot-13 encryption
*Source code by Martin Muguna
*Email: martinkaburu.m@gmail.com
*5-03-2018  00.23 AM
*********************************/
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
	if(argc<2){
		printf("Too few arguments.\nInput file name\nUse 'help' or '--h' for help\n\a");
		return 1;
	}
	if((argc<3)&&((strcmp(argv[1], "help")!=0)||((strcmp(argv[1], "--h")!=0)))){
		printf("Too few arguments.\nInput file name\nUse 'help' or '--h' for help\n\a");
		return 1;
	}
	if(argc>3){
		printf("Too many arguments\nUse 'help' or '--h' for help\n\a");
		return 1;
	}
	if((strcmp(argv[1], "help")==0)||((strcmp(argv[1], "--h")==0)&&(argc==2))){
		printf("\nUsage:\ndecrypt [argv[1]] [argv[2]]\n");
		printf("[argv[1]\t\tinput file\n[argv[2]]\t\toutput file\nfor help:\t[argv[1]] = \"help\" or \"--h\" and [argv[2]] = 'NULL'\n");
		return 0;
	}
	if(((strcmp(argv[1], "help")!=0)||((strcmp(argv[1], "--h")!=0)))&&(argc==2)){
		printf("Too few arguments\nUse 'help' or '--h' for help\n");
		return 1;
	}
	FILE *fptr,*fptr2;
	int i, linecount, characters=0;
	char singleline[500];
	char temp[500];
	if((fptr=fopen(argv[1], "r"))==NULL){
		printf("Invalid isnput file \"%s\"\n", argv[1]);
		return 1;
	}
	fptr2=fopen(argv[2], "w");
	while(!feof(fptr)){
        fgets(singleline, sizeof(singleline), fptr);
        fprintf(fptr2, "\n");
        int m = strlen(singleline);
        characters+=m;
        for(i=0;i<=m;i++){
        	int temp;
        	if(singleline[i]=='\0')
        		continue;
        	if(singleline[i]=='\n')
        		continue;
        	temp=singleline[i]+13;
			fprintf(fptr2, "%c", temp);
	    }
		linecount++;
	}
	printf("\nNumber of lines encrypted: %d\nNumber of characters encrypted: %d", linecount, characters);
	return 0;
}
