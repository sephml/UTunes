#ifndef __Playlist
#define __Playlist

#include <string>
#include <vector>
#include "user.h"


class Playlist
{
    public:
        Playlist();
    private:
        enum PRIVACY{ PUBLIC , PRIVATE};
        std::string name;
        User* owner;
        PRIVACY privacy;
};

#endif