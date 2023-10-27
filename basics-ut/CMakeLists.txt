cmake_minimum_required(VERSION 3.13)

project(googletest_sample)

#get googletest
include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG release-1.11.0)
FetchContent_GetProperties(googletest)
#googletest_POPULATED
#googletest_SOURCE_DIR
#googletest_BUILD_DIR
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_library(SumLib STATIC LibCode.cpp)

add_executable(MainApp main.cpp)
target_link_libraries(MainApp SumLib)

add_executable(UnitTestRunner test.cpp)
target_link_libraries(UnitTestRunner SumLib gtest_main gmock_main)