cmake_minimum_required(VERSION 3.13)

project(googletest_gmock)

SET(CXX_STANDARD_REQUIRED 17)

#get googletest
include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG release-1.11.0)
FetchContent_GetProperties(googletest)
#googletest_POPULATED
#googletest_SOURCE_DIR
#googletest_BUILD_DIR

FetchContent_MakeAvailable(googletest)

add_library(MyLib STATIC LibCode3.cpp)

add_executable(MainApp main.cpp)
target_link_libraries(MainApp MyLib)

add_executable(UnitTestRunner test.cpp)
target_link_libraries(UnitTestRunner MyLib GTest::gtest_main GTest::gmock_main pthread)