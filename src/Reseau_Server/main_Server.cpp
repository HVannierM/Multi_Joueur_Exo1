#include "pch.h"
//#include "main.h"
//#include "Ball_Server.h"
//
//sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
//Ball ball;
//SOCKET server;
//
//DWORD WINAPI Receive(void* lpParam) {
//    char buffer[8];
//    sockaddr_in from;
//    int fromlen = sizeof(from);
//
//    while (true)
//    {
//        int bytesReceived = recvfrom(server, buffer, sizeof(buffer), 0, reinterpret_cast<sockaddr*>(&from), &fromlen);
//        if (bytesReceived <= 0)
//        {
//            std::cout << "Erreur lors de la réception : " << WSAGetLastError() << std::endl;
//            break;
//        }
//        std::cerr << "Received : " << buffer << std::endl;
//        //decode buffer (X/Y)
//        int x, y;
//        std::memcpy(&x, buffer, 4);
//
//        std::memcpy(&y , buffer + 4 , 4);
//
//		ball.SetPosition(x, y);
//        //actualisation (Ball position)
//    }
//    return 0;
//}
//
//
//int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int cmdShow){
//    WSADATA data;
//    WSAStartup(MAKEWORD(2, 2), &data);
//    //Creation Serveur
//    //Thread 1 -> Reception de Valeur ()
//    //Thread 2 -> Affichage SFML avec Valeur Recus
//
//
//    server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//    if (server == INVALID_SOCKET)
//    {
//        std::cout << "Erreur lors de la création de la socket : " << WSAGetLastError() << std::endl;
//        WSACleanup();
//        return -1;
//    }
//    const unsigned short port = 6666;
//    sockaddr_in addr;
//    addr.sin_addr.s_addr = INADDR_ANY;
//    addr.sin_port = htons(port);
//    addr.sin_family = AF_INET;
//
//    std::cout << "init socket server" << std::endl;
//
//    int res = bind(server, (sockaddr*)&addr, sizeof(addr));
//    if (res != 0)
//    {
//        std::cout << "Erreur lors du bind : " << WSAGetLastError() << std::endl;
//        WSACleanup();
//        return -1;
//    }
//    std::cout << "Serveur demarre sur le port " << port << std::endl;
//
//    CreateThread(NULL, 0, Receive, NULL, 0, NULL);
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        window.clear();
//        window.draw(ball.Get());
//        window.display();
//    }
//
//    closesocket(server);
//    WSACleanup();
//    return 0;
//}
