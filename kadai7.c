#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ARRAY 50
#define MAX_CHAR 80
#define MAX_INPUT 9999
#define MIN_INPUT 1

void mergesort(int *array,int left,int right);
void merge(int *array,int *temp,int left,int right);
int input(int *array);
void output(int *array, int n);
int check(int hoge);

int main(void){
  int array[MAX_ARRAY],cnt;

  cnt=input(array);

  mergesort(array,0,cnt-1);
  output(array,cnt);

  return 0;
}

void merge(int *array,int *temp,int left,int right){
  if(left>=right)return ;
  int middle=(left+right)/2,i,j,k;

  merge(array,temp,left,middle);
  merge(array,temp,middle+1,right);
  
  for(i=left;i<=middle;i++){
    temp[i]=array[i];
  }

  for(i=middle+1,j=right;i<=right;i++,j--){
    temp[i]=array[j];
  }

  for(i=left,j=right,k=left;k<=right;k++){
    if(temp[i]<=temp[j])array[k]=temp[i++];
    else array[k]=temp[j--];
  }

}

void mergesort(int *array,int left,int right){
  int temp[MAX_ARRAY];
  merge(array,temp,left,right);
}

/*返却値は入力数*/
int input(int *array){
  char str[MAX_CHAR];
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
      return MAX_ARRAY;
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
        return MAX_ARRAY;
      }
    }
  }
  return i;
}

int check(int hoge){
  return (hoge>=MIN_INPUT && hoge<=MAX_INPUT);
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
