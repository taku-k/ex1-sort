#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ARRAY 50
#define MAX_CHAR 80
#define MAX_INPUT 9999
#define MIN_INPUT 1
#define STACK_SIZE 10

int input(int *array);
void output(int *array, int n);
int check(int hoge);
void quicksort(int *array,int n);
void swap(int *x,int *y);
int  middle3(int x,int y,int z);

int main(void){
  int array[MAX_ARRAY],cnt;

  cnt=input(array);

  quicksort(array,cnt);

  output(array,cnt);

  return 0;
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
    /*文字列比較でtpが"/"ならば入力値を返却して終了*/
    if(!strcmp(tp,"/"))return i;
    /*atoiを使って文字列を数値に変換*/
    if(check(atoi(tp))){
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
      if(check(atoi(tp))){
        fprintf(stderr,"入力値が範囲を越えています\n");
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
  return !(hoge>=MIN_INPUT && hoge<=MAX_INPUT);
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






void quicksort(int *array,int n){
  int stackleft[STACK_SIZE],stackright[STACK_SIZE],p=0;         //分割する位置を二つの配列を用いてスタックを表現する.pはその位置.
                                                  

  stackleft[p]=0;                                               //最初は配列全体を分割するのでleftには0
  stackright[p]=n-1;                                            //rightにはn-1
  p++;                                                          //スタックの位置をあげておく


  //スタックが空になるまでループ
  while(p-- > 0){
    int left=stackleft[p],right=stackright[p];
    int i=left,j=right,pivot=array[stackleft[p]];
    
    if(i==j)continue;
    
    if(right-left >= 2)pivot=middle3(array[left],array[right],array[(left+right)/2]);

    while(1){
      while(pivot>array[i])i++;
      while(pivot<array[j])j--;
      if(i>=j)break;
      swap(&array[i],&array[j]);
      i++;j--;
    }
    
    //スタックに積む
    if(left < i-1){
      stackleft[p]=left;
      stackright[p]=i-1;
      p++;
    }

    //スタックに積む
    if(j+1 < right){
      stackleft[p]=j+1;
      stackright[p]=right;
      p++;
    }
  }
  return;
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
