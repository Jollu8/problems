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
        src/cpp/random/rand_1.h
        src/cpp/random/rand_1.cpp
        tests/cpp/random/test_1.cpp
        src/cpp/stack/part_1.cpp
        src/cpp/stack/part_1.h
        tests/cpp/stack/test_part_1.cpp
        src/cpp/tree/binary_tree.cpp
        src/cpp/tree/binary_tree.h
        src/cpp/defs.h
        tests/cpp/tree/test_binary_tree.cpp
        tests/cpp/test_utils/test_utils.h
        src/cpp/datastructures/ds_1.cpp
        src/cpp/datastructures/ds_1.h
        tests/cpp/datastructures/test_ds_1.cpp
)

add_executable(hello_world
        main.cpp
)

target_include_directories(cpp_tests PRIVATE
        src/cpp
        tests/cpp/test_utils
)

target_link_libraries(cpp_tests PRIVATE
        GTest::gtest_main
        GTest::gmock
)

include(GoogleTest)

gtest_discover_tests(cpp_tests
        PROPERTIES
        TIMEOUT 1
)