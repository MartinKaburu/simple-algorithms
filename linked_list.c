#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int* data;
    struct node* next;
    }node;

#define TRUE 1

node* _getnode();
int _search(node* s, int num);

int main(int arg, char* argv){

    node* s = _getnode();
    s->next = NULL;
    node* temp = s;
    int c, choice;

    while(TRUE){

        printf("Input data for s->data:\n");
        scanf("%d",&s->data);
        printf("To add data enter Y to exit enter N:\n");
        fflush(stdin);
        c = getchar();
        if((c == 'N')||(c == 'n')){
            s->next = NULL;
            break;
        }
        else{
        s->next = _getnode();
        s = s->next;
        }
    }

    s = temp;
    printf("[+] options:\n 1. Search\n 2. Print All\n 3. Exit\n");
    scanf("%d", &choice);
    switch(choice){
      case 1:{
        system("cls");
        printf("[+] Search for :\n");
        scanf("%d", &c);
        int result = _search(s, c);
        if(result > 0)
          printf("Number %d was Not found\n", c);
        else
          printf("Number %d was found\n", c);
        break;
      }
      case 2:{
        system("cls");
        while(s != NULL){
            printf("%d\n",s->data);
            s = s->next;
        }
        printf("NULL\n");
        break;
      }
      case 3:{
        return 0;
      }
      default:{
        printf("[-] Invalid choice!\n[-] Exiting!");
      }
    }

    return 0;
}
node* _getnode(){
    return ((node*)malloc(sizeof(node)));
    }

int _search(node* s, int num){
  while(s -> data != num){
    s = s -> next;
    if(s == NULL){
      return 1;
      break;
    }
  }
  return -1;
}
