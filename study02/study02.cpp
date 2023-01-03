/*
 * 项目名称：数据类型测试程序
 * 日期：2022-1-2
 * 
 * 收获：wchar_t 类型，即宽字符型，本质上是一种int类型
 * 
 */
#include <iostream>
#include <limits>

//#define TEST_EXTERN 1         //失败的猜想
//#define GLOBAL_VARIABLE_TEST 1
//#define CONSTANT_QUANTITY_TEST 1


#ifdef TEST_EXTERN
extern int test_extern;
void test_extern_fun(void);
#endif

#ifdef GLOBAL_VARIABLE_TEST
int global_x;
void global_variable_test(void);
#endif // GLOBAL_VARIABLE_TEST

#ifdef CONSTANT_QUANTITY_TEST

#define CONSTANT_QUANTITY_1 11
const int constant_quantity_2 = 12;

#endif

void data_type_test(void);
void memory_occupation_test(void);
void value_range_test(void);
void type_definition_test(void);
void enum_test(void);

int main()
{
#ifdef TEST_EXTERN
    int test_extern = 10;
    std::cout << "befor: test_extern = " << test_extern << std::endl;
    test_extern_fun();
    std::cout << "end:   test_extern = " << test_extern << std::endl;
#endif

#ifdef GLOBAL_VARIABLE_TEST
    std::cout << "before: global_x = " << global_x << std::endl;
    global_variable_test();
    std::cout << "after : global_x = " << global_x << std::endl;
#endif

#ifdef CONSTANT_QUANTITY_TEST

    std::cout << "常量1：" << CONSTANT_QUANTITY_1 << "\t来自宏定义" << std::endl;
    std::cout << "常量2：" << constant_quantity_2 << "\t来自常变量定义" << std::endl;

#endif

    //  data_type_test();
    //  memory_occupation_test();
    //  value_range_test();
    //  type_definition_test();
    //  enum_test();

    std::cout << "\n完成测试\n";
    return 0;
}

void data_type_test(void)
{
    std::cout << "以下是基本数据类型测试： " << std::endl;

    bool data1 = 2;
    std::cout << "bool data1 = " << data1 << std::endl;

    char data2 = 'L';
    std::cout << "char data2 = " << data2 << std::endl;

    int data3 = 98;
    std::cout << "int  data3 = " << data3 << std::endl;

    float data4 = 3.1415926535897;
    std::cout << "float data4 = " << data4 << std::endl;

    double data5 = 3.1415926535897;
    std::cout << "double data5 = " << data5 << std::endl;

    wchar_t data6 = '乐';
    std::cout << "wchar_t data6 = " << data6 << std::endl;

    wchar_t data7 = 'P';
    std::cout << "wchar_t data7 = " << data7 << std::endl;

    int data8 = 'P';
    std::cout << "int data8 = " << data8 << std::endl;

    int data9 = '乐';
    std::cout << "int data9 = " << data9 << std::endl;

    long double data10 = 3.1415926535897;
    std::cout << "long double data10 = " << data10 << std::endl;
}

void memory_occupation_test(void)
{
    std::cout << std::endl << "以下是类型占用内存大小： " << std::endl;

    std::cout << "bool 占用字节数：" << sizeof(bool) << std::endl;
    std::cout << "int 占用字节数：" << sizeof(int) << std::endl;
    std::cout << "char 占用字节数：" << sizeof(char) << std::endl;
    std::cout << "float 占用字节数：" << sizeof(float) << std::endl;
    std::cout << "double 占用字节数：" << sizeof(double) << std::endl;
    std::cout << "long 占用字节数：" << sizeof(long) << std::endl;
    std::cout << "long long 占用字节数：" << sizeof(long long) << std::endl;
    std::cout << "wchar_t 占用字节数：" << sizeof(wchar_t) << std::endl;
    std::cout << "long double 占用字节数：" << sizeof(long double) << std::endl;
    std::cout << "size_t 占用字节数：" << sizeof(size_t) << std::endl;

}

void value_range_test(void)
{
    std::cout << "以下是取值范围测试" << std::endl;

    std::cout << "bool max:" << (std::numeric_limits< bool >::max)() 
        << "\tmin:" << (std::numeric_limits< bool >::min)() << std::endl;

    std::cout << "char max:" << (int)(std::numeric_limits< char >::max)()
        << "\tmin:" << (int)(std::numeric_limits< char >::min)() << std::endl;

    std::cout << "int max:" << (std::numeric_limits< int >::max )()
        << "\tmin:" << (std::numeric_limits< int >::min)() << std::endl;

    std::cout << "wchar_t max:" << (std::numeric_limits< wchar_t >::max )()
        << "\tmin:" << (std::numeric_limits< wchar_t >::min)() << std::endl;

    std::cout << "long max:" << (std::numeric_limits< long >::max )()
        << "\tmin:" << (std::numeric_limits< long >::min)() << std::endl;

    std::cout << "long long max:" << (std::numeric_limits< long long >::max )()
        << "\tmin:" << (std::numeric_limits< long long >::min)() << std::endl;

    std::cout << "float max:" << (std::numeric_limits< float >::max)()
        << "\tmin:" << (std::numeric_limits< float >::min)() << std::endl;

    std::cout << "double max:" << (std::numeric_limits< double >::max)()
        << "\tmin:" << (std::numeric_limits< double >::min)() << std::endl;
    
    std::cout << "long double max:" << (std::numeric_limits< long double >::max)()
        << "\tmin:" << (std::numeric_limits< long double >::min)() << std::endl;

    std::cout << "string max:" << (std::numeric_limits< std::string >::max )()
        << "\tmin:" << (std::numeric_limits< std::string >::min)() << std::endl;

    std::cout << "size_t max:" << (std::numeric_limits< size_t >::max)()
        << "\tmin:" << (std::numeric_limits< size_t >::min)() << std::endl;

}

void type_definition_test(void)
{
    std::cout << "以下是类型定义的测试：" << std::endl;

    typedef int my_type;
    my_type x = 10;
    std::cout << "my_type x = " << x << std::endl
        << "\tsize : " << sizeof(my_type) << std::endl
        << "\tmax : " << (std::numeric_limits<my_type>::max)() << std::endl
        << "\tmin : " << (std::numeric_limits<my_type>::min)() << std::endl;

}

void enum_test(void)
{
    enum color
    { 
        red,
        green = 6,
        blue
    };

    color test = blue ;

    std::cout << "color x = " << test << std::endl
        << "\tsize : " << sizeof(color) << std::endl
        << "\tmax : " << (std::numeric_limits<color>::max)() << std::endl
        << "\tmin : " << (std::numeric_limits<color>::min)() << std::endl;

}

#ifdef TEST_EXTERN
void test_extern_fun(void)
{
    test_extern++;
}
#endif // TEST_EXTERN

#ifdef GLOBAL_VARIABLE_TEST
void global_variable_test(void)
{
    global_x++;
}
#endif // GLOBAL_VARIABLE_TEST



