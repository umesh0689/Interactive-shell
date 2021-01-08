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
void func_cd(int count,char **newstrg,char *org){
    if(count<=1 || (strcmp(newstrg[1],"~")==0)){
					if(chdir(org)!=0){
						perror(org);
					}

				}
				else{
					if (chdir(newstrg[1]) !=0){
						perror(newstrg[1]);}  }
}