#include "utunes.h"
#include <iostream>
#include "exceptions.h"



int main(int argc, char const *argv[])
{

    try
    {
        if (argc <1) throw NoFileAddressEx();

        UTunes ut;
        ut.readCSV(argv[1]);
        ut.readCommands();

    }catch(std::exception&  e)
    {
        std::cerr<< e.what();
    }


    
    return 0;
}