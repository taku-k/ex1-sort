#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_array 50
#define MAX_char 80
#define MAX_input 9999
#define MIN_input 1

void bubblesort(int *array, int n);
int input(int *array);
void output(int *array, int n);
int check(int hoge);

int main(void){
  int array[MAX_array],cnt;

  cnt=input(array);

  bubblesort(array,cnt);
  output(array,cnt);

  return 0;
}

void bubblesort(int *array, int n){
  int temp,i,j;
  for(i=0; i<n; i++){
    for(j=1; j<n-i; j++){
      if(array[j] < array[j-1]){
       temp=array[j];
       array[j]=array[j-1];
       array[j-1]=temp;
      }
    }
  }

  return ;
}

/*返却値は入力数*/
int input(int *array){
  char str[MAX_char];
  char *tp;
  int i=0;

  /*NULLが返されるか"/"が入力されるまでループ*/
  while((fgets(str, sizeof(str), stdin))!=NULL){
    
    /*スペースと改行を飛ばして分解していく*/
    tp=strtok(str," \n");
    /*文字列比較でtpが"/"ならば入力数を返却して終了*/
    if(!strcmp(tp,"/"))return i;
    /*atoiを使って文字列を数値に変換*/
    if(!check(atoi(tp))){
      fprintf(stderr,"入力値が入力範囲を越えています。\n");
    }else array[i++]=atoi(tp);
    if(i>50){
      fprintf(stderr,"入力できる上限を越えています。\nここまでの数値で終了します。\n");
      return MAX_array;
    }
    
    /*入力が終わるまでループ*/
    while(tp!=NULL){
      tp=strtok(NULL," \n");
      if(tp==NULL)break;
      if(!strcmp(tp,"/"))return i;
      if(!check(atoi(tp))){
        fprintf(stderr,"入力値が入力範囲を越えています\n");
      }else array[i++]=atoi(tp);
      if(i>50){
        fprintf(stderr,"入力できる上限を越えています。\nここまでの数値で終了します。\n");
        return MAX_array;
      }
    }
  }
  return i;
}

int check(int hoge){
  return (hoge>=MIN_input && hoge<=MAX_input);
}

void output(int *array, int n){
  int i;

  for(i=1;i<=n;i++){
    if(array[i-1]>=1 && array[i-1]<=9) printf("   %d",array[i-1]);
    else if(array[i-1]>=10 && array[i-1]<=99) printf("  %d",array[i-1]);
    else if(array[i-1]>=100 && array[i-1]<=999) printf(" %d",array[i-1]);
    else printf("%d",array[i-1]);
    
    if((i%10)==0 && !(i==n))printf("\n");
    else printf(" ");
  }
  if(!((i-1%10)==0))printf("\n");

  return ;
}
