#ifndef _User__
#define _User__

#include <string>
#include <vector>
#include "playlist.h"
#include "exceptions.h"

class User
{
    public:
        User(std::string, std::string, size_t pass);
        std::string getUsername(){ return username;}
        size_t getPass(){ return password;}
        std::string getEmail(){ return email;}
        bool hasLiked(int);
        void like(int);
        std::vector <int> getLiked(){ return likedSongs;}
        void disLike(int);
        void addPlayelist(std::string, PRIVACY, int);
        void printPlaylists(bool);
        Playlist* findPlaylistById(int);
        
    private:
        std::string email;
        size_t password;
        std::string username;
        std::vector<int> likedSongs;
        std::vector<Playlist*> playlists;

};

#endif