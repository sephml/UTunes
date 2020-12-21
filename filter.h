#ifndef __filter__
#define __filter__

#include <string>
#include <vector>
#include "song.h"

// class Filter
// {
//     public:
//         Filter(){};
        
//         virtual void set(std::string command) = 0 ;
//         virtual void reset() = 0 ;
//         virtual std::vector<Song* > DoFilter(const std::vector<Song*>& ) = 0;
//     private:
// };

// class FilterByArtist: public Filter
// {
//     public:
//         FilterByArtist();
//         void set();
//         void reset();
//         std::vector<Song*> DoFilter(const std::vector<Song*>& );

//     private:
//         std::string name; 
// };

// class FilterByLikes : public Filter {
//     public:
//         FilterByLikes();
//         void set(std::string );
//         void reset();
//         std::vector<Song*> DoFilter(const std::vector<Song*>& );

//     private:
//         int minLike;
//         int maxLike;
// };

// class FilterByYear : public Filter {
    
//     public:
//         FilterByYear();
//         void set(std::string rest_of_command);
//         void reset();
//         std::vector<Song*> DoFilter(const std::vector<Song*>& );

//    private:
//         int minYear;
//         int maxYear;
// };


#endif