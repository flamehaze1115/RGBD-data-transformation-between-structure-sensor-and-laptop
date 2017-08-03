#include <stdio.h>  
#include <Winsock2.h>  
#include "opencv2/opencv.hpp"
#include<iostream>
#include<fstream>
#include<ctime>

using namespace cv;


void main()
{


	


	SYSTEMTIME sys_time;
	//initialize winsocket  
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return;
	}

	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); 
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(4000);
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	listen(sockSrv, 5); 

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);

	SOCKET sockConn;
	sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);//accept connect request from iPad
	std::cout << (" Done.\n");

	Mat ima = imread("666.jpg");
	long int collen = 320 * 240 * 3;
	long int deplen = 320 * 240 * 2;
	int j = 0;

    cv:Mat depth, img;
	depth.create(240, 320, CV_16UC1);
	char* deprecvBuf = (char*)depth.data;
	img.create(240, 320, CV_8UC3);
	char* colrecvBuf = (char*)img.data;
	while (1)
	{   //send message to tell iPad send data
		send(sockConn,(char *)ima.data, 320 * 240 * 3, 0);//send image 666 to iPad, it will show in normalsview.

		//receive depth data
		recv(sockConn, deprecvBuf, deplen, MSG_WAITALL);//MSG_WAITALL means wait until the buffer is full
		memcpy(depth.data, deprecvBuf, deplen);
		std::string depfile_name = "img" + std::to_string(j++) + ".png";
		imwrite(depfile_name, depth);
		
		//receive rgb data
		recv(sockConn, colrecvBuf, collen, MSG_WAITALL);
		memcpy(img.data, colrecvBuf, collen);
		std::string colfile_name = "img" + std::to_string(j++) + ".jpg";
        imwrite(colfile_name, img);
	}
	closesocket(sockConn);
	WSACleanup();
}