#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

#define MAXLINE 1024 //buf ..
#define TOTALFORK 5 //..... .

void createClient(char *port, char *serverIP);
int main(int argc, char *argv[]) {
		if(argc != 3) {
		printf("Use %s ip_addr port\n", argv[0]);
		exit(0);
		}

	pid_t pids[TOTALFORK]; //client fork
	int runProcess = 0;
					
	while(runProcess < TOTALFORK) {
	sleep(1);
	pids[runProcess] = fork();

	if(pids[runProcess] < 0) {
	return -1;
	}
														
	if(pids[runProcess] == 0) {
	createClient(argv[2], argv[1]);
	exit(0);
	} else { //.. ....
																											
	printf("parent %ld, child %ld\n", (long)getpid(), (long)pids[runProcess]);
	}
	runProcess++;	
	}
	return 0;
   } 

void createClient(char *port, char *serverIP) {
	struct sockaddr_in servaddr;
    int strlen = sizeof(servaddr);
	int sockfd, buf, cNum;//cNum .. ..

	if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
	perror("socket fail");
	exit(0);
	}

	memset(&servaddr, 0, strlen);
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, serverIP, &servaddr.sin_addr);
	servaddr.sin_port = htons(atoi(port));

	if(connect(sockfd, (struct sockaddr *)&servaddr, strlen) < 0) {
	perror("connect fail");
	exit(0);
		}
									
	srand((unsigned)time(NULL));
	buf = rand() % 100 + 1; //rand . ..
	write(sockfd, &buf, 4); //server. ..
	printf("cleint value : %d\n", buf);
	read(sockfd, &buf, 4); //server.. .. .
	printf("Server sum result : %d\n", buf);
	close(sockfd);
}

