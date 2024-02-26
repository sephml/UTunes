#ifndef __Playlist
#define __Playlist

#include <string>
#include <vector>
#include "../song/song.h"
#include "../exceptions/exceptions.h"


enum PRIVACY{ PUBLIC , PRIVATE};
class Playlist
{
    public:
        Playlist(std::string _name,PRIVACY p,std::string Uname, int id);
        void printdetails();
        PRIVACY getType(){ return privacy;}
        int getId(){return Pid;}
        void addSong(std::string, Song*);
        void deleteSong(std::string, int);
        void printSongs(std::string);
    private:
        int Pid;
        std::string Pname;
        std::string usrenameOfOwner;
        std::vector<Song*> addedSongs;
        PRIVACY privacy;
};

#endif