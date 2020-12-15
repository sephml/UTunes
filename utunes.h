#ifndef __utunes
#define __utunes

#include "exceptions.h"
#include "song.h"
#include "user.h"
#include <string>
#include <vector>
#include <map>

typedef std::map<std::string,int> header;
const int SIGNUP_COMMAND_ATTRIB_LENGTH = 7;
const int LOGIN_COMMAND_ATTRIB_LENGTH = 5;

class UTunes
{
    private:
        
        //variables
        std::vector<Song *> songs;
        std::vector<User *> users;
        User* CurrentUser;
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
        void printLikedSongs();
        std::vector<std::string> parser();
        bool isUserUnique(const std::string&, const std::string&);
        int findSongById(int);


    public:
        UTunes();
        void readCSV(const std::string fileAddress);
        void readCommands();

};


#endif