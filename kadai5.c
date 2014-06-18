#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ARRAY 50
#define MAX_CHAR 80
#define MAX_INPUT 9999
#define MIN_INPUT 1

typedef struct listelem {
  int data;
  struct listelem *next;
}list;

list * insert_first(list *l,int x);
list * input(list *l);
list * insertsort(list *l);
void output_list(list *l);
int check(int hoge);
void print_list(list *l);
list * insert(list *l,int x);
list * delete(list *l,int x,int num);


int main(void){
  list *l=NULL;

  l=input(l);
  l=insertsort(l);
  output_list(l);

  return 0;
}




list * input(list *l){
  char str[MAX_CHAR];
  char *tp;
  int i=0;

  /*NULLが返されるか"/"が入力されるまでループ*/
  while((fgets(str, sizeof(str), stdin))!=NULL){
    
    /*スペースと改行を飛ばして分解していく*/
    tp=strtok(str," \n");
    
    /*文字列比較でtpが"/"ならば入力数を返却して終了*/
    if(!strcmp(tp,"/"))return l;
    
    /*atoiを使って文字列を数値に変換*/
    if(!check(atoi(tp))){
      fprintf(stderr,"入力値が入力範囲を越えています。\n");
    }else{
      l=insert_first(l,atoi(tp));
      i++;
    }


    if(i>50){
      fprintf(stderr,"入力できる上限を越えています。\nここまでの数値で終了します。\n");
      return l;
    }
    
    /*入力が終わるまでループ*/
    while(tp!=NULL){
      tp=strtok(NULL," \n");
      
      if(tp==NULL)break;
      
      if(!strcmp(tp,"/"))return l;
      
      if(!check(atoi(tp))){
        fprintf(stderr,"入力値が入力範囲を越えています\n");
      }else{
       l=insert_first(l,atoi(tp));
       i++;
      }
      
      if(i>50){
        fprintf(stderr,"入力できる上限を越えています。\nここまでの数値で終了します。\n");
        return l;
      }
    }
  }
  return l;

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




int check(int hoge){
  return (hoge>=MIN_INPUT && hoge<=MAX_INPUT);
}



void print_list(list *l) {
  while (l != NULL) {
    printf("%d ", l->data);
    l = l->next;
  }
  printf("\n");
}


void output_list(list *l){
  int i=1;
  list *p=l;

  while(p!=NULL){
    int x=p->data;
    if(x>=1 && x<=9) printf("   %d",x);
    else if(x>=10 && x<=99) printf("  %d",x);
    else if(x>=100 && x<=999) printf(" %d",x);
    else printf("%d",x);
    
    if((i%10)==0 && !(p->next!=NULL))printf("\n");
    else printf(" ");
    p=p->next;
    i++;
  }
  if(!((i-1%10)==0))printf("\n");

  return ;
}


list * insertsort(list *l){
  list *q,*prev_q,*p,*prev_p,*tmp;

  for(q=l;q!=NULL;prev_q=q,q=q->next){
    prev_p=q;
    for(p=q->next;p!=NULL;prev_p=p,p=p->next){
      if(p->data > q->data){
       if(prev_q){
         prev_q->next=p;
       }

       if(q == prev_q){
	 q->next = p->next;
	 p->next = q;
       }else{
	 tmp = p->next;
	 p->next = q->next;
	 q->next = tmp;
	 prev_p->next = q;
       }
       if(q == l){
	 l=p;
       }
       tmp = q;
       q = p;
       p = tmp;
      }
    }
  }
      
  return l;
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




list * delete(list *l,int x,int num){
  list *current=l,*prev=NULL,*p;
  int i=0;

  while(current!=NULL){
    if(current->data==x&&i>=num){
      if(prev==NULL){
	l=current->next;
      }else{
	prev->next=current->next;
      }
      p=current;
      current=current->next;
      free(p);
      return l;
    }else{
      prev=current;
      current=current->next;
    }
    i++;
  }
  return l;
}
