#include "utunes.h"
#include <iostream>
#include <fstream>
#include <sstream>
 
UTunes::UTunes(){}
 
void UTunes::readCSV(const std::string fileAddress)
{
    std::string line;
    header head;
    bool firstRow =true;
    try{
        std::fstream csvFile;
        bool firstRow =true;
        csvFile.open(fileAddress, std::ios::in);
        if (csvFile.is_open())
        {
            while ( getline(csvFile, line))
            {   
                if(firstRow)
                {
                    head = createLabelMap(line);
                    firstRow = false;
                    continue;
                }
                addToSongs(line,head);
            }
            csvFile.close();
        }else
        {
            throw FileOpenEX();
        }
    }
    catch(std::exception& e)
    {
        std::cerr<<e.what();
    }
}

header UTunes::createLabelMap(std::string line)
{
    header head;
    int colNum = 0;
    std::stringstream s(line);
    std::string word;
    while( std::getline(s,word,','))
    {
        head.insert(std::pair<std::string, int> (word , colNum));
        ++colNum;
    }
    return head;
}

void UTunes::addToSongs(std::string line, header head)
{   std::string word;
    std::stringstream s(line);
    std::vector<std::string> words;
    words.clear();
    while( std::getline(s, word, ','))
    {
        words.push_back(word);
    }

    songs.push_back(new Song(stoi(words[head["id"]]),
                            words[head["title"]],
                            words[head["artist"]],
                            stoi(words[head["release_year"]]),
                            words[head["link"]]));

}

void UTunes::readCommands()
{
    std::string command;
   
    while(true)
    {
        try
        {
            command.clear();
            std::cin>> command;
            if(command == "POST")
            {
                handlePost();
            }
            else if(command == "GET")
            {
                handleGet();
            }    
            else if(command == "DELETE")
            {
                handleDelete();
            }else
            {
                std::getline(std::cin,command);
                throw NotFoundEx();
            }
        }catch(std::exception& e)
        {
            std::cerr<<e.what();
        }
    }   
}

void UTunes::handlePost()
{
    std::string action;
    std::cin>>action;
    try
    {
        if(action == "signup")
        {
            signupCommand();
        }else if(action == "login")
        {
            loginCommand();
        }else if(action == "logout")
        {
            logoutCommand();
        }else if(action == "likes")
        {
            likeCommand();
        }
        else
        {
            throw BadRequestEx();
        }
    }catch(std::exception& e)
    {
        std::cerr << e.what();
    }
}

void UTunes::likeCommand()
{   

    if(CurrentUser == nullptr) 
    {   
        std::string command;
        std::getline(std::cin,command);
        throw PermissionDeniedEx();
    };

    std::vector<std::string> parsedCommand = parser();
    int id = stoi(parsedCommand[2]);
    if(findSongById(id)==-1) throw NotFoundEx();
    if(CurrentUser->hasLiked(id)) throw BadRequestEx();
    CurrentUser->like(id);
    songs[findSongById(id)]->incLike();
    std::cout<<"OK\n";
}

void UTunes::signupCommand()
{
    std::vector<std::string> parsedCommand = parser();
    std::hash<std::string> str_hash;
    if (parsedCommand.size() != SIGNUP_COMMAND_ATTRIB_LENGTH) throw BadRequestEx();
    if (parsedCommand[1] != "email" || parsedCommand[3] != "username" || parsedCommand[5] != "password") throw BadRequestEx();
    if (!isUserUnique(parsedCommand[2],parsedCommand[4])) throw BadRequestEx();
    CurrentUser = new User(parsedCommand[2],parsedCommand[4],str_hash(parsedCommand[6]));
    users.push_back(CurrentUser);
    std::cout<<"OK\n";
}

bool UTunes::isUserUnique(const std::string& email,const std::string& username)
{
    for(auto u:users)
    {
        if (u->getUsername() == username || u->getEmail() == email )
        {
            return false;
        }
    }
    return true;
}

std::vector<std::string> UTunes::parser()
{
    std::string word,line;
    std::getline(std::cin, line);
    std::stringstream s(line);
    std::vector<std::string> words;
    words.clear();
    while( std::getline(s, word, ' '))
    {
        words.push_back(word);
    }
    words.erase(words.begin());
    // words.erase(words.begin());
    return words;
}

void UTunes::loginCommand()
{
    bool logSuccess = false;
    std::vector<std::string> parsedCommand = parser();
    if (parsedCommand.size() != LOGIN_COMMAND_ATTRIB_LENGTH) throw BadRequestEx();
    std::hash<std::string> str_hash;
    
    for(auto u: users)
    {   
        if (u->getEmail() == parsedCommand[2] && u->getPass() == str_hash(parsedCommand[4]))
        {
            CurrentUser = u;
            logSuccess = true;
            std::cout<<"OK\n";
            break;
        }
    }
    if (!logSuccess) throw BadRequestEx();
}

void UTunes::logoutCommand()
{
    if (CurrentUser == nullptr) throw PermissionDeniedEx();
    CurrentUser = nullptr;
    std::cout<<"OK\n";
}

void UTunes::handleGet()
{
    try
    {   

        std::vector<std::string> parsedCommand = parser();
        std::string action = parsedCommand[0];
        if(action == "users")
        {
            // getUsers();
        }else if(action == "songs")
        {   
            parsedCommand.erase(parsedCommand.begin());
            printSongs(parsedCommand);
        }else if(action == "likes")
        {   
            parsedCommand.erase(parsedCommand.begin());
            printLikedSongs();
        }
        else
        {
            throw BadRequestEx();
        }
    }catch(std::exception& e)
    {
        std::cerr << e.what();
    }
}

void UTunes::printLikedSongs()
{
    if (CurrentUser == nullptr) throw PermissionDeniedEx();
    
    std::vector<int> likedSongs = CurrentUser->getLiked();
    if (likedSongs.size() == 0) throw EmptyListEx();
    for(auto s: likedSongs)
    {
        int id = findSongById(s);
        songs[id]->print();
    }
    
}

void UTunes::printSongs(std::vector<std::string > attribs)
{   
    if( CurrentUser == nullptr) throw PermissionDeniedEx();
    if(songs.size() == 0) throw EmptyListEx();
    if(attribs.size() == 0)
    {
        for(auto s:songs)
        {
            s->print();
        }
    }else
    {
        int id = findSongById(stoi(attribs[2]));
        if (id == -1) throw NotFoundEx();
        std::cout<< songs[id]->getID()<<std::endl;
        std::cout<< songs[id]->getTitle()<<std::endl;
        std::cout<< songs[id]->getArtist()<<std::endl;
        std::cout<< songs[id]->getRYear()<<std::endl;
        std::cout<<"#likes: "<< songs[id]->getLikes()<<std::endl;
        std::cout<<"#comments: "<< songs[id]->getComments()<<std::endl;
        std::cout<<"#playlists: "<< songs[id]->getPlaylists()<<std::endl;
    }
}


int UTunes::findSongById(int _id)
{
    for (int i = 0; i < songs.size(); i++)
    {
        if (songs[i]->getID()==_id)
        {
           return i;
        }
    }
    return -1;
}

void UTunes::handleDelete()
{
    std::string action;
    std::cin>>action;
    try
    {
        if(action == "likes")
        {
            deleteLikedSong();
        }else if(action == "logout")
        {
            
        }
        else
        {
            throw BadRequestEx();
        }
    }catch(std::exception& e)
    {
        std::cerr << e.what();
    }
}
 
void UTunes::deleteLikedSong()
{
    std::vector<std::string> parsedCommand = parser();
    if(CurrentUser == nullptr) throw PermissionDeniedEx();
    int id = stoi(parsedCommand[2]);
    if(!CurrentUser->hasLiked(id)) throw BadRequestEx();
    CurrentUser->disLike(id);
    songs[findSongById(id)]->decLike();
    std::cout<<"OK\n";
}
 










