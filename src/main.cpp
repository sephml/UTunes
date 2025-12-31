#include "./utunes/utunes.h"
#include <iostream>
#include "./exceptions/exceptions.h"



int main(int argc, char const *argv[])
{

    try
    {
        if (argc < 2) throw NoFileAddressEx();

        UTunes ut;
        ut.readCSV(argv[1]);
        ut.readCommands();

    }catch(std::exception&  e)
    {
        std::cerr<< e.what();
    }


    
    return 0;
}