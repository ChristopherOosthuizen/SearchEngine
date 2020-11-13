//
// Created by chris on 10/28/20.
//

#ifndef SEARCHENGINE_WEBSITE_H
#define SEARCHENGINE_WEBSITE_H

#include <iostream>
#include <string>
using namespace std;

//data container  object that just stores the information on a website url
class Website {

    friend bool operator==(const Website& lhs, const Website& rhs){
        return lhs.m_id  == rhs.m_id|| lhs.m_address == rhs.m_address;
    }

    friend bool operator<(const Website& lhs,const Website& rhs){
        return lhs.m_score> rhs.m_score;
    }

public:
    Website(const string& input);
    int m_id;
    int m_score;

    string m_address;
};

class Keyword {

	public:
		int m_id;
		int m_value;
        string m_word;
		Keyword(const string& input);
};



#endif //SEARCHENGINE_WEBSITE_H
