#include <iostream>

#include "sql_format/sf_formatter.h"

DefaultEscapeHandler mysql;

// MYSQL mysql;

// taf::TC_DBConf conf;
// taf::TC_Mysql mysql(conf);


long uid = 1024; // 用户id 
std::string product = "book"; // 产品名称
const char* remark = "newest"; // 备注关键字
int startIndex = 10; // 分页开始
int pageSize = 10; // 分页大小

void basic_usage() // 基本用法
{
    std::string sql = SqlFormat::Format(mysql, "SELECT * FROM t_order WHERE uid=? AND remark=? LIMIT ?,?", uid, remark, startIndex, pageSize);
    std::cout << sql << std::endl; // SELECT * FROM t_order WHERE uid=1024 AND remark='newest' LIMIT 10,10
}

void like_support() // LIKE支持 
{
    std::string sql = SqlFormat::Format(mysql, "SELECT * FROM t_order WHERE remark LIKE ?", like_lr(remark));
    std::cout << sql << std::endl; // SELECT * FROM t_order WHERE remark LIKE '%newest%' 
}

void complex_logic_support() // 复杂逻辑 
{
    bool searchRemark = false; // 是否是搜索备注
    bool paging = true; // 是否分页

    std::string sql = "SELECT * FROM t_order WHERE uid=? ";
    SqlFormat::Formatter formatter(uid);

    if (searchRemark)
    {
        sql += "AND remark= ";
        formatter.append(remark);
    }

    if (paging)
    {
        sql += "LIMIT ?,? ";
        formatter.append(startIndex, pageSize);
    }

    std::cout << formatter.format(mysql, sql) << std::endl; // SELECT * FROM t_order WHERE uid=1024 LIMIT 10,10
}

void in_range_support() // 范围支持 
{
    std::list<std::string> productList = {"book", "iphone", "cup"};
    std::string sql = SqlFormat::Format(mysql, "SELECT * FROM t_order WHERE product IN ?", in_range(productList));
    std::cout << sql << std::endl; // SELECT * FROM t_order WHERE product IN ('book','iphone','cup') 
}

int main()
{
    basic_usage();
    like_support();
    complex_logic_support();
    in_range_support();

    return 0;
}
