//Lucas Gon�alves e Silva
//11811EAU016
//Trabalho 02 - Copiar Arquivos

//Bibliotecas
#include<stdio.h>
#include<stdlib.h>

//Main
int main(int nargs, char ** args){
  size_t buffSize =1024*10000; // 10Mb 
  size_t bytesReaded;
  char *buff;
  FILE *fin,*fout;
  if(nargs!= 3){
    fprintf(stderr,"N�mero  de argumentos inv�lidos\n");
    return -1;
  }
  if (!(fin = fopen(args[1],"rb"))){
    fprintf(stderr,"O arquivo %s n�o  foi encontrado\n",args[1]);
    return -1;
  }if (!(fout = fopen(args[2],"wb"))){
    fprintf(stderr,"O arquivo %s n�o   pode ser criado\n",args[2]);
    return -1;
  }
  buff =(char*) malloc(buffSize);
  if(!buff){
     fprintf(stderr,"N�o foi possivel alocar memoria\n");
     goto freeFiles;
  }

  while(!feof(fin)){
    bytesReaded = fread(buff,1,buffSize,fin);
    //fwrite(buff,100,1,stdout);
    printf("%d\n",bytesReaded);
    if(bytesReaded <=0)break;
    fwrite(buff,bytesReaded,1,fout);
  }
  free(buff);
  freeFiles:
  fclose(fin);
  fclose(fout);
  
  return 0;
}

