#include<sys/types.h>
#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
char *message;
int n;
printf("fork program starting\n");
pid = fork();
switch(pid)
{
case -1:
perror("fork failed");
exit(1);
case 0:
message = "child";
n = 3;
break;
default:
message = "parent";
n = 5;
break;
}
for(; n > 0; n--) {
puts(message);
sleep(1);
}
}
