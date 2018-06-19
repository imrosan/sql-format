sql-format
===========

#### 功能: SQL语句格式化库，避免SQL拼接，防止SQL注入

#### 使用说明：
1. 使用方法参见demo.cpp
2. 使用"?"问号作为参数的占位符
3. 支持格式化的数据类型有如下:
   1) 基本数字数据类型 bool, char, char16_t, char32_t, wchar_t, short, int, long, long long, float, double
   2) 条目1)对应的无符号版本的数据类型
   3) char*, const char*, string, char[]
4. 字符串类型支持防御SQL注入, 不过需要在sql_format/sf_escape.h文件中定义的escape函数（里面有几个默认实现可以参考）
5. 此库只包含头文件，正常使用包含头文件sql_format/sf_formatter.h 即可


#### 常用使用方法：
MYSQL mysql;</br>
long uid = 1024; // 用户id </br>
std::string product = "book"; // 产品名称</br>
const char* remark = "newest"; // 备注关键字</br>
int startIndex = 10; // 分页开始</br>
int pageSize = 10; // 分页大小</br>


#### 基本用法
std::string sql = SqlFormat::Format(mysql, "SELECT * FROM t_order WHERE uid=? AND remark=? LIMIT ?,?", uid, remark, startIndex, pageSize);</br>
// SELECT * FROM t_order WHERE uid=1024 AND remark='newest' LIMIT 10,10


#### LIKE支持 
std::string sql = SqlFormat::Format(mysql, "SELECT * FROM t_order WHERE remark LIKE ?", like_lr(remark));</br>
// SELECT * FROM t_order WHERE remark LIKE '%newest%' 


#### 范围支持 
std::list&lt;std::string&gt; productList = {"book", "iphone", "cup"};</br>
std::string sql = SqlFormat::Format(mysql, "SELECT * FROM t_order WHERE product IN ?", in_range(productList));</br>
// SELECT * FROM t_order WHERE product IN ('book','iphone','cup') 


#### 复杂逻辑 
bool searchRemark = false; // 是否是搜索备注</br>
bool paging = true; // 是否分页</br>

std::string sql = "SELECT * FROM t_order WHERE uid=? ";</br>
SqlFormat::Formatter formatter(uid);</br>

if (searchRemark)</br>
{</br>
    &nbsp;&nbsp;&nbsp;&nbsp;sql += "AND remark= ";</br>
    &nbsp;&nbsp;&nbsp;&nbsp;formatter.append(remark);</br>
}</br>

if (paging)</br>
{</br>
    &nbsp;&nbsp;&nbsp;&nbsp;sql += "LIMIT ?,? ";</br>
    &nbsp;&nbsp;&nbsp;&nbsp;formatter.append(startIndex, pageSize);</br>
}</br>

std::string sql = formatter.format(mysql, sql);</br>
// SELECT * FROM t_order WHERE uid=1024 LIMIT 10,10</br>
