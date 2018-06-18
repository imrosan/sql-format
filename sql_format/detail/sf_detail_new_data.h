#ifndef SF_DETAIL_NEW_DATA_H
#define SF_DETAIL_NEW_DATA_H

#include <type_traits>

#include "sql_format/detail/sf_detail_data.h"
#include "sql_format/detail/sf_detail_data_array.h"

namespace SqlFormat
{
namespace Detail
{

template<typename T, bool isArray>
struct NewDataImp {};

template<typename T>
struct NewDataImp<T, false>
{
    template<typename U, typename = typename std::enable_if<Data<U, std::is_arithmetic<U>::value>::enable>::type>
    DataBase* operator()(const U& t) const
    {
        return new Data<U, std::is_arithmetic<U>::value>(t);
    }
};

template<typename T>
struct NewDataImp<T, true>
{
    template<typename U, size_t N, typename = typename std::enable_if<Detail::DataArray<U, N>::enable>::type>
    DataBase* operator()(const U (&t) [N]) const
    {
        return new DataArray<U, N>(t);
    }
};

}
}

#endif // SF_DETAIL_NEW_DATA_H
