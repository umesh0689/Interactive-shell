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




void func_setenv(int count,char **newstrg)
{   
    if(count ==1 || count >=4)
    {
        fprintf(stderr,"INVALID No.of arguments\n");
    }   
    char *env_var=(char *)malloc(sizeof(char)*10000);
    strcpy(env_var,newstrg[1]);
    strcat(env_var,"=");
    int result=putenv(env_var);
    strcat(env_var,newstrg[2]);
    putenv(env_var);
    return;

}
void func_getenv(int count,char **newstrg){
    if(count>2)
    {
        fprintf(stderr,"Invalid no.of arguments");
    }
    if(getenv(newstrg[1]))
    printf("%s\n",getenv(newstrg[1]));
    else
    {
        printf("%s","");
    }
    return;
}
void func_unsetenv(int count,char **newstrg){
     if(count>2)
    {
        fprintf(stderr,"Invalid no.of arguments");
    }
    unsetenv(newstrg[1]);
    return;
}