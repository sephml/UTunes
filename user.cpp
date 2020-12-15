#include "user.h"

User::User(std::string mail, std::string _username, size_t pass)
:email(mail),username(_username),password(pass){}

bool User::hasLiked(int id)
{
    for(auto i: likedSongs)
    {
        if (id == i)
        {
            return true;
        }
    }
    return false;
}

void User::like(int Sid)
{
    likedSongs.push_back(Sid);
}

void User::disLike(int id)
{
    std::vector<int> tempLikes;
    for(auto i : likedSongs)
    {
        if (i != id)
        {
            tempLikes.push_back(i);
        }
    }
    likedSongs = tempLikes;
}
