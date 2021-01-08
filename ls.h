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
void func_ls(int count,char **newstrg){
    if(count==1){
					DIR *mydir;
					struct dirent *myfile;
					struct stat mystat;

					char buf[512];
					mydir = opendir(".");
					while((myfile = readdir(mydir)) != NULL)
					{	
						strcpy(buf,".");
						strcat(buf,"/");
						strcat(buf,myfile->d_name);

						stat(buf, &mystat);
						if(!(strcmp(myfile->d_name,".")==0 || strcmp(myfile->d_name,"..")==0))
							printf(" %s\n", myfile->d_name);
					}
					closedir(mydir);
				}
				else if(count==2){
					if(strcmp(newstrg[1],"-a")==0){
						DIR *mydir;
						struct dirent *myfile;
						struct stat mystat;

						char buf[512];
						mydir = opendir(".");
						while((myfile = readdir(mydir)) != NULL)
						{	
							strcpy(buf,".");
							strcat(buf,"/");
							strcat(buf,myfile->d_name);
							stat(buf, &mystat);
							printf(" %s\n", myfile->d_name);
						}
						closedir(mydir);				

					}
					else if(strcmp(newstrg[1],"-l")==0){
						DIR *mydir;
						struct dirent *myfile;
						struct stat mystat;

						char buf[512];
						mydir = opendir(".");
						while((myfile = readdir(mydir)) != NULL){
							if(!(strcmp(myfile->d_name,".")==0 || strcmp(myfile->d_name,"..")==0)){
								strcpy(buf,".");
								strcat(buf,"/");
								strcat(buf,myfile->d_name);
								stat(buf,&mystat);
								permission(mystat);
								printf(" %ld", mystat.st_nlink);
								printf(" %s", getpwuid(mystat.st_uid)->pw_name);
								printf(" %s", getgrgid(mystat.st_gid)->gr_name);
								printf(" %ld ", mystat.st_size);
								tym(mystat);
								printf("%s",myfile->d_name);
								printf("\n");
							}
						}

					}
					else if(strcmp(newstrg[1],"-la")==0 ||strcmp(newstrg[1],"-al")==0  ){
						DIR *mydir;
						struct dirent *myfile;
						struct stat mystat;

						char buf[512];
						mydir = opendir(".");
						while((myfile = readdir(mydir)) != NULL){
							strcpy(buf,".");
							strcat(buf,"/");
							strcat(buf,myfile->d_name);
							stat(buf,&mystat);
							permission(mystat);
							printf(" %ld", mystat.st_nlink);
							printf(" %s", getpwuid(mystat.st_uid)->pw_name);
							printf(" %s", getgrgid(mystat.st_gid)->gr_name);
							printf(" %ld ", mystat.st_size);
							tym(mystat);
							printf("%s",myfile->d_name);
							printf("\n");
						}	
					}

					else{
						DIR *mydir;
						struct dirent *myfile;
						struct stat mystat;

						char buf[512];
						mydir = opendir(newstrg[1]);
						while((myfile = readdir(mydir)) != NULL)
						{	
							strcpy(buf,newstrg[1]);
							strcat(buf,"/");
							strcat(buf,myfile->d_name);
							stat(buf, &mystat);
							if(!(strcmp(myfile->d_name,".")==0 || strcmp(myfile->d_name,"..")==0))
								printf(" %s\n", myfile->d_name);
						}
						closedir(mydir);
					}}

				else{ 
					if(strcmp(newstrg[1],"-l")==0){
						DIR *mydir;
						struct dirent *myfile;
						struct stat mystat;

						char buf[512];
						mydir = opendir(newstrg[2]);
						while((myfile = readdir(mydir)) != NULL){
							if(!(strcmp(myfile->d_name,".")==0 || strcmp(myfile->d_name,"..")==0)){
								strcpy(buf,newstrg[2]);
								strcat(buf,"/");
								strcat(buf,myfile->d_name);
								stat(buf,&mystat);
								permission(mystat);
								printf(" %ld", mystat.st_nlink);
								printf(" %s", getpwuid(mystat.st_uid)->pw_name);
								printf(" %s", getgrgid(mystat.st_gid)->gr_name);
								printf(" %ld ", mystat.st_size);
								tym(mystat);
								printf("%s",myfile->d_name);
								printf("\n");
							}
						}		

					}
					else if(strcmp(newstrg[1],"-a")==0){
						DIR *mydir;
						struct dirent *myfile;
						struct stat mystat;
						char buf[512];
						mydir = opendir(newstrg[2]);
						while((myfile = readdir(mydir)) != NULL)
						{	
							strcpy(buf,newstrg[2]);
							strcat(buf,"/");
							strcat(buf,myfile->d_name);
							stat(buf, &mystat);
							printf(" %s\n", myfile->d_name);
						}
						closedir(mydir);
					}
					else if(strcmp(newstrg[1],"-la")==0 ||strcmp(newstrg[1],"-al")==0  ){
						DIR *mydir;
						struct dirent *myfile;
						struct stat mystat;

						char buf[512];
						mydir = opendir(newstrg[2]);
						while((myfile = readdir(mydir)) != NULL){
							strcpy(buf,newstrg[2]);
							strcat(buf,"/");
							strcat(buf,myfile->d_name);
							stat(buf,&mystat);
							permission(mystat);
							printf(" %ld", mystat.st_nlink);
							printf(" %s", getpwuid(mystat.st_uid)->pw_name);
							printf(" %s", getgrgid(mystat.st_gid)->gr_name);
							printf(" %ld ", mystat.st_size);
							tym(mystat);
							printf("%s",myfile->d_name);
							printf("\n");
						}
					}	
				}
}