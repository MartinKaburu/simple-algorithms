#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int anagram(char first_word[256], char second_word[256]);

int main(int argc, char* argv[]){
  if(argc != 3){
    printf("USAGE: anaram first_word second_word ");
    return 1;
  }

  else{
    int ans = 1;
    ans = anagram(argv[1], argv[2]);
    if(ans == 0)
      printf("\n\t[+] Its an anagram\n");
    else
      printf("\n\t[-] Its not an anagram\n");
    return 0;
  }
}

int anagram(char first_word[256], char second_word[256]){
  int S1, S2, C1, C2, CT;
  S1 = strlen(first_word);
  S2 = strlen(second_word);
  if(S1 == S2){
    CT = 0;
    for(S2 = 0; S2 <= S1; S2++){
      if(first_word[S2] == '\0')
        continue;
      for(C2 = 0; C2 <= S1; C2++){
        if(second_word[C2] == '\0')
          continue;
        else if(first_word[S2] == second_word[C2])
          CT++;
      }
    }
    if(CT == S1)
      return 0;
    else
      return 1;
  }
  else
    return 1;
}
