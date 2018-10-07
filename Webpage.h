#pragma once

#include <string>
using namespace std;

class Webpage {
public:
    Webpage();
    Webpage(const string&, const time_t&);
    string getUrl();
    time_t getTime();

private:
    string url;
    time_t time;
};

Webpage::Webpage(){
    url = "#";
    time = time_t(0000000000);
}

Webpage::Webpage(const string& webpageUrl, const time_t& timeVisited){
    url = webpageUrl;
    time = timeVisited;
}

string Webpage::getUrl(){
    return url;
}

time_t Webpage::getTime(){
    return time;
}