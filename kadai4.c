#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR_SIZE 80
#define MAX_INPUT 9999
#define MIN_INPUT 1

typedef struct listelem {
  int data;
  struct listelem *next;
}list;

list * insert_first(list *l,int x);
list * insert(list *l,int x);
list * delete(list *l,int x);
void print_list(list *l);
int input(void);
int check(int hoge);

int main(void){
  list *l=NULL;
  int i,x;

  printf("値を10個入力してください.\n1行につき1個です.\n");
  for(i=0;i<10;i++){
    x=input();
    l=insert_first(l,x);
  }
  print_list(l);

  printf("挿入します.10個入力してください.\n");
  for(i=0;i<10;i++){
    x=input();
    l=insert(l,x);
    print_list(l);
  }

  printf("削除します.10個入力してください.\n");
  for(i=0;i<10;i++){
    x=input();
    l=delete(l,x);
    print_list(l);
  }

  return 0;
}





list * insert_first(list *l,int x){
  list *p;                                  
  p=(list *)malloc(sizeof(list));   
  p->data=x;                                 
  p->next=NULL;

  if(l==NULL){                                
    return p;
  }
  list *q=l;
  while(q->next != NULL){
    q=q->next;
  }
  q->next=p;
  return l;
}






list * delete(list *l,int x){
  list *current=l,*prev=NULL,*p;
  while(current!=NULL){
    if(current->data==x){
      if(prev==NULL){
	l=current->next;
      }else{
	prev->next=current->next;
      }
      p=current;
      current=current->next;
      free(p);
    }else{
      prev=current;
      current=current->next;
    }
  }
  return l;
}






void print_list(list *l) {
  while (l != NULL) {
    printf("%d ", l->data);
    l = l->next;
  }
  printf("\n");
}



int input(void){
  int x;
  char buf[MAX_CHAR_SIZE];
  
  while(1){
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf,"%d",&x);
    if(check(x)){
      break;
    }else{
      fprintf(stderr,"値が入力範囲を越えています.\nもう一度入力してください.\n");
    }
  }
  return x;
}

int check(int hoge){
  return (hoge>=MIN_INPUT && hoge<=MAX_INPUT);
}



list * insert(list *l,int x){
  list *p,*current=NULL,*q=l;
  p=(list *)malloc(sizeof(list));
  p->data=x;

  while(x > q->data){
    current=q;
    q=q->next;
    if(q == NULL)break;
  }

  if(current==NULL){
    p->next=q;
    return p;
  }else if(q == NULL){
    p->next=NULL;
    current->next=p;
  }else{
    p->next=q;
    current->next=p;
  }

  return l;
}
