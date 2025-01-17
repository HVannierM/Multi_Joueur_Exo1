#include "pch.h"
#include "UDP_Serveur.h"

UDPServer::UDPServer(unsigned short port) : window(sf::VideoMode(800, 800), "Serveur Window"), running(false) {
    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);

    server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (server == INVALID_SOCKET) {
        std::cerr << "Erreur lors de la création de la socket : " << WSAGetLastError() << std::endl;
        WSACleanup();
        throw std::runtime_error("Socket creation failed");
    }

    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;

    if (bind(server, (sockaddr*)&addr, sizeof(addr)) != 0) {
        std::cerr << "Erreur lors du bind : " << WSAGetLastError() << std::endl;
        closesocket(server);
        WSACleanup();
        throw std::runtime_error("Bind failed");
    }
}

UDPServer::~UDPServer() {
    Stop();
    closesocket(server);
    WSACleanup();
}

void UDPServer::Start() {
    running = true;
    receiveThread = CreateThread(NULL, 0, Receive, this, 0, NULL);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(ball.Get());
        window.display();
    }
}

void UDPServer::Stop() {
    running = false;
    if (receiveThread) {
        WaitForSingleObject(receiveThread, INFINITE);
        CloseHandle(receiveThread);
    }
}

DWORD WINAPI UDPServer::Receive(LPVOID lpParam) {
    UDPServer* serverInstance = static_cast<UDPServer*>(lpParam);
    char buffer[8];
    sockaddr_in from;
    int fromlen = sizeof(from);

    while (serverInstance->running) {
        int bytesReceived = recvfrom(serverInstance->server, buffer, sizeof(buffer), 0, reinterpret_cast<sockaddr*>(&from), &fromlen);
        if (bytesReceived <= 0) {
            std::cerr << "Erreur lors de la réception : " << WSAGetLastError() << std::endl;
            break;
        }
        std::cerr << "Received : " << buffer << std::endl;

        int x, y;
        std::memcpy(&x, buffer, 4);
        std::memcpy(&y, buffer + 4, 4);

        serverInstance->ball.SetPosition(x, y);
    }
    return 0;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int cmdShow) {
    try {
        UDPServer server(6666);
        server.Start();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}