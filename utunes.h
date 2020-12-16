#ifndef __utunes
#define __utunes

#include "exceptions.h"
#include "song.h"
#include "user.h"
// #include "playlist.h"
#include <string>
#include <vector>
#include <map>

typedef std::map<std::string,int> header;
const int SIGNUP_COMMAND_ATTRIB_LENGTH = 7;
const int LOGIN_COMMAND_ATTRIB_LENGTH = 5;
const int PLAYLIST_CREATE_COMMAND = 5;
const int PLAYLIST_PRINT_COMMAND = 3;


class UTunes
{
    private:
        
        //variables
        std::vector<Song *> songs;
        std::vector<User *> users;
        User* CurrentUser;
        int lastPlaylistId;


        //methods
        void addToSongs(std::string, header);
        header createLabelMap(std::string);
        void handlePost();
        void handleGet();
        void handleDelete();
        void signupCommand();
        void loginCommand();
        void logoutCommand();
        void likeCommand();
        void deleteLikedSong();
        void printSongs(std::vector<std::string >);
        void printaUsersPlaylists(std::vector<std::string >);
        void printLikedSongs();
        void createPlaylistCommand();
        std::vector<std::string> parser();
        bool isUserUnique(const std::string&, const std::string&);
        int findSongById(int);
        int findUserByUsername(std::string);

    public:
        UTunes();
        void readCSV(const std::string fileAddress);
        void readCommands();

};


#endif