/*
  Homero Arellano ---- This file gives the prototypes of all the functions used by my 
  		       Profile class, as seen, it contains the attributes of each
		       user. Below is are descriptions for each function.
*/

#ifndef P1_TEST_PROFILE_HPP
#define P1_TEST_PROFILE_HPP


#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>


using namespace std;

class Profile {

public:
    Profile(); // default constructor
    Profile(int uniqueID, string uniqueName, string uniqueLoc, string uniqueUrl, vector<int> uniqueFollow);// parameterized constructor with attibutes of user.
    int getID() {return id;} // returns id of that specific Profile object
    string getName() {return name;} //returns the name of that specific Profile object
    string Converter(int num); // function that converts an int data type into a string datatype
    vector<Profile> usersInOrder(vector<Profile> users); //passed a vector of users, and returns a new vector of users sorted by their id
    Profile getUser(vector<Profile> users,int user_id); // gets and returns a user by their id
    void index_html(vector<Profile> all_users); // passed a vector of all users and creates an index html page 
    void users_html (string filename, vector<Profile> all_users); // passed a desired name of file and a vector of all the users, and spits out html pages for each






private:
    int id;
    string name;
    string location;
    string pic_url;
    vector<int> follows;


};


#endif //P1_TEST_PROFILE_HPP
