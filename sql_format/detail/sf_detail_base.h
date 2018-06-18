#ifndef SF_DETAIL_BASE_H_
#define SF_DETAIL_BASE_H_

#include <string>

#include "sql_format/sf_base.h"

namespace SqlFormat
{
namespace Detail
{

class DataBase
{
public:
    virtual std::string format(EscapeHandler& escapeHandler) = 0;
};

struct Disable
{
    static const bool enable = false;
};

struct Enable
{
    static const bool enable = true;
};

template<typename T>
class DataWrapper : public Enable
{
public:
    DataWrapper(const T& t) : t_(t) {}

    const T& GetData() const { return t_; }

private:
    T t_;
};

}
}

#endif // SF_DETAIL_BASE_H_
