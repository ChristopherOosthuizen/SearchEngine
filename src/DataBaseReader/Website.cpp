//
// Created by chris on 10/28/20.
//

#include <sstream>
#include "Website.h"

int stringToInt(string str){
	stringstream interStream(str);
	int meduim =0;
	interStream  >> meduim;
	return meduim;
}

//parsers the strings formatted value:{actual}\n
string findValue(int start, const string &input) {
    int middle = input.find(":",start)+1;
    int end = input.find("\n",start);
    return input.substr(middle,end-middle);
}

/*
 * This constructor parses the following format to retires its member variables
 *  "
 *  id:{id}\etchn
 *  url:{url}\n"
 */
Website::Website(const string &input) {
    //I use stringstream because this appears to be the easiest way to convert a string into a int
    m_id = stringToInt(findValue(1,input));
    m_address = findValue(input.find("\n",1)+1,input);
    m_score =0;
}

Keyword::Keyword(const string& input){

    m_id = stringToInt(findValue(0,input));
    m_value = stringToInt(findValue(input.find("\n"),input));
    m_word = findValue(input.find("\n",input.find("\n")),input);

}

