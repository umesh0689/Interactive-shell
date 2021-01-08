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
#include<readline/readline.h>
#include<readline/history.h>

extern void func_setenv(int count,char **newstrg);
extern void func_getenv(int count,char **newstrg);
extern void func_unsetenv(int count,char **newstrg);
extern char arry[100][3][100];
extern int arrcnt;
void pnt(){
		int k,a,check=0;
	char name[1000],flg[100];
	char *lan;
	lan=(char *)malloc(sizeof(char)*1000);
	pid_t tt=waitpid(-1,&a,WNOHANG);
	for(int aa=0;aa<arrcnt;aa++) 
	{
		if(tt==atoi(arry[aa][0]))
			check=1;
	}
	if(check==0){
	// fprintf(stderr,"returning");
	return ;}
	sprintf(lan,"%d",tt);
	for(int j=0;j<arrcnt;j++){
		if(strcmp(lan,arry[j][0])==0){
			 strcpy(flg,arry[j][2]);
			 strcpy(name,arry[j][1]);
			 strcpy(arry[j][2],"-1");

		}
	}
	fprintf(stderr,"process %s with pid: %s exited normally\n",name,lan);

}
void new_handler()
{
	return;
}
void func_all(char **newstrg,int count,char *org,int arr[2]){
				if(newstrg[0][0]==0){
					return;
				}
				else if(strcmp(newstrg[0],"cd")==0)
				{
				func_cd(count,newstrg,org);
				}
				else if(strcmp(newstrg[0],"overkill")==0){
					for (int jj=0;jj<arrcnt;jj++){
						if(strcmp(arry[jj][2],"-1"))
						kill(atoi(arry[jj][0]),SIGKILL);	
					}
				}
				else if(strcmp(newstrg[0],"quit")==0){
					exit(0);
				}
				else if(strcmp(newstrg[0],"setenv")==0)
				{
					func_setenv(count,newstrg);
				}
				else if(strcmp(newstrg[0],"kjob")==0){
	
					int jj=0,mm=0;


					for(jj=0;jj<arrcnt;jj++)
					{
						if(strcmp(arry[jj][2],"-1"))
							mm++;
						if(mm==atoi(newstrg[1])){
							kill(atoi(arry[jj][0]),atoi(newstrg[2]));
							break;
						}
					}
				}
				else if(strcmp(newstrg[0],"getenv")==0)
				{
					func_getenv(count,newstrg);
				}
				else if(strcmp(newstrg[0],"unsetenv")==0){
					func_unsetenv(count,newstrg);
				}
				else if(strcmp(newstrg[0],"pinfo")==0)
				{
					func_pinfo(count,newstrg);
 				}

				else
				{
					int smart=0;
				if(strcmp(newstrg[count-1],"&")==0){
					smart=1;
				}
				pid_t kk=fork();
				if(kk<0)
					printf("failed to fork!!\n");
				if(kk==0){
					dup2(arr[1],1);
				if(strcmp(newstrg[0],"pwd")==0){
					func_pwd(org);
				close(arr[1]);
				exit(0);
				}
				else if(newstrg[0]==0){
					close(arr[1]);
					exit(0);
				}
				else if(strcmp(newstrg[0],"echo")==0){
					func_eco(count,newstrg);
				close(arr[1]);
				exit(0);
				}
				else if(strcmp(newstrg[0],"ls")==0 /*&& !(count==2 && strcmp(newstrg[1],"&")==0)*/){
					func_ls(count,newstrg);
				close(arr[1]);
				exit(0);
				}
				else if(strcmp(newstrg[0],"jobs")==0){
					int j=0;
					for(int dd=0;dd<arrcnt;dd++){
						if(strcmp(arry[dd][2],"-1"))
						{
							j++;
							printf("[%d] RUNNING  %s [%s]\n",j,arry[dd][1],arry[dd][0]);
						}
					}
					
					close(arr[1]);
					exit(0);
				}
				else
				{	
					char **mi;
					mi=(char **)malloc(sizeof(char *)*1000);
					for( int k=0;k<1000;k++){
						mi[k]=(char *)malloc(sizeof(char)*1000);
						mi[k]=newstrg[k];
					}
					mi[count]=NULL;
					char *umesh1=(char *)malloc(sizeof(char)*1000);
					char *umesh2=(char *)malloc(sizeof(char)*1000);
					char *umesh3=(char *)malloc(sizeof(char)*1000);
					char *umesh4=(char *)malloc(sizeof(char)*1000);
					strcpy(umesh1,"/usr/bin/");
					strcpy(umesh2,"/usr/sbin/");
					strcpy(umesh3,"/sbin/");
					strcpy(umesh4,"/bin/");
					strcat(umesh1,mi[0]);
					strcat(umesh2,mi[0]);
					strcat(umesh3,mi[0]);
					strcat(umesh4,mi[0]);
					if(execvp(umesh1,mi)<0 && execvp(umesh2,mi)<0 && execvp(umesh3,mi)<0 && execvp(umesh4,mi)<0 && execvp(mi[0],mi))
						printf("%s -- This command does not exist\n",mi[0]);
				
					close(arr[1]);
					exit(0);
				}
			}
		
				else if(!smart){
					wait(NULL);
				}
				else if(smart){
					setpgid(kk,kk);
					sprintf(arry[arrcnt][2],"%d",smart);
					strcpy(arry[arrcnt][1],newstrg[0]);
					sprintf(arry[arrcnt][0],"%d",kk);
					
					// for(int lann=0;lann<=arrcnt;lann++)
					// printf("%s  %s  %s\n",arry[lann][0],arry[lann][1],arry[lann][2]);
					arrcnt++;
					signal(SIGCHLD,pnt);

				}
		}
		}