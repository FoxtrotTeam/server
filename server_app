#include "stdafx.h"
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <windows.h>
#include "app.h"
#define MAX_LOADSTRING 100

#include <iostream>
#include <sstream>
#include <string>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

// Необходимо, чтобы линковка происходила с DLL-библиотекой 
#pragma comment (lib, "ws2_32.lib") 
#pragma comment (lib, "mswsock.lib")

using namespace std;

#define		MAX_CONN	10
#define		MSG_LEN		128

int main()
{
	WSADATA wsaData;
	// старт использования библиотеки сокетов процессом
	// (подгружается Ws2_32.dll)
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	// Если произошла ошибка подгрузки библиотеки
	if (result != 0)
	{
		cout << "WSAStartup failed: " << result << "\n";
		return result;
	}
	else
	{
		cout << "WSAStartup succeed" << endl;
	}

	struct addrinfo* addr = NULL; // структура, хранящая информацию
	// об IP-адресе  слущающего сокета

	// Шаблон для инициализации структуры адреса
	struct addrinfo hints;
	ZeroMemory(&hints, sizeof(hints));

	// AF_INET определяет, что используется сеть для работы с сокетом, это семейство адресов которые слушает сокет,
	//поэтому в getaddrinfo в качестве первого параметра NULL
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM; // Задаем потоковый тип сокета
	hints.ai_protocol = IPPROTO_TCP; // Используем протокол TCP
	// Сокет биндится на адрес, чтобы принимать входящие соединения
	hints.ai_flags = AI_PASSIVE;

	// Инициализируем структуру, хранящую адрес сокета - addr.
	// HTTP-сервер будет висеть на 8000-м порту локалхоста
	result = getaddrinfo("NULL", "1332", &hints, &addr);

	// Если инициализация структуры адреса завершилась с ошибкой,
	// выведем сообщением об этом и завершим выполнение программы 
	if (result != 0)
	{
		cout << "getaddrinfo failed: " << result << "\n";
		WSACleanup(); // выгрузка библиотеки Ws2_32.dll
		return 1;
	}
	else
	{
		cout << "getaddrinfo succeed" << endl;
	}

	// Создание сокета
	int listen_socket = socket(addr->ai_family, addr->ai_socktype,
		addr->ai_protocol);
	// Если создание сокета завершилось с ошибкой, выводим сообщение,
	// освобождаем память, выделенную под структуру addr,
	// выгружаем dll-библиотеку и закрываем программу
	if (listen_socket == INVALID_SOCKET)
	{
		cout << "Error at socket: " << WSAGetLastError() << "\n";
		freeaddrinfo(addr);
		WSACleanup();
		return 1;
	}
	else
	{
		cout << "Creating socket succeed" << endl;
	}

	// Привязываем сокет к IP-адресу
	result = bind(listen_socket, addr->ai_addr, (int)addr->ai_addrlen);

	// Если привязать адрес к сокету не удалось, то выводим сообщение
	// об ошибке, освобождаем память, выделенную под структуру addr.
	// и закрываем открытый сокет.
	// Выгружаем DLL-библиотеку из памяти и закрываем программу.
	if (result == SOCKET_ERROR)
	{
		cout << "bind failed with error: " << WSAGetLastError() << "\n";
		freeaddrinfo(addr);
		closesocket(listen_socket);
		WSACleanup();
		return 1;
	}
	else
	{
		cout << "Bind succeed" << endl;
	}

	// Инициализируем слушающий сокет
	if (listen(listen_socket, SOMAXCONN) == SOCKET_ERROR)
	{
		cout << "listen failed with error: " << WSAGetLastError() << "\n";
		closesocket(listen_socket);
		WSACleanup();
		return 1;
	}
	else
	{
		cout << "Listen succeed" << endl;
	}


	const int max_client_buffer_size = 1024;
	char buf[max_client_buffer_size]="world!)\0";
	const char *ans = &buf[max_client_buffer_size];
	
	int client_socket = INVALID_SOCKET;

	for (;;)
	{
		// Принимаем входящие соединения
		client_socket = accept(listen_socket, NULL, NULL);
		if (client_socket == INVALID_SOCKET)
		{
			cout << "accept failed: " << WSAGetLastError() << "\n";
			closesocket(listen_socket);
			WSACleanup();
			return 1;
		}
		else
		{
			cout << "Accept succeed" << endl;
		}

		result = recv(client_socket, buf, max_client_buffer_size, 0);



		if (result == SOCKET_ERROR)
		{
			// ошибка получения данных
			cout << "recv failed: " << result << "\n";
			closesocket(client_socket);
		}
		else if (result == 0)
		{
			// соединение закрыто клиентом
			cout << "connection closed...\n";
		}
		else if (result > 0)
		{
			// Мы знаем размер полученных данных, поэтому ставим метку конца строки
			// В буфере запроса.
			cout << "Data recieved" << endl;
			buf[result] = '\0';
			




			// Отправляем ответ клиенту с помощью функции send
			result = send(client_socket, ans,
				max_client_buffer_size, 0);

			if (result == SOCKET_ERROR)
			{
				// произошла ошибка при отправле данных
				cout << "send failed: " << WSAGetLastError() << "\n";
			}
			else
			{
				cout << "Send succeed"<<endl;
			}

			// Закрываем соединение к клиентом
			closesocket(client_socket);
		}
	}

	closesocket(listen_socket);
	freeaddrinfo(addr);
	WSACleanup();
	return 0;

}
