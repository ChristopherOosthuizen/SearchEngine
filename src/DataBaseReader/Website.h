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
    int m_id;
    string m_address;

public:
    Website(const string& input);

};

class Keyword {

	public:
		int m_id;
		int m_value;
	
		Keyword(const string& input);
};



#endif //SEARCHENGINE_WEBSITE_H
