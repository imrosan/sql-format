#ifndef SF_DETAIL_DATA_H_
#define SF_DETAIL_DATA_H_

#include <vector>
#include <list>
#include <set>
#include <cstdio>
#include <sstream>

#include "sql_format/detail/sf_detail_base.h"

namespace SqlFormat
{

template<typename T>
Detail::DataBase* NewData(const T& t);

namespace Detail
{

template<typename /*T*/, bool /*isArithmetic*/>
class Data : public DataBase, public Disable {};

// for arithmetic type
template<typename T>
class Data<T, true> : public DataBase, public DataWrapper<T>
{
public:
    Data(const T& t) : DataWrapper<T>(t) {}

private:
    virtual std::string format(EscapeHandler& /*escapeHandler*/)
    {
        std::ostringstream oss;
        oss << this->GetData();
        return oss.str();
    }
};

// for 'string' type
template<>
class Data<std::string, false> : public DataBase, public DataWrapper<std::string>
{
public:
    Data(const std::string& t) : DataWrapper<std::string>(t) {}

private:
    virtual std::string format(EscapeHandler& escapeHandler)
    {
        std::string result = "'";
        result += HandleEscape(escapeHandler, GetData());
        result += "'";

        return result; 
    }
};

// for 'char*' type
template<>
class Data<char*, false> : public DataBase, public DataWrapper<char*>
{
public:
    Data(char* const t) : DataWrapper<char*>(t) {}

private:
    virtual std::string format(EscapeHandler& escapeHandler)
    {
        std::string result = "'";
        result += HandleEscape(escapeHandler, GetData());
        result += "'";

        return result; 
    }
};

// for 'const char*' type
template<>
class Data<const char*, false> : public DataBase, public DataWrapper<const char*>
{
public:
    Data(const char* const t) : DataWrapper<const char*>(t) {}

private:
    virtual std::string format(EscapeHandler& escapeHandler)
    {
        std::string result = "'";
        result += HandleEscape(escapeHandler, GetData());
        result += "'";

        return result; 
    }
};

struct LikeData
{
    enum LikeModeFlag
    {
        LIKE_MODE_LEFT = 0x0001,
        LIKE_MODE_RIGHT = 0x0002,
    };

    LikeData(const std::string& _s, int _likeMode) : s(_s), likeMode(_likeMode) {}

    std::string s;
    int likeMode;
};

// for 'LikeData' type
template<>
class Data<LikeData, false> : public DataBase, public DataWrapper<LikeData>
{
public:
    Data(const LikeData& t) : DataWrapper<LikeData>(t) {}

private:
    virtual std::string format(EscapeHandler& escapeHandler)
    {
        const LikeData& likeData = GetData();
        int likeMode = likeData.likeMode;

        std::string result = "'";

        if ((likeMode & LikeData::LIKE_MODE_LEFT) != 0)
        {
            result += '%';
        }

        result += HandleEscape(escapeHandler, likeData.s);

        if ((likeMode & LikeData::LIKE_MODE_RIGHT) != 0)
        {
            result += '%';
        }

        result += "'";

        return result; 
    }
};

template<typename T>
struct InData
{
    InData(const std::vector<T>& _dataList) : dataList(_dataList) {}
    // InData(const std::list<T>& _dataList) : dataList(_dataList.begin(), _dataList.end()) {}
    // InData(const std::set<T>& _dataList) : dataList(_dataList.begin(), _dataList.end()) {}

    std::vector<T> dataList;
};

// for 'InData' type
template<typename T>
class Data<InData<T>, false> : public DataBase, public DataWrapper<InData<T> >
{
public:
    Data(const InData<T>& t) : DataWrapper<InData<T> >(t) {}

private:
    virtual std::string format(EscapeHandler& escapeHandler)
    {
        const InData<T>& inData = this->GetData();
        const std::vector<T>& dataList = inData.dataList;

        std::string result = "(";

        for (size_t i = 0; i < dataList.size(); ++i)
        {
            if (i > 0)
            {
                result += ',';
            }

            DataBase* d = NewData(dataList[i]);
            result += d->format(escapeHandler);
            delete d;
        }

        result += ")";

        return result; 
    }
};

}
}

#endif // SF_DETAIL_DATA_H_
