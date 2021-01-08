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
void func_pwd(char *org){
    char *cwd=(char *)malloc(sizeof(char)*100000);
    	getcwd(cwd,100000);
				if(strlen(cwd)>=strlen(org))
				cwd=chng(cwd,org);
				printf("%s\n",cwd);
}