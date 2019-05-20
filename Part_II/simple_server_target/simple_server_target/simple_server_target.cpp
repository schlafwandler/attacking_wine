// simple_server_target.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

void WIN(void);

void handle_connection(int s)
{
	char buffer2[128];
	//char buffer[1024];

	send(s,"What's your name?\r\n",sizeof("What's your name?\r\n"),0);
	int l = recv(s,buffer2,512,0);
	printf("recv %d\n",l);
	//sprintf(buffer2,"\r\nHello %s, how nice to meet you!\r\n",buffer);

	send(s,buffer2,strlen(buffer2),0);

	closesocket(s);
}

int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wsaData;
	int iResult;

	if (argc > 1)
	{
		printf("WIN at %p\n",WIN);
		printf("Stack at %p\n",&iResult);
	}

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}

	int s = socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in sa;
	sa.sin_addr.S_un.S_addr	= INADDR_ANY;
	sa.sin_family = AF_INET;
	sa.sin_port = htons(31337);

	bind(s,(struct sockaddr*)&sa,sizeof(struct sockaddr_in));
	listen(s,3);

	while(1)
	{
		struct sockaddr_in ca;
		int addrlen = sizeof(struct sockaddr_in);
		int c = accept(s,(struct sockaddr*)&ca,&addrlen);

		handle_connection(c);
		//CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)handle_connection,(LPVOID)c,0,NULL);
	}
	return 0;
}

void WIN(void)
{
	printf("#########################\r\n");
	printf("###   You have won!   ###\r\n");
	printf("#########################\r\n");

	ExitProcess(1);
}