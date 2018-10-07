#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>
#include "Webpage.h"
using namespace std;

class BrowserHistory {
public:
    BrowserHistory();

    void visitSite(Webpage newSite);
    string back();
    string forward();

    void readHistory(string fileName);

    string getUrl();
    size_t getNavSize();
    list<Webpage> getSitesVisited();

private:
    list<Webpage> navHistory;
    list<Webpage>::iterator navPos;
    list<Webpage> sitesVisited;
    int numSites;
};
BrowserHistory::BrowserHistory(){
    numSites = 0;
    navPos = navHistory.end();
}
string BrowserHistory::back(){
    if (navHistory.size()<=1)
        throw invalid_argument("Can't go back. History is empty");
    --navPos;
       
    return navPos->getUrl();        
}
string BrowserHistory::forward(){
    if(navHistory.end() == navPos)
        throw invalid_argument("Can't go forward. Forward History is empty.");
    navPos++;
    string _url = getUrl();
    return _url;
}
size_t BrowserHistory::getNavSize(){
    size_t temp = navHistory.size();
    
    return temp;
}
string BrowserHistory::getUrl(){
    if(navHistory.empty())
    {
        throw invalid_argument("History Empty");
    }
    return navPos->getUrl();
}

list<Webpage> BrowserHistory::getSitesVisited(){
    return sitesVisited;
}
void BrowserHistory::visitSite(Webpage newSite){
    navHistory.push_back(newSite);
    sitesVisited.push_back(newSite);
    numSites++;
    //navPos = navHistory.end();
}
void BrowserHistory::readHistory(string fileName) {
    string temp;
    int newTime;
    Webpage newSite;
    ifstream inFile(fileName.c_str());

    while(inFile >> temp) {
        if(temp == "new") {
            inFile >> temp >> newTime;
            newSite = Webpage(temp, time_t(newTime));
            visitSite(newSite);
        } else if(temp == "back") {
            back();
        } else if(temp == "forward") {
            forward();
        } else {
            throw logic_error("invalid command");
        }
    }
}
