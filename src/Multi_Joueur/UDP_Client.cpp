#include "pch.h"
#include "UDP_Client.h"

UDPClient::UDPClient(const std::string& serverIp, unsigned short port) : window(sf::VideoMode(800, 800), "Client Window"), running(false) {
    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);

    client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (client == INVALID_SOCKET) {
        std::cerr << "Erreur lors de la création de la socket : " << WSAGetLastError() << std::endl;
        WSACleanup();
        throw std::runtime_error("Socket creation failed");
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, serverIp.c_str(), &serverAddr.sin_addr);
}

UDPClient::~UDPClient() {
    Stop();
    closesocket(client);
    WSACleanup();
}

void UDPClient::Start() {
    running = true;
    sendThread = CreateThread(NULL, 0, SendData, this, 0, NULL);

    ball.SetPosition(400, 400);
    sf::Clock clock;

    float Start = clock.getElapsedTime().asSeconds();
    float End = clock.getElapsedTime().asSeconds();
    float Dt = End - Start;
    while (window.isOpen()) {
        Start = clock.getElapsedTime().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ball.Move(Dt);
        ball.Check_Collision(800, 800);
        window.clear();
        window.draw(ball.Get());
        window.display();
        End = clock.getElapsedTime().asSeconds();
        Dt = End - Start;
    }
}

void UDPClient::Stop() {
    running = false;
    if (sendThread) {
        WaitForSingleObject(sendThread, INFINITE);
        CloseHandle(sendThread);
    }
}

DWORD WINAPI UDPClient::SendData(LPVOID lpParam) {
    UDPClient* clientInstance = static_cast<UDPClient*>(lpParam);
    while (clientInstance->running) {
        char buff[8];
        int x = clientInstance->ball.GetPositionX();
        int y = clientInstance->ball.GetPositionY();

        std::memcpy(buff, &x, 4);
        std::memcpy(buff + 4, &y, 4);

        int sendResult = sendto(clientInstance->client, buff, sizeof(buff), 0, (sockaddr*)&clientInstance->serverAddr, sizeof(clientInstance->serverAddr));
        if (sendResult <= 0) {
            std::cerr << "Erreur lors de l'envoi : " << WSAGetLastError() << std::endl;
            break;
        }
    }
    return 0;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int cmdShow) {
    try {
        UDPClient client("127.0.0.1", 6666);
        client.Start();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}