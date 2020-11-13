#include <iostream>
#include <fstream>
#include "Socket/ClientSock.h"
#include "DataBaseReader/Reader.h"
#include "../lib/CWebServer/src/Model/Model.h"
#include "../lib/CWebServer/src/Server/Server.h"
#include "../lib/CWebServer/src/Server/Server.cpp"
#include "../lib/CWebServer/src/HTTP/HTTPRequest.h"
#include <signal.h>
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
        string result = "";
        string line;
        ifstream file("/home/chris/Projects/SearchEngine/src/home.html");

        while(getline(file,line)){

            result +=(line);

        }
        HTTPRequest http("OK",200,result);
        return http.toString();
    }
    string res = response.m_extra.substr(2);
    string result ="<input type=\"text\" name=\"search bar\" id=\"search\">\n"
                   "<input type=\"button\" name=\"submit\" id=\"submit\" value=\"search\">\n"
                   "<input type=\"button\" name=\"submit\" id=\"image\" value=\"image\">\n"
                   "<br> results for :<p id='location'>"+response.m_extra.substr(2) +"</p><br>"
                   "<script>\n"
                   "document.getElementById('submit').onclick = function() {\n"
                   "if(document.getElementById(\"search\").value !==\"\")"
                   "    location.href = '/?=' +document.getElementById(\"search\").value.trim().replaceAll(\" \",\"%\").toLowerCase();\n"
                   "};\n"
                   "document.getElementById('image').onclick = function() {\n"
                   "if(document.getElementById(\"location\").value !==\"\")"
                   "    location.href = '/images/?=' +document.getElementById('location').innerHTML;"
                   "\n"
                   "}\n"
                   "</script><br>";
    list<string> words =splitString(res,"%");
    DatabaseReader reader(8080);
    list<Website> websites = reader.findAllWebsites(words,"website");
    for(Website web:websites)
        result += "<a href="+web.m_address +">"+web.m_address+"</a><br>";
    HTTPRequest http("OK",200,result);
    return http.toString();
}
string images(HTTPResponse response){
    if(response.m_extra.empty() ){
        string result = "";
        string line;
        ifstream file("/home/chris/Projects/SearchEngine/src/home.html");

        while(getline(file,line)){

            result +=(line);

        }
        HTTPRequest http("OK",200,result);
        return http.toString();
    }
    string res = response.m_extra.substr(2);
    string result = "<input type=\"text\" name=\"search bar\" id=\"search\">\n"
                    "<input type=\"button\" name=\"submit\" id=\"submit\" value=\"search\">\n"
                    "<input type=\"button\" name=\"submit\" id=\"image\" value=\"image\">\n"
                    "<br> results for :<p id='location'>"+response.m_extra.substr(2) +"</p><br>"
                    "<script>\n"
                    "document.getElementById('submit').onclick = function() {\n"
                    "if(document.getElementById(\"search\").value !==\"\")"
                    "    location.href = '/?=' +document.getElementById(\"search\").value.trim().replaceAll(\" \",\"%\").toLowerCase();\n"
                    "};\n"
                    "document.getElementById('image').onclick = function() {\n"
                    "if(document.getElementById(\"search\").value !==\"\")"
                    "    location.href = '/images/?=' +document.getElementById('location').innerHTML;"
                    "\n"
                    "}\n"
                    "</script><br>";
    list<string> words =splitString(res,"%");
    DatabaseReader reader(8080);
    list<Website> websites = reader.findAllWebsites(words,"image");
    for(Website web:websites)
        result += "<img widht=200 height=200 src="+web.m_address +">";
    HTTPRequest http("OK",200,result);
    return http.toString();
}
void sigpipe_handler(int unused)
{
}

int main() {
    signal(SIGPIPE, sigpipe_handler);
    Model* mod = new Model(base,"GET");
    mod->add("images","GET",images);
    Server server(mod);
    server.run("888");
    return 0;


}
