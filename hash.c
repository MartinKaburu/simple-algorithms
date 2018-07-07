/*
*Code by Muguna Martin Kaburu
*Compare hashes of different files
*Add another argument vector to compare a given hash and the generated one
*Buy Coffee
*/
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<unistd.h>

int checkHash(char* firstFile,char* secondFile,char* hashAlgorithm);
char* theHash(char* fileName, char* _hash);

int main(int argc, char* argv[]){
  if(argc != 4){
    printf("Invalid NUmber of arguments!\n");
    return 1;
  }
  else{
    if((access(argv[1], F_OK) != -1) && (access(argv[2], F_OK) != -1)){
      int retValue = checkHash(argv[1], argv[2], argv[3]);
      if(retValue == 0)
        printf("Hash confirmed\n");
      else
        printf("Hash does not match\n");
    }
    else{
      printf("Invalid File(s)!\n");
      return 1;
    }
  }
  return 0;
}
char* theHash(char* fileName, char* _hash){
  FILE *ptr;
  char command[256] = "certutil -hashfile ";
  char ch;
  char hash[256];
  int n = 0;
  fileName = strcat(fileName, " ");
  fileName = strcat(fileName, _hash);
  command[256] = strcat(command, fileName);
  ptr = popen(command, "r");
  if(ptr == NULL){
    printf("Error running command\n");
    return "Something went wrong";
  }
  else{
    while((ch = fgetc(ptr)) != EOF){
      if(ch == ':'){
        while((ch = fgetc(ptr)) != 'C'){
          hash[n] = ch;
          n++;
        }
        hash[n++] = '\0';
        break;
      }
      else
        continue;
    }
  }
  pclose(ptr);
  char* rtnptr = hash;
  return rtnptr;
}
int checkHash(char* firstFile,char* secondFile,char* hashAlgorithm){
  char* _theHash;
  char secondHash[256];
  char firstHash[256];
  int retValue;
  _theHash = theHash(firstFile, hashAlgorithm);
  strcpy(firstHash, _theHash);
  _theHash = theHash(secondFile, hashAlgorithm);
  strcpy(secondHash, _theHash);
  retValue = strcmp(secondHash, firstHash);
  if(retValue == 0)
    return 0;
  else
    return retValue;
}
