#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ARRAY 30000
#define MAX_CHAR 160
#define FUNC_NUM 2



int input(int *array);
void output(int *array, int n);
void quicksort(int *array, int n);
void quick(int *array,int left,int right);
void swap(int *x,int *y);
int  middle3(int x,int y,int z);
void bubblesort(int *array, int n);



int main(int argc, char *argv[]){
  
  void (*f[])(int *a,int n) = {bubblesort, quicksort};

  int array[MAX_ARRAY],cnt,tmp=0,check=0;
  char str[MAX_CHAR];

  if(argc!=2){
    printf("どのソートを実行するか選択してください。\n");
    printf("(0)->Bubblesort (1)->Quicksort\n");
    do{
      if(check != 0){
	fprintf(stderr,"入力幅に収まっていません。\n");
	fprintf(stderr,"もう一度選択してください。\n");
      }
      fgets(str,sizeof(str),stdin);
      sscanf(str,"%d",&tmp);
      check++;
    }while(tmp<0 || tmp>FUNC_NUM-1);
  }else{
    sscanf(argv[1],"%d",&tmp);
  }
  
  cnt=input(array);

  f[tmp](array,cnt);

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
    array[i++]=atoi(tp);
    
    /*入力が終わるまでループ*/
    while(tp!=NULL){
      tp=strtok(NULL," \n");
      if(tp==NULL)break;
      if(!strcmp(tp,"/"))return i;
      array[i++]=atoi(tp);
    }
  }
  return i;
}







/*出力*/
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




 void quicksort(int *array, int n){
   quick(array,0,n-1);
   return ;
}




void quick(int *array,int left,int right){
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

  if(left<i-1)quick(array,left,i-1);
  if(j+1<right)quick(array,j+1,right);
  return ;
}




void swap(int *x,int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;

  return ;
}



/*３つの数値の中央値を返す*/
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





/*バブルソート*/
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
