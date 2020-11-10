#include <iostream>
#include <fstream>
#include "Socket/ClientSock.h"
#include "DataBaseReader/Reader.h"
#include "../lib/CWebServer/src/Model/Model.h"
#include "../lib/CWebServer/src/Server/Server.h"
#include "../lib/CWebServer/src/Server/Server.cpp"
#include "../lib/CWebServer/src/HTTP/HTTPRequest.h"
//#include "../lib/CWebServer/src/HTTP/HTTPRequest.cpp"
list<string> splitString(string str, string delt){
    list<string> result;
    string actual = str;
    int index =0;
    while((index = actual.find(delt)) != -1){
        string temp = actual.substr(0,index);
        result.push_back(temp);
        actual = actual.substr(index+1);
    }
    result.push_back(actual);
    return result;
}
string base(HTTPResponse response){
    if(response.m_extra.empty() ){

        HTTPRequest http("OK",200,"hello");
        return http.toString();
    }
    string res = response.m_extra.substr(2);
    string result;
    list<string> words =splitString(res,"+");
    DatabaseReader reader(8080);
    list<Website> websites = reader.findAllWebsites(words);
    for(Website web:websites)
        result += "<a href="+web.m_address +">"+web.m_address+"</a><br>";
    HTTPRequest http("OK",200,result);
    return http.toString();
}
int main() {

    DatabaseReader reader(8080);
    list<string> lister;
    lister.push_back("rust");
	reader.findAllWebsites(lister);
    Model* mod = new Model(base,"GET");
    Server server(mod);
    server.run("888");
    return 0;


}
