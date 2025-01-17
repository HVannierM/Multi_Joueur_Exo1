#include "pch.h"
//#include "main.h"
//#include "Ball.h"
//#include <string>
//
//SOCKET client;
//Ball ball;
//sockaddr_in serverAddr;
//
//DWORD WINAPI Send_Data_To_Server(void* lpParam);
//
//int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int cmdShow = 1)
//{
//    WSADATA data;
//    WSAStartup(MAKEWORD(2, 2), &data);
//
//    // Initialiser la socket client
//    client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//    if (client == INVALID_SOCKET){
//        std::cerr << "Erreur lors de la création de la socket : " << WSAGetLastError() << std::endl;
//        WSACleanup();
//        return -1;
//    }
//
//    serverAddr.sin_family = AF_INET;
//    serverAddr.sin_port = htons(6666);
//    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
//
//    CreateThread(NULL, 0, Send_Data_To_Server, NULL, 0, NULL);
//
//    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
//    ball.SetPosition(400, 400);
//
//    sf::Clock clock;
//
//    float Start = clock.getElapsedTime().asSeconds();
//    float End = clock.getElapsedTime().asSeconds();
//    float Dt = End - Start;
//    while (window.isOpen())
//    {
//        Start = clock.getElapsedTime().asSeconds();
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        ball.Move(Dt);
//        ball.Check_Collision(800, 800);
//        window.clear();
//        window.draw(ball.Get());
//        window.display();
//        End = clock.getElapsedTime().asSeconds();
//        Dt = End - Start;
//    }
//    closesocket(client);
//    WSACleanup();
//    return 0;
//}
//
//DWORD WINAPI Send_Data_To_Server(void* lpParam) {
//    while (true)
//    {
//        char buff[8];
//		int x = ball.GetPositionX(); 
//		int y = ball.GetPositionY(); 
//
//        std::memcpy(buff, &x, 4);
//        std::memcpy(buff+4, &y, 4);
//
//        int sendResult = sendto(client, buff, sizeof(buff), 0, (sockaddr*)&serverAddr, sizeof(serverAddr));
//        if (sendResult <= 0){
//            std::cerr << "Erreur lors de l'envoi : " << WSAGetLastError() << std::endl;
//            break;
//        }
//    }
//    return 0;
//}