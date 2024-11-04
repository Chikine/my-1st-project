#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//global boolen 
bool CheckSystem = true;
//get the link randomly
string getlink(){
string randomlink;
string link;
getline(cin,randomlink);
if(randomlink == ""){
link = "https://nhentai.to/g/" + to_string(rand() % 500000) ;
}
else{link = "";};
return link;
}
//start command on window
int start(string &link){
if(!CheckSystem){
string command = "start " + link;
system(command.c_str());
//cout << link;
}
else{
cout << link;
};
return 0;
}
//main func
int main(){
string link;
bool loop = true;
bool firstclick = true;
cout << "Window(0) or mobile(1)";
cin >> CheckSystem;
cout << "Enter to generate code";
srand(static_cast<unsigned int>(std::time(0))); // Use current time as seed
while(loop){
link = getlink();
if(!firstclick){
(link == "") ? loop = false : start(link);
}
else{firstclick = false;};
};
return 0;
}