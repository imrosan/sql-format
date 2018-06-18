# sql-format
功能: SQL语句格式化库，避免SQL拼接，防止SQL注入

1. 使用方法参见demo.cpp
2. 使用"?"问号作为参数的占位符
3. 支持格式化的数据类型有如下:
   1) 基本数字数据类型 bool, char, char16_t, char32_t, wchar_t, short, int, long, long long, float, double
   2) 条目1)对应的无符号版本的数据类型
   3) char*, const char*, string, char[]
4. 字符串类型支持防御SQL注入, 不过需要在sql_format/sf_escape.h文件中定义的escape函数（里面有几个默认实现可以参考）
5. 此库只包含头文件，正常使用包含头文件sql_format/sf_formatter.h 即可



MYSQL mysql;
long uid = 1024;
