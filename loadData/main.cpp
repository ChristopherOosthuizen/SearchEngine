//
// Created by chris on 11/9/20.
//


#include <iostream>
#include <fstream>
#include "Socket/ClientSock.h"
#include "DataBaseReader/Reader.h"

int main(){

    ClientSock sock("127.0.0.1",8080);
    sock.write("/home/chris/\a");

    string line;

    ifstream file("/home/chris/Projects/SearchEngine/loadData/preloadData.txt");
    while(getline(file,line)){

        sock.write(line+"\a");
        sock.read(100);
    }
    sock.write(":q");

}