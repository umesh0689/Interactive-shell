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
void func_eco(int count,char **newstrg){
	for(int j=1;j<count;j++){
					printf("%s ",newstrg[j]);
				}
				printf("\n");
}