/****
 * main.cpp
 *
 *  Created on: 2025-01-24
 *  Author    : Mahmoud S. Khedr
 *  version   : .0.1
 *  Email     : mahmoud.s.khedr.2@gmail.com
 *  GitHub    : https://github.com/mahmoud-s-khedr
 *  LinkedIn  : https://www.linkedin.com/in/mahmoud-s-khedr
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;
unordered_map<string, string> map;
void Set(string key, string value, bool force = false) {
    if(map.count(key)&&force==false){
        cout<<"Key already exists use 'set key value --force' to change the value "<<endl;
        return;
    }
    map[key] = value;
}
string Get(string key) {
    if(!map.count(key)){
        cout<<"Key not found"<<endl;
        return "";
    }
    return map[key];
}
void Delete(string key) {
    if(!map.count(key)){
        cout<<"Key not found"<<endl;
        return;
    }
    map.erase(key);
}
vector<string> parse(string args){
    vector<string>commands;
    int start = 0;
    for(int i=0;i<args.size();i++){
        if(args[i]==' '){
            commands.push_back(args.substr(start,i-start));
            start = i+1;
        }
    }
    commands.push_back(args.substr(start));
    return commands;
}
int main() {

    bool flag = true;
    do {
        string args;
        getline(cin, args);
        
        vector<string>commands = parse(args);
        
        if (commands[0] == "set") {
            if (commands.size() == 3) {
                Set(commands[1], commands[2]);
            } else if (commands.size() == 4 && commands[3] == "--force") {
                Set(commands[1], commands[2], true);
            }
        } else if (commands[0] == "get") {
            if (commands.size() == 2) {
                cout << Get(commands[1]) << endl;
            }
        } else if (commands[0] == "delete") {
            if (commands.size() == 2) {
                Delete(commands[1]);
            }
        } else if (commands[0] == "exit") {
            flag = false;
        }

    } while (flag);

    return 0;
}