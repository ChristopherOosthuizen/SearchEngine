//
// Created by chris on 10/27/20.
//

#ifndef SEARCHENGINE_CLIENTSOCK_H
#define SEARCHENGINE_CLIENTSOCK_H
#include <string>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
using namespace std;
class ClientSock {
    int m_port;
    int m_sock;
    string m_address;
public:
    ClientSock(const string& address,int port);
    string read(int size);
    void write(const string& str);
};


#endif //SEARCHENGINE_CLIENTSOCK_H
