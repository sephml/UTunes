#ifndef __Playlist
#define __Playlist

#include <string>
#include <vector>
#include "song.h"

enum PRIVACY{ PUBLIC , PRIVATE};
class Playlist
{
    public:
        Playlist(std::string _name,PRIVACY p, int id);
        void printdetails();
        PRIVACY getType(){ return privacy;}

    private:
        int Pid;
        std::string Pname;
        std::string usrenameOfOwner;
        std::vector<Song*> addedSongs;
        PRIVACY privacy;
};

#endif