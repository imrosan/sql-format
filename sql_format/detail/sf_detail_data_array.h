#ifndef SF_DETAIL_DATA_ARRAY_H_
#define SF_DETAIL_DATA_ARRAY_H_

#include "sql_format/detail/sf_detail_base.h"

namespace SqlFormat
{
namespace Detail
{

template<typename /*T*/, size_t /*N*/>
struct DataArray : public DataBase, public Disable {};

template<size_t N>
class DataArray<char, N> : public DataBase, public DataWrapper<const char*>
{
public:
    DataArray(const char (&t) [N]) : DataWrapper<const char*>(t) {}

private:
    virtual std::string format(EscapeHandler& escapeHandler)
    {
        std::string result = "'";
        result += HandlerEscape(escapeHandler, GetData());
        result += "'";

        return result; 

    }
};

}
}

#endif // SF_DETAIL_DATA_ARRAY_H_
