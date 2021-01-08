#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<limits.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>
#include<fcntl.h>
#include<sys/wait.h>
char *chng(char *cwd,char *org){
	cwd[strlen(org)-1]='~';
	cwd=cwd+(strlen(org)-1);
	return cwd;
}
int sepc(char *inpt,char **fstrg){
	int i=0;
	while(inpt!=NULL){
		fstrg[i++]=strsep(&inpt,";");
	}
	return i;
}
int seppi(char *inpt,char **istrg){
	int i=0;
	while(inpt!=NULL){
		istrg[i++]=strsep(&inpt,"|");
	}
	return i;
}
char 	*remspace(char *inp)
{
  char *temp=(char *)malloc(sizeof(char)*10000);
  int k=-1,i=0;
  while(inp[i]==' ')
              i++;
  for(i;i<strlen(inp);i++){
    if( !(inp[i]==' ' && (inp[i+1]==' '||i==strlen(inp)-1)) ){
      k++;
      temp[k]=inp[i];
    }
  }
  return temp;    
}
int seps(char *inpt,char **newstrg){
	for(int i=0;i<10000;i++){
	newstrg[i]=(char *)malloc(sizeof(char)*10000);}
	int k=0;
	while(inpt!=NULL){
		newstrg[k++]=strsep(&inpt," ");
	}
	return k;
}