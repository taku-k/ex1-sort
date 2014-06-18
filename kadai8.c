#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_array 50
#define MAX_char 80
#define MAX_input 9999
#define MIN_input 1

int input(int *array);
void output(int *array, int n);
int check(int hoge);
void quicksort(int *array,int left,int right);
void swap(int *x,int *y);
int  middle3(int x,int y,int z);

int main(void){
  int array[MAX_array],cnt;

  cnt=input(array);

  quicksort(array,0,cnt-1);
  output(array,cnt);

  return 0;
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
    /*文字列比較でtpが"/"ならば入力値を返却して終了*/
    if(!strcmp(tp,"/"))return i;
    /*atoiを使って文字列を数値に変換*/
    if(check(atoi(tp))){
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
      if(check(atoi(tp))){
        fprintf(stderr,"入力値が範囲を越えています\n");
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
  return !(hoge>=MIN_input && hoge<=MAX_input);
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
  if(!((i-1%10)==0)||i<=10)printf("\n");

  return ;
}

void quicksort(int *array,int left,int right){
  int i=left,j=right,pivot=array[left];

  /*要素が１つになったら終了*/
  if(i==j)return;

  /*３個の数値をとってきてその中間値をpivotに代入*/
  if(right-left>=2)pivot=middle3(array[left],array[right],array[(left+right)/2]);

  while(1){
    while(pivot>array[i])i++;
    while(pivot<array[j])j--;
    if(i>=j)break;
    swap(&array[i],&array[j]);
    i++;j--;
  }

  if(left<i-1)quicksort(array,left,i-1);
  if(j+1<right)quicksort(array,j+1,right);
  return ;
}

void swap(int *x,int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;

  return ;
}

int middle3(int  x,int  y,int  z){
  if(x<y){
    if(y<z){
      return y;
    }else if(z<x){
      return x;
    }else{
      return z;
    }
  }else{
    if(z<y){
      return y;
    }else if(x<z){
      return x;
    }else{
      return z;
    }
  }
}
