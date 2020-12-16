#include "playlist.h"
#include <iostream>

Playlist::Playlist(std::string _name,PRIVACY p, int id)
:Pname(_name),privacy(p),Pid(id){
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