// SocketServer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#include <ws2tcpip.h>


#define SIZE_BUFFER 1024

#pragma comment(lib, "ws2_32.lib")

//#define SERVER

#ifdef SERVER

using sysclock_t = std::chrono::system_clock;

std::string CurrentDate()
{
	std::time_t now = sysclock_t::to_time_t(sysclock_t::now());

	char buf[100] = { 0 };
	std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

	return std::string(buf);
}

int WorkFunc(int value)
{
	return value* value;
}

void ProcessRequest(SOCKET sock)
{
	std::cout << "start socket request process" << std::endl;

	char buffer[SIZE_BUFFER];
	memset(buffer, 0, SIZE_BUFFER);


	int iResult = recv(sock, buffer, sizeof(buffer), 0);

	if (iResult == SOCKET_ERROR)
	{
		std::cout << "SOCKET_ERROR by recv" << WSAGetLastError();
		closesocket(sock);
		return ;
	}

	int value=atoi(buffer);

	std::cout << "Пришло value = " << value << std::endl;

	value=WorkFunc(value);

	std::cout << "Вычислили value = " << value << std::endl;

	memset(buffer, 0, SIZE_BUFFER);
	_itoa_s(value, buffer, 10);

	iResult = send(sock, buffer, strlen(buffer), 0);

	if (iResult == SOCKET_ERROR)
	{
		std::cout << "SOCKET_ERROR by send" << WSAGetLastError();
		closesocket(sock);
		return;
	}

	closesocket(sock);

	std::cout << "end socket request process" << std::endl << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	WSADATA WSAData = { 0 };
	int wsaStatus = WSAStartup(MAKEWORD(2, 0), &WSAData);

	if (wsaStatus != NO_ERROR) 
	{
		std::cout << "WSA Startup выполнился неуспешно: " << wsaStatus;
		system("pause");
		return 0;
	}

	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0); 

	if (serverSocket == INVALID_SOCKET) {
		std::cout << "INVALID_SOCKET by socket" << WSAGetLastError();
		WSACleanup();
		system("pause");
		return 0;
	}

	SOCKADDR_IN sin = { 0 };
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(1234);

	int iResult=bind(serverSocket, (SOCKADDR*)&sin, sizeof(sin));
	
	if (iResult == SOCKET_ERROR)
	{
		std::cout << "SOCKET_ERROR by bind" << WSAGetLastError();
		WSACleanup();
		system("pause");
		return 0;
	}

	listen(serverSocket, 5); 

	while (1)
	{
		std::cout << "waiting...." << std::endl << std::endl;	

		int sizeof_sin = sizeof(sin); 
		SOCKET sock = accept(serverSocket, (SOCKADDR*)&sin, &sizeof_sin); 		

		std::cout << CurrentDate() << " :: Host connected "<< inet_ntoa(sin.sin_addr)<< std::endl;
		
		if (sock != INVALID_SOCKET)
		{
			ProcessRequest(sock);
		}
		else 
		{
			std::cout << "INVALID_SOCKET by accept" << std::endl;
		}
	}

	closesocket(serverSocket);
	WSACleanup();

	system("pause");
}
#endif // DEBUG


#define CLIENT

#ifdef CLIENT


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	int value = -2;

	if (argc==1)
	{
		std::cout << "необходимо было ввести число"<<std::endl;
	}
	else
	{
		value=atoi(argv[1]);
	}

	std::cout << "value = "<< value << std::endl;

	WSADATA WSAData = { 0 };
	int wsaStatus = WSAStartup(MAKEWORD(2, 0), &WSAData);

	if (wsaStatus != NO_ERROR)
	{
		std::cout << "WSA Startup выполнился неуспешно: " << wsaStatus;
		system("pause");
		return 0;
	}

	SOCKET clientSocket= socket(AF_INET, SOCK_STREAM, 0);

	if (clientSocket == INVALID_SOCKET)
	{
		std::cout << "INVALID_SOCKET by socket" << WSAGetLastError();
		WSACleanup();

		system("pause");
		return 0;
	}

	SOCKADDR_IN sin = {0};//information about the socket

	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(1234);

	

	int iResult = connect(clientSocket, (SOCKADDR*)&sin, sizeof(sin));

	if (iResult == SOCKET_ERROR)
	{ 
		std::cout << "SOCKET_ERROR in  connect" << WSAGetLastError();
		closesocket(clientSocket);
		WSACleanup();

		system("pause");
		return 0;
	}

	std::cout << "start socket request process" << std::endl;

	char buffer[SIZE_BUFFER];
	memset(buffer, 0, SIZE_BUFFER);

	
	_itoa_s(value, buffer, 10);

	iResult = send(clientSocket, buffer, strlen(buffer), 0);

	if (iResult == SOCKET_ERROR)
	{
		std::cout << "SOCKET_ERROR in send " << WSAGetLastError() << std::endl;
		closesocket(clientSocket);
		WSACleanup();

		system("pause");
		return 0;
	}
	
	memset(buffer, 0, SIZE_BUFFER);

	iResult = recv(clientSocket, buffer, sizeof(buffer), 0);

	if (iResult == SOCKET_ERROR)
	{
		std::cout << "SOCKET_ERROR by recv" << WSAGetLastError();
		closesocket(clientSocket);

		system("pause");
		return 0;
	}

	value = atoi(buffer);

	std::cout << "value=" << value << std::endl;
	std::cout << "end socket request process " << std::endl;

	system("pause");
	return 0;
}
#endif // DEBUG




