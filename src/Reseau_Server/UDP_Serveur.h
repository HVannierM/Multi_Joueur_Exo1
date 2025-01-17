#pragma once
#include "pch.h"
#include "main.h"
#include "Ball_Server.h"

class UDPServer {
public:
    UDPServer(unsigned short port);
    ~UDPServer();
    void Start();
    void Stop();

private:
    static DWORD WINAPI Receive(LPVOID lpParam);
    SOCKET server;
    sockaddr_in addr;
    HANDLE receiveThread;
    bool running;
    Ball ball;
    sf::RenderWindow window;
};