#include "playlist.h"
#include <iostream>

Playlist::Playlist(std::string _name,PRIVACY p, std::string Uname,int id)
:Pname(_name),privacy(p),Pid(id),usrenameOfOwner(Uname){
}

void Playlist::printdetails()
{
    std::string p;
    if (privacy == PRIVATE)
    {
        p = "private";
    }else
    {
        p = "public";
    }

    std::cout<<Pid<<" "<<Pname<<" "<<p<<std::endl;
}

void Playlist::addSong(std::string Uname, Song* s)
{
    if (Uname != usrenameOfOwner) throw PermissionDeniedEx();
    for(auto song:addedSongs)
    {
        if (s->getID() == song->getID())
        {
            return;
        }
        
    }
    addedSongs.push_back(s);
    
}

void Playlist::printSongs(std::string Uname)
{   
    if (Uname != usrenameOfOwner && privacy == PRIVATE) throw PermissionDeniedEx();
    
    if(addedSongs.size() == 0) throw EmptyListEx();
    for(auto s:addedSongs)
    {
        s->print();
    }
}
