#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encrypt(char* input, char* output);

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("USAGE: complement [input file] [output file]\n");
		return 1;
	}
	encrypt(argv[1], argv[2]);
	return 0;
}

void encrypt(char* input, char* output){
	FILE *fa, *fb;
	char ch;
	char c = '\n';
	fa = fopen(input, "r");
	fb = fopen(output, "w");
	if((fa == NULL) || (fb == NULL))
		printf("Error reading files!\n");
	while((ch=getc(fa)) != EOF){
		if(ch == '\n')
			putc(c, fb);
		else
			putc(~ch, fb);
	}
}