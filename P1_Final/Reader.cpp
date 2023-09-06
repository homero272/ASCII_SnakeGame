/*
   Homero Arellano ---- This file corresponds to the Reader.hpp and provides definitions
   			to all the functions in the hpp. Specifically, this file is 
			responsible for reading and parsing the json file.
*/
#include <iostream>
#include <vector>

#include "Reader.hpp"

#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string Reader::remove_quotes(string attribute) {
    string updated_attribute = "";
    for(int i = 0; i < attribute.size(); ++i)
    {
        if(attribute[i] !='\"')
        {
            updated_attribute += attribute[i];
        }
    }
    return updated_attribute;

}

vector<int> Reader::follows(string follow_array) {
    vector<int> updated;
    string noBrackets = "";
    for(int i = 0; i < follow_array.size(); ++i)
    {
        if(isdigit(follow_array[i]) || follow_array[i] == ',')
        {
            noBrackets += follow_array[i];
        }
    }

    stringstream buffer(noBrackets);
    string line = "";
    while(getline(buffer,line,','))
    {
        stringstream converter;
        int num;
        converter << line;
        converter >> num;
        updated.push_back(num);
    }
    return updated;
}



vector<Profile> Reader::jSonReader(string filename) {
    string reader;
    int id;
    string name, location, url;
    vector<int> follow_vec;
    ifstream jSon;
    vector<Profile> users;
    jSon.open(filename);
    if(!jSon.is_open())
    {
        cout << "Couldn't open " << filename << endl;
    }
    else
    {
        while(!jSon.eof()) {
            if(reader == "}," || reader == "}")
            {
                Profile curr_user(id,name,location,url,follow_vec);
                users.push_back(curr_user);
                id = 0;
                name = location = url = "";
                follow_vec.clear();

                if(reader == "}"){
                    break;
                }
            }
            jSon >> reader;
            while (reader != ",") {

                if(reader == "},"|| reader == "}")
                {

                    break;
                }

                else if(reader == "\"id_str\"")
                {
                    stringstream converter;
                    jSon >> reader;
                    jSon >> reader;
                    converter << (remove_quotes(reader));
                    converter >> id;


                }
                else if(reader == "\"name\"")
                {
                    jSon >> reader;
                    jSon >> reader;
                    if(reader[reader.size()-1] != '\"')
                    {
                        string half = "";
                        jSon >> half;
                        reader += " ";
                        reader += half;
                    }
                    name = remove_quotes(reader);
                }
                else if(reader == "\"location\"")
                {
                    jSon >> reader;
                    jSon >> reader;
                    if(reader[reader.size()-1] != '\"')
                    {
                        string half = "";
                        jSon >> half;
                        reader += " ";
                        reader += half;
                    }
                    location = remove_quotes(reader);
                }
                else if(reader == "\"pic_url\"")
                {
                    jSon >> reader;
                    jSon >> reader;
                    url = remove_quotes(reader);
                }
                else if(reader == "\"follows\"")
                {
                    string temp;

                    jSon >> reader;
                    jSon >> reader;
                    temp = remove_quotes(reader);
                    follow_vec = follows(temp);

                }
                jSon >> reader;
            }
        }


    }

    return users;


}

