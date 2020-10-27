//
// Created by chris on 10/27/20.
//

#include <stdexcept>
#include "ClientSock.h"

ClientSock::ClientSock(const string& address, int port){
    m_sock =  0;
    struct sockaddr_in serv_addr{};

    //connect to socket with address and port all other settings are arbitrary
    m_sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, address.c_str(), &serv_addr.sin_addr);
    int worked = connect(m_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    //the connect function returns -1 if the socket cant connect
    if(worked ==-1){
        throw std::invalid_argument(" unable to connect");
    }

}

void ClientSock::write(const string &str) {
    send(m_sock,str.c_str(),str.length(),0);

}

string ClientSock::read(int size) {
    char buffer[size];
    ::read(m_sock,buffer,size);
    return string(buffer);
}