
#include "exceptions.h"

const char* NoFileAddressEx::what() const throw()
{
        return "No File Address Is Linked.\n";
}

const char* FileOpenEX::what() const throw()
{
        return "File couldn't be opened.\n";
}

const char* NotFoundEx::what() const throw()
{
        return "Not Found\n";
}

const char* BadRequestEx::what() const throw()
{
        return "Bad Request\n";
}

const char* EmptyListEx::what() const throw()
{
        return "Empty\n";
}

const char* PermissionDeniedEx::what() const throw()
{
        return "Permission Denied\n";
}