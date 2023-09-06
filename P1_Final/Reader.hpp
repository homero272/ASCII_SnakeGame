/*
    Homero Arellano ---- This file provides the function prototypes, and is specifically
    			 responsible for the reading and parsing of the json file. Below
			 are the definitions of the functions.
*/

#ifndef P1_TEST_READER_HPP
#define P1_TEST_READER_HPP


#include <iostream>
#include <vector>
#include "Profile.hpp"


#include <fstream>
#include <sstream>
#include <string>
using namespace std;


class Reader {
public:
    vector<Profile> jSonReader(string filename); // main source of reading and parsing, calls Profile class, creating objects of type Profile and adds them to a vector that is returned
    string remove_quotes(string attribute); // is passed an attribute in form of string with quotes, function removes the quotes
    vector<int> follows(string follow_array); // is passed an "array" formated string of object follows attribute and converts into a vector of ints


private:
};



#endif //P1_TEST_READER_HPP
