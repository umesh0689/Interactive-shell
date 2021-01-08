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
void func_pinfo(int count,char **newstrg){
				char buf[1000];
				char bu[1000];
				if(count==1){
					int ll=getpid();
					sprintf(newstrg[1], "%d", ll);

				}
				printf("pid -- %s\n",newstrg[1]);
				strcpy(buf,"/");
				strcat(buf,"proc");
				strcat(buf,"/");
				strcat(buf,newstrg[1]);
				strcat(buf,"/");
				strcat(buf,"status");
				FILE *fd=fopen(buf,"r");
				count=1;	                                         
				while(count<=3){
					fgets(bu,1000,fd);
					count++;
				}
				char *p;
				p=strstr(bu,"State:");
				printf("Process status -- %s",p+7);
				while(count<=18){

					fgets(bu,1000,fd);
					count++;
				}
				p=strstr(bu,"VmSize:");
				printf("memory -- %s",p+10);
				strcpy(buf,"/");
				strcat(buf,"proc");
				strcat(buf,"/");
				strcat(buf,newstrg[1]);
				strcat(buf,"/");
				strcat(buf,"cmdline");
				fd=fopen(buf,"r");
				fgets(bu,1000,fd);
				printf("Executable Path -- %s\n",bu);
			}