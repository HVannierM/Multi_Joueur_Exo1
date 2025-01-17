#pragma once
#include "pch.h"
#include "main.h"
#include "Ball.h"

class UDPClient {
public:
    UDPClient(const std::string& serverIp, unsigned short port);
    ~UDPClient();
    void Start();
    void Stop();

private:
    static DWORD WINAPI SendData(LPVOID lpParam);
    SOCKET client;
    sockaddr_in serverAddr;
    HANDLE sendThread;
    bool running;
    Ball ball;
    sf::RenderWindow window;
};