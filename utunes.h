#ifndef __utunes
#define __utunes

#include "exceptions.h"
#include "song.h"
#include "user.h"
#include "playlist.h"
#include <string>
#include <vector>
#include <map>
#include <algorithm>

typedef std::map<std::string,int> header;
const int SIGNUP_COMMAND_ATTRIB_LENGTH = 7;
const int LOGIN_COMMAND_ATTRIB_LENGTH = 5;
const int PLAYLIST_CREATE_COMMAND = 5;
const int PLAYLIST_PRINT_COMMAND = 3;
const int PLAYLIST_ADD_SONG_COMMAND = 5;
const int DELETE_SONG_FROM_PLAYLIST = 5;

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
        void deleteaSongFromAPlaylist();
        void printSongs(std::vector<std::string >);
        void printaUsersPlaylists(std::vector<std::string >);
        void printaPlaylistsSongs(std::vector<std::string >);
        void printLikedSongs();
        void printUsers();
        void createPlaylistCommand();
        void addSongToPlaylistCommand();
        std::vector<std::string> parser();
        bool isUserUnique(const std::string&, const std::string&);
        int findSongById(int);
        int findUserByUsername(std::string);
        Playlist* findPlaylistFromUsers(int);
        std::vector<User*> sortUsersByName(std::vector<User*> );
        std::vector<Song*> sortSongs(std::vector<Song*> );
        // bool compareUsersByName(User*, User* );
    public:
        UTunes();
        ~UTunes();
        void readCSV(const std::string fileAddress);
        void readCommands();

};


#endif