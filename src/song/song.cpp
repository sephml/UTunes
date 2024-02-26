
#include "song.h"
#include <iostream>

Song::Song(int _id, std::string _title, std::string _artist, int _year, std::string _link)
:id(_id),title(_title),artist(_artist),releaseYear(_year),link(_link){

    likes = 0;
    comments = 0;
    playlists = 0;
}


void Song::print()
{
    std::cout<<id<<" "<<title<<" "<<artist<<" "<<releaseYear<<std::endl;
}


