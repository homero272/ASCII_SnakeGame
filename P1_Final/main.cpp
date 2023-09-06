/*
   Homero Arellano --- This file calls functions from my Reader and Profile class. This file is repsonsible for
		       calling functions that spit out the index page and the html page for every user in the json file
*/
#include <iostream>
#include <vector>
//#include "Profile.hpp"
#include "Reader.hpp"

#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string filename = "input.json";
    
    Reader get_users;
    vector<Profile> all_users;
    all_users = get_users.jSonReader(filename);
    
    string u = "user";
    string h = ".html";
    Profile temp;
    all_users = temp.usersInOrder(all_users);
    Profile test;
    test.index_html(all_users);

    for(unsigned long int i = 0; i < all_users.size(); ++i) {

        string user_num;
        stringstream converter;
        converter << i + 1;
        user_num = converter.str();

        all_users.at(i).users_html(u+ user_num + h, all_users);
    }




    return 0;
}
