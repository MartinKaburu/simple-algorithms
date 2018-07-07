#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void _palindrome(char word[50]);

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("USAGE: palindrome [word]\n");
		return 1;
	}
	_palindrome(argv[1]);	
	return 0;
}

void _palindrome(char word[50]){
	int s = strlen(word);
	char* inv = malloc(sizeof(char)*s);
	int d = 0;
	for(int i = s; i >= 0; i--){
		if(word[i] == '\0')
            continue;
		inv[d] = word[i];
		d++;
	}
	inv[d] = '\0';
	if (strcmp(inv, word) == 0)
        printf("It's a palindrome.\n");
	else
        printf("Its not a palindrome.\n");
}