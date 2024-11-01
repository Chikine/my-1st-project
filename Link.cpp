#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <tlhelp32.h>
using namespace std;
//global boolen 
bool CheckSystem = false;
const char* chromePath = "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe";
//get the link randomly
string getlink(){
string randomlink;
string link;
getline(cin,randomlink);
if(randomlink == ""){
link = "https://nhentai.to/g/" + to_string((rand() % 5000)*100 + (rand() % 100)) ;
}
else{link = "";};
return link;
}
//main func
int main(){
string link;
bool loop = true;
bool firstclick = true;
cout << "Window(0) or Mobile(1)?   ";
cin >> CheckSystem;
CheckSystem =!CheckSystem ;
cout << "Enter to generate code";
srand(static_cast<unsigned int>(std::time(0))); // Use current time as seed
while(loop){
link = getlink();
if(!firstclick){
if(link == ""){
     loop = false;
}
else{
    if(CheckSystem){
//string command = "start " + link;
//system(command.c_str());
HINSTANCE result = ShellExecuteA(NULL, "open", chromePath, ("-incognito " + link).c_str(), NULL, SW_SHOWNORMAL);
cout << "redirecting...";
}
else{
cout << link;
};
};
}
else{firstclick = false;};
};
return 0;
}