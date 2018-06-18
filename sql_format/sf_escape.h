#ifndef SF_ESCAPE_H_
#define SF_ESCAPE_H_

// default escape, do nothing 
struct DefaultEscapeHandler {};

namespace SqlFormat
{

typedef DefaultEscapeHandler EscapeHandler;

inline std::string HandleEscape(EscapeHandler& handler, const std::string& s)
{
    return s;
}

// mysql escape
/*
#include <mysql.h>

namespace SqlFormat
{

typedef MYSQL EscapeHandler;

inline std::string HandleEscape(EscapeHandler& handler, const std::string& s)
{
    std::string r(s.size() * 2 + 1, '\0');
    mysql_real_escape_string(&handler, &r[0], s.c_str(), s.size()); 
    return r;
}
*/

/*
// tc_mysql escape
#include <util/tc_mysql.h>

namespace SqlFormat
{

typedef taf::TC_Mysql EscapeHandler;

inline std::string HandleEscape(EscapeHandler& handler, const std::string& s)
{
    return handler.escapeString(s);
}
*/

};

#endif // SF_ESCAPE_H_
