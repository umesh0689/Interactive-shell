Features:
All commands working on real terminal will work
Some commands listed below are implemented separatly
 ls
 cd
 pinfo
 echo
 pwd
 jobs
 kjob
 overkill
 setenv
 getenv
 unsetenv
 quit
Processes are made background processes when used '&'
Pipes and redirection are handled properly
current directory of shell is made home directorys

How to run:
Go to the working directory and run make
use ./output to start shell

Description:
cd.h:
    cd
echo.h:
    echo
env.h:
    setenv
    unsetenv
ls.h:
    ls
lscomm.h:
   printing file permissions
pinfo.h:
    pinfo
pwd.h:
    pwd
sepa.h:
    input handling
all.h:
    remaining command will run from here
