/*
   Homero Arellano ---- This file corresponds to Profile.hpp and defines all the functions in it.
			Specifically, holds attributes of a Profile type data type, spitting out index and profiles html,
			and sorting the users
*/ 
#include <vector>
#include "Profile.hpp"
#include <fstream>
#include <sstream>
#include <string>
//#include <bits/stdc++.h>

Profile::Profile()
{
    int id = 0;
    string name = "";
    string location = "";
    string pic_url = "";
    vector<int> follows;
}

Profile::Profile(int uniqueID, string uniqueName, string uniqueLoc, string uniqueUrl, vector<int> uniqueFollow){
    id = uniqueID;
    name = uniqueName;
    location = uniqueLoc;
    pic_url = uniqueUrl;
    follows = uniqueFollow;


}


string Profile::Converter(int num) {
    stringstream converter;
    string literal;
    converter << num;
    literal = converter.str();
    return literal;
}

Profile Profile::getUser(vector<Profile> users,int user_id) {
    for(int i = 0; i < users.size(); ++i)
    {
        if(users.at(i).getID() == user_id)
        {
            return users.at(i);
        }
    }
}


vector<Profile> Profile::usersInOrder(vector<Profile> users) {
    vector<Profile> sorted_users;
    vector<int> ids;
    Profile temp;
    for(int i = 0; i < users.size(); ++i)
    {
        ids.push_back(users.at(i).getID());
    }
    sort(ids.begin(),ids.end());
    for(int i = 0; i < ids.size(); ++i)
    {
        sorted_users.push_back(getUser(users,ids.at(i)));
    }
    return sorted_users;



}



void Profile::index_html(vector<Profile> all_users) {
    ofstream index_html("index.html");
    index_html << "<!DOCTYPE html>" << endl;
    index_html << "<html>" << endl;
    index_html << "<head>" << endl;
    index_html << "<title> My Social Network </title>" << endl;
    index_html << "</head>" << endl;
    index_html << "<body>" << endl;
    index_html << "<h1> My Social Network: User List </h1>" << endl;
    index_html << "<ol>" << endl;
    for(int i = 0; i < all_users.size(); ++i)
    {
        string literal = Converter(i+1);
        index_html << "<li><a href =\"user" + literal + ".html\">" << all_users.at(i).name << "</a></li>" << endl;
    }
    index_html << "</ol>" << endl;
    index_html << "</body>" << endl;
    index_html << "</html>" << endl;
}





void Profile::users_html(string filename, vector<Profile> all_users) {
    ofstream html_file(filename);
    html_file << "<!DOCTYPE html>" << endl;
    html_file << "<html>" << endl;
    html_file << "<head>" << endl;
    html_file << "<title> " << name << "'s Profile </title>" << endl;
    html_file << "</head>" << endl;
    html_file << "<body>" << endl;
    if(location != "") {
        html_file << "<h1> " << name << " in " << location << "</h1>" << endl;
    }
    else{
        html_file << "<h1> " << name << "</h1>" << endl;//"" in " << "Unknown" << "</h1>" << endl;
    }
    if(pic_url != "")
    {
        html_file << "<img alt= \"Profile pic\" src = "<< pic_url << " />" << endl;
    }
    else{
        html_file << "<img alt= \"Profile pic\" src = "<< "https://upload.wikimedia.org/wikipedia/commons/a/ac/No_image_available.svg" << " />" << endl;
    }
    html_file << "<h2> Follows </h2>" << endl;
    html_file << "<ul>" << endl;
    vector<Profile> following;
    if(follows.size() < 1)
    {
        html_file << "NONE" << endl;
    }

    else {
        for(int i =0; i < follows.size(); ++i)
        {
            if(all_users.at(0).id == follows.at(i))
            {
                following.push_back(all_users.at(0));
                html_file << "<li><a href = \"user" << all_users.at(0).id << ".html\">" << all_users.at(0).name << "</a></li>"
                          << endl;
                continue;
            }
            int low = all_users.at(0).id;
            int high = all_users.at(all_users.size()-1).id;
            int mid;
            while(low<=high)
            {
                mid = (low +high)/2;
                if(all_users.at(mid).id == follows.at(i))
                {
                    following.push_back(all_users.at(mid));
                    html_file << "<li><a href = \"user" << all_users.at(mid).id << ".html\">" << all_users.at(mid).name << "</a></li>"
                              << endl;
                    break;
                }
                else if(follows.at(i) > all_users.at(mid).id)
                {
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
	}
    }
    vector<Profile> followers;
    html_file << "</ul>" << endl;
    html_file << "<h2> Followers</h2>" << endl;
    html_file << "<ul>" << endl;
    int count = 0;
    for(int i = 0; i < all_users.size(); ++i)
    {
        for(int j = 0; j < all_users.at(i).follows.size(); ++j)
        {
            if(all_users.at(i).follows.at(j) == id)
            {
                followers.push_back(all_users.at(i));
                count += 1;
                int userid = all_users.at(i).getID();
                string literal_num = Converter(userid);
                html_file << "<li><a href = \"user" + literal_num + ".html\">" << all_users.at(i).name << "</a></li>"
                          << endl;
            }
        }
    }
    if(count == 0)
    {
        html_file << "NONE" << endl;
    }
    html_file << "</ul>" << endl;


    html_file << "<h2> Mutuals </h2>" << endl;
    html_file << "<ul>" << endl;
    int mutual_count = 0;
    if(following.size() < followers.size()) {
        for (int i = 0; i < following.size(); ++i) {
            int low = 0;
            int high = followers.size()-1;
            if(following.at(i).id == followers.at(0).id)
            {
                mutual_count ++;
                html_file << "<li><a href = \"user" << following.at(i).id << ".html\">" << following.at(i).name << "</a></li>"
                          << endl;
                continue;
            }
            while(low<=high)
            {
                int mid = (low + high)/2;
                if(following.at(i).id == followers.at(mid).id)
                {
                    mutual_count ++;
                    html_file << "<li><a href = \"user" << following.at(i).id << ".html\">" << following.at(i).name << "</a></li>"
                              << endl;
                    break;
                }
                else if(following.at(i).id > followers.at(mid).id)
                {
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }


            }

        }
    }
    else{
        for(int i = 0; i < followers.size(); ++i)
        {
            int low = 0;
            int high = following.size()-1;
            if(followers.at(i).id == following.at(0).id)
            {
                mutual_count ++;
                html_file << "<li><a href = \"user" << followers.at(i).id << ".html\">" << followers.at(i).name << "</a></li>"
                          << endl;
                continue;
            }
            while(low<=high)
            {
                int mid = (low + high)/2;
                if(followers.at(i).id == following.at(mid).id)
                {
                    mutual_count ++;
                    html_file << "<li><a href = \"user" << followers.at(i).id << ".html\">" << followers.at(i).name << "</a></li>"
                              << endl;
                    break;
                }
                else if(followers.at(i).id > following.at(mid).id)
                {
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }


            }
        }
    }
    if(mutual_count == 0)
    {
        html_file << "NONE" << endl;
    }

    html_file << "</ul>" << endl;
    html_file << "</body>" << endl;
    html_file << "</html>" << endl;
    html_file.close();


}



