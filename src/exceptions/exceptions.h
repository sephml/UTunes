#ifndef __Exception
#define __Exception

#include <exception>

class NoFileAddressEx: public std::exception
{
  virtual const char* what() const throw();
};

class FileOpenEX:public std::exception
{
  virtual const char* what() const throw();
};

class NotFoundEx:public std::exception
{
  virtual const char* what() const throw();
};

class BadRequestEx:public std::exception
{
  virtual const char* what() const throw();
};

class PermissionDeniedEx: public std::exception
{
  virtual const char* what() const throw();
};

class EmptyListEx: public std::exception
{
  virtual const char* what() const throw();
};




#endif