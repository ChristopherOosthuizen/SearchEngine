//
// Created by chris on 10/28/20.
//

#include <sstream>
#include "Website.h"

int stringToInt(const string& str){
	stringstream interStream(str);
	int meduim =0;
	interStream  >> meduim;
	return meduim;
}

//parsers the strings formatted value:{actual}\n
string findValue(int start, const string &input) {
    int middle = input.find(start,':');
    int end = input.find(middle,'\n');
    return input.substr(middle,end-middle);
}

/*
 * This constructor parses the following format to retires its member variables
 *  "
 *  id:{id}\n
 *  url:{url}\n"
 */
Website::Website(const string &input) {
    //I use stringstream because this appears to be the easiest way to convert a string into a int
    stringstream interStream (findValue(0,input));
    interStream >>m_id;

    m_address = findValue(input.find('\n'),input);
}

Keyword::Keyword(const string& input){
	cout<<"hello";	
}

