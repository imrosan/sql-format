#ifndef SF_BASE_H_
#define SF_BASE_H_

#include <exception>
#include <string>

#include "sql_format/sf_escape.h"

namespace SqlFormat
{

class SqlFormatException : public std::exception
{
public:
    SqlFormatException() {}

private:
    virtual const char* what() const throw()
    {
        return "sql escape exception";
    }
};

class PlaceholderException : public SqlFormatException 
{
public:
    PlaceholderException() {}

private:
    virtual const char* what() const throw()
    {
        return "sql placeholder exception";
    }

};

}

#endif // SF_BASE_H_
