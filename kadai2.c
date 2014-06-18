#include <stdio.h>

int  main(void){
  FILE *fp1,*fp2;
  int i;
  char buf[256];
  char lec[6][30]={"Mo1","Mo2","Tu1","Tu3","We1","Th1"};

  /*ファイルをオープンする*/
  fp1=fopen("mylecture.txt","r");
  if(fp1==NULL){
    printf("ファイルをオープンできません\n");
    return 0;
  }

  fp2=fopen("mylecture.data","w");
  if(fp2==NULL){
    printf("ファイルをオープンできません\n");
    return 0;
  }

  /*fp1から文字を読み取ってfp2に出力*/
  for(i=0;i<6;i++){
    fscanf(fp1,"%s",buf);
    fprintf(fp2,"%s\t",lec[i]);
    fprintf(fp2,"%s\n",buf);
  }

  /*ファイルを閉じる*/
  fclose(fp1);
  fclose(fp2);

  return 0;
}
