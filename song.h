#ifndef __song
#define __song

#include<string>
#include <iostream>

class Song
{

    private:
        int id;
        std::string title;
        std::string artist;
        std::string link;
        int releaseYear;
        int likes;
        int comments;
        int playlists;


    public:
        Song(int, std::string,std::string,int,std::string);


        void decLike(){ likes--;;}
        void incLike(){ likes++;}
        void print();
        int getID(){return id;}
        std::string getTitle(){return title;}
        std::string getArtist(){return artist;}
        int getRYear(){return releaseYear;}
        int getLikes(){return likes;}
        int getComments(){return comments;}
        int getPlaylists(){return playlists;}


};


#endif