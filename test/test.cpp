#include <codecvt>
#include <cstring>
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

#include <ctest.h>
#include <libtodo/txt.hpp>

using namespace std;

// test checkfile
CTEST(checkfile, file_existence) 
{
    FILE *f;
    ASSERT_EQUAL(0, check_file(f));
}

CTEST(check_data, test_1_txt) 
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    INFO info[5];
    std::vector<std::wstring> words;
    wstring txt;
    wstring search_data = L"22.04";
    transformation_txt(words, txt,"resources/data_test/test_1.txt");
    int a = find_data(txt,search_data, info);
    ASSERT_EQUAL(0, a);
}

CTEST(check_data, test_2_txt) 
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    INFO info[5];
    std::vector<std::wstring> words;
    wstring txt;
    wstring search_data = L"22.11";
    transformation_txt(words, txt,"resources/data_test/test_2.txt");
    int a = find_data(txt,search_data, info);
    ASSERT_EQUAL(4, a);
}

CTEST(check_data, test_3_txt) 
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    INFO info[5];
    std::vector<std::wstring> words;
    wstring txt;
    wstring search_data = L"21.05";
    transformation_txt(words, txt,"resources/data_test/test_3.txt");
    int a = find_data(txt,search_data, info);
    ASSERT_EQUAL(1, a);
}

CTEST(check_data, test_4_txt) 
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    INFO info[5];
    std::vector<std::wstring> words;
    wstring txt;
    wstring search_data = L"21.05";
    transformation_txt(words, txt,"resources/data_test/test_4.txt");
    int a = find_data(txt,search_data, info);
    ASSERT_EQUAL(0, a);
}

CTEST(check_data, test_5_txt) 
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    INFO info[5];
    std::vector<std::wstring> words;
    wstring txt;
    wstring search_data = L".05";
    transformation_txt(words, txt,"resources/data_test/test_5.txt");
    int a = find_data(txt,search_data, info);
    ASSERT_EQUAL(0, a);
}



