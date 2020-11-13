//
// Created by chris on 11/8/20.
//
#pragma once
#ifndef SEARCHENGINE_READER_H
#define SEARCHENGINE_READER_H
#include <DataBaseReader/Website.h>
#include <string>
#include <list>
#include <set>

using namespace std;
class KeywordData{
    int m_id;
    string m_url;
    list<Website> m_websites;
    list<Keyword> m_keywords;
public:
   KeywordData(int id,string url,const list<Website>& websites, const list<Keyword>& keywords){
       m_id=id;
       m_keywords = keywords;
       m_url = url;
   }


};

class DatabaseReader {
    int m_port;
    ClientSock* m_sock;
public:

    DatabaseReader(int port){
        m_port = port;
        m_sock  = new ClientSock("localhost",m_port);
        m_sock->write("/home/chris/\a");
    }

    ~DatabaseReader() {
        m_sock->write(":q");
        delete m_sock;
    }
    list<Website> findAllWebsites(list<string> keyword,string type);
};


#endif //SEARCHENGINE_READER_H
