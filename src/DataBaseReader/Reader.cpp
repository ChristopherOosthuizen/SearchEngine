// Created by chris on 11/8/20->
//

#include <Socket/ClientSock.h>
#include "Reader.h"
#include <algorithm>
list<string> splitString(string str,const string& del){
    int pos =0;
    string token;
    list<string> keywords;
    while ((pos = str.find(del)) != std::string::npos) {
        token = str.substr(0, pos)+'\n';
        if(!token.empty() && token != "\n")
            keywords.push_back(token);
        str.erase(0, pos + del.length());
    }
    return keywords;


}
list<Website> DatabaseReader::findAllWebsites(list<string> words,string type) {
    string whole;
   for(string keyword: words) {
       m_sock->write("SEARCH OBJECT keyword{word:\"" + keyword + "\";}\n\a");
       string result = m_sock->read(10090);
       result = result.substr(result.find('\n'));
       whole+= result;
   }
    list<string> splits = splitString(whole, "\n\n");
    list<Keyword> keywords;
    for(string str:splits){
        Keyword keyword(str);

        keywords.push_back(keyword);
    }


    list<Website> websites;
    for(Keyword key:keywords) {
        m_sock->write("SEARCH OBJECT "+type+"{id:" + to_string(key.m_id) + ";}\n\a");
        string websiteData = m_sock->read(1000);
        websiteData = websiteData.substr(websiteData.find("\n\n") + 1);
        Website web(websiteData);
        if(find(websites.begin(),websites.end(),web) == websites.end()){
            web.m_score = key.m_value;
        websites.push_back(web);
    }
      else{
            auto pos = find(websites.begin(),websites.end(),web);
            pos->m_score += key.m_value;
            cout<< "repetat";
      }
    }

    websites.sort();
    for( Website web: websites)
        cout << web.m_address<<endl;
    cout<< websites.size() ;
       m_sock->write(":q");

    return websites;

}