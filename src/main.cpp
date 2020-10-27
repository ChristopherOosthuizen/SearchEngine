#include <iostream>
#include <fstream>
#include "Socket/ClientSock.h"

int main() {

    ClientSock sock("127.0.0.1",8080);
    sock.write("/home/chris/\a");

   string line;

    ifstream file("/home/chris/IdeaProjects/searchEngine/src/preloadData.txt");
    while(getline(file,line)){

        sock.write(line+"\a");
        cout<<sock.read(100)<<endl;
    }
    sock.write("SEARCH OBJECT keyword {id:12;}\n\a");
    cout<< sock.read(100) << endl;
    cout<<sock.read(100000);


}