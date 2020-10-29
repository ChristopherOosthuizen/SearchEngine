//
// Created by chris on 10/28/20.
//

#ifndef SEARCHENGINE_WEBSITE_H
#define SEARCHENGINE_WEBSITE_H

#include <string>
using namespace std;

//data container  object that just stores the information on a website url
class Website {
    int m_id;
    string m_address;
   static  string findValue(int start,const string& input);

public:
    Website(const string& input);

};


#endif //SEARCHENGINE_WEBSITE_H
