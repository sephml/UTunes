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

User::~User()
{
    for(auto playlist: playlists ) delete playlist;
    playlists.clear();
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

void User::addPlayelist(std::string _name, PRIVACY p, int id)
{
    playlists.push_back(new Playlist(_name, p, username, id));
}

void User::printPlaylists(bool isOwner)
{
    if (isOwner)
    {
        
        if(playlists.size() == 0) throw EmptyListEx();
        for(auto p:playlists)
        {
            p->printdetails();
        }

    }else
    {   
        int count = 0;
        for(auto p:playlists)
        {
            if(p->getType()== PUBLIC)
            {
                p->printdetails();
                count ++;
            }
        }
        if(count == 0) throw EmptyListEx();
    }
}

Playlist* User::findPlaylistById(int Pid)
{
    for(auto p: playlists)
    {
        if (p->getId() == Pid)
        {
            return p;
        }
    }
    return nullptr;
}





