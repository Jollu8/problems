cmake_minimum_required(VERSION 4.0.2)

project(problems_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(cpp_tests
        tests/cpp/test_sorts.cpp
        src/cpp/string/substr.h
        src/cpp/string/substr.cpp
        tests/cpp/string/test_substr.cpp
)

target_include_directories(cpp_tests PRIVATE
        src/cpp
)

target_link_libraries(cpp_tests PRIVATE
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(cpp_tests
        PROPERTIES
        TIMEOUT 1
)