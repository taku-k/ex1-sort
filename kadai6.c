#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ARRAY 50
#define MAX_CHAR 80
#define MAX_INPUT 9999
#define MIN_INPUT 1

void heapsort(int *a,int n);
void dheap1(int *a,int size,int root);
void dheap2(int *a,int size,int root);
int input(int *array);
void output(int *array, int n);
int check(int hoge);



int main(void){
  int array[MAX_ARRAY],cnt;

  cnt=input(array);

  heapsort(array,cnt);

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


//ヒープ木の構成で前半は非再帰で、後半は再帰で実行します
void heapsort(int *a,int n){
  int i,size=n-1;
  int root=(size-1)/2;          //sizeの葉に対する親（末尾の葉に対するノード）
  
  for(i=root;i>=0;i--){         //末尾に対する親から上の段へ順序的にヒープ木を構成
    dheap2(a,size,i);
  }
  
  i=size;
  while(i>0){                  //sizeが根に到達するまで
    int temp=a[i];             //根と末尾を交換して配列の最大値を末尾に
    a[i]=a[0];
    a[0]=temp;

    i--;                      //末尾はソートされたのでヒープ木に含めない
    dheap2(a,i,0);            //交換された根を下ろしていく
  }
}




//ヒープ木を構成（非再帰版）
void dheap1(int *a,int size,int root){
  int i = root*2+1;             //根に対する左側の子

  //子がsizeを越えるまで繰り返す
  while(i <= size){
    if(i<size){                      //i==sizeであれば右側の子が存在しない
      if(a[i+1]>a[i]) i++;           //左側と右側を比較
    }

    if(a[root]>=a[i])break;          //根と比較して根の方が大きければ終了

    int temp=a[root];                //値を交換
    a[root]=a[i];
    a[i]=temp;

    root=i;                          //根と子を更新
    i=root*2+1;
  }
}


//ヒープ木の構成（再帰版）
void dheap2(int *a,int size,int root){
  int i=root*2+1;
  if(i>size)return;

  if(i<size)
    if(a[i+1]>a[i])i++;

  if(a[root]>=a[i])return;

  int temp=a[root];
  a[root]=a[i];
  a[i]=temp;

  dheap2(a,size,i);             //次の部分木を再帰的に
}
