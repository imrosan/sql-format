#ifndef SF_FORMATTER_H_
#define SF_FORMATTER_H_

#include <vector>
#include <type_traits>

#include "sql_format/detail/sf_detail_new_data.h"

inline SqlFormat::Detail::LikeData like_l(const std::string& s)
{
    return SqlFormat::Detail::LikeData(s, SqlFormat::Detail::LikeData::LIKE_MODE_LEFT);
}

inline SqlFormat::Detail::LikeData like_r(const std::string& s)
{
    return SqlFormat::Detail::LikeData(s, SqlFormat::Detail::LikeData::LIKE_MODE_RIGHT);
}

inline SqlFormat::Detail::LikeData like_lr(const std::string& s)
{
    return SqlFormat::Detail::LikeData(s, (SqlFormat::Detail::LikeData::LIKE_MODE_LEFT | SqlFormat::Detail::LikeData::LIKE_MODE_RIGHT));
}

template<typename T>
SqlFormat::Detail::InData<T> in_range(const std::vector<T>& dataList)
{
    return SqlFormat::Detail::InData<T>(dataList);
}

template<typename T>
SqlFormat::Detail::InData<T> in_range(const std::list<T>& dataList)
{
    return SqlFormat::Detail::InData<T>(std::vector<T>(dataList.begin(), dataList.end()));
}

template<typename T>
SqlFormat::Detail::InData<T> in_range(const std::set<T>& dataList)
{
    return SqlFormat::Detail::InData<T>(std::vector<T>(dataList.begin(), dataList.end()));
}

namespace SqlFormat
{

template<typename T>
Detail::DataBase* NewData(const T& t)
{
    return Detail::NewDataImp<T, std::is_array<T>::value >()(t);
}

class Formatter
{
public:
    Formatter() {}

    template<typename A0>
    Formatter(const A0& a0)
    {
        append(a0);
    }

    template<typename A0, typename A1>
    Formatter(const A0& a0, const A1& a1)
    {
        append(a0, a1);
    }

    template<typename A0, typename A1, typename A2>
    Formatter(const A0& a0, const A1& a1, const A2& a2)
    {
        append(a0, a1, a2);
    }

    template<typename A0, typename A1, typename A2, typename A3>
    Formatter(const A0& a0, const A1& a1, const A2& a2, const A3& a3)
    {
        append(a0, a1, a2, a3);
    }

    template<typename A0, typename A1, typename A2, typename A3, typename A4>
    Formatter(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4)
    {
        append(a0, a1, a2, a3, a4);
    }

    template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
    Formatter(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5)
    {
        append(a0, a1, a2, a3, a4, a5);
    }

    template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
    Formatter(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6)
    {
        append(a0, a1, a2, a3, a4, a5, a6);
    }

    template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
    Formatter(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7)
    {
        append(a0, a1, a2, a3, a4, a5, a6, a7);
    }

    template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
    Formatter(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8)
    {
        append(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }

    template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
    Formatter(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9)
    {
        append(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }

    template<typename A0>
    void append(const A0& a0)
    {
        dataList_.push_back(NewData(a0));
    }

    template<typename A0, typename A1>
    void append(const A0& a0, const A1& a1)
    {
        dataList_.push_back(NewData(a0));
        dataList_.push_back(NewData(a1));
    }

    template<typename A0, typename A1, typename A2>
    void append(const A0& a0, const A1& a1, const A2& a2)
    {
        dataList_.push_back(NewData(a0));
        dataList_.push_back(NewData(a1));
        dataList_.push_back(NewData(a2));
    }

    template<typename A0, typename A1, typename A2, typename A3>
    void append(const A0& a0, const A1& a1, const A2& a2, const A3& a3)
    {
        dataList_.push_back(NewData(a0));
        dataList_.push_back(NewData(a1));
        dataList_.push_back(NewData(a2));
        dataList_.push_back(NewData(a3));
    }

    template<typename A0, typename A1, typename A2, typename A3, typename A4>
    void append(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4)
    {
        dataList_.push_back(NewData(a0));
        dataList_.push_back(NewData(a1));
        dataList_.push_back(NewData(a2));
        dataList_.push_back(NewData(a3));
        dataList_.push_back(NewData(a4));
    }

    template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
    void append(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5)
    {
        dataList_.push_back(NewData(a0));
        dataList_.push_back(NewData(a1));
        dataList_.push_back(NewData(a2));
        dataList_.push_back(NewData(a3));
        dataList_.push_back(NewData(a4));
        dataList_.push_back(NewData(a5));
    }

    template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
    void append(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6)
    {
        dataList_.push_back(NewData(a0));
        dataList_.push_back(NewData(a1));
        dataList_.push_back(NewData(a2));
        dataList_.push_back(NewData(a3));
        dataList_.push_back(NewData(a4));
        dataList_.push_back(NewData(a5));
        dataList_.push_back(NewData(a6));
    }

    template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
    void append(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7)
    {
        dataList_.push_back(NewData(a0));
        dataList_.push_back(NewData(a1));
        dataList_.push_back(NewData(a2));
        dataList_.push_back(NewData(a3));
        dataList_.push_back(NewData(a4));
        dataList_.push_back(NewData(a5));
        dataList_.push_back(NewData(a6));
        dataList_.push_back(NewData(a7));
    }

    template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
    void append(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8)
    {
        dataList_.push_back(NewData(a0));
        dataList_.push_back(NewData(a1));
        dataList_.push_back(NewData(a2));
        dataList_.push_back(NewData(a3));
        dataList_.push_back(NewData(a4));
        dataList_.push_back(NewData(a5));
        dataList_.push_back(NewData(a6));
        dataList_.push_back(NewData(a7));
        dataList_.push_back(NewData(a8));
    }

    template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
    void append(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9)
    {
        dataList_.push_back(NewData(a0));
        dataList_.push_back(NewData(a1));
        dataList_.push_back(NewData(a2));
        dataList_.push_back(NewData(a3));
        dataList_.push_back(NewData(a4));
        dataList_.push_back(NewData(a5));
        dataList_.push_back(NewData(a6));
        dataList_.push_back(NewData(a7));
        dataList_.push_back(NewData(a8));
        dataList_.push_back(NewData(a9));
    }

    template<typename EscapeHandler>
    std::string format(EscapeHandler& escapeHandler, const std::string& sql)
    {
        static const std::string placeholder = "?";

        std::string result = sql;
        size_t pos = 0;

        for (size_t i = 0; i < dataList_.size(); ++i)
        {
            Detail::DataBase* d = dataList_[i]; 

            size_t p = result.find(placeholder, pos);
            if (p == std::string::npos)
                throw PlaceholderException();

            std::string formatted = d->format(escapeHandler);
            result.replace(p, placeholder.size(), formatted); 

            pos = p + formatted.size();
        }

        return result;
    }
    
private:
    std::vector<Detail::DataBase*> dataList_;
};

// helper functions
template<typename A0>
std::string Format(EscapeHandler& escapeHandler, const std::string& sql, const A0& a0)
{
    Formatter formatter(a0);
    return formatter.format(escapeHandler, sql);
}

template<typename A0, typename A1>
std::string Format(EscapeHandler& escapeHandler, const std::string& sql, const A0& a0, const A1& a1)
{
    Formatter formatter(a0, a1);
    return formatter.format(escapeHandler, sql);
}

template<typename A0, typename A1, typename A2>
std::string Format(EscapeHandler& escapeHandler, const std::string& sql, const A0& a0, const A1& a1, const A2& a2)
{
    Formatter formatter(a0, a1, a2);
    return formatter.format(escapeHandler, sql);
}

template<typename A0, typename A1, typename A2, typename A3>
std::string Format(EscapeHandler& escapeHandler, const std::string& sql, const A0& a0, const A1& a1, const A2& a2, const A3& a3)
{
    Formatter formatter(a0, a1, a2, a3);
    return formatter.format(escapeHandler, sql);
}

template<typename A0, typename A1, typename A2, typename A3, typename A4>
std::string Format(EscapeHandler& escapeHandler, const std::string& sql, const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4)
{
    Formatter formatter(a0, a1, a2, a3, a4);
    return formatter.format(escapeHandler, sql);
}

template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
std::string Format(EscapeHandler& escapeHandler, const std::string& sql, const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5)
{
    Formatter formatter(a0, a1, a2, a3, a4, a5);
    return formatter.format(escapeHandler, sql);
}

template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
std::string Format(EscapeHandler& escapeHandler, const std::string& sql, const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6)
{
    Formatter formatter(a0, a1, a2, a3, a4, a5, a6);
    return formatter.format(escapeHandler, sql);
}

template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
std::string Format(EscapeHandler& escapeHandler, const std::string& sql, const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7)
{
    Formatter formatter(a0, a1, a2, a3, a4, a5, a6, a7);
    return formatter.format(escapeHandler, sql);
}

template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
std::string Format(EscapeHandler& escapeHandler, const std::string& sql, const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8)
{
    Formatter formatter(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    return formatter.format(escapeHandler, sql);
}

template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
std::string Format(EscapeHandler& escapeHandler, const std::string& sql, const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9)
{
    Formatter formatter(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    return formatter.format(escapeHandler, sql);
}

}

#endif // SF_FORMATTER_H_
