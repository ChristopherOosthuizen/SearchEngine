#include <iostream>
#include <fstream>
#include "Socket/ClientSock.h"
#include "DataBaseReader/Reader.h"

int main() {

    DatabaseReader reader(8080);
    list<string> lister;
    lister.push_back("rust");
	reader.findAllWebsites(lister);
    return 0;


}
