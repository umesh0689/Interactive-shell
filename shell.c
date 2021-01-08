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
#include"echo.h"
#include"pinfo.h"
#include"sepa.h"
#include"lscomm.h"
#include"ls.h"
#include"pwd.h"
#include"cd.h"
#include"all.h"
#include"env.h"
char arry[100][3][100];
int arrcnt=0;
int count,new_fd=-1,copy_fd,raw,new12_fd,copy12_fd,ct;
int main(void){
					
					signal(SIGINT,new_handler);

	char *cwd=(char *)malloc(sizeof(char)*100000);
	char *org=(char *)malloc(sizeof(char)*100000);
	char *newp=(char *)malloc(sizeof(char)*100000);
	char *inpt=NULL;
	char *user=(char *)malloc(sizeof(char)*100000);
	char *host=(char *)malloc(sizeof(char)*100000);
	char *redi=(char *)malloc(sizeof(char)*100000);
	char temp;
	char *newstrg[10000];
	char *fstrg[10000];
	char *istrg[10000];
	char *pin;
	for(int i=0;i<10000;i++){
		newstrg[i]=(char *)malloc(sizeof(char)*10000);
	}
	for(int i=0;i<10000;i++){
		fstrg[i]=(char *)malloc(sizeof(char)*10000);
	}
	for(int i=0;i<10000;i++){
		istrg[i]=(char *)malloc(sizeof(char)*10000);
	}
	char ramesh[1000];
	getcwd(cwd,10000);
	strcpy(org,cwd);
	using_history();
	while(1){
		user=getenv("USER");
		gethostname(host,10000);
		copy_fd=dup(1);
		copy12_fd=dup(0);
		int flag,k;
		getcwd(cwd,100000);
		if(strlen(cwd)>=strlen(org))
			cwd=chng(cwd,org);
		sprintf(ramesh,"<%s@%s:%s>",user,host,cwd);
		inpt=readline(ramesh);
		add_history(inpt);
		inpt=remspace(inpt);
		int i=0;
		i=sepc(inpt,fstrg);
		for(int lan=0;lan<i;lan++){
			fstrg[lan]=remspace(fstrg[lan]);
		}
		k=0;
		for(k=0;k<i;k++)
        {
			new_fd=-1;
            pin=strstr(fstrg[k],">>");
			if(pin){
				*pin=0;
				pin+=2;
				while(*pin==' ')
				{
					pin++;
				}
				strcpy(redi,pin);
				new_fd=open(redi, O_WRONLY |O_CREAT | O_APPEND,0644);
				dup2(new_fd,1);
			}
			pin=strstr(fstrg[k],">");
			if(pin){
				*pin=0;
				pin+=1;
				while(*pin==' ')
				{
					pin++;
				}
				strcpy(redi,pin);
				new_fd=open(redi, O_WRONLY |O_CREAT | O_TRUNC,0644);
				dup2(new_fd,1);
			}
			fstrg[k]=remspace(fstrg[k]);
			ct=seppi(fstrg[k],istrg);
            for(int j=0;j<ct;j++)
                istrg[j]=remspace(istrg[j]);
            
			for(int j=0;j<ct;j++){
				int pp[2];
                if(j==0)
                {
                    char *hij=(char *)malloc(sizeof(char)*100);
                    hij=strstr(istrg[j],"<");
                    if (hij)
                    {
                        *hij=0;
                        hij++;
                        while(*hij==' ')
                            hij++;
                        int outfile=open(hij,O_RDONLY);
                        if(outfile)
                        dup2(outfile,0);
                    }
                }
                istrg[j]=remspace(istrg[j]);
                count=seps(istrg[j],newstrg);
                if(j!=ct-1)
    				pipe(pp);
                else
                    pp[1]=new_fd;
                func_all(newstrg,count,org,pp);
                close(pp[1]);
                if(j!=ct-1)
                {
                    dup2(pp[0],0);
                }                                
            
			}
            dup2(copy12_fd,0);
            dup2(copy_fd,1);
 		}
	}
	return 0;
}